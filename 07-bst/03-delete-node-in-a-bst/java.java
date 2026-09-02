// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump every key except key, then rebuild a balanced BST from the sorted list. Simple, but you throw away the original shape.

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
    public TreeNode deleteNode(TreeNode root, int key) {
        List<Integer> keys = new ArrayList<Integer>();
        collect(root, key, keys);
        Collections.sort(keys);
        return build(keys, 0, keys.size() - 1);
    }
    void collect(TreeNode node, int key, List<Integer> keys) {
        if (node == null) return;
        if (node.val != key) keys.add(node.val);
        collect(node.left, key, keys);
        collect(node.right, key, keys);
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
// Time: O(h) | Space: O(h)
// Recurse to the node. Leaf or one child: return the other child. Two children: copy leftmost of right into node.val, then delete that successor from the right subtree.

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
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;
        if (key < root.val) root.left = deleteNode(root.left, key);
        else if (key > root.val) root.right = deleteNode(root.right, key);
        else {
            if (root.left == null) return root.right;
            if (root.right == null) return root.left;
            TreeNode succ = root.right;
            while (succ.left != null) succ = succ.left;
            root.val = succ.val;
            root.right = deleteNode(root.right, succ.val);
        }
        return root;
    }
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative search with a parent pointer. Splice zero/one-child nodes directly. For two children, copy the successor value then unlink the successor (it has no left child).

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
    TreeNode splice(TreeNode root, TreeNode parent, TreeNode node, TreeNode child) {
        if (parent == null) return child;
        if (parent.left == node) parent.left = child;
        else parent.right = child;
        return root;
    }
    public TreeNode deleteNode(TreeNode root, int key) {
        TreeNode parent = null, cur = root;
        while (cur != null && cur.val != key) {
            parent = cur;
            cur = key < cur.val ? cur.left : cur.right;
        }
        if (cur == null) return root;
        if (cur.left == null) return splice(root, parent, cur, cur.right);
        if (cur.right == null) return splice(root, parent, cur, cur.left);
        TreeNode sp = cur, succ = cur.right;
        while (succ.left != null) { sp = succ; succ = succ.left; }
        cur.val = succ.val;
        if (sp.left == succ) sp.left = succ.right;
        else sp.right = succ.right;
        return root;
    }
}
