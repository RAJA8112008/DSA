// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records the path to p and the path to q as arrays. Last common entry is the LCA. Extra path storage.

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
    private boolean lowestCommonAncestor_find(TreeNode node, TreeNode target, List<Integer> path) {
        if (node == null) {
            return false;
        }
        path.add(node);
        if (node == target) {
            return true;
        }
        if (lowestCommonAncestor_find(node.left, target, path) != null || lowestCommonAncestor_find(node.right, target, path) != null) {
            return true;
        }
        path.remove(path.size()-1);
        return false;
    }

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        List<TreeNode> a = new ArrayList<>();
        List<TreeNode> b = new ArrayList<>();
        lowestCommonAncestor_find(root, p, a);
        lowestCommonAncestor_find(root, q, b);
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) {
            i++;
        }
        return a[i - 1];
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If node is null, p, or q, return node. Recurse left and right. If both sides return non-null, node is LCA. Else return the non-null side. One DFS.

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
        if (root == null || root == p || root == q) {
            return root;
        }
        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);
        if (left != null && right != null) {
            return root;
        }
        return (left != null ? left : right);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative stack builds a parent map. Collect ancestors of p in a Set. Walk q's parent chain until a node is in the set. No recursion; extra map of n parents.

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
        Map<TreeNode, TreeNode> parent = new HashMap<>();
        parent.put(root, null);
        List<TreeNode> stack = new ArrayList<>(); stack.add(root);
        while (!parent.contains(p) || !parent.contains(q)) {
            TreeNode node = stack.remove(stack.size()-1);
            if (node.left != null) {
                parent.put(node.left, node);
                stack.add(node.left);
            }
            if (node.right != null) {
                parent.put(node.right, node);
                stack.add(node.right);
            }
        }
        Set<TreeNode> seen = new HashSet<>();
        TreeNode cur = p;
        while (cur != null) {
            seen.add(cur);
            cur = parent.get(cur);
        }
        cur = q;
        while (!seen.contains(cur)) {
            cur = parent.get(cur);
        }
        return cur;
    }
}
