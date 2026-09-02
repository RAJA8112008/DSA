// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate you scan the whole list. n+1 candidates times n looks.
// How it works: if value x is never found in nums, x is missing.

// vector, unordered_map, string
int missingNumber(vector<int>& nums) {
  int n = (int)nums.size();
  for (int x = 0; x <= n; x++) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      if (nums[i] == x) { found = true; break; }
    }
    if (!found) return x;
  }
  return -1;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Copy and sort, then a linear gap check. Sorting dominates.
// How it works: after sort, index i should hold i. The first mismatch is the missing number. If the list is 0..n-1, n is missing.

// vector, unordered_map, string
int missingNumber(vector<int>& nums) {
  vector<int> list = nums;
  sort(list.begin(), list.end());
  for (int i = 0; i < (int)list.size(); i++) {
    if (list[i] != i) return i;
  }
  return (int)list.size();
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// XOR cancels pairs. Indexes 0..n XOR all values leaves the missing one. No overflow the way a large sum might in other languages (JS numbers are fine here too).
// How it works: start missing = n. XOR i and nums[i] for every i. The leftover is the missing number.

// vector, unordered_map, string
int missingNumber(vector<int>& nums) {
  int n = (int)nums.size();
  int missing = n;
  for (int i = 0; i < n; i++) {
    missing = missing ^ i ^ nums[i];
  }
  return missing;
}
