// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each number is included or skipped. No cache. 2^n subsets. The odd-total check is the only prune. Stack is O(n).

int partGo(int *nums, int n, int i, int remain) {
    if (remain == 0) return 1;
    if (i == n || remain < 0) return 0;
    return partGo(nums, n, i + 1, remain - nums[i]) || partGo(nums, n, i + 1, remain);
}
int canPartition(int *nums, int n) {
    int total = 0, i;
    for (i = 0; i < n; i++) total += nums[i];
    if (total % 2 != 0) return 0;
    return partGo(nums, n, 0, total / 2);
}


// Method 2: Optimal
// Time: O(n * sum) | Space: O(n * sum)
// can[i][s] is true if some subset of the first i numbers adds to s. Classic 0/1 knapsack boolean table. n * (sum/2) cells, each O(1).

int canPartition(int *nums, int n) {
    int total = 0, i, s, need, ans;
    int **can;
    for (i = 0; i < n; i++) total += nums[i];
    if (total % 2 != 0) return 0;
    need = total / 2;
    can = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) can[i] = (int *)calloc(need + 1, sizeof(int));
    for (i = 0; i <= n; i++) can[i][0] = 1;
    for (i = 1; i <= n; i++) {
        for (s = 1; s <= need; s++) {
            can[i][s] = can[i - 1][s];
            if (nums[i - 1] <= s && can[i - 1][s - nums[i - 1]]) can[i][s] = 1;
        }
    }
    ans = can[n][need];
    for (i = 0; i <= n; i++) free(can[i]);
    free(can);
    return ans;
}


// Method 3: More optimal
// Time: O(n * sum) | Space: O(sum)
// One boolean row. Walk s from need down to num so each number is used at most once. Same 0/1 rule as knapsack space cut. Extra memory is need+1 flags.

int canPartition(int *nums, int n) {
    int total = 0, i, s, need, ans;
    int *can;
    for (i = 0; i < n; i++) total += nums[i];
    if (total % 2 != 0) return 0;
    need = total / 2;
    can = (int *)calloc(need + 1, sizeof(int));
    can[0] = 1;
    for (i = 0; i < n; i++) {
        int num = nums[i];
        for (s = need; s >= num; s--) {
            if (can[s - num]) can[s] = 1;
        }
    }
    ans = can[need];
    free(can);
    return ans;
}
