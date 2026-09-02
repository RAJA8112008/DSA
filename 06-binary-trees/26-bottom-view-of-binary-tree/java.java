// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect (hd, depth, index, val), sort, keep the last per hd.

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
    public List<Integer> bottomView(TreeNode root) {
        List<int[]> items = new ArrayList<int[]>();
        int[] idx = {0};
        go(root, 0, 0, items, idx);
        items.sort((a, b) -> a[0] != b[0] ? a[0] - b[0] : a[1] != b[1] ? a[1] - b[1] : a[2] - b[2]);
        List<Integer> out = new ArrayList<Integer>();
        for (int i = 0; i < items.size(); i++) {
            if (i + 1 == items.size() || items.get(i)[0] != items.get(i + 1)[0]) out.add(items.get(i)[3]);
        }
        return out;
    }
    void go(TreeNode node, int hd, int d, List<int[]> items, int[] idx) {
        if (node == null) return;
        items.add(new int[]{hd, d, idx[0]++, node.val});
        go(node.left, hd - 1, d + 1, items, idx);
        go(node.right, hd + 1, d + 1, items, idx);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS overwrite per hd. Last write is the deepest (or the right one on a tie). Emit min..max.

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
    public List<Integer> bottomView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        Map<Integer, Integer> last = new HashMap<Integer, Integer>();
        Queue<TreeNode> nq = new ArrayDeque<TreeNode>();
        Queue<Integer> hq = new ArrayDeque<Integer>();
        nq.add(root); hq.add(0);
        int minH = 0, maxH = 0;
        while (!nq.isEmpty()) {
            TreeNode node = nq.poll();
            int hd = hq.poll();
            last.put(hd, node.val);
            minH = Math.min(minH, hd);
            maxH = Math.max(maxH, hd);
            if (node.left != null) { nq.add(node.left); hq.add(hd - 1); }
            if (node.right != null) { nq.add(node.right); hq.add(hd + 1); }
        }
        for (int h = minH; h <= maxH; h++) out.add(last.get(h));
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS: keep val for hd when depth >= stored depth (overwrite on tie so right-later wins if you visit right after left).

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
    Map<Integer, Integer> val = new HashMap<Integer, Integer>();
    Map<Integer, Integer> dep = new HashMap<Integer, Integer>();
    int minH, maxH;
    void go(TreeNode node, int hd, int d) {
        if (node == null) return;
        if (!dep.containsKey(hd) || d >= dep.get(hd)) {
            dep.put(hd, d);
            val.put(hd, node.val);
        }
        minH = Math.min(minH, hd);
        maxH = Math.max(maxH, hd);
        go(node.left, hd - 1, d + 1);
        go(node.right, hd + 1, d + 1);
    }
    public List<Integer> bottomView(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        minH = 0; maxH = 0;
        go(root, 0, 0);
        for (int h = minH; h <= maxH; h++) out.add(val.get(h));
        return out;
    }
}
