// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order into lists. Reverse rows whose index is odd. Extra reverse pass per odd level.

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
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
            if (out.size() % 2 == 1) Collections.reverse(row);
            out.add(row);
        }
        return out;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Deque of nodes. Even levels poll from the front and offer children left-then-right at the back. Odd levels poll from the back and offer children right-then-left at the front.

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        if (root == null) return out;
        Deque<TreeNode> dq = new ArrayDeque<TreeNode>();
        dq.add(root);
        boolean leftToRight = true;
        while (!dq.isEmpty()) {
            int n = dq.size();
            List<Integer> row = new ArrayList<Integer>();
            for (int i = 0; i < n; i++) {
                if (leftToRight) {
                    TreeNode node = dq.pollFirst();
                    row.add(node.val);
                    if (node.left != null) dq.addLast(node.left);
                    if (node.right != null) dq.addLast(node.right);
                } else {
                    TreeNode node = dq.pollLast();
                    row.add(node.val);
                    if (node.right != null) dq.addFirst(node.right);
                    if (node.left != null) dq.addFirst(node.left);
                }
            }
            out.add(row);
            leftToRight = !leftToRight;
        }
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with depth. Append a new list when you first reach a depth. Push on even depths, unshift on odd depths. Recursion stack only.

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        go(root, 0, out);
        return out;
    }
    void go(TreeNode node, int d, List<List<Integer>> out) {
        if (node == null) return;
        if (d == out.size()) out.add(new ArrayList<Integer>());
        if (d % 2 == 0) out.get(d).add(node.val);
        else out.get(d).add(0, node.val);
        go(node.left, d + 1, out);
        go(node.right, d + 1, out);
    }
}
