// Method 1: Brute
// Time: O(n · m) | Space: O(1)
// For each nums1 value, scan nums2 to find it, then scan the suffix for a greater number. Fine when both arrays are tiny.

import java.util.*;
class Solution {
  public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    int[] ans = new int[nums1.length];
    for (int i = 0; i < nums1.length; i++) {
      boolean found = false;
      int next = -1;
      for (int j = 0; j < nums2.length; j++) {
        if (!found) {
          if (nums2[j] == nums1[i]) found = true;
          continue;
        }
        if (nums2[j] > nums1[i]) { next = nums2[j]; break; }
      }
      ans[i] = next;
    }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(n · m) | Space: O(m)
// Hash each nums2 value to its index so the find step is O(1). The right scan is still O(m) per query. Clearer, same worst case.

import java.util.*;
class Solution {
  public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    Map<Integer, Integer> idx = new HashMap<Integer, Integer>();
    for (int i = 0; i < nums2.length; i++) idx.put(nums2[i], i);
    int[] ans = new int[nums1.length];
    for (int i = 0; i < nums1.length; i++) {
      int next = -1;
      for (int j = idx.get(nums1[i]) + 1; j < nums2.length; j++) {
        if (nums2[j] > nums1[i]) { next = nums2[j]; break; }
      }
      ans[i] = next;
    }
    return ans;
  }
}


// Method 3: More optimal
// Time: O(n + m) | Space: O(m)
// Monotonic stack on nums2 builds next[value] = first greater to the right. Then each nums1 lookup is O(1). Linear in the two array lengths.

import java.util.*;
class Solution {
  public int[] nextGreaterElement(int[] nums1, int[] nums2) {
    Map<Integer, Integer> next = new HashMap<Integer, Integer>();
    ArrayDeque<Integer> st = new ArrayDeque<Integer>();
    for (int x : nums2) {
      while (!st.isEmpty() && st.peek() < x) next.put(st.pop(), x);
      st.push(x);
    }
    int[] ans = new int[nums1.length];
    for (int i = 0; i < nums1.length; i++) ans[i] = next.getOrDefault(nums1[i], -1);
    return ans;
  }
}
