// Method 1: Brute
// Time: O(n) | Space: O(n)
// Ignore the BST. DFS every node into a list, then scan for val. Correct on any binary tree, but you throw away the ordering.

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
    public TreeNode searchBST(TreeNode root, int val) {
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        go(root, nodes);
        for (TreeNode node : nodes) {
            if (node.val == val) return node;
        }
        return null;
    }
    void go(TreeNode node, List<TreeNode> nodes) {
        if (node == null) return;
        nodes.add(node);
        go(node.left, nodes);
        go(node.right, nodes);
    }
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse on one child. Each call compares val with the node and drops a whole subtree. Stack depth is the height.

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
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null || root.val == val) return root;
        if (val < root.val) return searchBST(root.left, val);
        return searchBST(root.right, val);
    }
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same comparisons in a while loop. No call stack. Returns the node or null when the walk falls off.

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
    public TreeNode searchBST(TreeNode root, int val) {
        TreeNode cur = root;
        while (cur != null && cur.val != val) {
            cur = val < cur.val ? cur.left : cur.right;
        }
        return cur;
    }
}
