// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target/min)
// Every call copies path.concat. You keep going while the sum is not past target, with no sort prune. Extra arrays at every node. Correct but heavy.

void go(vector<int>& cands, int start, int sum, int target, vector<int> path, vector<vector<int>>& ans) {
  if (sum == target) { ans.push_back(path); return; }
  if (sum > target) return;
  for (int i = start; i < (int)cands.size(); i++) {
    path.push_back(cands[i]);
    go(cands, i, sum + cands[i], target, path, ans);
    path.pop_back();
  }
}


// Method 2: Optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// One path, push/pop. remain shrinks. Call go(i, remain - cands[i]) to reuse this value, or move to i+1 to skip. Copy only at remain == 0.

void go(vector<int>& cands, int i, int remain, vector<int>& path, vector<vector<int>>& ans) {
  if (remain == 0) { ans.push_back(path); return; }
  if (i == (int)cands.size() || remain < 0) return;
  go(cands, i + 1, remain, path, ans);
  path.push_back(cands[i]);
  go(cands, i, remain - cands[i], path, ans);
  path.pop_back();
}


// Method 3: More optimal
// Time: O(n^{target/min}) | Space: O(target/min)
// Sort first. In the for-loop, break when cands[i] > remain so larger later values are never tried. Same answers, fewer dead branches.

void go(vector<int>& cands, int start, int remain, vector<int>& path, vector<vector<int>>& ans) {
  if (remain == 0) { ans.push_back(path); return; }
  for (int i = start; i < (int)cands.size(); i++) {
    if (cands[i] > remain) break;
    path.push_back(cands[i]);
    go(cands, i, remain - cands[i], path, ans);
    path.pop_back();
  }
}
