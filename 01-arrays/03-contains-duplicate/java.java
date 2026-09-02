// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Each pair is compared. Fine for tiny lists, too slow for large n.
// How it works: if nums[i] equals nums[j] for j > i, a duplicate exists.

class Solution {
  public boolean containsDuplicate(int[] nums) {
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] == nums[j]) return true;
      }
    }
    return false;
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Copy then sort, then a linear neighbor check. Sorting dominates.
// How it works: equals become neighbors after sort. If two neighbors match, return true.

class Solution {
  public boolean containsDuplicate(int[] nums) {
    int[] copy = nums.clone();
    Arrays.sort(copy);
    for (int i = 1; i < copy.length; i++) {
      if (copy[i] == copy[i - 1]) return true;
    }
    return false;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass. Set.has is average O(1).
// How it works: if the set already has the number, it is a duplicate. Otherwise add it.

class Solution {
  public boolean containsDuplicate(int[] nums) {
    Set<Integer> seen = new HashSet<>();
    for (int i = 0; i < nums.length; i++) {
      if (seen.contains(nums[i])) return true;
      seen.add(nums[i]);
    }
    return false;
  }
}
