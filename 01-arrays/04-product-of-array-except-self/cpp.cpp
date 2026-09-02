// Method 1: Brute
// Time: O(n²) | Space: O(n)
// For each i you multiply n - 1 others. That is n² multiplications.
// How it works: skip index i in the inner loop. Store the product in out[i].

// vector, unordered_map, string
vector<int> productExceptSelf(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> out = vector<int>(n);
  for (int i = 0; i < n; i++) {
    int prod = 1;
    for (int j = 0; j < n; j++) {
      if (j != i) prod *= nums[j];
    }
    out[i] = prod;
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Three linear passes and two extra arrays of length n.
// How it works: left[i] is the product of items before i. right[i] is the product after i. out[i] = left[i] * right[i].

// vector, unordered_map, string
vector<int> productExceptSelf(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> left = vector<int>(n);
  vector<int> right = vector<int>(n);
  vector<int> out = vector<int>(n);
  left[0] = 1;
  for (int i = 1; i < n; i++) left[i] = left[i - 1] * nums[i - 1];
  right[n - 1] = 1;
  for (int i = n - 2; i >= 0; i--) right[i] = right[i + 1] * nums[i + 1];
  for (int i = 0; i < n; i++) out[i] = left[i] * right[i];
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Still O(n) memory for the answer list, but no extra left/right arrays.
// How it works: fill out with prefix products. Then walk right to left with a running suffix product and multiply it in.

// vector, unordered_map, string
vector<int> productExceptSelf(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> out = vector<int>(n);
  out[0] = 1;
  for (int i = 1; i < n; i++) out[i] = out[i - 1] * nums[i - 1];
  int right = 1;
  for (int i = n - 1; i >= 0; i--) {
    out[i] *= right;
    right *= nums[i];
  }
  return out;
}
