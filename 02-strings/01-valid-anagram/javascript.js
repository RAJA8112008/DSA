// Method 1: Brute
// Time: O(n²) | Space: O(n)
// For each letter in s you search t and splice it out. Each splice is O(n), so quadratic.
// How it works: copy t into an array. For every character of s, indexOf that character in the copy; if missing, false; else splice it out. Empty copy at the end means success.

function isAnagram(s, t) {
  if (s.length !== t.length) return false;
  const letters = t.split("");
  for (let i = 0; i < s.length; i++) {
    const idx = letters.indexOf(s[i]);
    if (idx === -1) return false;
    letters.splice(idx, 1);
  }
  return letters.length === 0;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sorting both strings dominates. Extra arrays hold the split characters.
// How it works: sort the character lists and compare them index by index.

function isAnagram(s, t) {
  if (s.length !== t.length) return false;
  const a = s.split("").sort();
  const b = t.split("").sort();
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) return false;
  }
  return true;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass over both strings and 26 integers. For lowercase a-z the extra space is constant.
// How it works: count[s[i]]++, count[t[i]]--. If every slot is 0, the bags of letters matched.

function isAnagram(s, t) {
  if (s.length !== t.length) return false;
  const count = new Array(26).fill(0);
  for (let i = 0; i < s.length; i++) {
    count[s.charCodeAt(i) - 97]++;
    count[t.charCodeAt(i) - 97]--;
  }
  for (let i = 0; i < 26; i++) {
    if (count[i] !== 0) return false;
  }
  return true;
}
