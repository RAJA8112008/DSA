// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order into rows, then map each row to its last value. Extra storage for every node value.

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
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<List<Integer>> levels = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>(); queue.add(root);
        while (!queue.isEmpty()) {
            int n = queue.size();
            List<Integer> row = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.remove(0);
                row.add(node.val);
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
            levels.add(row);
        }
        return levels.stream().map(row -> row.get(row.size()-1)).toList();
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS visit right child first. If depth === ans.length, this is the first node seen at that depth from the right. Recursion O(h).

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
    private List<Integer> rightSideView_dfs(TreeNode node, int d) {
        if (node == null) {
            return;
        }
        if (d == ans.size()) {
            ans.add(node.val);
        }
        rightSideView_dfs(node.right, d + 1);
        rightSideView_dfs(node.left, d + 1);
    }

    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        rightSideView_dfs(root, 0);
        return ans;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(w)
// BFS. For each level of size n, the last shifted node is the right-side value. Only the answer plus the queue, no full row arrays.

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
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<Integer> ans = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>(); queue.add(root);
        while (!queue.isEmpty()) {
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                TreeNode node = queue.remove(0);
                if (i == n - 1) {
                    ans.add(node.val);
                }
                if (node.left != null) {
                    queue.add(node.left);
                }
                if (node.right != null) {
                    queue.add(node.right);
                }
            }
        }
        return ans;
    }
}
