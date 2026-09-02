// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect every (hd, depth, val), sort, keep the first (smallest depth) per hd.

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
    public List<Integer> topView(TreeNode root) {
        List<int[]> items = new ArrayList<int[]>();
        go(root, 0, 0, items);
        items.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] - b[1]);
        List<Integer> out = new ArrayList<Integer>();
        Integer prev = null;
        for (int[] it : items) {
            if (prev == null || it[0] != prev) { out.add(it[2]); prev = it[0]; }
        }
        return out;
    }
    void go(TreeNode node, int hd, int d, List<int[]> items) {
        if (node == null) return;
        items.add(new int[]{hd, d, node.val});
        go(node.left, hd - 1, d + 1, items);
        go(node.right, hd + 1, d + 1, items);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS. The first time an hd appears, record it. Then emit from min hd to max hd.

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
    public List<Integer> topView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        Map<Integer, Integer> first = new HashMap<Integer, Integer>();
        Queue<TreeNode> nq = new ArrayDeque<TreeNode>();
        Queue<Integer> hq = new ArrayDeque<Integer>();
        nq.add(root); hq.add(0);
        int minH = 0, maxH = 0;
        while (!nq.isEmpty()) {
            TreeNode node = nq.poll();
            int hd = hq.poll();
            first.putIfAbsent(hd, node.val);
            minH = Math.min(minH, hd);
            maxH = Math.max(maxH, hd);
            if (node.left != null) { nq.add(node.left); hq.add(hd - 1); }
            if (node.right != null) { nq.add(node.right); hq.add(hd + 1); }
        }
        for (int h = minH; h <= maxH; h++) out.add(first.get(h));
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS with depth. Keep a node for hd only if this depth is smaller. Then scan min..max hd. No queue.

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
    Map<Integer, Integer> bestVal = new HashMap<Integer, Integer>();
    Map<Integer, Integer> bestD = new HashMap<Integer, Integer>();
    int minH, maxH;
    void go(TreeNode node, int hd, int d) {
        if (node == null) return;
        if (!bestD.containsKey(hd) || d < bestD.get(hd)) {
            bestD.put(hd, d);
            bestVal.put(hd, node.val);
        }
        minH = Math.min(minH, hd);
        maxH = Math.max(maxH, hd);
        go(node.left, hd - 1, d + 1);
        go(node.right, hd + 1, d + 1);
    }
    public List<Integer> topView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        minH = 0; maxH = 0;
        go(root, 0, 0);
        for (int h = minH; h <= maxH; h++) out.add(bestVal.get(h));
        return out;
    }
}
