// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk and push a value only when it differs from the last kept one, then rebuild. Extra array of uniques.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        List<Integer> vals = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            if (vals.size() == 0 || vals.get(vals.size()-1) != cur.val) {
                vals.add(cur.val);
            }
            cur = cur.next;
        }
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        for (var v : vals) {
            tail.next = new ListNode(v);
            tail = tail.next;
        }
        return dummy.next;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse on head.next first. If the next node has the same val, skip it. Stack is O(n).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        head.next = deleteDuplicates(head.next);
        if (head.next != null && head.next.val == head.val) {
            return head.next;
        }
        return head;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pointer. While the next node duplicates, skip it. Then advance. In-place, constant extra space.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode cur = head;
        while (cur != null && cur.next != null) {
            if (cur.val == cur.next.val) {
                cur.next = cur.next.next;
            }
            else {
                cur = cur.next;
            }
        }
        return head;
    }
}
