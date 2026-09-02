// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full inorder into an array, return vals[k-1]. Always walks the whole tree.

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
    private int kthSmallest_inorder(TreeNode node) {
        if (node == null) {
            return;
        }
        kthSmallest_inorder(node.left);
        vals.add(node.val);
        kthSmallest_inorder(node.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        List<Integer> vals = new ArrayList<>();
        kthSmallest_inorder(root);
        return vals[k - 1];
    }
}


// Method 2: Optimal
// Time: O(h+k) | Space: O(h)
// Recursive inorder with a counter. When count hits k, record val and stop expanding. Better when k is small.

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
    private int kthSmallest_go(TreeNode node) {
        if (node == null || box.count >= k) {
            return;
        }
        kthSmallest_go(node.left);
        box_count++;
        if (box.count == k) {
            box_ans = node.val;
            return;
        }
        kthSmallest_go(node.right);
    }

    public int kthSmallest(TreeNode root, int k) {
        int box_count = 0;
        int box_ans = 0;
        kthSmallest_go(root);
        return box.ans;
    }
}


// Method 3: More optimal
// Time: O(h+k) | Space: O(h)
// Iterative inorder. Each pop is the next smallest. After k pops, return that val. Easy to stop early; no extra values array.

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
    public int kthSmallest(TreeNode root, int k) {
        List<TreeNode> stack = new ArrayList<>();
        TreeNode cur = root;
        while (true) {
            while (cur != null) {
                stack.add(cur);
                cur = cur.left;
            }
            cur = stack.remove(stack.size()-1);
            k--;
            if (k == 0) {
                return cur.val;
            }
            cur = cur.right;
        }
    }
}
