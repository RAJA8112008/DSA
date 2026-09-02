// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Each zero may be swapped toward the end across many cells. Worst case quadratic.
// How it works: when you see a zero, swap it right until a non-zero neighbor is found or you hit the end. Slow, but in place.

// vector, unordered_map, string
vector<int> moveZeroes(vector<int>& nums) {
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    if (nums[i] != 0) continue;
    int j = i + 1;
    while (j < n && nums[j] == 0) j++;
    if (j == n) break;
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  return nums;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Extra array holds the compacted values, then you copy back.
// How it works: collect non-zeros, append zeros until length n, copy into nums.

// vector, unordered_map, string
vector<int> moveZeroes(vector<int>& nums) {
  vector<int> extra;
  for (int i = 0; i < (int)nums.size(); i++) {
    if (nums[i] != 0) extra.push_back(nums[i]);
  }
  while ((int)extra.size() < (int)nums.size()) extra.push_back(0);
  for (int i = 0; i < (int)nums.size(); i++) nums[i] = extra[i];
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One write index, two linear passes, no extra list.
// How it works: copy each non-zero to write and increment write. Then fill nums[write..] with 0.

// vector, unordered_map, string
vector<int> moveZeroes(vector<int>& nums) {
  int write = 0;
  for (int read = 0; read < (int)nums.size(); read++) {
    if (nums[read] != 0) {
      nums[write] = nums[read];
      write++;
    }
  }
  while (write < (int)nums.size()) {
    nums[write] = 0;
    write++;
  }
  return nums;
}
