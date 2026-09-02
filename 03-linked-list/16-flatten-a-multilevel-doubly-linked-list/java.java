// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS preorder into an array (node, child, next). Then walk the array and set next/prev, clear child. Extra array of every node.

import java.util.*;

class Node {
    int val;
    Node prev;
    Node next;
    Node child;
    Node(int val, Node prev, Node next, Node child) {
        this.val = val; this.prev = prev; this.next = next; this.child = child;
    }
}

class Solution {
    private Node flatten_dfs(Node node) {
        while (node != null) {
            nodes.add(node);
            if (node.child != null) {
                flatten_dfs(node.child);
            }
            node = node.next;
        }
    }

    public Node flatten(Node head) {
        List<Node> nodes = new ArrayList<>();
        flatten_dfs(head);
        for (int i = 0; i < nodes.size(); i++) {
            nodes[i].prev = i == 0 ? null : nodes[i - 1];
            nodes[i].next = i == nodes.size() - 1 ? null : nodes[i + 1];
            nodes[i].child = null;
        }
        return nodes[0] || null;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse: if a node has a child, flatten the child, hang it after the node, find the child's tail, attach the old next. Stack depth follows nesting.

import java.util.*;

class Node {
    int val;
    Node prev;
    Node next;
    Node child;
    Node(int val, Node prev, Node next, Node child) {
        this.val = val; this.prev = prev; this.next = next; this.child = child;
    }
}

class Solution {
    private Node flatten_go(Node node) {
        Node cur = node;
        Node last = node;
        while (cur != null) {
            Node next = cur.next;
            if (cur.child != null) {
                Node childLast = flatten_go(cur.child);
                cur.next = cur.child;
                cur.child.prev = cur;
                cur.child = null;
                if (childLast != null) {
                    childLast.next = next;
                    if (next != null) {
                        next.prev = childLast;
                    }
                    last = childLast;
                }
            }
            else {
                last = cur;
            }
            cur = next;
        }
        return last;
    }

    public Node flatten(Node head) {
        flatten_go(head);
        return head;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Walk with one pointer. On a child, find that child's current tail (no recurse), splice the whole child between cur and cur.next, clear child. Then continue. Auxiliary space O(1).

import java.util.*;

class Node {
    int val;
    Node prev;
    Node next;
    Node child;
    Node(int val, Node prev, Node next, Node child) {
        this.val = val; this.prev = prev; this.next = next; this.child = child;
    }
}

class Solution {
    public Node flatten(Node head) {
        Node cur = head;
        while (cur != null) {
            if (cur.child != null) {
                Node tail = cur.child;
                while (tail.next != null) {
                    tail = tail.next;
                }
                tail.next = cur.next;
                if (cur.next != null) {
                    cur.next.prev = tail;
                }
                cur.next = cur.child;
                cur.child.prev = cur;
                cur.child = null;
            }
            cur = cur.next;
        }
        return head;
    }
}
