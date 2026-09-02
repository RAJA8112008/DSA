// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node recompute both heights and recurse isBalanced on children. Height work repeats on the same nodes.

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
    private boolean isBalanced_height(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(isBalanced_height(node.left), isBalanced_height(node.right));
    }

    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        if (Math.abs(isBalanced_height(root.left) - isBalanced_height(root.right)) > 1) {
            return false;
        }
        return isBalanced(root.left) && isBalanced(root.right);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder returns height. If a child is already unbalanced or |lh-rh|>1, return -1 and bubble up. One visit per node.

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
    private boolean isBalanced_walk(TreeNode node) {
        if (node == null) {
            return 0;
        }
        TreeNode lh = isBalanced_walk(node.left);
        if (lh < 0) {
            return -1;
        }
        TreeNode rh = isBalanced_walk(node.right);
        if (rh < 0) {
            return -1;
        }
        if (Math.abs(lh - rh) > 1) {
            return -1;
        }
        return 1 + Math.max(lh, rh);
    }

    public boolean isBalanced(TreeNode root) {
        return isBalanced_walk(root) >= 0;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder with a height map. After both children, check |lh-rh| and store height. No recursion.

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
    public boolean isBalanced(TreeNode root) {
        if (root == null) {
            return true;
        }
        List<TreeNode> stack = new ArrayList<>(); stack.add(root);
        Map<TreeNode, Integer> height = new HashMap<>();
        height.put(null, 0);
        while (!stack.isEmpty()) {
            TreeNode node = stack.get(stack.size()-1);
            if (node.left != null && !height.contains(node.left)) {
                stack.add(node.left);
                continue;
            }
            if (node.right != null && !height.contains(node.right)) {
                stack.add(node.right);
                continue;
            }
            stack.remove(stack.size()-1);
            TreeNode lh = height.get(node.left) || 0;
            TreeNode rh = height.get(node.right) || 0;
            if (Math.abs(lh - rh) > 1) {
                return false;
            }
            height.put(node, 1 + Math.max(lh, rh));
        }
        return true;
    }
}
