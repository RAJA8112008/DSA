// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each position may branch into a 1-digit take and a 2-digit take. Overlapping suffixes are recomputed. Zeros prune some branches but the worst case is still exponential.

function numDecodings(s) {
  function go(i) {
    if (i === s.length) return 1;
    if (s[i] === "0") return 0;
    let ways = go(i + 1);
    if (i + 1 < s.length) {
      const two = Number(s[i] + s[i + 1]);
      if (two >= 10 && two <= 26) ways += go(i + 2);
    }
    return ways;
  }
  return go(0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each start index is solved once. Work per index is O(1) digit checks. Memo of n cells plus the call stack. Linear in the length of s.

function numDecodings(s) {
  const memo = [];
  function go(i) {
    if (i === s.length) return 1;
    if (s[i] === "0") return 0;
    if (memo[i] !== undefined) return memo[i];
    let ways = go(i + 1);
    if (i + 1 < s.length) {
      const two = Number(s[i] + s[i + 1]);
      if (two >= 10 && two <= 26) ways += go(i + 2);
    }
    memo[i] = ways;
    return ways;
  }
  return go(0);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// prev1 is ways for the prefix ending here, prev2 is ways for the prefix one shorter. A one-digit code adds prev1. A two-digit code adds prev2. Empty string and a leading zero are the bases. No array.

function numDecodings(s) {
  if (!s.length || s[0] === "0") return 0;
  let prev2 = 1;
  let prev1 = 1;
  for (let i = 1; i < s.length; i++) {
    let cur = 0;
    if (s[i] !== "0") cur += prev1;
    const two = Number(s[i - 1] + s[i]);
    if (two >= 10 && two <= 26) cur += prev2;
    prev2 = prev1;
    prev1 = cur;
  }
  return prev1;
}
