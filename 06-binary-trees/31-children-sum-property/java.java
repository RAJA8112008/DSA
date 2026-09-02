// Method 1: Brute
// Time: O(n) | Space: O(n)
// For every node, sum the two children (0 if null) and compare. Recurse both sides. Extra list of all nodes first.

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
    public boolean isSumTree(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        go(root, nodes);
        for (TreeNode n : nodes) {
            if (n.left == null && n.right == null) continue;
            int L = n.left == null ? 0 : n.left.val;
            int R = n.right == null ? 0 : n.right.val;
            if (n.val != L + R) return false;
        }
        return true;
    }
    void go(TreeNode node, List<TreeNode> nodes) {
        if (node == null) return;
        nodes.add(node);
        go(node.left, nodes);
        go(node.right, nodes);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder boolean. Null and leaves are true. Then check val == left+right and both subtrees hold.

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
    public boolean isSumTree(TreeNode root) {
        if (root == null) return true;
        if (root.left == null && root.right == null) return true;
        int L = root.left == null ? 0 : root.left.val;
        int R = root.right == null ? 0 : root.right.val;
        return root.val == L + R && isSumTree(root.left) && isSumTree(root.right);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Return a pair (ok, val) so a failed subtree aborts. Same checks, one value returned upward.

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
    class Pair { boolean ok; int val; Pair(boolean ok, int val) { this.ok = ok; this.val = val; } }
    Pair go(TreeNode node) {
        if (node == null) return new Pair(true, 0);
        if (node.left == null && node.right == null) return new Pair(true, node.val);
        Pair L = go(node.left);
        Pair R = go(node.right);
        boolean ok = L.ok && R.ok && node.val == L.val + R.val;
        return new Pair(ok, node.val);
    }
    public boolean isSumTree(TreeNode root) {
        return go(root).ok;
    }
}
