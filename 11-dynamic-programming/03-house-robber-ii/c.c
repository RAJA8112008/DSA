// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each range is still a take/skip tree with no memo. Two ranges do not change the exponential shape. Stack depth is O(n).

int robGoRange(int *nums, int i, int end) {
    if (i > end) return 0;
    int take = nums[i] + robGoRange(nums, i + 2, end);
    int skip = robGoRange(nums, i + 1, end);
    return take > skip ? take : skip;
}
int rob(int *nums, int n) {
    int a, b;
    if (n == 1) return nums[0];
    a = robGoRange(nums, 0, n - 2);
    b = robGoRange(nums, 1, n - 1);
    return a > b ? a : b;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each linear street is the house-robber table. Two passes, each O(n) states. You still store a best[] array per pass. Handles n = 1 before splitting.

int robLine(int *nums, int start, int end) {
    int len = end - start + 1;
    int *best = (int *)calloc(len, sizeof(int));
    int i, ans;
    for (i = start; i <= end; i++) {
        int j = i - start;
        int take = nums[i] + (j >= 2 ? best[j - 2] : 0);
        int skip = j >= 1 ? best[j - 1] : 0;
        best[j] = take > skip ? take : skip;
    }
    ans = best[len - 1];
    free(best);
    return ans;
}
int rob(int *nums, int n) {
    int a, b;
    if (n == 1) return nums[0];
    a = robLine(nums, 0, n - 2);
    b = robLine(nums, 1, n - 1);
    return a > b ? a : b;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The same two ranges, each robbed with two rolling numbers. Extra memory no longer depends on n. Time is still two linear scans.

int robLine(int *nums, int start, int end) {
    int skip = 0, take = 0, i;
    for (i = start; i <= end; i++) {
        int nextTake = skip + nums[i];
        skip = skip > take ? skip : take;
        take = nextTake;
    }
    return skip > take ? skip : take;
}
int rob(int *nums, int n) {
    int a, b;
    if (n == 1) return nums[0];
    a = robLine(nums, 0, n - 2);
    b = robLine(nums, 1, n - 1);
    return a > b ? a : b;
}
