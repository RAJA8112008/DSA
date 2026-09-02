// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Every index is take or skip with extra path copies. Keep combinations whose sum is target, unique them with a sorted-tuple Set. Duplicate indexes still explore the full 2^n tree.

void go(vector<int>& cands, int i, int sum, int target, vector<int> path, set<vector<int>>& seen, vector<vector<int>>& ans) {
  if (sum == target) {
    sort(path.begin(), path.end());
    if (seen.insert(path).second) ans.push_back(path);
    return;
  }
  if (i == (int)cands.size() || sum > target) return;
  go(cands, i + 1, sum, target, path, seen, ans);
  path.push_back(cands[i]);
  go(cands, i + 1, sum + cands[i], target, path, seen, ans);
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort. Skip nums[i] == nums[i-1] at the same start so identical values do not start the same role twice. Each index is used at most once (go(i+1)).

void go(vector<int>& cands, int start, int remain, vector<int>& path, vector<vector<int>>& ans) {
  if (remain == 0) { ans.push_back(path); return; }
  for (int i = start; i < (int)cands.size(); i++) {
    if (i > start && cands[i] == cands[i - 1]) continue;
    if (cands[i] > remain) continue;
    path.push_back(cands[i]);
    go(cands, i + 1, remain - cands[i], path, ans);
    path.pop_back();
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// After sort, break when cands[i] > remain. Later values are larger, so they cannot help. Same unique combinations, fewer recursive calls.

void go(vector<int>& cands, int start, int remain, vector<int>& path, vector<vector<int>>& ans) {
  if (remain == 0) { ans.push_back(path); return; }
  for (int i = start; i < (int)cands.size(); i++) {
    if (cands[i] > remain) break;
    if (i > start && cands[i] == cands[i - 1]) continue;
    path.push_back(cands[i]);
    go(cands, i + 1, remain - cands[i], path, ans);
    path.pop_back();
  }
}
