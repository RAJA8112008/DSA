// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each range is still a take/skip tree with no memo. Two ranges do not change the exponential shape. Stack depth is O(n).

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        return Math.max(go(nums, 0, n - 2), go(nums, 1, n - 1));
    }
    private int go(int[] nums, int i, int end) {
        if (i > end) return 0;
        int take = nums[i] + go(nums, i + 2, end);
        int skip = go(nums, i + 1, end);
        return Math.max(take, skip);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each linear street is the house-robber table. Two passes, each O(n) states. You still store a best[] array per pass. Handles n = 1 before splitting.

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        return Math.max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }
    private int robLine(int[] nums, int start, int end) {
        int len = end - start + 1;
        int[] best = new int[len];
        for (int i = start; i <= end; i++) {
            int j = i - start;
            int take = nums[i] + (j >= 2 ? best[j - 2] : 0);
            int skip = j >= 1 ? best[j - 1] : 0;
            best[j] = Math.max(take, skip);
        }
        return best[len - 1];
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The same two ranges, each robbed with two rolling numbers. Extra memory no longer depends on n. Time is still two linear scans.

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        return Math.max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
    }
    private int robLine(int[] nums, int start, int end) {
        int skip = 0, take = 0;
        for (int i = start; i <= end; i++) {
            int nextTake = skip + nums[i];
            skip = Math.max(skip, take);
            take = nextTake;
        }
        return Math.max(skip, take);
    }
}
