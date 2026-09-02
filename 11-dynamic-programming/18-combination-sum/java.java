// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target / min)
// From start you may reuse candidates[i] (call go(i, remain - value)) or move on. Order is frozen by the index, so combinations are unique. No cache; the tree size tracks how you can pile the smallest coin. Depth is about target / min(candidates).

class Solution {
    public int combinationSum(int[] candidates, int target) {
        return go(candidates, 0, target);
    }
    private int go(int[] candidates, int start, int remain) {
        if (remain == 0) return 1;
        if (remain < 0) return 0;
        int ways = 0;
        for (int i = start; i < candidates.length; i++) {
            ways += go(candidates, i, remain - candidates[i]);
        }
        return ways;
    }
}


// Method 2: Optimal
// Time: O(n * target) | Space: O(n * target)
// Each pair (start index, remaining target) is solved once. Work per state is a loop over the leftover candidates. Map size is O(n * target). Same combination semantics as the backtrack.

class Solution {
    public int combinationSum(int[] candidates, int target) {
        java.util.HashMap<String, Integer> memo = new java.util.HashMap<String, Integer>();
        return go(candidates, 0, target, memo);
    }
    private int go(int[] candidates, int start, int remain, java.util.HashMap<String, Integer> memo) {
        String key = start + ":" + remain;
        if (memo.containsKey(key)) return memo.get(key);
        if (remain == 0) {
            memo.put(key, 1);
            return 1;
        }
        if (remain < 0) return 0;
        int ways = 0;
        for (int i = start; i < candidates.length; i++) {
            ways += go(candidates, i, remain - candidates[i], memo);
        }
        memo.put(key, ways);
        return ways;
    }
}


// Method 3: More optimal
// Time: O(n * target) | Space: O(target)
// Unbounded knapsack ways. Outer loop is the coin, inner loop walks sums upward so that coin may be reused. That order counts combinations, not permutations. One row of size target+1. If you swapped the loops, you would count ordered sequences instead.

class Solution {
    public int combinationSum(int[] candidates, int target) {
        int[] ways = new int[target + 1];
        ways[0] = 1;
        for (int i = 0; i < candidates.length; i++) {
            int coin = candidates[i];
            for (int s = coin; s <= target; s++) {
                ways[s] += ways[s - coin];
            }
        }
        return ways[target];
    }
}
