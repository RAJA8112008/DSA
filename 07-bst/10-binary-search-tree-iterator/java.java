// Method 1: Brute
// Time: O(n) init, O(1) next | Space: O(n)
// Flatten inorder into an array at construction. next/hasNext are index moves. Simple, but you pay linear memory before the first call.

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
    List<Integer> vals = new ArrayList<Integer>();
    int i = 0;
    public Solution(TreeNode root) {
        go(root);
    }
    void go(TreeNode node) {
        if (node == null) return;
        go(node.left);
        vals.add(node.val);
        go(node.right);
    }
    public int next() { return vals.get(i++); }
    public boolean hasNext() { return i < vals.size(); }
}


// Method 2: Optimal
// Time: O(h) init, amortized O(1) next | Space: O(h)
// Stack holds the path to the next node. Construction pushes the left spine. next() pops, then pushes the left spine of the right child.

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
    Deque<TreeNode> stack = new ArrayDeque<TreeNode>();
    public Solution(TreeNode root) { pushLeft(root); }
    void pushLeft(TreeNode node) {
        while (node != null) { stack.push(node); node = node.left; }
    }
    public int next() {
        TreeNode node = stack.pop();
        pushLeft(node.right);
        return node.val;
    }
    public boolean hasNext() { return !stack.isEmpty(); }
}


// Method 3: More optimal
// Time: amortized O(1) next | Space: O(1)
// Morris: thread predecessor.right to the current node, walk without a stack. Unthread before yielding so the tree is restored. Extra memory is a handful of pointers.

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
    TreeNode cur;
    public Solution(TreeNode root) { cur = root; }
    public int next() {
        while (cur != null) {
            if (cur.left == null) {
                int val = cur.val;
                cur = cur.right;
                return val;
            }
            TreeNode pred = cur.left;
            while (pred.right != null && pred.right != cur) pred = pred.right;
            if (pred.right == null) {
                pred.right = cur;
                cur = cur.left;
            } else {
                pred.right = null;
                int val = cur.val;
                cur = cur.right;
                return val;
            }
        }
        return 0;
    }
    public boolean hasNext() { return cur != null; }
}
