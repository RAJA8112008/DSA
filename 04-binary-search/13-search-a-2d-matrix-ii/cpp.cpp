// Method 1: Brute
// Time: O(rc) | Space: O(1)
// Visit every cell. Correct, ignores both sorted axes.

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for (auto& row : matrix) for (int v : row) if (v == target) return true;
    return false;
  }
};


// Method 2: Optimal
// Time: O(r log c) | Space: O(1)
// Each row is sorted, so binary search that row. Skip a row whose first cell is already larger than target or whose last cell is smaller. Good when there are few rows.

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int cols = (int)matrix[0].size();
    for (auto& row : matrix) {
      if (row[0] > target || row[cols - 1] < target) continue;
      int lo = 0, hi = cols - 1;
      while (lo <= hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (row[mid] == target) return true;
        if (row[mid] < target) lo = mid + 1;
        else hi = mid - 1;
      }
    }
    return false;
  }
};


// Method 3: More optimal
// Time: O(r + c) | Space: O(1)
// Start at top-right. The cell is the largest in its row prefix and the smallest in its column suffix. Larger than target: nothing in this column below can be smaller in a useful way — move left. Smaller: move down. Each step drops a row or a column.

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r = 0, c = (int)matrix[0].size() - 1;
    while (r < (int)matrix.size() && c >= 0) {
      if (matrix[r][c] == target) return true;
      if (matrix[r][c] > target) c--;
      else r++;
    }
    return false;
  }
};
