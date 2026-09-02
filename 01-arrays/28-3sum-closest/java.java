// Method 1: Brute
// Time: O(n³) | Space: O(1)
// Every triple, track the sum whose absolute gap to target is smallest.

class Solution {
  public int threeSumClosest(int[] nums, int target) {
    int n = nums.length, best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++) {
          int s = nums[i] + nums[j] + nums[k];
          if (Math.abs(s - target) < Math.abs(best - target)) best = s;
        }
    return best;
  }
}


// Method 2: Optimal
// Time: O(n² log n) | Space: O(n)
// Sort. Fix two indexes, binary search the value closest to the leftover. Extra log n on each pair.

import java.util.*;
class Solution {
  public int threeSumClosest(int[] nums, int target) {
    Arrays.sort(nums);
    int n = nums.length, best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int need = target - nums[i] - nums[j];
        int lo = j + 1, hi = n - 1, pick = j + 1;
        if (lo > hi) continue;
        while (lo <= hi) {
          int mid = (lo + hi) / 2;
          if (nums[mid] == need) return target;
          pick = mid;
          if (nums[mid] < need) lo = mid + 1;
          else hi = mid - 1;
        }
        int[] cand = { pick, pick - 1, pick + 1 };
        for (int k : cand) {
          if (k <= j || k >= n) continue;
          int s = nums[i] + nums[j] + nums[k];
          if (Math.abs(s - target) < Math.abs(best - target)) best = s;
        }
      }
    }
    return best;
  }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1) extra
// Sort. Fix i. Two pointers on the rest. Move the side that improves the sum. Track the closest. Stop early on an exact hit.

import java.util.*;
class Solution {
  public int threeSumClosest(int[] nums, int target) {
    Arrays.sort(nums);
    int n = nums.length, best = nums[0] + nums[1] + nums[2];
    for (int i = 0; i < n; i++) {
      int L = i + 1, R = n - 1;
      while (L < R) {
        int s = nums[i] + nums[L] + nums[R];
        if (Math.abs(s - target) < Math.abs(best - target)) best = s;
        if (s == target) return s;
        if (s < target) L++;
        else R--;
      }
    }
    return best;
  }
}
