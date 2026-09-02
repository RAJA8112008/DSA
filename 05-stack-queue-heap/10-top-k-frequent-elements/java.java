// Method 1: Brute
// Time: O(n + u · k) | Space: O(u)
// Count in a map. Then k times scan all unique keys for the remaining max count and remove it. u is the number of unique values.

import java.util.*;
class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    Map<Integer, Integer> count = new HashMap<Integer, Integer>();
    for (int x : nums) count.put(x, count.getOrDefault(x, 0) + 1);
    int[] ans = new int[k];
    for (int t = 0; t < k; t++) {
      int bestKey = 0, best = -1;
      for (int key : count.keySet()) {
        if (count.get(key) > best) { best = count.get(key); bestKey = key; }
      }
      ans[t] = bestKey;
      count.remove(bestKey);
    }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(n + u log u) | Space: O(u)
// Count, then sort unique keys by frequency descending, take k. Clear and fast enough for interview n.

import java.util.*;
class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    Map<Integer, Integer> count = new HashMap<Integer, Integer>();
    for (int x : nums) count.put(x, count.getOrDefault(x, 0) + 1);
    ArrayList<Integer> keys = new ArrayList<Integer>(count.keySet());
    keys.sort((a, b) -> count.get(b) - count.get(a));
    int[] ans = new int[k];
    for (int i = 0; i < k; i++) ans[i] = keys.get(i);
    return ans;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Bucket sort: buckets[i] holds numbers that appear i times. Walk i from n down and collect k numbers. Linear because counts are at most n. A size-k min-heap is O(n log k) if they want a heap instead.

import java.util.*;
class Solution {
  public int[] topKFrequent(int[] nums, int k) {
    Map<Integer, Integer> count = new HashMap<Integer, Integer>();
    for (int x : nums) count.put(x, count.getOrDefault(x, 0) + 1);
    ArrayList<Integer>[] buckets = new ArrayList[nums.length + 1];
    for (int i = 0; i < buckets.length; i++) buckets[i] = new ArrayList<Integer>();
    for (int num : count.keySet()) buckets[count.get(num)].add(num);
    int[] ans = new int[k];
    int p = 0;
    for (int f = buckets.length - 1; f >= 0 && p < k; f--) {
      for (int i = 0; i < buckets[f].size() && p < k; i++) ans[p++] = buckets[f].get(i);
    }
    return ans;
  }
}
