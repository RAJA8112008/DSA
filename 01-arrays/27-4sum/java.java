// Method 1: Brute
// Time: O(n^4) | Space: O(1) extra
// Four nested indexes. Sort each hit so a set of strings can drop duplicates. Correct and too slow.

import java.util.*;
class Solution {
  public List<List<Integer>> fourSum(int[] nums, int target) {
    int n = nums.length;
    Set<String> seen = new HashSet<String>();
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++)
          for (int p = k + 1; p < n; p++) {
            if ((long) nums[i] + nums[j] + nums[k] + nums[p] != target) continue;
            int[] q = { nums[i], nums[j], nums[k], nums[p] };
            Arrays.sort(q);
            String key = q[0] + "," + q[1] + "," + q[2] + "," + q[3];
            if (!seen.add(key)) continue;
            out.add(Arrays.asList(q[0], q[1], q[2], q[3]));
          }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n^3) | Space: O(n)
// Fix i, j, k. Look up target - (a+b+c) in a set of values after k. Still cubic, extra set, duplicates need care. A stepping stone to two pointers.

import java.util.*;
class Solution {
  public List<List<Integer>> fourSum(int[] nums, int target) {
    int n = nums.length;
    Set<String> seenQ = new HashSet<String>();
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        Set<Long> seen = new HashSet<Long>();
        for (int k = j + 1; k < n; k++) {
          long need = (long) target - nums[i] - nums[j] - nums[k];
          if (seen.contains(need)) {
            int[] q = { nums[i], nums[j], nums[k], (int) need };
            Arrays.sort(q);
            String key = q[0] + "," + q[1] + "," + q[2] + "," + q[3];
            if (seenQ.add(key)) out.add(Arrays.asList(q[0], q[1], q[2], q[3]));
          }
          seen.add((long) nums[k]);
        }
      }
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n^3) | Space: O(1) extra
// Sort. Fix i and j. Two pointers on the rest. Skip duplicate i, j, left, and right. Use 64-bit sums if the language overflows. This is the expected answer.

import java.util.*;
class Solution {
  public List<List<Integer>> fourSum(int[] nums, int target) {
    Arrays.sort(nums);
    int n = nums.length;
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    for (int i = 0; i < n; i++) {
      if (i > 0 && nums[i] == nums[i - 1]) continue;
      for (int j = i + 1; j < n; j++) {
        if (j > i + 1 && nums[j] == nums[j - 1]) continue;
        int L = j + 1, R = n - 1;
        while (L < R) {
          long sum = (long) nums[i] + nums[j] + nums[L] + nums[R];
          if (sum == target) {
            out.add(Arrays.asList(nums[i], nums[j], nums[L], nums[R]));
            L++; R--;
            while (L < R && nums[L] == nums[L - 1]) L++;
            while (L < R && nums[R] == nums[R + 1]) R--;
          } else if (sum < target) L++;
          else R--;
        }
      }
    }
    return out;
  }
}
