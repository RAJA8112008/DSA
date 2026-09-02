// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each value, count how many times it appears. Push it once if the count is 2. Slow, no extra set.

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> out;
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < n; j++) if (nums[j] == nums[i]) c++;
    if (c == 2 && find(out.begin(), out.end(), nums[i]) == out.end()) out.push_back(nums[i]);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1) extra
// Sort, then walk adjacent pairs. Equal neighbors are a duplicate. Simple, mutates order.

vector<int> findDuplicates(vector<int>& nums) {
  auto a = nums;
  sort(a.begin(), a.end());
  vector<int> out;
  for (int i = 1; i < (int)a.size(); i++) if (a[i] == a[i - 1]) out.push_back(a[i]);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// Value x belongs at index x-1. Negate that slot when you first see x. If it is already negative, x is the duplicate. Restore signs later if you must.

vector<int> findDuplicates(vector<int>& nums) {
  vector<int> out;
  for (int i = 0; i < (int)nums.size(); i++) {
    int x = nums[i] < 0 ? -nums[i] : nums[i];
    int slot = x - 1;
    if (nums[slot] < 0) out.push_back(x);
    else nums[slot] = -nums[slot];
  }
  return out;
}
