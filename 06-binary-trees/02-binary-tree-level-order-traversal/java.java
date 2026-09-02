// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS with a depth argument. Push val into levels[depth], creating the row if needed. Extra recursion stack plus the answer.

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
    private List<List<Integer>> levelOrder_dfs(TreeNode node, int d) {
        if (node == null) {
            return;
        }
        if (!levels[d]) {
            levels[d] = [];
        }
        levels[d].push(node.val);
        levelOrder_dfs(node.left, d + 1);
        levelOrder_dfs(node.right, d + 1);
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<>();
        levelOrder_dfs(root, 0);
        return levels;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS queue. Each node is stored with its depth. Rows grow as depth increases. Extra pair objects on the queue.

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        List<List<Integer>> levels = new ArrayList<>();
        List<Item> queue = new ArrayList<>(); queue.add(new Item([{ node: root, d: 0 }]));
        while (!queue.isEmpty()) {
            var __it = queue.remove(0); var node = __it.node; var d = __it.d;
            if (!levels[d]) {
                levels[d] = [];
            }
            levels[d].push(node.val);
            if (node.left != null) {
                queue.add({ node: node.left, d: d + 1 });
            }
            if (node.right != null) {
                queue.add({ node: node.right, d: d + 1 });
            }
        }
        return levels;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS without storing depth. n = queue.length is the current row size. Process exactly those n nodes, enqueue children for the next row. Cleaner constant factors; still O(width) queue.

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
    public List<List<Integer>> levelOrder(TreeNode root) {
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
        return levels;
    }
}
