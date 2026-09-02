// Method 1: Brute
// Time: O(n) | Space: O(n)
// Undirected graph of val->neighbors (vals are unique on LC). BFS from target.val for K steps.

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
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<Integer, List<Integer>> g = new HashMap<Integer, List<Integer>>();
        build(root, g);
        Set<Integer> seen = new HashSet<Integer>();
        Queue<int[]> q = new ArrayDeque<int[]>();
        q.add(new int[]{target.val, 0});
        seen.add(target.val);
        List<Integer> out = new ArrayList<Integer>();
        while (!q.isEmpty()) {
            int[] p = q.poll();
            if (p[1] == k) { out.add(p[0]); continue; }
            for (int v : g.getOrDefault(p[0], Collections.emptyList())) {
                if (seen.add(v)) q.add(new int[]{v, p[1] + 1});
            }
        }
        return out;
    }
    void link(Map<Integer, List<Integer>> g, int a, int b) {
        g.computeIfAbsent(a, x -> new ArrayList<Integer>()).add(b);
        g.computeIfAbsent(b, x -> new ArrayList<Integer>()).add(a);
    }
    void build(TreeNode node, Map<Integer, List<Integer>> g) {
        if (node == null) return;
        if (node.left != null) { link(g, node.val, node.left.val); build(node.left, g); }
        if (node.right != null) { link(g, node.val, node.right.val); build(node.right, g); }
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent map from nodes (not values). BFS from the target node with a visited set of pointers. Collect at distance k.

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
    Map<TreeNode, TreeNode> parent = new HashMap<TreeNode, TreeNode>();
    void mark(TreeNode node, TreeNode p) {
        if (node == null) return;
        parent.put(node, p);
        mark(node.left, node);
        mark(node.right, node);
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        mark(root, null);
        Set<TreeNode> seen = new HashSet<TreeNode>();
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        Queue<Integer> dq = new ArrayDeque<Integer>();
        q.add(target); dq.add(0); seen.add(target);
        List<Integer> out = new ArrayList<Integer>();
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            int d = dq.poll();
            if (d == k) { out.add(node.val); continue; }
            TreeNode[] nbr = {node.left, node.right, parent.get(node)};
            for (TreeNode nx : nbr) {
                if (nx == null || !seen.add(nx)) continue;
                q.add(nx); dq.add(d + 1);
            }
        }
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS returns distance from this subtree to target, or -1. When a child reports dist, walk the other child at k - dist - 2, and maybe record this node. Downward walk from target collects depth k.

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
    List<Integer> out;
    void collect(TreeNode node, int dist) {
        if (node == null || dist < 0) return;
        if (dist == 0) { out.add(node.val); return; }
        collect(node.left, dist - 1);
        collect(node.right, dist - 1);
    }
    int dfs(TreeNode node, TreeNode target, int k) {
        if (node == null) return -1;
        if (node == target) { collect(node, k); return 0; }
        int L = dfs(node.left, target, k);
        if (L >= 0) {
            if (L + 1 == k) out.add(node.val);
            else collect(node.right, k - L - 2);
            return L + 1;
        }
        int R = dfs(node.right, target, k);
        if (R >= 0) {
            if (R + 1 == k) out.add(node.val);
            else collect(node.left, k - R - 2);
            return R + 1;
        }
        return -1;
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        out = new ArrayList<Integer>();
        dfs(root, target, k);
        return out;
    }
}
