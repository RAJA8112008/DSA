// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each number branches into plus or minus. 2^n signed assignments. Stack is n. Fine as a correctness check on tiny n.

int targetGo(int *nums, int n, int target, int i, int sum) {
    if (i == n) return sum == target ? 1 : 0;
    return targetGo(nums, n, target, i + 1, sum + nums[i]) +
           targetGo(nums, n, target, i + 1, sum - nums[i]);
}
int findTargetSumWays(int *nums, int n, int target) {
    return targetGo(nums, n, target, 0, 0);
}


// Method 2: Optimal
// Time: O(n * sum) | Space: O(n * sum)
// Memo keys are (index, running sum). Running sum ranges about [-total, total], so unique states are O(n * total). Each state does two branches once.

int targetGo(int *nums, int n, int target, int i, int sum, int **memo, int offset) {
    int idx = sum + offset;
    if (memo[i][idx] != -1) return memo[i][idx];
    if (i == n) {
        memo[i][idx] = sum == target ? 1 : 0;
        return memo[i][idx];
    }
    memo[i][idx] = targetGo(nums, n, target, i + 1, sum + nums[i], memo, offset) +
                   targetGo(nums, n, target, i + 1, sum - nums[i], memo, offset);
    return memo[i][idx];
}
int findTargetSumWays(int *nums, int n, int target) {
    int total = 0, i, ans, width;
    int **memo;
    for (i = 0; i < n; i++) total += nums[i];
    width = 2 * total + 1;
    memo = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 0; i <= n; i++) {
        int j;
        memo[i] = (int *)malloc(width * sizeof(int));
        for (j = 0; j < width; j++) memo[i][j] = -1;
    }
    ans = targetGo(nums, n, target, 0, 0, memo, total);
    for (i = 0; i <= n; i++) free(memo[i]);
    free(memo);
    return ans;
}


// Method 3: More optimal
// Time: O(n * sum) | Space: O(sum)
// Map onto 0/1 subset-sum ways for need = (total + target) / 2. One ways[] row, inner loop backwards so each number is used once. Cleaner bottom-up, same polynomial, smaller constant memory.

int findTargetSumWays(int *nums, int n, int target) {
    int total = 0, i, s, need, ans;
    int *ways;
    for (i = 0; i < n; i++) total += nums[i];
    if (target < 0 ? -target > total : target > total) return 0;
    if ((total + target) % 2 != 0) return 0;
    need = (total + target) / 2;
    ways = (int *)calloc(need + 1, sizeof(int));
    ways[0] = 1;
    for (i = 0; i < n; i++) {
        int num = nums[i];
        for (s = need; s >= num; s--) ways[s] += ways[s - num];
    }
    ans = ways[need];
    free(ways);
    return ans;
}
