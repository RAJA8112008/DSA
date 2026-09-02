// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order queue. For each level, node.next = the next polled node, last.next = null.

import java.util.*;

class Node {
    int val;
    Node left;
    Node right;
    Node next;
    Node() {}
    Node(int val) { this.val = val; }
    Node(int val, Node left, Node right, Node next) {
        this.val = val; this.left = left; this.right = right; this.next = next;
    }
}

class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        Queue<Node> q = new ArrayDeque<Node>();
        q.add(root);
        while (!q.isEmpty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node node = q.poll();
                if (i + 1 < n) node.next = q.peek();
                if (node.left != null) q.add(node.left);
                if (node.right != null) q.add(node.right);
            }
        }
        return root;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// On a perfect tree, left.next = right, and right.next = node.next.left. Recurse both children. Uses the next links already set on this level.

import java.util.*;

class Node {
    int val;
    Node left;
    Node right;
    Node next;
    Node() {}
    Node(int val) { this.val = val; }
    Node(int val, Node left, Node right, Node next) {
        this.val = val; this.left = left; this.right = right; this.next = next;
    }
}

class Solution {
    public Node connect(Node root) {
        if (root == null || root.left == null) return root;
        root.left.next = root.right;
        if (root.next != null) root.right.next = root.next.left;
        connect(root.left);
        connect(root.right);
        return root;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative: leftmost starts at root. Walk the level via next. Wire children, then leftmost = leftmost.left. No recursion, no queue.

import java.util.*;

class Node {
    int val;
    Node left;
    Node right;
    Node next;
    Node() {}
    Node(int val) { this.val = val; }
    Node(int val, Node left, Node right, Node next) {
        this.val = val; this.left = left; this.right = right; this.next = next;
    }
}

class Solution {
    public Node connect(Node root) {
        if (root == null) return null;
        Node leftmost = root;
        while (leftmost.left != null) {
            Node cur = leftmost;
            while (cur != null) {
                cur.left.next = cur.right;
                if (cur.next != null) cur.right.next = cur.next.left;
                cur = cur.next;
            }
            leftmost = leftmost.left;
        }
        return root;
    }
}
