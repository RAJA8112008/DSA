// Method 1: Brute
// Time: O(n^n) | Space: O(n)
// From i you try every legal step. No cache, so overlapping positions explode. Depth is at most n. Fine only as a correctness sketch.

class Solution {
    public int jump(int[] nums) {
        return go(nums, 0);
    }
    private int go(int[] nums, int i) {
        if (i >= nums.length - 1) return 0;
        int best = 1000000000;
        for (int step = 1; step <= nums[i]; step++) {
            best = Math.min(best, 1 + go(nums, i + step));
        }
        return best;
    }
}


// Method 2: Optimal
// Time: O(n^2) | Space: O(n)
// best[j] is min jumps to index j. From each i you relax the range i+1 .. i+nums[i]. Up to n updates per i. This is the basic DP table for min jumps.

class Solution {
    public int jump(int[] nums) {
        int n = nums.length;
        int INF = 1000000000;
        int[] best = new int[n];
        java.util.Arrays.fill(best, INF);
        best[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int step = 1; step <= nums[i] && i + step < n; step++) {
                best[i + step] = Math.min(best[i + step], best[i] + 1);
            }
        }
        return best[n - 1];
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Greedy BFS on the line. end is the close of the current jump’s window. farthest is the furthest index a jump from this window can reach. When i hits end, you spend one jump and open the next window. One pass, no array.

class Solution {
    public int jump(int[] nums) {
        int jumps = 0, end = 0, farthest = 0;
        for (int i = 0; i < nums.length - 1; i++) {
            farthest = Math.max(farthest, i + nums[i]);
            if (i == end) {
                jumps += 1;
                end = farthest;
            }
        }
        return jumps;
    }
}
