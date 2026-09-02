// Method 1: Brute
// Time: O(n) | Space: O(n)
// Gather every in-range key, sort, rebuild a balanced tree. Correct values, but new nodes and a different shape.

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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        List<Integer> keys = new ArrayList<Integer>();
        collect(root, low, high, keys);
        Collections.sort(keys);
        return build(keys, 0, keys.size() - 1);
    }
    void collect(TreeNode node, int low, int high, List<Integer> keys) {
        if (node == null) return;
        if (node.val >= low && node.val <= high) keys.add(node.val);
        collect(node.left, low, high, keys);
        collect(node.right, low, high, keys);
    }
    TreeNode build(List<Integer> keys, int lo, int hi) {
        if (lo > hi) return null;
        int mid = lo + (hi - lo) / 2;
        TreeNode node = new TreeNode(keys.get(mid));
        node.left = build(keys, lo, mid - 1);
        node.right = build(keys, mid + 1, hi);
        return node;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder prune using the BST property. Reuse the original nodes. If the root is outside the window, drop it and return one trimmed child.

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
    public TreeNode trimBST(TreeNode root, int low, int high) {
        if (root == null) return null;
        if (root.val < low) return trimBST(root.right, low, high);
        if (root.val > high) return trimBST(root.left, low, high);
        root.left = trimBST(root.left, low, high);
        root.right = trimBST(root.right, low, high);
        return root;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Move the root iteratively until it sits inside [low, high], then recursively trim the two sides. Fewer frames when the original root is far outside the window.

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
    TreeNode trim(TreeNode node, int low, int high) {
        if (node == null) return null;
        if (node.val < low) return trim(node.right, low, high);
        if (node.val > high) return trim(node.left, low, high);
        node.left = trim(node.left, low, high);
        node.right = trim(node.right, low, high);
        return node;
    }
    public TreeNode trimBST(TreeNode root, int low, int high) {
        while (root != null && (root.val < low || root.val > high)) {
            root = root.val < low ? root.right : root.left;
        }
        if (root == null) return null;
        root.left = trim(root.left, low, high);
        root.right = trim(root.right, low, high);
        return root;
    }
}
