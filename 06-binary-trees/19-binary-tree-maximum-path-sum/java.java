// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node, maxDown on left and right is computed from scratch, then visit children. Nested tree walks.

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
    private int maxPathSum_maxDown(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return node.val + Math.max(0, maxPathSum_maxDown(node.left), maxPathSum_maxDown(node.right));
    }

    private int maxPathSum_visit(TreeNode node) {
        if (node == null) {
            return;
        }
        TreeNode left = Math.max(0, maxDown(node.left));
        TreeNode right = Math.max(0, maxDown(node.right));
        int through = node.val + left + right;
        if (through > best) {
            best = through;
        }
        maxPathSum_visit(node.left);
        maxPathSum_visit(node.right);
    }

    public int maxPathSum(TreeNode root) {
        int best = Integer.MIN_VALUE;
        maxPathSum_visit(root);
        return best;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// gain(node) = val + max(0, gain(left), gain(right)) for continuing up. Through-node sum updates a boxed best. One DFS.

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
    private int maxPathSum_gain(TreeNode node) {
        if (node == null) {
            return 0;
        }
        TreeNode left = Math.max(0, maxPathSum_gain(node.left));
        TreeNode right = Math.max(0, maxPathSum_gain(node.right));
        int through = node.val + left + right;
        if (through > best) {
            best = through;
        }
        return node.val + Math.max(left, right);
    }

    public int maxPathSum(TreeNode root) {
        int best = Integer.MIN_VALUE;
        maxPathSum_gain(root);
        return best;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Same linear DFS, but dfs returns {gain, best} so there is no outer mutable. Parent combines through, left.best, and right.best. Cleaner to reason about.

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
    private int maxPathSum_dfs(TreeNode node) {
        if (node == null) {
            return new int[]{0, Integer.MIN_VALUE};
        }
        TreeNode L = maxPathSum_dfs(node.left);
        TreeNode R = maxPathSum_dfs(node.right);
        TreeNode left = Math.max(0, L.gain);
        TreeNode right = Math.max(0, R.gain);
        int through = node.val + left + right;
        int gain = node.val + Math.max(left, right);
        int best = Math.max(through, L.best, R.best);
        return new int[]{gain, best};
    }

    public int maxPathSum(TreeNode root) {
        return maxPathSum_dfs(root).best;
    }
}
