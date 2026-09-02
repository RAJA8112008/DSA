// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode each tree as a preorder array with N for null, then compare the arrays. Extra strings/arrays for both trees.

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
    private boolean isSameTree_enc(TreeNode node, List<String> out) {
        if (node == null) {
            out.add("N");
            return;
        }
        out.add(String.valueOf(node.val));
        isSameTree_enc(node.left, out);
        isSameTree_enc(node.right, out);
    }

    public boolean isSameTree(TreeNode p, TreeNode q) {
        List<TreeNode> a = new ArrayList<>();
        List<TreeNode> b = new ArrayList<>();
        isSameTree_enc(p, a);
        isSameTree_enc(q, b);
        if (a.size() != b.size()) {
            return false;
        }
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If both null, true. If one null or vals differ, false. Else both lefts and both rights. Stack O(h).

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) {
            return true;
        }
        if (p == null || q == null || p.val != q.val) {
            return false;
        }
        return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative: stack of pairs. Pop two nodes, check null/val, push children pairs. Same complexity, no recursion.

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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        List<TreeNode[]> stack = new ArrayList<>();
        while (!stack.isEmpty()) {
            int pair = stack.remove(stack.size()-1);
            TreeNode a = pair[0];
            TreeNode b = pair[1];
            if (a == null && b == null) {
                continue;
            }
            if (a == null || b == null || a.val != b.val) {
                return false;
            }
            stack.add([a.left, b.left]);
            stack.add([a.right, b.right]);
        }
        return true;
    }
}
