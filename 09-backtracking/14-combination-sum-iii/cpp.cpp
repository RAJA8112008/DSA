// Method 1: Brute
// Time: O(C(9, k) * k) | Space: O(k)
// Generate every k-subset with path copies, then filter by sum. C(9,k) is tiny, but you still build losers and copy arrays on every call.

void go(int start, int k, int n, vector<int> path, vector<vector<int>>& ans) {
  if ((int)path.size() == k) {
    int sum = 0; for (int x : path) sum += x;
    if (sum == n) ans.push_back(path);
    return;
  }
  for (int x = start; x <= 9; x++) {
    path.push_back(x);
    go(x + 1, k, n, path, ans);
    path.pop_back();
  }
}


// Method 2: Optimal
// Time: O(C(9, k) * k) | Space: O(k)
// One path. Push x, remain -= x, recurse x+1, pop. Snapshot when k numbers are chosen and remain is 0. No extra copies on internal nodes.

void go(int start, int left, int remain, vector<int>& path, vector<vector<int>>& ans) {
  if (left == 0) { if (remain == 0) ans.push_back(path); return; }
  for (int x = start; x <= 9; x++) {
    path.push_back(x);
    go(x + 1, left - 1, remain - x, path, ans);
    path.pop_back();
  }
}


// Method 3: More optimal
// Time: O(C(9, k) * k) | Space: O(k)
// Prune: remain < 0, or remain bigger than the largest left numbers, or remain smaller than the smallest left numbers. Stop the loop when x itself is already too big.

void go(int start, int left, int remain, vector<int>& path, vector<vector<int>>& ans) {
  if (left == 0) { if (remain == 0) ans.push_back(path); return; }
  int minSum = left * (2 * start + left - 1) / 2;
  int maxSum = left * (2 * 9 - left + 1) / 2;
  if (remain < minSum || remain > maxSum) return;
  for (int x = start; x <= 9; x++) {
    if (x > remain) break;
    path.push_back(x);
    go(x + 1, left - 1, remain - x, path, ans);
    path.pop_back();
  }
}
