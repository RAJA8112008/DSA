// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push every node into an array, then return the node at floor(length/2). Extra array of pointers.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        List<ListNode> nodes = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            nodes.add(cur);
            cur = cur.next;
        }
        return nodes[(nodes.size() / 2)];
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive slow/fast: if fast cannot take two steps, slow is the middle. Stack depth is O(n).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private ListNode middleNode_walk(int slow, int fast) {
        if (fast == null || fast.next == null) {
            return slow;
        }
        return middleNode_walk(slow.next, fast.next.next);
    }

    public ListNode middleNode(ListNode head) {
        return middleNode_walk(head, head);
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative tortoise and hare. When fast falls off, slow is the second middle on even length. Constant extra space.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        return slow;
    }
}
