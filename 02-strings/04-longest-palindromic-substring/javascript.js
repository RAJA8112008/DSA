// Method 1: Brute
// Time: O(n³) | Space: O(1)
// O(n²) slices, each palindrome test is O(n).
// How it works: try longer slices first so the first hit is a longest palindrome. isPalin uses two pointers on s[left..right].

function longestPalindrome(s) {
  function isPalin(left, right) {
    while (left < right) {
      if (s[left] !== s[right]) return false;
      left++;
      right--;
    }
    return true;
  }
  const n = s.length;
  for (let len = n; len >= 1; len--) {
    for (let i = 0; i + len - 1 < n; i++) {
      if (isPalin(i, i + len - 1)) return s.slice(i, i + len);
    }
  }
  return "";
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// 2n-1 expansions, each O(n) in the worst case. Extra memory is a few indexes.
// How it works: expand(i,i) covers odd length, expand(i,i+1) covers even. Keep the longest slice.

function longestPalindrome(s) {
  let bestL = 0;
  let bestR = 0;
  function expand(left, right) {
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      if (right - left > bestR - bestL) {
        bestL = left;
        bestR = right;
      }
      left--;
      right++;
    }
  }
  for (let i = 0; i < s.length; i++) {
    expand(i, i);
    expand(i, i + 1);
  }
  return s.slice(bestL, bestR + 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Manacher: a transformed string with separators, plus a radius array of length 2n+3. Each side is expanded only past the known right bound.
// How it works: t = ^#s#s#$ so even and odd palindromes look the same. p[i] is the radius. Mirror across center when i is inside right. Original start is (center - radius) / 2 on the # string.

function longestPalindrome(s) {
  if (s.length < 2) return s;
  const t = ["^"];
  for (let i = 0; i < s.length; i++) {
    t.push("#");
    t.push(s[i]);
  }
  t.push("#");
  t.push("$");
  const n = t.length;
  const p = new Array(n).fill(0);
  let center = 0;
  let right = 0;
  let bestC = 0;
  let bestLen = 0;
  for (let i = 1; i < n - 1; i++) {
    const mirror = 2 * center - i;
    if (i < right) p[i] = Math.min(right - i, p[mirror]);
    while (t[i + 1 + p[i]] === t[i - 1 - p[i]]) p[i]++;
    if (i + p[i] > right) {
      center = i;
      right = i + p[i];
    }
    if (p[i] > bestLen) {
      bestLen = p[i];
      bestC = i;
    }
  }
  const start = Math.floor((bestC - bestLen) / 2);
  return s.slice(start, start + bestLen);
}
