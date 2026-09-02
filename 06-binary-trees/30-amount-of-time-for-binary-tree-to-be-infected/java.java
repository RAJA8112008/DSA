// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build undirected graph on values (unique). BFS from start. Answer is the max distance.

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
    public int amountOfTime(TreeNode root, int start) {
        Map<Integer, List<Integer>> g = new HashMap<Integer, List<Integer>>();
        build(root, g);
        Set<Integer> seen = new HashSet<Integer>();
        Queue<int[]> q = new ArrayDeque<int[]>();
        q.add(new int[]{start, 0});
        seen.add(start);
        int best = 0;
        while (!q.isEmpty()) {
            int[] p = q.poll();
            best = Math.max(best, p[1]);
            for (int v : g.getOrDefault(p[0], Collections.emptyList())) {
                if (seen.add(v)) q.add(new int[]{v, p[1] + 1});
            }
        }
        return best;
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
// Parent pointers, BFS from the start node (find it first). Minutes = max distance.

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
    TreeNode src;
    void mark(TreeNode node, TreeNode p, int start) {
        if (node == null) return;
        parent.put(node, p);
        if (node.val == start) src = node;
        mark(node.left, node, start);
        mark(node.right, node, start);
    }
    public int amountOfTime(TreeNode root, int start) {
        mark(root, null, start);
        Set<TreeNode> seen = new HashSet<TreeNode>();
        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
        Queue<Integer> dq = new ArrayDeque<Integer>();
        q.add(src); dq.add(0); seen.add(src);
        int best = 0;
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            int d = dq.poll();
            best = Math.max(best, d);
            TreeNode[] nbr = {node.left, node.right, parent.get(node)};
            for (TreeNode nx : nbr) {
                if (nx == null || !seen.add(nx)) continue;
                q.add(nx); dq.add(d + 1);
            }
        }
        return best;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS returns height of the subtree. When the start node is found, ans is max(height below, distance going up through the parent). One traversal, no graph.

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
    int ans;
    int dfs(TreeNode node, int start) {
        if (node == null) return 0;
        int L = dfs(node.left, start);
        int R = dfs(node.right, start);
        if (node.val == start) {
            ans = Math.max(ans, Math.max(L, R));
            return -1;
        }
        if (L < 0) { ans = Math.max(ans, R - L); return L - 1; }
        if (R < 0) { ans = Math.max(ans, L - R); return R - 1; }
        return 1 + Math.max(L, R);
    }
    public int amountOfTime(TreeNode root, int start) {
        ans = 0;
        dfs(root, start);
        return ans;
    }
}
