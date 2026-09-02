// Method 1: Brute
// Time: O(n^n) | Space: O(n)
// From i you try every legal step. No cache, so overlapping positions explode. Depth is at most n. Fine only as a correctness sketch.

int jumpGo(vector<int>& nums, int i) {
    const int INF = 1000000000;
    if (i >= (int)nums.size() - 1) return 0;
    int best = INF;
    for (int step = 1; step <= nums[i]; step++) {
        best = min(best, 1 + jumpGo(nums, i + step));
    }
    return best;
}
int jump(vector<int>& nums) {
    return jumpGo(nums, 0);
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// best[j] is min jumps to index j. From each i you relax the range i+1 .. i+nums[i]. Up to n updates per i. This is the basic DP table for min jumps.

int jump(vector<int>& nums) {
    int n = nums.size();
    const int INF = 1000000000;
    vector<int> best(n, INF);
    best[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int step = 1; step <= nums[i] && i + step < n; step++) {
            best[i + step] = min(best[i + step], best[i] + 1);
        }
    }
    return best[n - 1];
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Greedy BFS on the line. end is the close of the current jump’s window. farthest is the furthest index a jump from this window can reach. When i hits end, you spend one jump and open the next window. One pass, no array.

int jump(vector<int>& nums) {
    int jumps = 0, end = 0, farthest = 0;
    for (int i = 0; i < (int)nums.size() - 1; i++) {
        farthest = max(farthest, i + nums[i]);
        if (i == end) {
            jumps += 1;
            end = farthest;
        }
    }
    return jumps;
}
