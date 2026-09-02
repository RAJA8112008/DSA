// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// Build every subset with extra path copies, stringify, and keep a Set. Duplicate work is thrown away after you already built it. Fine for tiny n, not the interview finish.

void go(vector<int>& nums, int i, vector<int> path, set<vector<int>>& seen, vector<vector<int>>& ans) {
  if (i == (int)nums.size()) {
    vector<int> copy = path;
    sort(copy.begin(), copy.end());
    if (seen.insert(copy).second) ans.push_back(copy);
    return;
  }
  go(nums, i + 1, path, seen, ans);
  path.push_back(nums[i]);
  go(nums, i + 1, path, seen, ans);
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// Sort, then at each start skip nums[i] when it equals nums[i-1]. Those two 2s cannot start the same role twice, so [1,2] appears once. One path, push/pop.

void go(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
  ans.push_back(path);
  for (int i = start; i < (int)nums.size(); i++) {
    if (i > start && nums[i] == nums[i - 1]) continue;
    path.push_back(nums[i]);
    go(nums, i + 1, path, ans);
    path.pop_back();
  }
}
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  vector<int> path;
  go(nums, 0, path, ans);
  return ans;
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n)
// Same sort-and-skip, plus you can count how many copies of this value exist and take 0..count in one shot. That collapses a chain of duplicate-index decisions into one loop.

void go(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& ans) {
  ans.push_back(path);
  int i = start;
  while (i < (int)nums.size()) {
    int j = i;
    while (j < (int)nums.size() && nums[j] == nums[i]) j++;
    int count = j - i;
    for (int t = 1; t <= count; t++) {
      path.push_back(nums[i]);
      go(nums, j, path, ans);
    }
    for (int t = 1; t <= count; t++) path.pop_back();
    i = j;
  }
}
