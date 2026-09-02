// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Root is preorder[0]. Scan inorder for it, slice left/right arrays, recurse. Slicing and scanning are O(n) per node.

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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        if (preorder.isEmpty()) {
            return null;
        }
        int rootVal = preorder[0];
        TreeNode root = new TreeNode(rootVal);
        TreeNode mid = inorder.indexOf(rootVal);
        root.left = buildTree(new ArrayList<>(preorder.subList(1, mid + 1)), new ArrayList<>(inorder.subList(0, mid)));
        root.right = buildTree(new ArrayList<>(preorder.subList(mid + 1), new ArrayList<>(inorder.subList(mid + 1, inorder.size()))));
        return root;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// HashMap of inorder indexes. Recurse with (preL, preR, inL, inR) bounds. Each node created once; map lookup O(1).

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
    private TreeNode buildTree_build(int preL, int preR, int inL, int inR) {
        if (preL > preR) {
            return null;
        }
        TreeNode root = new TreeNode(preorder[preL]);
        TreeNode mid = idx.get(root.val);
        int leftSize = mid - inL;
        root.left = buildTree_build(preL + 1, preL + leftSize, inL, mid - 1);
        root.right = buildTree_build(preL + leftSize + 1, preR, mid + 1, inR);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> idx = new HashMap<>();
        for (int i = 0; i < inorder.size(); i++) {
            idx.put(inorder[i], i);
        }
        return buildTree_build(0, preorder.size() - 1, 0, inorder.size() - 1);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Advance a preorder index and an inorder index. build(stop) creates a node, builds left until inorder hits this val, then right until stop. No hashmap; O(h) stack only besides the tree.

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
    private TreeNode buildTree_build(int stop) {
        if (p >= preorder.size()) {
            return null;
        }
        if (inorder[i] == stop) {
            i++;
            return null;
        }
        TreeNode root = new TreeNode(preorder[p++]);
        root.left = buildTree_build(root.val);
        root.right = buildTree_build(stop);
        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        TreeNode p = 0;
        int i = 0;
        return buildTree_build();
    }
}
