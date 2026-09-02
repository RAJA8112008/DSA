// Method 1: Brute
// Time: O(n) | Space: O(n)
// Store every node in an array. Remove index length-n, then relink the remaining nodes in order. Extra array of pointers.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        List<ListNode> nodes = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            nodes.add(cur);
            cur = cur.next;
        }
        nodes.splice(nodes.size() - n, 1);
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
// Recursive walk to the end, counting on the way back. When the counter hits n, skip that node from the parent. Stack is O(n).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private ListNode removeNthFromEnd_go(ListNode node) {
        if (node == null) {
            return 0;
        }
        ListNode fromEnd = removeNthFromEnd_go(node.next) + 1;
        if (fromEnd == n + 1) {
            node.next = node.next.next;
        }
        return fromEnd;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        removeNthFromEnd_go(dummy);
        return dummy.next;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy head. Fast walks n+1 steps so the gap is n nodes. Then slow and fast move together. When fast is null, slow sits before the victim. Unlink and return dummy.next. One pass, constant extra space.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(0, head);
        ListNode fast = dummy;
        ListNode slow = dummy;
        for (int i = 0; i < n + 1; i++) {
            fast = fast.next;
        }
        while (fast != null) {
            fast = fast.next;
            slow = slow.next;
        }
        slow.next = slow.next.next;
        return dummy.next;
    }
}
