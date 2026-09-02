// Method 1: Brute
// Time: O(n) | Space: O(n)
// BFS into an array of every node, then swap left/right on each. Extra list of n pointers.

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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return root;
        }
        List<TreeNode> nodes = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>(); queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove(0);
            nodes.add(node);
            if (node.left != null) {
                queue.add(node.left);
            }
            if (node.right != null) {
                queue.add(node.right);
            }
        }
        for (var node : nodes) {
            TreeNode tmp = node.left;
            node.left = node.right;
            node.right = tmp;
        }
        return root;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse: invert children, then swap this node's left and right (order of swap vs recurse both work). Stack O(h).

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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        invertTree(root.left);
        invertTree(root.right);
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
        return root;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack. Pop a node, swap children, push non-null children. Same work, no recursion. Queue instead of stack is also fine.

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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return null;
        }
        List<TreeNode> stack = new ArrayList<>(); stack.add(root);
        while (!stack.isEmpty()) {
            TreeNode node = stack.remove(stack.size()-1);
            TreeNode tmp = node.left;
            node.left = node.right;
            node.right = tmp;
            if (node.left != null) {
                stack.add(node.left);
            }
            if (node.right != null) {
                stack.add(node.right);
            }
        }
        return root;
    }
}
