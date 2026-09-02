// Method 1: Brute
// Time: O(n · n!) | Space: O(n · n!)
// Generate every permutation of 1..n, insert into a BST, serialize the shape, keep one copy per unique serialization. Correct but factorial.

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
    public List<TreeNode> generateTrees(int n) {
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = i + 1;
        Set<String> seen = new HashSet<String>();
        List<TreeNode> out = new ArrayList<TreeNode>();
        perm(nums, 0, seen, out);
        return out;
    }
    void perm(int[] nums, int i, Set<String> seen, List<TreeNode> out) {
        if (i == nums.length) {
            TreeNode root = null;
            for (int v : nums) root = insert(root, v);
            String s = serial(root);
            if (seen.add(s)) out.add(clone(root));
            return;
        }
        for (int j = i; j < nums.length; j++) {
            int tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
            perm(nums, i + 1, seen, out);
            tmp = nums[i]; nums[i] = nums[j]; nums[j] = tmp;
        }
    }
    TreeNode insert(TreeNode node, int val) {
        if (node == null) return new TreeNode(val);
        if (val < node.val) node.left = insert(node.left, val);
        else node.right = insert(node.right, val);
        return node;
    }
    TreeNode clone(TreeNode node) {
        if (node == null) return null;
        return new TreeNode(node.val, clone(node.left), clone(node.right));
    }
    String serial(TreeNode node) {
        if (node == null) return "#";
        return node.val + "," + serial(node.left) + "," + serial(node.right);
    }
}


// Method 2: Optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// For each root i in [lo, hi], cartesian product of left trees and right trees. Empty range yields a single null tree so a missing child is represented once.

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
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) return new ArrayList<TreeNode>();
        return build(1, n);
    }
    List<TreeNode> build(int lo, int hi) {
        List<TreeNode> out = new ArrayList<TreeNode>();
        if (lo > hi) { out.add(null); return out; }
        for (int i = lo; i <= hi; i++) {
            for (TreeNode left : build(lo, i - 1)) {
                for (TreeNode right : build(i + 1, hi)) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    out.add(node);
                }
            }
        }
        return out;
    }
}


// Method 3: More optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// Memoize [lo, hi]. Shared ranges (for example all trees on 3,4,5) are built once. Catalan many trees still must be allocated.

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
    Map<String, List<TreeNode>> memo = new HashMap<String, List<TreeNode>>();
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) return new ArrayList<TreeNode>();
        return build(1, n);
    }
    List<TreeNode> build(int lo, int hi) {
        String key = lo + "," + hi;
        if (memo.containsKey(key)) return memo.get(key);
        List<TreeNode> out = new ArrayList<TreeNode>();
        if (lo > hi) { out.add(null); memo.put(key, out); return out; }
        for (int i = lo; i <= hi; i++) {
            for (TreeNode left : build(lo, i - 1)) {
                for (TreeNode right : build(i + 1, hi)) {
                    TreeNode node = new TreeNode(i);
                    node.left = left;
                    node.right = right;
                    out.add(node);
                }
            }
        }
        memo.put(key, out);
        return out;
    }
}
