// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// Collect every root-to-leaf path, then keep those whose sum equals target. Path copies dominate memory.

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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> paths = new ArrayList<List<Integer>>();
        go(root, new ArrayList<Integer>(), paths);
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        for (List<Integer> p : paths) {
            int s = 0;
            for (int v : p) s += v;
            if (s == targetSum) out.add(p);
        }
        return out;
    }
    void go(TreeNode node, List<Integer> path, List<List<Integer>> paths) {
        if (node == null) return;
        path.add(node.val);
        if (node.left == null && node.right == null) paths.add(new ArrayList<Integer>(path));
        go(node.left, path, paths);
        go(node.right, path, paths);
        path.remove(path.size() - 1);
    }
}


// Method 2: Optimal
// Time: O(n²) | Space: O(h)
// Backtracking. remain starts at targetSum. At a leaf, if remain == node.val, snapshot the path. Copying a path is O(h); total output can be O(n²).

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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        go(root, targetSum, new ArrayList<Integer>(), out);
        return out;
    }
    void go(TreeNode node, int remain, List<Integer> path, List<List<Integer>> out) {
        if (node == null) return;
        path.add(node.val);
        if (node.left == null && node.right == null && remain == node.val) out.add(new ArrayList<Integer>(path));
        go(node.left, remain - node.val, path, out);
        go(node.right, remain - node.val, path, out);
        path.remove(path.size() - 1);
    }
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Iterative stack of {node, remain, path}. Same snapshots at leaves. Avoids call-stack overflow on a stick, still copies paths.

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
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        if (root == null) return out;
        Deque<TreeNode> ns = new ArrayDeque<TreeNode>();
        Deque<Integer> rs = new ArrayDeque<Integer>();
        Deque<List<Integer>> ps = new ArrayDeque<List<Integer>>();
        ns.push(root); rs.push(targetSum); ps.push(new ArrayList<Integer>(Arrays.asList(root.val)));
        while (!ns.isEmpty()) {
            TreeNode node = ns.pop();
            int remain = rs.pop();
            List<Integer> path = ps.pop();
            if (node.left == null && node.right == null && remain == node.val) out.add(path);
            if (node.right != null) {
                List<Integer> np = new ArrayList<Integer>(path);
                np.add(node.right.val);
                ns.push(node.right); rs.push(remain - node.val); ps.push(np);
            }
            if (node.left != null) {
                List<Integer> np = new ArrayList<Integer>(path);
                np.add(node.left.val);
                ns.push(node.left); rs.push(remain - node.val); ps.push(np);
            }
        }
        return out;
    }
}
