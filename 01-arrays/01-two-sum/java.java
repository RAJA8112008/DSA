// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Every pair is checked. For n numbers that is about n*(n-1)/2 additions.
// How it works: the outer loop picks the first index. The inner loop picks a later index. The first pair whose sum equals target is returned.

class Solution {
  public int[] twoSum(int[] nums, int target) {
    int n = nums.length;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (nums[i] + nums[j] == target) return new int[] { i, j };
      }
    }
    return new int[] {};
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sorting is the extra cost. After that, two pointers only walk the copied list once.
// How it works: store {value, index} so sorting does not lose positions. Move left up when the sum is too small, right down when it is too big.

class Solution {
  public int[] twoSum(int[] nums, int target) {
    List<Integer> pairs = new ArrayList<>();
    for (int i = 0; i < nums.length; i++) {
      pairs.add([nums[i], i ]);
    }
    pairs.sort((a, b) -> a[0] - b[0]);

    int left = 0;
    int right = pairs.size() - 1;
    while (left < right) {
      int sum = pairs[left].value + pairs[right].value;
      if (sum == target) return new int[] { pairs[left }.index, pairs[right].index];
      if (sum < target) left++;
      else right--;
    }
    return new int[] {};
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// One pass. Each lookup in the map is average O(1), so the whole walk is O(n).
// How it works: for x, look up target - x. If it was stored, return those indexes. If not, store x and its index, then continue.

class Solution {
  public int[] twoSum(int[] nums, int target) {
    Map<Integer, Integer> seen = new HashMap<>();
    for (int i = 0; i < nums.length; i++) {
      int need = target - nums[i];
      if (seen.containsKey(need)) return new int[] { seen.get(need), i };
      seen.put(nums[i], i);
    }
    return new int[] {};
  }
}
