// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Mismatch branches into two calls. Matching still walks both strings. Overlapping (i, j) pairs are recomputed. Stack is O(m+n).

function longestCommonSubsequence(text1, text2) {
  function go(i, j) {
    if (i === text1.length || j === text2.length) return 0;
    if (text1[i] === text2[j]) return 1 + go(i + 1, j + 1);
    return Math.max(go(i + 1, j), go(i, j + 1));
  }
  return go(0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per prefix pair. Each cell is O(1) work from three neighbors. The full grid makes the recurrence obvious and is what you draw on a whiteboard.

function longestCommonSubsequence(text1, text2) {
  const m = text1.length;
  const n = text2.length;
  const dp = Array.from({ length: m + 1 }, function () {
    return Array(n + 1).fill(0);
  });
  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (text1[i - 1] === text2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  return dp[m][n];
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(min(m, n))
// A cell only needs the previous row. Keep prev and cur. Swap the shorter string onto the row so extra memory is the smaller length. Time is still every pair of letters.

function longestCommonSubsequence(text1, text2) {
  if (text1.length < text2.length) {
    const tmp = text1;
    text1 = text2;
    text2 = tmp;
  }
  const n = text2.length;
  let prev = Array(n + 1).fill(0);
  for (let i = 1; i <= text1.length; i++) {
    const cur = Array(n + 1).fill(0);
    for (let j = 1; j <= n; j++) {
      if (text1[i - 1] === text2[j - 1]) cur[j] = prev[j - 1] + 1;
      else cur[j] = Math.max(prev[j], cur[j - 1]);
    }
    prev = cur;
  }
  return prev[n];
}
