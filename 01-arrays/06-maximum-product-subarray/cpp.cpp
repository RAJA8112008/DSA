// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every subarray product is computed. Zeros and negatives are handled automatically, at quadratic cost.
// How it works: start at i, multiply as j walks right, track the max product.

// vector, unordered_map, string
int maxProduct(vector<int>& nums) {
  int best = INT_MIN;
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    int prod = 1;
    for (int j = i; j < n; j++) {
      prod *= nums[j];
      if (prod > best) best = prod;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Linear time with min/max DP arrays. A negative number can turn a min into a max.
// How it works: maxEnd[i] and minEnd[i] consider nums[i] alone, or times the previous max, or times the previous min. Answer is the max of maxEnd.

// vector, unordered_map, string
int maxProduct(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> maxEnd = vector<int>(n);
  vector<int> minEnd = vector<int>(n);
  maxEnd[0] = nums[0];
  minEnd[0] = nums[0];
  int best = nums[0];
  for (int i = 1; i < n; i++) {
    int x = nums[i];
    maxEnd[i] = max(x, max(maxEnd[i - 1] * x, minEnd[i - 1] * x));
    minEnd[i] = min(x, min(maxEnd[i - 1] * x, minEnd[i - 1] * x));
    if (maxEnd[i] > best) best = maxEnd[i];
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Same recurrence, two scalars instead of two arrays.
// How it works: copy prev max/min into locals before updating, because both formulas need the old values. Then take the global max of maxEnd.

// vector, unordered_map, string
int maxProduct(vector<int>& nums) {
  int maxEnd = nums[0];
  int minEnd = nums[0];
  int best = nums[0];
  for (int i = 1; i < (int)nums.size(); i++) {
    int x = nums[i];
    int prevMax = maxEnd;
    int prevMin = minEnd;
    maxEnd = max(x, max(prevMax * x, prevMin * x));
    minEnd = min(x, min(prevMax * x, prevMin * x));
    if (maxEnd > best) best = maxEnd;
  }
  return best;
}
