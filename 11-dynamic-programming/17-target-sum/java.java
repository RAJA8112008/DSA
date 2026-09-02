// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each number branches into plus or minus. 2^n signed assignments. Stack is n. Fine as a correctness check on tiny n.

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        return go(nums, target, 0, 0);
    }
    private int go(int[] nums, int target, int i, int sum) {
        if (i == nums.length) return sum == target ? 1 : 0;
        return go(nums, target, i + 1, sum + nums[i]) + go(nums, target, i + 1, sum - nums[i]);
    }
}


// Method 2: Optimal
// Time: O(n * sum) | Space: O(n * sum)
// Memo keys are (index, running sum). Running sum ranges about [-total, total], so unique states are O(n * total). Each state does two branches once.

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        java.util.HashMap<String, Integer> memo = new java.util.HashMap<String, Integer>();
        return go(nums, target, 0, 0, memo);
    }
    private int go(int[] nums, int target, int i, int sum, java.util.HashMap<String, Integer> memo) {
        String key = i + ":" + sum;
        if (memo.containsKey(key)) return memo.get(key);
        if (i == nums.length) {
            int ans = sum == target ? 1 : 0;
            memo.put(key, ans);
            return ans;
        }
        int ways = go(nums, target, i + 1, sum + nums[i], memo) + go(nums, target, i + 1, sum - nums[i], memo);
        memo.put(key, ways);
        return ways;
    }
}


// Method 3: More optimal
// Time: O(n * sum) | Space: O(sum)
// Map onto 0/1 subset-sum ways for need = (total + target) / 2. One ways[] row, inner loop backwards so each number is used once. Cleaner bottom-up, same polynomial, smaller constant memory.

class Solution {
    public int findTargetSumWays(int[] nums, int target) {
        int total = 0;
        for (int x : nums) total += x;
        if (Math.abs(target) > total || (total + target) % 2 != 0) return 0;
        int need = (total + target) / 2;
        int[] ways = new int[need + 1];
        ways[0] = 1;
        for (int i = 0; i < nums.length; i++) {
            int num = nums[i];
            for (int s = need; s >= num; s--) {
                ways[s] += ways[s - num];
            }
        }
        return ways[need];
    }
}
