// Method 1: Brute
// Time: O(n * n!) | Space: O(n * n!)
// At each step you copy the leftover numbers into a new array and copy the path. Extra copies on every internal node. n! leaves, each of length n.

void go(vector<int> left, vector<int> path, vector<vector<int>>& ans) {
  if (left.empty()) { ans.push_back(path); return; }
  for (int i = 0; i < (int)left.size(); i++) {
    vector<int> nextLeft = left;
    vector<int> nextPath = path;
    nextPath.push_back(nextLeft[i]);
    nextLeft.erase(nextLeft.begin() + i);
    go(nextLeft, nextPath, ans);
  }
}


// Method 2: Optimal
// Time: O(n * n!) | Space: O(n)
// used[j] marks nums[j] as taken. One path, mark/unmark. Extra space is O(n) besides the n! output lists.

void go(vector<int>& nums, vector<int>& used, vector<int>& path, vector<vector<int>>& ans) {
  if ((int)path.size() == (int)nums.size()) { ans.push_back(path); return; }
  for (int j = 0; j < (int)nums.size(); j++) {
    if (used[j]) continue;
    used[j] = 1; path.push_back(nums[j]);
    go(nums, used, path, ans);
    path.pop_back(); used[j] = 0;
  }
}
vector<vector<int>> permute(vector<int>& nums) {
  vector<vector<int>> ans;
  vector<int> used(nums.size()), path;
  go(nums, used, path, ans);
  return ans;
}


// Method 3: More optimal
// Time: O(n * n!) | Space: O(n)
// Swap nums[start] with each later index, recurse start+1, swap back. The prefix is the path. No used[] and no leftover copies. Still n! output.

void go(vector<int>& nums, int start, vector<vector<int>>& ans) {
  if (start == (int)nums.size()) { ans.push_back(nums); return; }
  for (int i = start; i < (int)nums.size(); i++) {
    swap(nums[start], nums[i]);
    go(nums, start + 1, ans);
    swap(nums[start], nums[i]);
  }
}
