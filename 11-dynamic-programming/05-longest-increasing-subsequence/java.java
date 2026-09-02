// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// At each index you take (if it is larger than prev) or skip. No cache, so every subset of positions is explored. Depth is n.

class Solution {
    public int lengthOfLIS(int[] nums) {
        return go(nums, 0, -1);
    }
    private int go(int[] nums, int i, int prev) {
        if (i == nums.length) return 0;
        int skip = go(nums, i + 1, prev);
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + go(nums, i + 1, i);
        }
        return Math.max(skip, take);
    }
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// len[i] is the longest increasing subsequence that ends at i. Each pair (j, i) with j < i is checked once. n^2 states of work, one array of n cells. Standard interview DP.

class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] len = new int[n];
        java.util.Arrays.fill(len, 1);
        int best = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    len[i] = Math.max(len[i], len[j] + 1);
                }
            }
            best = Math.max(best, len[i]);
        }
        return best;
    }
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// tails[k] is the smallest tail of all increasing subsequences of length k+1. For each number, binary search the first tail that is >= num and replace it (or append). Length of tails is the LIS length. Tails is not the LIS itself.

class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] tails = new int[nums.length];
        int size = 0;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            int left = 0, right = size;
            while (left < right) {
                int mid = (left + right) / 2;
                if (tails[mid] < num) left = mid + 1;
                else right = mid;
            }
            if (left == size) tails[size++] = num;
            else tails[left] = num;
        }
        return size;
    }
}
