// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every start and end pair is summed. Fine to explain, too slow for large n.
// How it works: i is start, running sum grows with j. Each time the sum equals k, add 1 to the count.

class Solution {
  public int subarraySum(int[] nums, int k) {
    int count = 0;
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += nums[j];
        if (sum == k) count++;
      }
    }
    return count;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build all prefixes, then query a map. Two linear passes, O(n) extra.
// How it works: prefix[i] is sum of the first i numbers. For each end i, the number of starts with prefix[i] - prefix[start] = k is how often prefix[i] - k already appeared.

class Solution {
  public int subarraySum(int[] nums, int k) {
    int n = nums.length;
    int[] prefix = new int[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
    Map<Integer, Integer> freq = new HashMap<>();
    int count = 0;
    for (int i = 0; i <= n; i++) {
      int need = prefix[i] - k;
      if (freq.containsKey(need)) count += freq.get(need);
      freq.put(prefix[i], (freq.getOrDefault(prefix[i], 0)) + 1);
    }
    return count;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same map idea without a prefix array. One running sum.
// How it works: start the map with 0 seen once (empty prefix). After adding nums[i], add the frequency of sum - k, then record this sum.

class Solution {
  public int subarraySum(int[] nums, int k) {
    Map<Integer, Integer> freq = new HashMap<>();
    freq.put(0, 1);
    int sum = 0;
    int count = 0;
    for (int i = 0; i < nums.length; i++) {
      sum += nums[i];
      int need = sum - k;
      if (freq.containsKey(need)) count += freq.get(need);
      freq.put(sum, (freq.getOrDefault(sum, 0)) + 1);
    }
    return count;
  }
}
