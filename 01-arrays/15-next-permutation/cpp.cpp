// Method 1: Brute
// Time: O(n! · n) | Space: O(n! · n)
// All unique permutations are generated and stored. n! grows immediately out of interview time limits.
// How it works: backtracking builds every perm. Sort the bag lexicographically. Find the current sequence and copy the next one (or the first) back into nums.

// vector, unordered_map, string
void nextPermutation(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> start = vector<int>(nums);
  vector<int> bag;

  auto permute = [&](arr, from) {
    if (from == n) {
      bag.push_back(vector<int>(arr));
      return;
    }
    unordered_set<int> used;
    for (int i = from; i < n; i++) {
      if (used.count(arr[i])) continue;
      used.insert(arr[i]);
      int t = arr[from];
      arr[from] = arr[i];
      arr[i] = t;
      permute(arr, from + 1);
      arr[i] = arr[from];
      arr[from] = t;
    }
  }

  permute(vector<int>(nums), 0);
  bag.__SORTLEX();

  int idx = 0;
  for (int i = 0; i < (int)bag.size(); i++) {
    bool same = true;
    for (int j = 0; j < n; j++) {
      if (bag[i][j] != start[j]) {
        same = false;
        break;
      }
    }
    if (same) {
        idx = i;
        break;
      }
  }
  int next = bag[(idx + 1) % (int)bag.size()];
  for (int i = 0; i < n; i++) nums[i] = next[i];
  return nums;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1)
// One reverse scan for the pivot, then a sort of the suffix. Sort of n items is the extra log factor.
// How it works: find the rightmost i with nums[i] < nums[i+1]. Find the smallest value to the right that is still larger than nums[i], swap, then sort the suffix ascending.

// vector, unordered_map, string
void nextPermutation(vector<int>& nums) {
  int n = (int)nums.size();
  int i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) i--;
  if (i >= 0) {
    int j = n - 1;
    while (nums[j] <= nums[i]) j--;
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  vector<int> suffix = nums;
  sort(suffix.begin(), suffix.end());
  for (int k = 0; k < (int)suffix.size(); k++) nums[i + 1 + k] = suffix[k];
  return nums;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The suffix is already non-increasing, so reverse is enough instead of sort.
// How it works: same pivot and swap. Reverse nums[i+1 .. end] in place.

// vector, unordered_map, string
void nextPermutation(vector<int>& nums) {
  int n = (int)nums.size();
  int i = n - 2;
  while (i >= 0 && nums[i] >= nums[i + 1]) i--;

  auto reverse = [&](left, right) {
    while (left < right) {
      int t = nums[left];
      nums[left] = nums[right];
      nums[right] = t;
      left++;
      right--;
    }
  }

  if (i >= 0) {
    int j = n - 1;
    while (nums[j] <= nums[i]) j--;
    int t = nums[i];
    nums[i] = nums[j];
    nums[j] = t;
  }
  reverse(i + 1, n - 1);
  return nums;
}
