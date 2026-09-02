// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target / min)
// From start you may reuse candidates[i] (call go(i, remain - value)) or move on. Order is frozen by the index, so combinations are unique. No cache; the tree size tracks how you can pile the smallest coin. Depth is about target / min(candidates).

int combGo(vector<int>& candidates, int start, int remain) {
    if (remain == 0) return 1;
    if (remain < 0) return 0;
    int ways = 0;
    for (int i = start; i < (int)candidates.size(); i++) {
        ways += combGo(candidates, i, remain - candidates[i]);
    }
    return ways;
}
int combinationSum(vector<int>& candidates, int target) {
    return combGo(candidates, 0, target);
}


// Method 2: Optimal
// Time: O(n * target) | Space: O(n * target)
// Each pair (start index, remaining target) is solved once. Work per state is a loop over the leftover candidates. Map size is O(n * target). Same combination semantics as the backtrack.

int combGo(vector<int>& candidates, int start, int remain, unordered_map<string, int>& memo) {
    string key = to_string(start) + ":" + to_string(remain);
    if (memo.count(key)) return memo[key];
    if (remain == 0) {
        memo[key] = 1;
        return 1;
    }
    if (remain < 0) return 0;
    int ways = 0;
    for (int i = start; i < (int)candidates.size(); i++) {
        ways += combGo(candidates, i, remain - candidates[i], memo);
    }
    memo[key] = ways;
    return ways;
}
int combinationSum(vector<int>& candidates, int target) {
    unordered_map<string, int> memo;
    return combGo(candidates, 0, target, memo);
}


// Method 3: More optimal
// Time: O(n * target) | Space: O(target)
// Unbounded knapsack ways. Outer loop is the coin, inner loop walks sums upward so that coin may be reused. That order counts combinations, not permutations. One row of size target+1. If you swapped the loops, you would count ordered sequences instead.

int combinationSum(vector<int>& candidates, int target) {
    vector<int> ways(target + 1, 0);
    ways[0] = 1;
    for (int i = 0; i < (int)candidates.size(); i++) {
        int coin = candidates[i];
        for (int s = coin; s <= target; s++) ways[s] += ways[s - coin];
    }
    return ways[target];
}
