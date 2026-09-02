// Method 1: Brute
// Time: O(n² · 26) | Space: O(1)
// Every window rebuilds 26 counts and checks whether length - maxCount <= k.
// How it works: if the letters that are not the most common letter fit in k replacements, the window is valid. Keep the max valid length.

function characterReplacement(s, k) {
  let best = 0;
  const n = s.length;
  for (let i = 0; i < n; i++) {
    const count = new Array(26).fill(0);
    let maxCount = 0;
    for (let j = i; j < n; j++) {
      const idx = s.charCodeAt(j) - 65;
      count[idx]++;
      if (count[idx] > maxCount) maxCount = count[idx];
      const len = j - i + 1;
      if (len - maxCount <= k && len > best) best = len;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n · 26) | Space: O(1)
// One window. When invalid, left moves and you recompute maxCount by scanning 26 slots.
// How it works: grow right. While length - maxCount > k, decrement s[left] and recount maxCount. Then update best.

function characterReplacement(s, k) {
  const count = new Array(26).fill(0);
  let left = 0;
  let best = 0;
  for (let right = 0; right < s.length; right++) {
    count[s.charCodeAt(right) - 65]++;
    function maxInCount() {
      let m = 0;
      for (let i = 0; i < 26; i++) if (count[i] > m) m = count[i];
      return m;
    }
    while (right - left + 1 - maxInCount() > k) {
      count[s.charCodeAt(left) - 65]--;
      left++;
    }
    const len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// maxCount only increases when a better majority appears. For the longest window, you never need a smaller maxCount.
// How it works: grow right, update maxCount. If window is too dirty, move left once (not a while with a rescan). Window size still only grows when valid history allows it.

function characterReplacement(s, k) {
  const count = new Array(26).fill(0);
  let left = 0;
  let maxCount = 0;
  let best = 0;
  for (let right = 0; right < s.length; right++) {
    const idx = s.charCodeAt(right) - 65;
    count[idx]++;
    if (count[idx] > maxCount) maxCount = count[idx];
    if (right - left + 1 - maxCount > k) {
      count[s.charCodeAt(left) - 65]--;
      left++;
    }
    const len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}
