// Method 1: Brute
// Time: O(n·m) | Space: O(n)
// Push every node of root into an array, then isSameTree against subRoot for each. Extra array plus O(n*m) compares.

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
    private boolean isSubtree_same(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null || a.val != b.val) {
            return false;
        }
        return isSubtree_same(a.left, b.left) && isSubtree_same(a.right, b.right);
    }

    private boolean isSubtree_collect(TreeNode node) {
        if (node == null) {
            return;
        }
        nodes.add(node);
        isSubtree_collect(node.left);
        isSubtree_collect(node.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        List<TreeNode> nodes = new ArrayList<>();
        isSubtree_collect(root);
        for (var node : nodes) {
            if (isSubtree_same(node, subRoot)) {
                return true;
            }
        }
        return false;
    }
}


// Method 2: Optimal
// Time: O(n·m) | Space: O(h)
// No extra node list. If this node matches as a tree, true. Else try left or right. Worst case still O(n*m), typical interview code.

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
    private boolean isSubtree_same(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null || a.val != b.val) {
            return false;
        }
        return isSubtree_same(a.left, b.left) && isSubtree_same(a.right, b.right);
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
        if (isSubtree_same(root, subRoot)) {
            return true;
        }
        return (isSubtree(root.left, subRoot) != null ? isSubtree(root.left, subRoot) : isSubtree(root.right, subRoot));
    }
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(n+m)
// Serialize with parentheses so each subtree is a unique string. Check whether ser(subRoot) is a substring of ser(root). Linear in the size of the strings (and typical includes).

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
    private boolean isSubtree_ser(TreeNode node) {
        if (node == null) {
            return "N";
        }
        return "(" + node.val + "," + isSubtree_ser(node.left) + "," + isSubtree_ser(node.right) + ")";
    }

    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        return isSubtree_ser(root).indexOf(isSubtree_ser(subRoot)) != -1;
    }
}
