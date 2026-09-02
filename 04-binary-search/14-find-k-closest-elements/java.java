// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Pair each value with its distance, sort by distance then by value, take k items, sort those k again so the answer is ascending. Heavy, but matches the tie rule clearly.

import java.util.*;
class Solution {
  public List<Integer> findClosestElements(int[] arr, int k, int x) {
    Integer[] idx = new Integer[arr.length];
    for (int i = 0; i < arr.length; i++) idx[i] = i;
    Arrays.sort(idx, (i, j) -> {
      int di = Math.abs(arr[i] - x), dj = Math.abs(arr[j] - x);
      if (di != dj) return di - dj;
      return arr[i] - arr[j];
    });
    List<Integer> pick = new ArrayList<Integer>();
    for (int t = 0; t < k; t++) pick.add(arr[idx[t]]);
    Collections.sort(pick);
    return pick;
  }
}


// Method 2: Optimal
// Time: O(n - k) | Space: O(k)
// The answer is a contiguous window of length k (the array is sorted). Shrink from both ends until the window is size k. Drop the farther end; on a tie drop the right (larger) value.

import java.util.*;
class Solution {
  public List<Integer> findClosestElements(int[] arr, int k, int x) {
    int lo = 0, hi = arr.length - 1;
    while (hi - lo + 1 > k) {
      if (Math.abs(arr[lo] - x) > Math.abs(arr[hi] - x)) lo++;
      else hi--;
    }
    List<Integer> ans = new ArrayList<Integer>();
    for (int i = lo; i <= hi; i++) ans.add(arr[i]);
    return ans;
  }
}


// Method 3: More optimal
// Time: O(log(n - k) + k) | Space: O(k)
// Binary search the left index of the k-window in [0, n-k]. If x is closer to arr[mid+k] than to arr[mid], the window should start further right. Overflow-safe mid. Copy k values at the end.

import java.util.*;
class Solution {
  public List<Integer> findClosestElements(int[] arr, int k, int x) {
    int lo = 0, hi = arr.length - k;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
      else hi = mid;
    }
    List<Integer> ans = new ArrayList<Integer>();
    for (int i = lo; i < lo + k; i++) ans.add(arr[i]);
    return ans;
  }
}
