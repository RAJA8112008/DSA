// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every start index pairs with every end index. Inner additions make this quadratic.
// How it works: i is the start. sum grows as j walks right. best tracks the largest sum seen, including all-negative lists.

// vector, unordered_map, string
int maxSubArray(vector<int>& nums) {
  int best = INT_MIN;
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = i; j < n; j++) {
      sum += nums[j];
      if (sum > best) best = sum;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Linear time with a DP array of length n.
// How it works: dp[i] is the best sum among subarrays that end at i. It is either nums[i] alone or dp[i - 1] + nums[i]. The answer is the max of dp.

// vector, unordered_map, string
int maxSubArray(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> dp = vector<int>(n);
  dp[0] = nums[0];
  int best = dp[0];
  for (int i = 1; i < n; i++) {
    dp[i] = max(nums[i], dp[i - 1] + nums[i]);
    if (dp[i] > best) best = dp[i];
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Kadane: only the previous ending-sum is needed, so extra memory is constant.
// How it works: endingHere is dp[i] without the array. best is the global max. Start both from nums[0] so all-negative input still works.

// vector, unordered_map, string
int maxSubArray(vector<int>& nums) {
  int endingHere = nums[0];
  int best = nums[0];
  for (int i = 1; i < (int)nums.size(); i++) {
    endingHere = max(nums[i], endingHere + nums[i]);
    if (endingHere > best) best = endingHere;
  }
  return best;
}
