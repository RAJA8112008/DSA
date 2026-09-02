// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// Generate every leftover-copy permutation, stringify, keep a Set. Duplicate 1s still walk the full n! tree. Extra copies plus the Set.

void go(vector<int> left, vector<int> path, set<vector<int>>& seen, vector<vector<int>>& ans) {
  if (left.empty()) {
    if (seen.insert(path).second) ans.push_back(path);
    return;
  }
  for (int i = 0; i < (int)left.size(); i++) {
    vector<int> nextLeft = left, nextPath = path;
    nextPath.push_back(nextLeft[i]);
    nextLeft.erase(nextLeft.begin() + i);
    go(nextLeft, nextPath, seen, ans);
  }
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// Sort so equal values are adjacent. Skip nums[j] when it equals nums[j-1] and used[j-1] is false. That forces a fixed order on identical numbers. One path, used[].

void go(vector<int>& nums, vector<int>& used, vector<int>& path, vector<vector<int>>& ans) {
  if ((int)path.size() == (int)nums.size()) { ans.push_back(path); return; }
  for (int j = 0; j < (int)nums.size(); j++) {
    if (used[j]) continue;
    if (j > 0 && nums[j] == nums[j - 1] && !used[j - 1]) continue;
    used[j] = 1; path.push_back(nums[j]);
    go(nums, used, path, ans);
    path.pop_back(); used[j] = 0;
  }
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// In-place swap. A tiny set of values already swapped into start this round stops identical branches. No sort required. Same unique output, less leftover copying.

void go(vector<int>& nums, int start, vector<vector<int>>& ans) {
  if (start == (int)nums.size()) { ans.push_back(nums); return; }
  unordered_set<int> seen;
  for (int i = start; i < (int)nums.size(); i++) {
    if (!seen.insert(nums[i]).second) continue;
    swap(nums[start], nums[i]);
    go(nums, start + 1, ans);
    swap(nums[start], nums[i]);
  }
}
