// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect nodes, swap each pair of indexes, relink in that order. Extra array.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode swapPairs(ListNode head) {
        List<ListNode> nodes = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            nodes.add(cur);
            cur = cur.next;
        }
        for (int i = 0; i + 1 < nodes.size(); i += 2) {
            int t = nodes[i];
            nodes[i] = nodes[i + 1];
            nodes[i + 1] = t;
        }
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (var node : nodes) {
            tail.next = node;
            tail = tail.next;
        }
        tail.next = null;
        return dummy.next;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// If fewer than two nodes, return head. Else first = head, second = head.next, first.next = swapPairs(second.next), second.next = first, return second. Stack O(n/2).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode first = head;
        ListNode second = head.next;
        first.next = swapPairs(second.next);
        second.next = first;
        return second;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. prev, a, b: prev.next = b, a.next = b.next, b.next = a, then prev = a. Iterative, constant extra space.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0, head);
        ListNode prev = dummy;
        while (prev.next != null && prev.next.next != null) {
            ListNode a = prev.next;
            ListNode b = a.next;
            prev.next = b;
            a.next = b.next;
            b.next = a;
            prev = a;
        }
        return dummy.next;
    }
}
