// Method 1: Brute
// Time: O(n²) | Space: O(1)
// Outer index i, inner j > i. First pair that sums to target is the answer. Works, ignores the sorted hint.

class Solution {
  public int[] twoSum(int[] numbers, int target) {
    int n = numbers.length;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        if (numbers[i] + numbers[j] == target) return new int[] { i + 1, j + 1 };
    return new int[] {};
  }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(1)
// For each left value, binary search target - numbers[i] on the right side. Sorted order makes the search legal. Extra log n versus two pointers.

class Solution {
  public int[] twoSum(int[] numbers, int target) {
    int n = numbers.length;
    for (int i = 0; i < n; i++) {
      int need = target - numbers[i];
      int lo = i + 1, hi = n - 1;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (numbers[mid] == need) return new int[] { i + 1, mid + 1 };
        if (numbers[mid] < need) lo = mid + 1;
        else hi = mid - 1;
      }
    }
    return new int[] {};
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Left at start, right at end. Sum too small: left++. Sum too big: right--. Sorted order guarantees you never miss the pair. Interview finish line.

class Solution {
  public int[] twoSum(int[] numbers, int target) {
    int left = 0, right = numbers.length - 1;
    while (left < right) {
      int sum = numbers[left] + numbers[right];
      if (sum == target) return new int[] { left + 1, right + 1 };
      if (sum < target) left++;
      else right--;
    }
    return new int[] {};
  }
}
