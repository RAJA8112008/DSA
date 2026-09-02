// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Inorder keys, then insert in sorted order into a fresh BST. That rebuilds a stick. Shows why you must pick mids, not insert in order.

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
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> keys = new ArrayList<Integer>();
        go(root, keys);
        TreeNode out = null;
        for (int val : keys) out = insert(out, val);
        return out;
    }
    void go(TreeNode node, List<Integer> keys) {
        if (node == null) return;
        go(node.left, keys);
        keys.add(node.val);
        go(node.right, keys);
    }
    TreeNode insert(TreeNode node, int val) {
        if (node == null) return new TreeNode(val);
        if (val < node.val) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Inorder into an array, then mid-as-root rebuild. Height is log n. Extra array of keys (or of nodes if you reuse them).

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
    public TreeNode balanceBST(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        go(root, nodes);
        return build(nodes, 0, nodes.size() - 1);
    }
    void go(TreeNode node, List<TreeNode> nodes) {
        if (node == null) return;
        go(node.left, nodes);
        nodes.add(node);
        go(node.right, nodes);
    }
    TreeNode build(List<TreeNode> nodes, int lo, int hi) {
        if (lo > hi) return null;
        int mid = lo + (hi - lo) / 2;
        TreeNode node = nodes.get(mid);
        node.left = build(nodes, lo, mid - 1);
        node.right = build(nodes, mid + 1, hi);
        return node;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// DSW: rotate every left child to the right to make a vine (linked list of right pointers). Then repeatedly rotate the vine to fold it into a balanced tree. In-place, O(1) extra besides recursion-free loops.

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
    TreeNode dummy;
    int vine() {
        TreeNode tail = dummy;
        TreeNode rest = dummy.right;
        int n = 0;
        while (rest != null) {
            if (rest.left != null) {
                TreeNode old = rest;
                rest = rest.left;
                old.left = rest.right;
                rest.right = old;
                tail.right = rest;
            } else {
                tail = rest;
                rest = rest.right;
                n++;
            }
        }
        return n;
    }
    void compress(int count) {
        TreeNode parent = dummy;
        for (int i = 0; i < count; i++) {
            TreeNode child = parent.right;
            parent.right = child.right;
            child.right = parent.right.left;
            parent.right.left = child;
            parent = parent.right;
        }
    }
    public TreeNode balanceBST(TreeNode root) {
        dummy = new TreeNode(0);
        dummy.right = root;
        int n = vine();
        int m = 1;
        while (m * 2 + 1 <= n) m = m * 2 + 1;
        compress(n - m);
        for (m /= 2; m >= 1; m /= 2) compress(m);
        return dummy.right;
    }
}
