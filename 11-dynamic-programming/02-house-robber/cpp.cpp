// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every house branches into take or skip with no cache, so the tree is exponential. The stack is one frame per house along a path.

int robGo(vector<int>& nums, int i) {
    if (i >= (int)nums.size()) return 0;
    int take = nums[i] + robGo(nums, i + 2);
    int skip = robGo(nums, i + 1);
    return max(take, skip);
}
int rob(vector<int>& nums) {
    return robGo(nums, 0);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// best[i] is the best total using the first i houses. Each i is filled from i-1 and i-2 in constant time. n states, linear time and linear extra memory.

int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> best(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int take = nums[i - 1] + (i >= 2 ? best[i - 2] : 0);
        int skip = best[i - 1];
        best[i] = max(take, skip);
    }
    return best[n];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Only skip (best without the previous house as a take-chain) and take (best that used the previous house) are live. One pass updates both. Same linear scan, constant extra memory.

int rob(vector<int>& nums) {
    int skip = 0, take = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        int nextTake = skip + nums[i];
        skip = max(skip, take);
        take = nextTake;
    }
    return max(skip, take);
}
