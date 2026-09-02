// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Dump all values, then compare every pair. Extra array and quadratic checks.

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
    public int getMinimumDifference(TreeNode root) {
        List<Integer> vals = new ArrayList<Integer>();
        go(root, vals);
        int best = Integer.MAX_VALUE;
        for (int i = 0; i < vals.size(); i++) {
            for (int j = i + 1; j < vals.size(); j++) {
                int d = Math.abs(vals.get(i) - vals.get(j));
                if (d < best) best = d;
            }
        }
        return best;
    }
    void go(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        vals.add(node.val);
        go(node.left, vals);
        go(node.right, vals);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder. Compare each node with the previous inorder value. The min of those adjacent gaps is the global min.

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
    Integer prev;
    int best;
    public int getMinimumDifference(TreeNode root) {
        prev = null;
        best = Integer.MAX_VALUE;
        go(root);
        return best;
    }
    void go(TreeNode node) {
        if (node == null) return;
        go(node.left);
        if (prev != null) best = Math.min(best, node.val - prev);
        prev = node.val;
        go(node.right);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with a previous pointer. Same adjacent-gap logic, no stack.

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
    public int getMinimumDifference(TreeNode root) {
        Integer prev = null;
        int best = Integer.MAX_VALUE;
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left == null) {
                if (prev != null) best = Math.min(best, cur.val - prev);
                prev = cur.val;
                cur = cur.right;
            } else {
                TreeNode pred = cur.left;
                while (pred.right != null && pred.right != cur) pred = pred.right;
                if (pred.right == null) {
                    pred.right = cur;
                    cur = cur.left;
                } else {
                    pred.right = null;
                    if (prev != null) best = Math.min(best, cur.val - prev);
                    prev = cur.val;
                    cur = cur.right;
                }
            }
        }
        return best;
    }
}
