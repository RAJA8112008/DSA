// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// DFS push [col, row, val]. Sort by col, then row, then val. Group into lists. Matches LeetCode 987.

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
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<int[]> items = new ArrayList<int[]>();
        go(root, 0, 0, items);
        items.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] != b[1] ? a[1] - b[1] : a[2] - b[2]);
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        Integer prev = null;
        for (int[] it : items) {
            if (prev == null || it[0] != prev) { out.add(new ArrayList<Integer>()); prev = it[0]; }
            out.get(out.size() - 1).add(it[2]);
        }
        return out;
    }
    void go(TreeNode node, int row, int col, List<int[]> items) {
        if (node == null) return;
        items.add(new int[]{col, row, node.val});
        go(node.left, row + 1, col - 1, items);
        go(node.right, row + 1, col + 1, items);
    }
}


// Method 2: Optimal
// Time: O(n log w) | Space: O(n)
// BFS so row order is natural. TreeMap / sorted map of columns. GFG order (no value sort). w is the number of columns.

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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        if (root == null) return out;
        TreeMap<Integer, List<Integer>> cols = new TreeMap<Integer, List<Integer>>();
        Queue<TreeNode> nq = new ArrayDeque<TreeNode>();
        Queue<Integer> hq = new ArrayDeque<Integer>();
        nq.add(root); hq.add(0);
        while (!nq.isEmpty()) {
            TreeNode node = nq.poll();
            int hd = hq.poll();
            cols.computeIfAbsent(hd, k -> new ArrayList<Integer>()).add(node.val);
            if (node.left != null) { nq.add(node.left); hq.add(hd - 1); }
            if (node.right != null) { nq.add(node.right); hq.add(hd + 1); }
        }
        out.addAll(cols.values());
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same BFS. Record min and max hd, then emit columns in a plain loop. No log w map.

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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> out = new ArrayList<List<Integer>>();
        if (root == null) return out;
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        List<Integer> hds = new ArrayList<Integer>();
        nodes.add(root); hds.add(0);
        int minH = 0, maxH = 0;
        for (int i = 0; i < nodes.size(); i++) {
            TreeNode node = nodes.get(i);
            int hd = hds.get(i);
            minH = Math.min(minH, hd);
            maxH = Math.max(maxH, hd);
            if (node.left != null) { nodes.add(node.left); hds.add(hd - 1); }
            if (node.right != null) { nodes.add(node.right); hds.add(hd + 1); }
        }
        for (int h = minH; h <= maxH; h++) out.add(new ArrayList<Integer>());
        for (int i = 0; i < nodes.size(); i++) out.get(hds.get(i) - minH).add(nodes.get(i).val);
        return out;
    }
}
