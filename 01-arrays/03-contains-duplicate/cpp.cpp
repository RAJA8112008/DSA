// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Each pair is compared. Fine for tiny lists, too slow for large n.
// How it works: if nums[i] equals nums[j] for j > i, a duplicate exists.

// vector, unordered_map, string
bool containsDuplicate(vector<int>& nums) {
  int n = (int)nums.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (nums[i] == nums[j]) return true;
    }
  }
  return false;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Copy then sort, then a linear neighbor check. Sorting dominates.
// How it works: equals become neighbors after sort. If two neighbors match, return true.

// vector, unordered_map, string
bool containsDuplicate(vector<int>& nums) {
  vector<int> copy = vector<int>(nums);
  sort(copy.begin(), copy.end());
  for (int i = 1; i < (int)copy.size(); i++) {
    if (copy[i] == copy[i - 1]) return true;
  }
  return false;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass. Set.has is average O(1).
// How it works: if the set already has the number, it is a duplicate. Otherwise add it.

// vector, unordered_map, string
bool containsDuplicate(vector<int>& nums) {
  unordered_set<int> seen;
  for (int i = 0; i < (int)nums.size(); i++) {
    if (seen.count(nums[i])) return true;
    seen.insert(nums[i]);
  }
  return false;
}
