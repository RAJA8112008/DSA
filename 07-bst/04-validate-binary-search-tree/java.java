// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump all values, then check each pair is strictly increasing. Extra array holds the whole walk.

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
        List<Integer> vals = new ArrayList<Integer>();
        go(root, vals);
        for (int i = 1; i < vals.size(); i++) {
            if (vals.get(i) <= vals.get(i - 1)) return false;
        }
        return true;
    }
    void go(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        go(node.left, vals);
        vals.add(node.val);
        go(node.right, vals);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (lo, hi). Left child inherits hi = node.val; right inherits lo = node.val. Use a type wider than int so INT_MIN / INT_MAX are legal node values.

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
        return ok(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
    boolean ok(TreeNode node, long lo, long hi) {
        if (node == null) return true;
        if (node.val <= lo || node.val >= hi) return false;
        return ok(node.left, lo, node.val) && ok(node.right, node.val, hi);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. Track the previous value. If the current node is not greater, the tree is invalid. No extra value array.

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
        Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
        TreeNode cur = root;
        Integer prev = null;
        while (cur != null || !stack.isEmpty()) {
            while (cur != null) {
                stack.push(cur);
                cur = cur.left;
            }
            cur = stack.pop();
            if (prev != null && cur.val <= prev) return false;
            prev = cur.val;
            cur = cur.right;
        }
        return true;
    }
}
