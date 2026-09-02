// Method 1: Brute
// Time: O(n) | Space: O(n)
// Preorder collect nodes into an array. Then set each left to null and next.right to the following node. Extra array.

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
    private TreeNode flatten_pre(TreeNode node) {
        if (node == null) {
            return;
        }
        nodes.add(node);
        flatten_pre(node.left);
        flatten_pre(node.right);
    }

    public void flatten(TreeNode root) {
        List<TreeNode> nodes = new ArrayList<>();
        flatten_pre(root);
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].left = null;
            nodes[i].right = i + 1 < nodes.size() ? nodes[i + 1] : null;
        }
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse right, then left, keep a tail pointer of the already flattened suffix. Hang this node in front. Stack O(h).

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
    private TreeNode flatten_go(TreeNode node) {
        if (node == null) {
            return;
        }
        flatten_go(node.right);
        flatten_go(node.left);
        node.right = box_tail;
        node.left = null;
        box_tail = node;
    }

    public void flatten(TreeNode root) {
        TreeNode box_tail = null;
        flatten_go(root);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// While cur exists: if it has a left, find rightmost of left, attach cur.right there, move left to right, clear left. Then cur = cur.right. No extra stack.

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
    public void flatten(TreeNode root) {
        TreeNode cur = root;
        while (cur != null) {
            if (cur.left != null) {
                TreeNode pred = cur.left;
                while (pred.right != null) {
                    pred = pred.right;
                }
                pred.right = cur.right;
                cur.right = cur.left;
                cur.left = null;
            }
            cur = cur.right;
        }
    }
}
