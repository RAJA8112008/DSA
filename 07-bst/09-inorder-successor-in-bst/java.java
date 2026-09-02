// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder list of nodes, find p, return the next entry. Extra linear memory.

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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        go(root, nodes);
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.get(i) == p) return i + 1 < nodes.size() ? nodes.get(i + 1) : null;
        }
        return null;
    }
    void go(TreeNode node, List<TreeNode> nodes) {
        if (node == null) return;
        go(node.left, nodes);
        nodes.add(node);
        go(node.right, nodes);
    }
}


// Method 2: Optimal
// Time: O(h) | Space: O(1)
// Walk from the root. Whenever the current node is greater than p, it is a candidate successor — go left to hunt a closer one. Otherwise go right.

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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        TreeNode succ = null, cur = root;
        while (cur != null) {
            if (p.val < cur.val) { succ = cur; cur = cur.left; }
            else cur = cur.right;
        }
        return succ;
    }
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// If p has a right child, successor is leftmost there — O(h) on that spine only. Else fall back to the root walk. Same worst case, often shorter.

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
    public TreeNode inorderSuccessor(TreeNode root, TreeNode p) {
        if (p.right != null) {
            TreeNode n = p.right;
            while (n.left != null) n = n.left;
            return n;
        }
        TreeNode succ = null, cur = root;
        while (cur != null) {
            if (p.val < cur.val) { succ = cur; cur = cur.left; }
            else cur = cur.right;
        }
        return succ;
    }
}
