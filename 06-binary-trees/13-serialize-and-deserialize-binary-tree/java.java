// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON.stringify the nested {val,left,right} object and JSON.parse it back. Works for this node shape, hides the codec you are supposed to write, and is bulky.

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
    public String serialize(TreeNode root) {
        return stringify(root);
    }

    public TreeNode deserialize(String data) {
        if (data == "null") {
            return null;
        }
        return parse(data);
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Preorder join with commas, N for null. Deserialize consumes tokens with an index. Recursion rebuilds left then right.

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
    private TreeNode serialize_go(TreeNode node) {
        if (node == null) {
            out.add("N");
            return;
        }
        out.add(String.valueOf(node.val));
        serialize_go(node.left);
        serialize_go(node.right);
    }

    public String serialize(TreeNode root) {
        List<TreeNode> out = new ArrayList<>();
        serialize_go(root);
        return String.join(",", out);
    }

    private TreeNode deserialize_go() {
        int t = toks[i++];
        if (t == "N") {
            return null;
        }
        TreeNode node = new TreeNode(Integer.parseInt(t));
        node.left = deserialize_go();
        node.right = deserialize_go();
        return node;
    }

    public TreeNode deserialize(String data) {
        String toks = data.split(",");
        int i = 0;
        return deserialize_go();
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS codec: queue writes val or N level by level. Deserialize uses a queue of parents and attaches children in order. Iterative, same linear cost, no recurse on serialize/deserialize.

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
    public String serialize(TreeNode root) {
        if (root == null) {
            return "N";
        }
        List<TreeNode> out = new ArrayList<>();
        List<TreeNode> queue = new ArrayList<>(); queue.add(root);
        while (!queue.isEmpty()) {
            TreeNode node = queue.remove(0);
            if (node == null) {
                out.add("N");
                continue;
            }
            out.add(String.valueOf(node.val));
            queue.add(node.left);
            queue.add(node.right);
        }
        return String.join(",", out);
    }

    public TreeNode deserialize(String data) {
        String toks = data.split(",");
        if (toks[0] == "N") {
            return null;
        }
        TreeNode root = new TreeNode(Integer.parseInt(toks[0]));
        List<TreeNode> queue = new ArrayList<>(); queue.add(root);
        int i = 1;
        while (!queue.isEmpty() && i < toks.size()) {
            TreeNode node = queue.remove(0);
            if (toks[i] != "N") {
                node.left = new TreeNode(Integer.parseInt(toks[i]));
                queue.add(node.left);
            }
            i++;
            if (i < toks.size() && toks[i] != "N") {
                node.right = new TreeNode(Integer.parseInt(toks[i]));
                queue.add(node.right);
            }
            i++;
        }
        return root;
    }
}
