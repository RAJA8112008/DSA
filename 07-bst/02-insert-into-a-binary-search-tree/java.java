// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every key, append val, sort, and rebuild a balanced tree from the middle. Extra arrays; you never use the existing shape.

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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        List<Integer> keys = new ArrayList<Integer>();
        collect(root, keys);
        keys.add(val);
        Collections.sort(keys);
        return build(keys, 0, keys.size() - 1);
    }
    void collect(TreeNode node, List<Integer> keys) {
        if (node == null) return;
        keys.add(node.val);
        collect(node.left, keys);
        collect(node.right, keys);
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
// Recurse left or right and assign the returned child. When the child is null, allocate the new leaf. Root is returned unchanged unless the tree was empty.

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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) return new TreeNode(val);
        if (val < root.val) root.left = insertIntoBST(root.left, val);
        else root.right = insertIntoBST(root.right, val);
        return root;
    }
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative: if the tree is empty, return a new root. Else walk until the next child is null and attach there. No recursion.

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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode fresh = new TreeNode(val);
        if (root == null) return fresh;
        TreeNode cur = root;
        while (true) {
            if (val < cur.val) {
                if (cur.left == null) { cur.left = fresh; break; }
                cur = cur.left;
            } else {
                if (cur.right == null) { cur.right = fresh; break; }
                cur = cur.right;
            }
        }
        return root;
    }
}
