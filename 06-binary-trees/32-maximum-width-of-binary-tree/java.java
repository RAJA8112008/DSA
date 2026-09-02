// Method 1: Brute
// Time: O(n) | Space: O(w)
// BFS. Width of a level is the queue size (actual nodes). Max over levels. Matches GFG's non-null count.

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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int best = 0;
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            best = Math.max(best, n);
            for (int i = 0; i < n; i++) {
                TreeNode node = q.poll();
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }
        return best;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// LeetCode width: BFS with heap indices. Subtract the first index of the level so numbers stay small. Width = last - first + 1.

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
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int best = 0;
        Queue<TreeNode> nq = new ArrayDeque<TreeNode>();
        Queue<Integer> iq = new ArrayDeque<Integer>();
        nq.add(root); iq.add(0);
        while (!nq.isEmpty()) {
            int n = nq.size();
            int first = iq.peek();
            int last = first;
            for (int i = 0; i < n; i++) {
                TreeNode node = nq.poll();
                int idx = iq.poll() - first;
                last = idx;
                if (node.left != null) { nq.add(node.left); iq.add(idx * 2 + 1); }
                if (node.right != null) { nq.add(node.right); iq.add(idx * 2 + 2); }
            }
            best = Math.max(best, last + 1);
        }
        return best;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with (depth, normalized index). Store the first index seen at each depth. Width = idx - first[depth] + 1. Recursion only.

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
    List<Integer> first = new ArrayList<Integer>();
    int best;
    void go(TreeNode node, int d, int idx) {
        if (node == null) return;
        if (d == first.size()) first.add(idx);
        int pos = idx - first.get(d);
        best = Math.max(best, pos + 1);
        go(node.left, d + 1, pos * 2 + 1);
        go(node.right, d + 1, pos * 2 + 2);
    }
    public int widthOfBinaryTree(TreeNode root) {
        best = 0;
        go(root, 0, 0);
        return best;
    }
}
