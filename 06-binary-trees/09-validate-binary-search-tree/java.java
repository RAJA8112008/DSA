// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump into an array, then check each pair is strictly increasing. Extra O(n) array.

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
    private boolean isValidBST_inorder(TreeNode node) {
        if (node == null) {
            return;
        }
        isValidBST_inorder(node.left);
        vals.add(node.val);
        isValidBST_inorder(node.right);
    }

    public boolean isValidBST(TreeNode root) {
        List<Integer> vals = new ArrayList<>();
        isValidBST_inorder(root);
        for (int i = 1; i < vals.size(); i++) {
            if (vals[i] <= vals[i - 1]) {
                return false;
            }
        }
        return true;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (low, high). Left child gets high = node.val. Right child gets low = node.val. Use -Infinity / Infinity at the root. Recursion O(h).

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
    private boolean isValidBST_ok(TreeNode node, int low, int high) {
        if (node == null) {
            return true;
        }
        if (node.val <= low || node.val >= high) {
            return false;
        }
        return isValidBST_ok(node.left, low, node.val) && isValidBST_ok(node.right, node.val, high);
    }

    public boolean isValidBST(TreeNode root) {
        return isValidBST_ok(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. prev holds the last visited value. If node.val <= prev, fail. No extra values array.

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
    public boolean isValidBST(TreeNode root) {
        List<TreeNode> stack = new ArrayList<>();
        TreeNode cur = root;
        TreeNode prev = Integer.MIN_VALUE;
        boolean hasPrev = false;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.add(cur);
                cur = cur.left;
            }
            cur = stack.remove(stack.size()-1);
            if (hasPrev && cur.val <= prev) {
                return false;
            }
            prev = cur.val;
            hasPrev = true;
            cur = cur.right;
        }
        return true;
    }
}
