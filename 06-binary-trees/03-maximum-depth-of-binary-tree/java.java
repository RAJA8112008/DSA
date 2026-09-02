// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every root-to-leaf path into arrays, return the longest length. Extra memory for all paths.

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
    private int maxDepth_go(TreeNode node, List<Integer> path) {
        if (node == null) {
            return;
        }
        path.add(node.val);
        if (node.left == null && node.right == null) {
            paths.add(path.size());
        }
        maxDepth_go(node.left, path);
        maxDepth_go(node.right, path);
        path.remove(path.size()-1);
    }

    public int maxDepth(TreeNode root) {
        List<Integer> paths = new ArrayList<>();
        maxDepth_go(root, []);
        return paths.size() ? Collections.max(paths) : 0;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recursive height: null is 0, else 1 + max of children. One visit per node. Stack O(h).

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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of {node, depth}. Track the max depth seen. Same complexity, no engine recursion. BFS would use O(width) instead of O(h).

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
    public int maxDepth(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int best = 0;
        List<Item> stack = new ArrayList<>(); stack.add(new Item([{ node: root, d: 1 }]));
        while (!stack.isEmpty()) {
            TreeNode __it = stack.remove(stack.size()-1);
var node = __it.node; var d = __it.d;
            if (d > best) {
                best = d;
            }
            if (node.left != null) {
                stack.add({ node: node.left, d: d + 1 });
            }
            if (node.right != null) {
                stack.add({ node: node.right, d: d + 1 });
            }
        }
        return best;
    }
}
