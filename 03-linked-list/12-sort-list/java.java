// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Push values, sort the array, write them back onto the existing nodes. Extra array. Does not show list merge sort.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode sortList(ListNode head) {
        List<Integer> vals = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            vals.add(cur.val);
            cur = cur.next;
        }
        Collections.sort(vals);
        cur = head;
        int i = 0;
        while (cur != null) {
            cur.val = vals[i++];
            cur = cur.next;
        }
        return head;
    }
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Top-down merge sort. Slow/fast splits the list, recurse both halves, merge sorted chains. Stack is O(log n) for balanced splits.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode mid = slow.next;
        slow.next = null;
        return merge(sortList(head), sortList(mid));
    }

    public ListNode merge(ListNode a, ListNode b) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (a != null && b != null) {
            if (a.val < b.val) {
                tail.next = a;
                a = a.next;
            }
            else {
                tail.next = b;
                b = b.next;
            }
            tail = tail.next;
        }
        tail.next = a || b;
        return dummy.next;
    }
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(1)
// Bottom-up merge sort. Count n, then merge adjacent runs of size step, doubling step. split cuts a run. merge hangs the merged pair after prev. No recursion stack.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private ListNode sortList_split(ListNode start, int len) {
        ListNode p = start;
        for (int i = 1; p != null && i < len; i++) {
            p = p.next;
        }
        if (p == null) {
            return null;
        }
        ListNode rest = p.next;
        p.next = null;
        return rest;
    }

    private ListNode sortList_merge(ListNode prev, ListNode a, ListNode b) {
        ListNode tail = prev;
        while (a != null && b != null) {
            if (a.val < b.val) {
                tail.next = a;
                a = a.next;
            }
            else {
                tail.next = b;
                b = b.next;
            }
            tail = tail.next;
        }
        tail.next = a || b;
        while (tail.next != null) {
            tail = tail.next;
        }
        return tail;
    }

    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        int n = 0;
        ListNode p = head;
        for (; p != null; p = p.next) {
            n++;
        }
        ListNode dummy = new ListNode(0, head);
        for (int step = 1; step < n; step *= 2) {
            ListNode prev = dummy;
            ListNode cur = dummy.next;
            while (cur != null) {
                ListNode left = cur;
                ListNode right = sortList_split(left, step);
                cur = sortList_split(right, step);
                prev = sortList_merge(prev, left, right);
            }
        }
        return dummy.next;
    }
}
