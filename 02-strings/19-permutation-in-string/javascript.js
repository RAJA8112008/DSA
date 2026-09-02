// Method 1: Brute
// Time: O(m! · n) | Space: O(m! · m)
// All unique perms of s1 are generated, then each is searched in s2. Factorial in m.
// How it works: backtracking builds permutations. indexOf each perm in s2; any hit is true.

function checkInclusion(s1, s2) {
  const bag = [];
  function permute(arr, from) {
    if (from === arr.length) {
      bag.push(arr.join(""));
      return;
    }
    const used = new Set();
    for (let i = from; i < arr.length; i++) {
      if (used.has(arr[i])) continue;
      used.add(arr[i]);
      const t = arr[from];
      arr[from] = arr[i];
      arr[i] = t;
      permute(arr, from + 1);
      arr[i] = arr[from];
      arr[from] = t;
    }
  }
  permute(s1.split(""), 0);
  for (let i = 0; i < bag.length; i++) {
    if (s2.indexOf(bag[i]) !== -1) return true;
  }
  return false;
}


// Method 2: Optimal
// Time: O(n · 26) | Space: O(1)
// Window of size m slides across s2. Each position compares two 26-slot arrays.
// How it works: need counts s1. have counts the current window. If they match, true. Slide by dropping left and adding right.

function checkInclusion(s1, s2) {
  const m = s1.length;
  const n = s2.length;
  if (m > n) return false;
  const need = new Array(26).fill(0);
  const have = new Array(26).fill(0);
  for (let i = 0; i < m; i++) {
    need[s1.charCodeAt(i) - 97]++;
    have[s2.charCodeAt(i) - 97]++;
  }
  function same() {
    for (let i = 0; i < 26; i++) if (need[i] !== have[i]) return false;
    return true;
  }
  if (same()) return true;
  for (let right = m; right < n; right++) {
    have[s2.charCodeAt(right) - 97]++;
    have[s2.charCodeAt(right - m) - 97]--;
    if (same()) return true;
  }
  return false;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// matches tracks how many of the 26 letters currently have the right count. Each add/drop updates matches in O(1).
// How it works: when have[i] hits need[i], matches++. When it leaves, matches--. matches === 26 (or the number of letters that appear in s1) means the window is a permutation. Here we compare all 26 including zeros, so 26 is the target.

function checkInclusion(s1, s2) {
  const m = s1.length;
  const n = s2.length;
  if (m > n) return false;
  const need = new Array(26).fill(0);
  const have = new Array(26).fill(0);
  for (let i = 0; i < m; i++) {
    need[s1.charCodeAt(i) - 97]++;
    have[s2.charCodeAt(i) - 97]++;
  }
  let matches = 0;
  for (let i = 0; i < 26; i++) if (need[i] === have[i]) matches++;
  if (matches === 26) return true;
  for (let right = m; right < n; right++) {
    const add = s2.charCodeAt(right) - 97;
    const drop = s2.charCodeAt(right - m) - 97;
    have[add]++;
    if (have[add] === need[add]) matches++;
    else if (have[add] === need[add] + 1) matches--;
    have[drop]--;
    if (have[drop] === need[drop]) matches++;
    else if (have[drop] === need[drop] - 1) matches--;
    if (matches === 26) return true;
  }
  return false;
}
