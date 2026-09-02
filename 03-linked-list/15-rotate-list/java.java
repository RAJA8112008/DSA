// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, rotate the array with splice/concat or new indexes, rebuild. Extra array.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {
            return head;
        }
        List<Integer> vals = new ArrayList<>();
        ListNode p = head;
        for (; p != null; p = p.next) {
            vals.add(p.val);
        }
        k = k % vals.size();
        int rotated = new ArrayList<>(vals.subList(vals.size() - k).concat(new ArrayList<>(vals.subList(0, vals.size(, vals.size()))) - k));
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (var v : rotated) {
            tail.next = new ListNode(v);
            tail = tail.next;
        }
        return dummy.next;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive helper finds length and the tail, then a second walk cuts at n-k. Stack for the first walk is O(n). Same idea as counting, with recursion instead of a loop for length.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private int rotateRight_count(ListNode node) {
        if (node == null) {
            return;
        }
        box_n++;
        box_tail = node;
        rotateRight_count(node.next);
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        int box_n = 0;
        ListNode box_tail = null;
        rotateRight_count(head);
        k = k % box_n;
        if (k == 0) {
            return head;
        }
        int steps = box.n - k;
        ListNode cur = head;
        for (int i = 1; i < steps; i++) {
            cur = cur.next;
        }
        ListNode newHead = cur.next;
        cur.next = null;
        box_tail.next = head;
        return newHead;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Find tail and n in one walk, close the ring, walk n - k % n steps from head, cut. Constant extra space, one extra pass after the count.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }
        int n = 1;
        ListNode tail = head;
        while (tail.next != null) {
            tail = tail.next;
            n++;
        }
        k = k % n;
        if (k == 0) {
            return head;
        }
        tail.next = head;
        int steps = n - k;
        ListNode newTail = head;
        for (int i = 1; i < steps; i++) {
            newTail = newTail.next;
        }
        ListNode newHead = newTail.next;
        newTail.next = null;
        return newHead;
    }
}
