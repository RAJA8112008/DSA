// Method 1: Brute
// Time: O(n³) with naive fact | Space: O(n²)
// Each cell is nCr. Computing factorials from scratch per cell is slow and overflows. Picture is right, implementation is not the interview one.

function generate(numRows) {
  function nCr(n, r) {
    let a = 1, b = 1;
    for (let i = 0; i < r; i++) {
      a *= (n - i);
      b *= (i + 1);
    }
    return Math.round(a / b);
  }
  const out = [];
  for (let i = 0; i < numRows; i++) {
    const row = [];
    for (let j = 0; j <= i; j++) row.push(nCr(i, j));
    out.push(row);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// Row 0 is [1]. Each next row starts and ends with 1. Inner slot j is prev[j-1] + prev[j]. No overflow beyond 32-bit on the usual n <= 30 constraint.

function generate(numRows) {
  const out = [[1]];
  for (let r = 1; r < numRows; r++) {
    const prev = out[r - 1];
    const row = [1];
    for (let j = 1; j < r; j++) row.push(prev[j - 1] + prev[j]);
    row.push(1);
    out.push(row);
  }
  return out;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Each row built independently with the running product formula. Useful when you only need row r (Pascal's Triangle II) and do not want the whole triangle.

function generate(numRows) {
  const out = [];
  for (let r = 0; r < numRows; r++) {
    const row = [1];
    let v = 1;
    for (let k = 1; k <= r; k++) {
      v = v * (r - k + 1) / k;
      row.push(Math.round(v));
    }
    out.push(row);
  }
  return out;
}
