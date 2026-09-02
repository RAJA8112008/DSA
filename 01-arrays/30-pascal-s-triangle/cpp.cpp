// Method 1: Brute
// Time: O(n³) with naive fact | Space: O(n²)
// Each cell is nCr. Computing factorials from scratch per cell is slow and overflows. Picture is right, implementation is not the interview one.

vector<vector<int>> generate(int numRows) {
  auto nCr = [](int n, int r) {
    long a = 1, b = 1;
    for (int i = 0; i < r; i++) { a *= (n - i); b *= (i + 1); }
    return (int)(a / b);
  };
  vector<vector<int>> out;
  for (int i = 0; i < numRows; i++) {
    vector<int> row;
    for (int j = 0; j <= i; j++) row.push_back(nCr(i, j));
    out.push_back(row);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// Row 0 is [1]. Each next row starts and ends with 1. Inner slot j is prev[j-1] + prev[j]. No overflow beyond 32-bit on the usual n <= 30 constraint.

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> out = {{1}};
  for (int r = 1; r < numRows; r++) {
    vector<int>& prev = out.back();
    vector<int> row = {1};
    for (int j = 1; j < r; j++) row.push_back(prev[j - 1] + prev[j]);
    row.push_back(1);
    out.push_back(row);
  }
  return out;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Each row built independently with the running product formula. Useful when you only need row r (Pascal's Triangle II) and do not want the whole triangle.

vector<vector<int>> generate(int numRows) {
  vector<vector<int>> out;
  for (int r = 0; r < numRows; r++) {
    vector<int> row;
    long v = 1;
    row.push_back(1);
    for (int k = 1; k <= r; k++) {
      v = v * (r - k + 1) / k;
      row.push_back((int)v);
    }
    out.push_back(row);
  }
  return out;
}
