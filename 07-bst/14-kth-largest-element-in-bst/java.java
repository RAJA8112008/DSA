// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump, then return vals[n - k]. Extra array of every key.

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
    public int kthLargest(TreeNode root, int k) {
        List<Integer> vals = new ArrayList<Integer>();
        go(root, vals);
        return vals.get(vals.size() - k);
    }
    void go(TreeNode node, List<Integer> vals) {
        if (node == null) return;
        go(node.left, vals);
        vals.add(node.val);
        go(node.right, vals);
    }
}


// Method 2: Optimal
// Time: O(h + k) | Space: O(h)
// Reverse inorder. Decrement k at each visit. When k hits 0, that value is the answer. Stop walking.

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
    int kLeft, ans;
    public int kthLargest(TreeNode root, int k) {
        kLeft = k;
        ans = 0;
        go(root);
        return ans;
    }
    void go(TreeNode node) {
        if (node == null || kLeft == 0) return;
        go(node.right);
        if (kLeft == 0) return;
        kLeft--;
        if (kLeft == 0) { ans = node.val; return; }
        go(node.left);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris reverse inorder: thread the successor (leftmost of the right, via left pointers of the right spine). Visit without a stack, stop at k.

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
    public int kthLargest(TreeNode root, int k) {
        TreeNode cur = root;
        while (cur != null) {
            if (cur.right == null) {
                if (--k == 0) return cur.val;
                cur = cur.left;
            } else {
                TreeNode succ = cur.right;
                while (succ.left != null && succ.left != cur) succ = succ.left;
                if (succ.left == null) {
                    succ.left = cur;
                    cur = cur.right;
                } else {
                    succ.left = null;
                    if (--k == 0) return cur.val;
                    cur = cur.left;
                }
            }
        }
        return 0;
    }
}
