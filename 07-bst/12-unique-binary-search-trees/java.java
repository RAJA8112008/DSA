// Method 1: Brute
// Time: O(4^n / n^{3/2}) | Space: O(n)
// Naive recursion: try each root and multiply left-count * right-count. Exponential overlapping subproblems.

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val; this.left = left; this.right = right;
    }
}

class Solution {
    public int numTrees(int n) {
        return count(n);
    }
    int count(int len) {
        if (len <= 1) return 1;
        int total = 0;
        for (int left = 0; left < len; left++) total += count(left) * count(len - 1 - left);
        return total;
    }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n)
// dp[k] = number of BSTs on k keys. dp[0]=1. Each k sums dp[left]*dp[k-1-left]. Standard Catalan DP.

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val; this.left = left; this.right = right;
    }
}

class Solution {
    public int numTrees(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1;
        for (int k = 1; k <= n; k++) {
            for (int left = 0; left < k; left++) dp[k] += dp[left] * dp[k - 1 - left];
        }
        return dp[n];
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// C(n) = C(n-1) * 2(2n-1)/(n+1). Multiply carefully with integer arithmetic. One pass, constant extra memory.

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val; this.left = left; this.right = right;
    }
}

class Solution {
    public int numTrees(int n) {
        long c = 1;
        for (int i = 2; i <= n; i++) c = c * 2 * (2L * i - 1) / (i + 1);
        return (int) c;
    }
}
