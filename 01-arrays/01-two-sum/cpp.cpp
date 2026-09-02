// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every pair is checked. For n numbers that is about n*(n-1)/2 additions.
// How it works: the outer loop picks the first index. The inner loop picks a later index. The first pair whose sum equals target is returned.

// vector, unordered_map, string
vector<int> twoSum(vector<int>& nums, int target) {
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] + nums[j] == target) return { i, j };
    }
  }
  return {};
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sorting is the extra cost. After that, two pointers only walk the copied list once.
// How it works: store {value, index} so sorting does not lose positions. Move left up when the sum is too small, right down when it is too big.

// vector, unordered_map, string
vector<int> twoSum(vector<int>& nums, int target) {
  vector<int> pairs;
  for (int i = 0; i < (int)nums.size(); i++) {
    pairs.push_back([nums[i], i ]);
  }
  sort(pairs.begin(), pairs.end());

  int left = 0;
  int right = (int)pairs.size() - 1;
  while (left < right) {
    int sum = pairs[left].value + pairs[right].value;
    if (sum == target) return { pairs[left }.index, pairs[right].index];
    if (sum < target) left++;
    else right--;
  }
  return {};
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass. Each lookup in the map is average O(1), so the whole walk is O(n).
// How it works: for x, look up target - x. If it was stored, return those indexes. If not, store x and its index, then continue.

// vector, unordered_map, string
vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int,int> seen;
  for (int i = 0; i < (int)nums.size(); i++) {
    int need = target - nums[i];
    if (seen.count(need)) return { seen[need }, i];
    seen[nums[i]] = i;
  }
  return {};
}
