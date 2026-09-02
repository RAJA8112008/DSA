// Method 1: Brute
// Time: O(n^n) | Space: O(n)
// From i you try every legal step. No cache, so overlapping positions explode. Depth is at most n. Fine only as a correctness sketch.

int jumpGo(int *nums, int n, int i) {
    const int INF = 1000000000;
    int step, best;
    if (i >= n - 1) return 0;
    best = INF;
    for (step = 1; step <= nums[i]; step++) {
        int cand = 1 + jumpGo(nums, n, i + step);
        if (cand < best) best = cand;
    }
    return best;
}
int jump(int *nums, int n) {
    return jumpGo(nums, n, 0);
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// best[j] is min jumps to index j. From each i you relax the range i+1 .. i+nums[i]. Up to n updates per i. This is the basic DP table for min jumps.

int jump(int *nums, int n) {
    const int INF = 1000000000;
    int *best = (int *)malloc(n * sizeof(int));
    int i, step, ans;
    for (i = 0; i < n; i++) best[i] = INF;
    best[0] = 0;
    for (i = 0; i < n; i++) {
        for (step = 1; step <= nums[i] && i + step < n; step++) {
            if (best[i] + 1 < best[i + step]) best[i + step] = best[i] + 1;
        }
    }
    ans = best[n - 1];
    free(best);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Greedy BFS on the line. end is the close of the current jump’s window. farthest is the furthest index a jump from this window can reach. When i hits end, you spend one jump and open the next window. One pass, no array.

int jump(int *nums, int n) {
    int jumps = 0, end = 0, farthest = 0, i;
    for (i = 0; i < n - 1; i++) {
        if (i + nums[i] > farthest) farthest = i + nums[i];
        if (i == end) {
            jumps += 1;
            end = farthest;
        }
    }
    return jumps;
}
