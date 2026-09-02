// Method 1: Brute
// Time: O(n^{target/min}) | Space: O(target / min)
// From start you may reuse candidates[i] (call go(i, remain - value)) or move on. Order is frozen by the index, so combinations are unique. No cache; the tree size tracks how you can pile the smallest coin. Depth is about target / min(candidates).

int combGo(int *candidates, int n, int start, int remain) {
    int ways = 0, i;
    if (remain == 0) return 1;
    if (remain < 0) return 0;
    for (i = start; i < n; i++) {
        ways += combGo(candidates, n, i, remain - candidates[i]);
    }
    return ways;
}
int combinationSum(int *candidates, int n, int target) {
    return combGo(candidates, n, 0, target);
}


// Method 2: Optimal
// Time: O(n * target) | Space: O(n * target)
// Each pair (start index, remaining target) is solved once. Work per state is a loop over the leftover candidates. Map size is O(n * target). Same combination semantics as the backtrack.

int combGo(int *candidates, int n, int start, int remain, int **memo, int **seen) {
    int ways = 0, i;
    if (remain == 0) return 1;
    if (remain < 0) return 0;
    if (seen[start][remain]) return memo[start][remain];
    for (i = start; i < n; i++) {
        ways += combGo(candidates, n, i, remain - candidates[i], memo, seen);
    }
    seen[start][remain] = 1;
    memo[start][remain] = ways;
    return ways;
}
int combinationSum(int *candidates, int n, int target) {
    int **memo, **seen, i, ans;
    if (n == 0) return target == 0 ? 1 : 0;
    memo = (int **)malloc(n * sizeof(int *));
    seen = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        memo[i] = (int *)calloc(target + 1, sizeof(int));
        seen[i] = (int *)calloc(target + 1, sizeof(int));
    }
    ans = combGo(candidates, n, 0, target, memo, seen);
    for (i = 0; i < n; i++) {
        free(memo[i]);
        free(seen[i]);
    }
    free(memo);
    free(seen);
    return ans;
}


// Method 3: More optimal
// Time: O(n * target) | Space: O(target)
// Unbounded knapsack ways. Outer loop is the coin, inner loop walks sums upward so that coin may be reused. That order counts combinations, not permutations. One row of size target+1. If you swapped the loops, you would count ordered sequences instead.

int combinationSum(int *candidates, int n, int target) {
    int *ways = (int *)calloc(target + 1, sizeof(int));
    int i, s, ans;
    ways[0] = 1;
    for (i = 0; i < n; i++) {
        int coin = candidates[i];
        for (s = coin; s <= target; s++) ways[s] += ways[s - coin];
    }
    ans = ways[target];
    free(ways);
    return ans;
}
