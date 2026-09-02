// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Keep an array of visited nodes. For each new node, scan the array for the same object. Correct, but the scan makes it quadratic.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public boolean hasCycle(ListNode head) {
        List<ListNode> seen = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            for (int i = 0; i < seen.size(); i++) {
                if (seen[i] == cur) {
                    return true;
                }
            }
            seen.add(cur);
            cur = cur.next;
        }
        return false;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A Set stores nodes you already walked. Add is O(1) on average. First repeat means a cycle. Extra memory equals the number of distinct nodes before a repeat.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public boolean hasCycle(ListNode head) {
        Set<ListNode> seen = new HashSet<>();
        ListNode cur = head;
        while (cur != null) {
            if (seen.contains(cur)) {
                return true;
            }
            seen.add(cur);
            cur = cur.next;
        }
        return false;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Floyd: slow +1, fast +2. No set. If they meet, there is a cycle. If fast hits null, there is not. Constant extra pointers.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
}
