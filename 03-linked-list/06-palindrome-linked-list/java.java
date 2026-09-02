// Method 1: Brute
// Time: O(n) | Space: O(n)
// Dump values into an array. Check index i against length-1-i. Extra memory is the array.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> vals = new ArrayList<>();
        ListNode cur = head;
        while (cur != null) {
            vals.add(cur.val);
            cur = cur.next;
        }
        int i = 0;
        int j = vals.size() - 1;
        while (i < j) {
            if (vals[i] != vals[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse to the tail. A shared front pointer walks forward as the stack walks back. First mismatch fails. Stack is O(n).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private boolean isPalindrome_go(ListNode node) {
        if (node == null) {
            return;
        }
        isPalindrome_go(node.next);
        if (node.val != box.front.val) {
            box_ok = false;
        }
        box_front = box_front.next;
    }

    public boolean isPalindrome(ListNode head) {
        ListNode box_front = head;
        boolean box_ok = true;
        isPalindrome_go(head);
        return box.ok;
    }
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Slow/fast to the mid, reverse the second half, compare first half with reversed half. Only a few pointers. Mutates the list; reverse again if you must restore.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode prev = null;
        ListNode cur = slow;
        while (cur != null) {
            ListNode next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        ListNode a = head;
        ListNode b = prev;
        while (b != null) {
            if (a.val != b.val) {
                return false;
            }
            a = a.next;
            b = b.next;
        }
        return true;
    }
}
