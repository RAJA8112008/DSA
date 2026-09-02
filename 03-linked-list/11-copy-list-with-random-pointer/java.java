// Method 1: Brute
// Time: O(n) | Space: O(n)
// First pass: clone every node into a Map, next and random left null. Second pass: wire next and random through the map. Two walks, extra map of n nodes.

import java.util.*;

class Node {
    int val;
    Node next;
    Node random;
    Node(int val) { this.val = val; }
    Node(int val, Node next, Node random) {
        this.val = val; this.next = next; this.random = random;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        Map<Node, Node> map = new HashMap<>();
        Node cur = head;
        while (cur != null) {
            map.put(cur, new Node(cur.val));
            cur = cur.next;
        }
        cur = head;
        while (cur != null) {
            Node copy = map.get(cur);
            copy.next = cur.next ? map.get(cur.next) : null;
            copy.random = cur.random ? map.get(cur.random) : null;
            cur = cur.next;
        }
        return head ? map.get(head) : null;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One recursive walk with a Map. If the node is already cloned, return it (handles random cycles). Otherwise clone, then fill next and random. Still O(n) extra map plus stack.

import java.util.*;

class Node {
    int val;
    Node next;
    Node random;
    Node(int val) { this.val = val; }
    Node(int val, Node next, Node random) {
        this.val = val; this.next = next; this.random = random;
    }
}

class Solution {
    private Node copyRandomList_copy(Node node) {
        if (node == null) {
            return null;
        }
        if (map.contains(node)) {
            return map.get(node);
        }
        Node cloned = new Node(node.val);
        map.put(node, cloned);
        cloned.next = copyRandomList_copy(node.next);
        cloned.random = copyRandomList_copy(node.random);
        return cloned;
    }

    public Node copyRandomList(Node head) {
        Map<Node, Node> map = new HashMap<>();
        return copyRandomList_copy(head);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Weave: original -> copy -> original.next. Set copy.random from original.random.next. Unweave into two lists. Extra space is the copies themselves, no hash map. (O(1) auxiliary.)

import java.util.*;

class Node {
    int val;
    Node next;
    Node random;
    Node(int val) { this.val = val; }
    Node(int val, Node next, Node random) {
        this.val = val; this.next = next; this.random = random;
    }
}

class Solution {
    public Node copyRandomList(Node head) {
        if (head == null) {
            return null;
        }
        Node cur = head;
        while (cur != null) {
            Node copy = new Node(cur.val, cur.next, null);
            cur.next = copy;
            cur = copy.next;
        }
        cur = head;
        while (cur != null) {
            if (cur.random != null) {
                cur.next.random = cur.random.next;
            }
            cur = cur.next.next;
        }
        Node newHead = head.next;
        cur = head;
        while (cur != null) {
            Node copy = cur.next;
            cur.next = copy.next;
            copy.next = copy.next ? copy.next.next : null;
            cur = cur.next;
        }
        return newHead;
    }
}
