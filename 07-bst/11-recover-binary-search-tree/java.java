// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Store every node in inorder, copy values, sort the copy, write sorted values back. Structure is unchanged; you sort instead of finding the pair.

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
    public void recoverTree(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<TreeNode>();
        go(root, nodes);
        List<Integer> vals = new ArrayList<Integer>();
        for (TreeNode n : nodes) vals.add(n.val);
        Collections.sort(vals);
        for (int i = 0; i < nodes.size(); i++) nodes.get(i).val = vals.get(i);
    }
    void go(TreeNode node, List<TreeNode> nodes) {
        if (node == null) return;
        go(node.left, nodes);
        nodes.add(node);
        go(node.right, nodes);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder with a prev pointer. first is the previous node at the first drop. second is the current node at every drop (so adjacent swaps still work). Swap first.val and second.val.

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
    TreeNode first, second, prev;
    public void recoverTree(TreeNode root) {
        first = second = prev = null;
        go(root);
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
    void go(TreeNode node) {
        if (node == null) return;
        go(node.left);
        if (prev != null && prev.val > node.val) {
            if (first == null) first = prev;
            second = node;
        }
        prev = node;
        go(node.right);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with the same first/second logic. Thread and unthread predecessor links so you do not keep a stack.

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
    TreeNode first, second, prevN;
    void visit(TreeNode node) {
        if (prevN != null && prevN.val > node.val) {
            if (first == null) first = prevN;
            second = node;
        }
        prevN = node;
    }
    public void recoverTree(TreeNode root) {
        first = second = prevN = null;
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left == null) { visit(cur); cur = cur.right; }
            else {
                TreeNode pred = cur.left;
                while (pred.right != null && pred.right != cur) pred = pred.right;
                if (pred.right == null) { pred.right = cur; cur = cur.left; }
                else { pred.right = null; visit(cur); cur = cur.right; }
            }
        }
        int tmp = first.val;
        first.val = second.val;
        second.val = tmp;
    }
}
