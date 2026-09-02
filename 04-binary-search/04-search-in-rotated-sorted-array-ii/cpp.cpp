// Method 1: Brute
// Time: O(n) | Space: O(1)
// Duplicates already force O(n) in the worst case, so a linear scan is honest. Still too weak as the only answer: they want the rotated-half logic.

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    for (int v : nums) if (v == target) return true;
    return false;
  }
};


// Method 2: Optimal
// Time: O(log n) avg, O(n) worst | Space: O(1)
// If lo, mid, and hi are equal, shrink both ends. Otherwise one half is sorted; keep the half that can contain target. Worst case is all duplicates, which is linear.

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] == target) return true;
      if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) { lo++; hi--; continue; }
      if (nums[lo] <= nums[mid]) {
        if (nums[lo] <= target && target < nums[mid]) hi = mid - 1;
        else lo = mid + 1;
      } else {
        if (nums[mid] < target && target <= nums[hi]) lo = mid + 1;
        else hi = mid - 1;
      }
    }
    return false;
  }
};


// Method 3: More optimal
// Time: O(log n) avg, O(n) worst | Space: O(1)
// Skip a whole equal-run on each end instead of one index at a time when lo/mid/hi match. Fewer iterations on long duplicate prefixes and suffixes. Worst case is still linear.

class Solution {
public:
  bool search(vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo <= hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] == target || nums[lo] == target || nums[hi] == target) return true;
      if (nums[lo] == nums[mid] && nums[mid] == nums[hi]) {
        while (lo <= hi && nums[lo] == nums[mid]) lo++;
        while (lo <= hi && nums[hi] == nums[mid]) hi--;
        continue;
      }
      if (nums[lo] <= nums[mid]) {
        if (nums[lo] < target && target < nums[mid]) hi = mid - 1;
        else lo = mid + 1;
      } else {
        if (nums[mid] < target && target < nums[hi]) lo = mid + 1;
        else hi = mid - 1;
      }
    }
    return false;
  }
};
