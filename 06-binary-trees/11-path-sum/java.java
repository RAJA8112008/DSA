// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records every root-to-leaf path as an array, sums each, compares to target. Extra storage for all paths.

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
    private boolean hasPathSum_go(TreeNode node, List<Integer> path) {
        if (node == null) {
            return;
        }
        path.add(node.val);
        if (node.left == null && node.right == null) {
            int s = 0;
            for (var v : path) {
                s += v;
            }
            sums.add(s);
        }
        hasPathSum_go(node.left, path);
        hasPathSum_go(node.right, path);
        path.remove(path.size()-1);
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        List<Integer> sums = new ArrayList<>();
        hasPathSum_go(root, []);
        return sums.contains(targetSum);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse with remaining. At a leaf, remaining === node.val. Else try left or right with remaining - val.

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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }
        if (root.left == null && root.right == null) {
            return root.val == targetSum;
        }
        TreeNode rest = targetSum - root.val;
        return (hasPathSum(root.left, rest) != null ? hasPathSum(root.left, rest) : hasPathSum(root.right, rest));
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of node plus remaining sum. Same check at leaves. No recursion.

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
    public boolean hasPathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return false;
        }
        List<Item> stack = new ArrayList<>(); stack.add(new Item([{ node: root, left: targetSum }]));
        while (!stack.isEmpty()) {
            TreeNode __it = stack.remove(stack.size()-1);
var node = __it.node; var left = __it.left;
            if (node.left == null && node.right == null && node.val == left) {
                return true;
            }
            if (node.left != null) {
                stack.add({ node: node.left, left: left - node.val });
            }
            if (node.right != null) {
                stack.add({ node: node.right, left: left - node.val });
            }
        }
        return false;
    }
}
