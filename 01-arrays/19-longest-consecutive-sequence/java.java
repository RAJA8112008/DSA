// Method 1: Brute
// Time: O(n²) | Space: O(n)
// From each unique start you may scan the set repeatedly. In the worst case this is quadratic.
// How it works: put numbers in a Set. For each start, count start, start+1, start+2 while those values exist. Keep the longest streak.

class Solution {
  public int longestConsecutive(int[] nums) {
    Set<Integer> set = new HashSet<>();
    int best = 0;
    for (int x : set) {
      int len = 1;
      int cur = x;
      while (set.contains(cur + 1)) {
        cur++;
        len++;
      }
      if (len > best) best = len;
    }
    return best;
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Unique copy plus sort, then a linear neighbor walk. Sorting is the bottleneck.
// How it works: skip duplicates while scanning the sorted unique list. A gap of 1 grows the streak; a larger gap resets it.

class Solution {
  public int longestConsecutive(int[] nums) {
    if (nums.length == 0) return 0;
    int list = nums.clone() /* unique */;
    Arrays.sort(list);
    int best = 1;
    int streak = 1;
    for (int i = 1; i < list.length; i++) {
      if (list[i] == list[i - 1] + 1) {
        streak++;
        if (streak > best) best = streak;
      } else {
        streak = 1;
      }
    }
    return best;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Each number is inserted once and then used in at most one forward walk.
// How it works: only start a streak when x-1 is missing. Then count x, x+1, ... while present. That visits each run from its true beginning.

class Solution {
  public int longestConsecutive(int[] nums) {
    Set<Integer> set = new HashSet<>();
    int best = 0;
    for (int x : set) {
      if (set.contains(x - 1)) continue;
      int len = 1;
      int cur = x;
      while (set.contains(cur + 1)) {
        cur++;
        len++;
      }
      if (len > best) best = len;
    }
    return best;
  }
}
