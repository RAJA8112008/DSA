// Method 1: Brute
// Time: O(3^{m+n}) | Space: O(m + n)
// Mismatch tries insert, delete, and replace. Those three-way branches overlap heavily. Depth is the remaining letters. Unusable on long strings.

function minDistance(word1, word2) {
  function go(i, j) {
    if (i === word1.length) return word2.length - j;
    if (j === word2.length) return word1.length - i;
    if (word1[i] === word2[j]) return go(i + 1, j + 1);
    const insert = 1 + go(i, j + 1);
    const del = 1 + go(i + 1, j);
    const replace = 1 + go(i + 1, j + 1);
    return Math.min(insert, del, replace);
  }
  return go(0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// dp[i][j] is edit distance of the first i letters and first j letters. Borders are i and j. Each inner cell is O(1). The table is the standard Levenshtein grid.

function minDistance(word1, word2) {
  const m = word1.length;
  const n = word2.length;
  const dp = Array.from({ length: m + 1 }, function () {
    return Array(n + 1).fill(0);
  });
  for (let i = 0; i <= m; i++) dp[i][0] = i;
  for (let j = 0; j <= n; j++) dp[0][j] = j;
  for (let i = 1; i <= m; i++) {
    for (let j = 1; j <= n; j++) {
      if (word1[i - 1] === word2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = 1 + Math.min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]);
      }
    }
  }
  return dp[m][n];
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell needs the previous row (delete, replace) and the current row’s left (insert). Keep prev and cur. Extra memory is the length of word2 plus one.

function minDistance(word1, word2) {
  const m = word1.length;
  const n = word2.length;
  let prev = Array(n + 1);
  for (let j = 0; j <= n; j++) prev[j] = j;
  for (let i = 1; i <= m; i++) {
    const cur = Array(n + 1);
    cur[0] = i;
    for (let j = 1; j <= n; j++) {
      if (word1[i - 1] === word2[j - 1]) cur[j] = prev[j - 1];
      else cur[j] = 1 + Math.min(prev[j], cur[j - 1], prev[j - 1]);
    }
    prev = cur;
  }
  return prev[n];
}
