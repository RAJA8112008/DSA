// Method 1: Brute
// Time: O(2^{m+n}) | Space: O(m + n)
// Each cell branches right and down. Paths share prefixes but nothing is cached. Depth is m+n-2 moves. Fine only for tiny grids.

function uniquePaths(m, n) {
  function go(r, c) {
    if (r === m - 1 && c === n - 1) return 1;
    if (r >= m || c >= n) return 0;
    return go(r + 1, c) + go(r, c + 1);
  }
  return go(0, 0);
}


// Method 2: Optimal
// Time: O(m * n) | Space: O(m * n)
// One cell per grid square, filled from two neighbors in O(1). First row and column are the corridor of 1s. This is the table you draw in an interview.

function uniquePaths(m, n) {
  const ways = Array.from({ length: m }, function () {
    return Array(n).fill(0);
  });
  for (let r = 0; r < m; r++) ways[r][0] = 1;
  for (let c = 0; c < n; c++) ways[0][c] = 1;
  for (let r = 1; r < m; r++) {
    for (let c = 1; c < n; c++) {
      ways[r][c] = ways[r - 1][c] + ways[r][c - 1];
    }
  }
  return ways[m - 1][n - 1];
}


// Method 3: More optimal
// Time: O(m * n) | Space: O(n)
// A cell only needs the previous row. One row: ways[c] is “from above” before you add ways[c-1] (from the left). Extra memory is one row of width n.

function uniquePaths(m, n) {
  const ways = Array(n).fill(1);
  for (let r = 1; r < m; r++) {
    for (let c = 1; c < n; c++) {
      ways[c] += ways[c - 1];
    }
  }
  return ways[n - 1];
}
