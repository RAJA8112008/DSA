// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode the left subtree left-to-right with nulls, encode the right subtree right-to-left with nulls, compare. Extra arrays.

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
    private boolean isSymmetric_enc(TreeNode node, boolean leftFirst, List<String> out) {
        if (node == null) {
            out.add("N");
            return;
        }
        out.add(String.valueOf(node.val));
        if (leftFirst) {
            isSymmetric_enc(node.left, true, out);
            isSymmetric_enc(node.right, true, out);
        }
        else {
            isSymmetric_enc(node.right, false, out);
            isSymmetric_enc(node.left, false, out);
        }
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        List<TreeNode> a = new ArrayList<>();
        List<TreeNode> b = new ArrayList<>();
        isSymmetric_enc(root.left, true, a);
        isSymmetric_enc(root.right, false, b);
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
// mirror(a,b): both null ok; one null fail; vals equal and mirror(a.left,b.right) and mirror(a.right,b.left). Recurse from root.left and root.right.

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
    private boolean isSymmetric_mirror(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null || a.val != b.val) {
            return false;
        }
        return isSymmetric_mirror(a.left, b.right) && isSymmetric_mirror(a.right, b.left);
    }

    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        return isSymmetric_mirror(root.left, root.right);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Queue of node pairs. Dequeue a and b, check, enqueue a.left with b.right and a.right with b.left. Iterative mirror test.

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
    public boolean isSymmetric(TreeNode root) {
        if (root == null) {
            return true;
        }
        List<TreeNode> queue = new ArrayList<>(); queue.add(root.left, root.right);
        while (!queue.isEmpty()) {
            TreeNode a = queue.remove(0);
            TreeNode b = queue.remove(0);
            if (a == null && b == null) {
                continue;
            }
            if (a == null || b == null || a.val != b.val) {
                return false;
            }
            queue.add(a.left, b.right);
            queue.add(a.right, b.left);
        }
        return true;
    }
}
