// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every house branches into take or skip with no cache, so the tree is exponential. The stack is one frame per house along a path.

int robGo(int *nums, int n, int i) {
    if (i >= n) return 0;
    int take = nums[i] + robGo(nums, n, i + 2);
    int skip = robGo(nums, n, i + 1);
    return take > skip ? take : skip;
}
int rob(int *nums, int n) {
    return robGo(nums, n, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// best[i] is the best total using the first i houses. Each i is filled from i-1 and i-2 in constant time. n states, linear time and linear extra memory.

int rob(int *nums, int n) {
    int *best = (int *)calloc(n + 1, sizeof(int));
    int i, ans;
    for (i = 1; i <= n; i++) {
        int take = nums[i - 1] + (i >= 2 ? best[i - 2] : 0);
        int skip = best[i - 1];
        best[i] = take > skip ? take : skip;
    }
    ans = best[n];
    free(best);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only skip (best without the previous house as a take-chain) and take (best that used the previous house) are live. One pass updates both. Same linear scan, constant extra memory.

int rob(int *nums, int n) {
    int skip = 0, take = 0, i;
    for (i = 0; i < n; i++) {
        int nextTake = skip + nums[i];
        skip = skip > take ? skip : take;
        take = nextTake;
    }
    return skip > take ? skip : take;
}
