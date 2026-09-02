// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Each range is still a take/skip tree with no memo. Two ranges do not change the exponential shape. Stack depth is O(n).

int robGoRange(vector<int>& nums, int i, int end) {
    if (i > end) return 0;
    int take = nums[i] + robGoRange(nums, i + 2, end);
    int skip = robGoRange(nums, i + 1, end);
    return max(take, skip);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robGoRange(nums, 0, n - 2), robGoRange(nums, 1, n - 1));
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Each linear street is the house-robber table. Two passes, each O(n) states. You still store a best[] array per pass. Handles n = 1 before splitting.

int robLine(vector<int>& nums, int start, int end) {
    int len = end - start + 1;
    vector<int> best(len, 0);
    for (int i = start; i <= end; i++) {
        int j = i - start;
        int take = nums[i] + (j >= 2 ? best[j - 2] : 0);
        int skip = j >= 1 ? best[j - 1] : 0;
        best[j] = max(take, skip);
    }
    return best[len - 1];
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// The same two ranges, each robbed with two rolling numbers. Extra memory no longer depends on n. Time is still two linear scans.

int robLine(vector<int>& nums, int start, int end) {
    int skip = 0, take = 0;
    for (int i = start; i <= end; i++) {
        int nextTake = skip + nums[i];
        skip = max(skip, take);
        take = nextTake;
    }
    return max(skip, take);
}
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    return max(robLine(nums, 0, n - 2), robLine(nums, 1, n - 1));
}
