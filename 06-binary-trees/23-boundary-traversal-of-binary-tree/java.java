// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect all nodes with (isLeft, isRight, isLeaf). Then emit left bound, leaves, reverse right bound, skipping duplicates via a seen set.

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
    boolean isLeaf(TreeNode n) { return n != null && n.left == null && n.right == null; }
    void go(TreeNode node, boolean onLeft, boolean onRight, List<Integer> leftB, List<Integer> rightB, List<Integer> leaves) {
        if (node == null) return;
        if (isLeaf(node)) { leaves.add(node.val); return; }
        if (onLeft) leftB.add(node.val);
        else if (onRight) rightB.add(node.val);
        go(node.left, onLeft, onRight && node.right == null, leftB, rightB, leaves);
        go(node.right, onLeft && node.left == null, onRight, leftB, rightB, leaves);
    }
    public List<Integer> boundaryTraversal(TreeNode root) {
        List<Integer> leftB = new ArrayList<Integer>(), rightB = new ArrayList<Integer>(), leaves = new ArrayList<Integer>();
        if (root == null) return leftB;
        if (!isLeaf(root)) leftB.add(root.val);
        go(root.left, true, false, leftB, rightB, leaves);
        go(root.right, false, true, leftB, rightB, leaves);
        if (isLeaf(root)) leaves.add(root.val);
        Collections.reverse(rightB);
        leftB.addAll(leaves);
        leftB.addAll(rightB);
        return leftB;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Three passes: left edge (stop before a leaf), all leaves, right edge into a stack then pop. Clear and classic interview split.

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
    boolean isLeaf(TreeNode n) { return n.left == null && n.right == null; }
    void leaves(TreeNode node, List<Integer> out) {
        if (node == null) return;
        if (isLeaf(node)) { out.add(node.val); return; }
        leaves(node.left, out);
        leaves(node.right, out);
    }
    public List<Integer> boundaryTraversal(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        if (!isLeaf(root)) out.add(root.val);
        TreeNode cur = root.left;
        while (cur != null) {
            if (!isLeaf(cur)) out.add(cur.val);
            cur = cur.left != null ? cur.left : cur.right;
        }
        leaves(root, out);
        List<Integer> right = new ArrayList<Integer>();
        cur = root.right;
        while (cur != null) {
            if (!isLeaf(cur)) right.add(cur.val);
            cur = cur.right != null ? cur.right : cur.left;
        }
        for (int i = right.size() - 1; i >= 0; i--) out.add(right.get(i));
        return out;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// One DFS. Pass whether this node is on the left bound, right bound, or a leaf. Append left-bound before children, leaves in the middle, right-bound after children (so they reverse themselves).

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
    boolean isLeaf(TreeNode n) { return n.left == null && n.right == null; }
    void go(TreeNode node, boolean leftB, boolean rightB, List<Integer> out) {
        if (node == null) return;
        if (isLeaf(node) || leftB) out.add(node.val);
        go(node.left, leftB, rightB && node.right == null, out);
        go(node.right, leftB && node.left == null, rightB, out);
        if (rightB && !isLeaf(node) && !leftB) out.add(node.val);
    }
    public List<Integer> boundaryTraversal(TreeNode root) {
        List<Integer> out = new ArrayList<Integer>();
        if (root == null) return out;
        if (isLeaf(root)) { out.add(root.val); return out; }
        out.add(root.val);
        go(root.left, true, false, out);
        go(root.right, false, true, out);
        return out;
    }
}
