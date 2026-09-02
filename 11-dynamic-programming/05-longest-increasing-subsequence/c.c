// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// At each index you take (if it is larger than prev) or skip. No cache, so every subset of positions is explored. Depth is n.

int lisGo(int *nums, int n, int i, int prev) {
    int skip, take = 0;
    if (i == n) return 0;
    skip = lisGo(nums, n, i + 1, prev);
    if (prev == -1 || nums[i] > nums[prev]) {
        take = 1 + lisGo(nums, n, i + 1, i);
    }
    return skip > take ? skip : take;
}
int lengthOfLIS(int *nums, int n) {
    return lisGo(nums, n, 0, -1);
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// len[i] is the longest increasing subsequence that ends at i. Each pair (j, i) with j < i is checked once. n^2 states of work, one array of n cells. Standard interview DP.

int lengthOfLIS(int *nums, int n) {
    int *len, i, j, best, ans;
    if (n == 0) return 0;
    len = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) len[i] = 1;
    best = 1;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (nums[j] < nums[i] && len[j] + 1 > len[i]) len[i] = len[j] + 1;
        }
        if (len[i] > best) best = len[i];
    }
    ans = best;
    free(len);
    return ans;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(n)
// tails[k] is the smallest tail of all increasing subsequences of length k+1. For each number, binary search the first tail that is >= num and replace it (or append). Length of tails is the LIS length. Tails is not the LIS itself.

int lengthOfLIS(int *nums, int n) {
    int *tails = (int *)malloc(n * sizeof(int));
    int size = 0, i;
    for (i = 0; i < n; i++) {
        int num = nums[i];
        int left = 0, right = size;
        while (left < right) {
            int mid = (left + right) / 2;
            if (tails[mid] < num) left = mid + 1;
            else right = mid;
        }
        if (left == size) tails[size++] = num;
        else tails[left] = num;
    }
    free(tails);
    return size;
}
