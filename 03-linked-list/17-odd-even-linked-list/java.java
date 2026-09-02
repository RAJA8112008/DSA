// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push odd-position nodes, then even-position nodes, into arrays. Relink in that order. Extra arrays.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode oddEvenList(ListNode head) {
        List<ListNode> odds = new ArrayList<>();
        List<ListNode> evens = new ArrayList<>();
        ListNode cur = head;
        int i = 1;
        while (cur != null) {
            if (i % 2 == 1) {
                odds.add(cur);
            }
            else {
                evens.add(cur);
            }
            cur = cur.next;
            i++;
        }
        int nodes = concat(odds, evens);
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
// Recursive rewire: odd.next = even.next, even.next = that node's next, then recurse. Attach evenHead when even runs out. Stack O(n).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private ListNode oddEvenList_go(int odd, int even) {
        if (even == null || even.next == null) {
            odd.next = evenHead;
            return;
        }
        odd.next = even.next;
        even.next = odd.next.next;
        oddEvenList_go(odd.next, even.next);
    }

    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode evenHead = head.next;
        oddEvenList_go(head, evenHead);
        return head;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// odd and even pointers. odd.next = odd.next.next, even.next = even.next.next, until even is exhausted. odd.next = evenHead. In-place, constant extra space.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode oddEvenList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode odd = head;
        ListNode even = head.next;
        ListNode evenHead = even;
        while (even != null && even.next != null) {
            odd.next = even.next;
            odd = odd.next;
            even.next = odd.next;
            even = even.next;
        }
        odd.next = evenHead;
        return head;
    }
}
