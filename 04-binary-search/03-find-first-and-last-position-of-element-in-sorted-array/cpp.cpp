// Method 1: Brute
// Time: O(n) | Space: O(1)
// One left-to-right pass. First time you see target, store i. Every time you see it, update last. Missing target leaves both at -1.

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int first = -1, last = -1;
    for (int i = 0; i < (int)nums.size(); i++) {
      if (nums[i] == target) {
        if (first < 0) first = i;
        last = i;
      }
    }
    return {first, last};
  }
};


// Method 2: Optimal
// Time: O(log n) | Space: O(1)
// Two binary searches. When mid equals target, first-occurrence keeps searching left (hi = mid - 1) and last-occurrence keeps searching right (lo = mid + 1). Each is O(log n).

class Solution {
  int find(vector<int>& nums, int target, bool first) {
    int lo = 0, hi = (int)nums.size() - 1, ans = -1;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (nums[mid] == target) {
        ans = mid;
        if (first) hi = mid - 1;
        else lo = mid + 1;
      } else if (nums[mid] < target) lo = mid + 1;
      else hi = mid - 1;
    }
    return ans;
  }
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return {find(nums, target, true), find(nums, target, false)};
  }
};


// Method 3: More optimal
// Time: O(log n) | Space: O(1)
// Lower bound (first >= target) and upper bound (first > target). Last index is upper - 1. Overflow-safe mid. One helper, two flags, no extra ans in the loop.

class Solution {
  int bound(vector<int>& nums, int target, bool gt) {
    int lo = 0, hi = (int)nums.size();
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (nums[mid] < target || (gt && nums[mid] == target)) lo = mid + 1;
      else hi = mid;
    }
    return lo;
  }
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int L = bound(nums, target, false);
    if (L == (int)nums.size() || nums[L] != target) return {-1, -1};
    return {L, bound(nums, target, true) - 1};
  }
};
