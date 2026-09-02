// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each value, count how many times it appears. Push it once if the count is 2. Slow, no extra set.

import java.util.*;
class Solution {
  public List<Integer> findDuplicates(int[] nums) {
    List<Integer> out = new ArrayList<Integer>();
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      int c = 0;
      for (int j = 0; j < n; j++) if (nums[j] == nums[i]) c++;
      if (c == 2 && !out.contains(nums[i])) out.add(nums[i]);
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1) extra
// Sort, then walk adjacent pairs. Equal neighbors are a duplicate. Simple, mutates order.

import java.util.*;
class Solution {
  public List<Integer> findDuplicates(int[] nums) {
    Arrays.sort(nums);
    List<Integer> out = new ArrayList<Integer>();
    for (int i = 1; i < nums.length; i++) if (nums[i] == nums[i - 1]) out.add(nums[i]);
    return out;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// Value x belongs at index x-1. Negate that slot when you first see x. If it is already negative, x is the duplicate. Restore signs later if you must.

import java.util.*;
class Solution {
  public List<Integer> findDuplicates(int[] nums) {
    List<Integer> out = new ArrayList<Integer>();
    for (int i = 0; i < nums.length; i++) {
      int x = Math.abs(nums[i]);
      int slot = x - 1;
      if (nums[slot] < 0) out.add(x);
      else nums[slot] = -nums[slot];
    }
    return out;
  }
}
