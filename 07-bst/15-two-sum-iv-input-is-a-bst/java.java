// Method 1: Brute
// Time: O(n²) | Space: O(h)
// For each node, DFS the rest of the tree looking for k - val. Nested walks. No extra set.

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
    boolean exists(TreeNode node, TreeNode skip, int val) {
        if (node == null) return false;
        if (node != skip && node.val == val) return true;
        return exists(node.left, skip, val) || exists(node.right, skip, val);
    }
    boolean go(TreeNode root, TreeNode node, int k) {
        if (node == null) return false;
        if (exists(root, node, k - node.val)) return true;
        return go(root, node.left, k) || go(root, node.right, k);
    }
    public boolean findTarget(TreeNode root, int k) {
        return go(root, root, k);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Hash set of visited values. DFS: if k - val is in the set, done; else add val and continue. Works on any binary tree.

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
    public boolean findTarget(TreeNode root, int k) {
        Set<Integer> seen = new HashSet<Integer>();
        return go(root, k, seen);
    }
    boolean go(TreeNode node, int k, Set<Integer> seen) {
        if (node == null) return false;
        if (seen.contains(k - node.val)) return true;
        seen.add(node.val);
        return go(node.left, k, seen) || go(node.right, k, seen);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Inorder array is sorted. Two pointers from both ends. Uses the BST. Space is still linear for the array; two iterators would drop it to O(h).

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
    public boolean findTarget(TreeNode root, int k) {
        List<Integer> vals = new ArrayList<Integer>();
        go(root, vals);
        int i = 0, j = vals.size() - 1;
        while (i < j) {
            int s = vals.get(i) + vals.get(j);
            if (s == k) return true;
            if (s < k) i++;
            else j--;
        }
        return false;
    }
    void go(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        go(node.left, vals);
        vals.add(node.val);
        go(node.right, vals);
    }
}
