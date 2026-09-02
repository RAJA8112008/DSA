// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order lists, then pick the first value of each list.

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
    public List<Integer> leftView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            List<Integer> row = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                row.add(node.val);
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
            out.add(row.get(0));
        }
        return out;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// BFS. When i == 0 in the level loop, that node is the left view. w is the widest level.

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
    public List<Integer> leftView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                if (i == 0) out.add(node.val);
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS left-first. If depth == out.length this is the first node at that depth. Recursion stack only.

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
    public List<Integer> leftView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        go(root, 0, out);
        return out;
    }
    void go(TreeNode node, int d, List<Integer> out) {
        if (node == null) return;
        if (d == out.size()) out.add(node.val);
        go(node.left, d + 1, out);
        go(node.right, d + 1, out);
    }
}
