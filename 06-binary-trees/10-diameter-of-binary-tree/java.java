// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At every node, diameter candidate is height(left)+height(right). height itself walks the subtree, so nested walks are quadratic on a skewed tree.

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
    private int diameterOfBinaryTree_height(TreeNode node) {
        if (node == null) {
            return 0;
        }
        return 1 + Math.max(diameterOfBinaryTree_height(node.left), diameterOfBinaryTree_height(node.right));
    }

    private int diameterOfBinaryTree_visit(TreeNode node) {
        if (node == null) {
            return;
        }
        TreeNode through = height(node.left) + height(node.right);
        if (through > best) {
            best = through;
        }
        diameterOfBinaryTree_visit(node.left);
        diameterOfBinaryTree_visit(node.right);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        int best = 0;
        diameterOfBinaryTree_visit(root);
        return best;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS returns height. While returning, update best with leftHeight + rightHeight. Each node once.

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
    private int diameterOfBinaryTree_height(TreeNode node) {
        if (node == null) {
            return 0;
        }
        TreeNode lh = diameterOfBinaryTree_height(node.left);
        TreeNode rh = diameterOfBinaryTree_height(node.right);
        if (lh + rh > best) {
            best = lh + rh;
        }
        return 1 + Math.max(lh, rh);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        int best = 0;
        diameterOfBinaryTree_height(root);
        return best;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder. A Map stores height after both children are done. Update diameter from those heights. No call stack; extra map of n heights.

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
    public int diameterOfBinaryTree(TreeNode root) {
        if (root == null) {
            return 0;
        }
        List<TreeNode> stack = new ArrayList<>(); stack.add(root);
        Set<TreeNode> seen = new HashSet<>();
        Map<TreeNode, Integer> height = new HashMap<>();
        height.put(null, 0);
        int best = 0;
        while (!stack.isEmpty()) {
            TreeNode node = stack.get(stack.size()-1);
            if (node.left != null && !height.contains(node.left) && !seen.contains(node.left)) {
                stack.add(node.left);
                continue;
            }
            if (node.right != null && !height.contains(node.right) && !seen.contains(node.right)) {
                stack.add(node.right);
                continue;
            }
            stack.remove(stack.size()-1);
            seen.add(node);
            TreeNode lh = height.get(node.left) || 0;
            TreeNode rh = height.get(node.right) || 0;
            height.put(node, 1 + Math.max(lh, rh));
            if (lh + rh > best) {
                best = lh + rh;
            }
        }
        return best;
    }
}
