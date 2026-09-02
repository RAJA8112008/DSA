// Method 1: Brute
// Time: O(n³) | Space: O(n)
// O(n²) substrings, and each uniqueness check can scan the slice again.
// How it works: for every i..j, a Set of s[i..j] must have size j-i+1. Keep the max length.

function lengthOfLongestSubstring(s) {
  const n = s.length;
  let best = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      const seen = new Set();
      let unique = true;
      for (let k = i; k <= j; k++) {
        if (seen.has(s[k])) { unique = false; break; }
        seen.add(s[k]);
      }
      if (unique && j - i + 1 > best) best = j - i + 1;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// From each start, grow right until a repeat. Inner work is O(n), times n starts.
// How it works: seen is a Set for the current window. On a repeat, break and try the next start.

function lengthOfLongestSubstring(s) {
  let best = 0;
  const n = s.length;
  for (let i = 0; i < n; i++) {
    const seen = new Set();
    for (let j = i; j < n; j++) {
      if (seen.has(s[j])) break;
      seen.add(s[j]);
      if (j - i + 1 > best) best = j - i + 1;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each index is a right endpoint once. left only moves forward. Map stores last indexes.
// How it works: if this character last appeared inside the window, jump left past it. Then update last index and best length.

function lengthOfLongestSubstring(s) {
  const last = new Map();
  let left = 0;
  let best = 0;
  for (let right = 0; right < s.length; right++) {
    const ch = s[right];
    if (last.has(ch) && last.get(ch) >= left) left = last.get(ch) + 1;
    last.set(ch, right);
    const len = right - left + 1;
    if (len > best) best = len;
  }
  return best;
}
