// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Each call does path.concat so every node of the tree allocates a new array. Correct, but you pay extra copies on internal nodes, not only at leaves. Time is still exponential because there are 2^n subsets.

void go(vector<int>& nums, int i, vector<int> path, vector<vector<int>>& ans) {
  if (i == (int)nums.size()) { ans.push_back(path); return; }
  go(nums, i + 1, path, ans);
  path.push_back(nums[i]);
  go(nums, i + 1, path, ans);
}
vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> ans;
  go(nums, 0, {}, ans);
  return ans;
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// One path array is shared. Push, recurse, pop. You copy only at a leaf. Extra memory besides the output is the path plus O(n) stack.

void go(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& ans) {
  if (i == (int)nums.size()) { ans.push_back(path); return; }
  go(nums, i + 1, path, ans);
  path.push_back(nums[i]);
  go(nums, i + 1, path, ans);
  path.pop_back();
}
vector<vector<int>> subsets(vector<int>& nums) {
  vector<vector<int>> ans;
  vector<int> path;
  go(nums, 0, path, ans);
  return ans;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// No recursion. Each mask from 0 to 2^n-1 is one subset. Bit i on means nums[i] is in. Same output size, no call stack, tight inner loop.

vector<vector<int>> subsets(vector<int>& nums) {
  int n = (int)nums.size();
  vector<vector<int>> ans;
  int total = 1 << n;
  for (int mask = 0; mask < total; mask++) {
    vector<int> cur;
    for (int i = 0; i < n; i++) if (mask & (1 << i)) cur.push_back(nums[i]);
    ans.push_back(cur);
  }
  return ans;
}
