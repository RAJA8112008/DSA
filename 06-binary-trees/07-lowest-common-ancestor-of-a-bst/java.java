// Method 1: Brute
// Time: O(h) | Space: O(h)
// Walk BST paths into two arrays of nodes, then scan from the start until they differ. Extra path arrays.

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
    private TreeNode lowestCommonAncestor_pathTo(TreeNode node, TreeNode target) {
        List<Integer> path = new ArrayList<>();
        TreeNode cur = node;
        while (cur != null) {
            path.add(cur);
            if (cur == target || cur.val == target.val) {
                break;
            }
            cur = target.val < cur.val ? cur.left : cur.right;
        }
        return path;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode a = lowestCommonAncestor_pathTo(root, p);
        TreeNode b = lowestCommonAncestor_pathTo(root, q);
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
        }
        return a[i - 1];
    }
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recursive BST walk. Split point is the LCA. Stack O(h).

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (p.val < root.val && q.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        if (p.val > root.val && q.val > root.val) {
            return lowestCommonAncestor(root.right, p, q);
        }
        return root;
    }
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same split logic in a loop. No recursion. Constant extra space.

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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        TreeNode cur = root;
        while (cur != null) {
            if (p.val < cur.val && q.val < cur.val) {
                cur = cur.left;
            }
            else if (p.val > cur.val && q.val > cur.val) {
                cur = cur.right;
            }
            else {
                return cur;
            }
        }
        return null;
    }
}
