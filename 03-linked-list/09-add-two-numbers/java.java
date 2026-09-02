// Method 1: Brute
// Time: O(n+m) | Space: O(n+m)
// Turn each list into a BigInt (least-significant digit first), add, then emit digits into a new list. Easy in JavaScript, hides the carry logic interviewers want.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private int addTwoNumbers_toBig(ListNode node) {
        int n = 0L;
        int place = 1L;
        while (node != null) {
            n += node.val * place;
            place *= 10L;
            node = node.next;
        }
        return n;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int sum = addTwoNumbers_toBig(l1) + addTwoNumbers_toBig(l2);
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        if (sum == 0L) {
            return dummy;
        }
        while (sum > 0L) {
            tail.next = new ListNode(Integer.parseInt(sum % 10L));
            tail = tail.next;
            sum /= 10L;
        }
        return dummy.next;
    }
}


// Method 2: Optimal
// Time: O(max(n,m)) | Space: O(max(n,m))
// Recursive add of two nodes plus carry. Next call gets the rest of both lists. Stack depth follows the longer number.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    private ListNode addTwoNumbers_add(ListNode a, ListNode b, int carry) {
        if (a == null && b == null && carry == 0) {
            return null;
        }
        int sum = (a ? a.val : 0) + (b ? b.val : 0) + carry;
        ListNode node = new ListNode(sum % 10);
        node.next = addTwoNumbers_add(a ? a.next : null, b ? b.next : null, (sum / 10));
        return node;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return addTwoNumbers_add(l1, l2, 0);
    }
}


// Method 3: More optimal
// Time: O(max(n,m)) | Space: O(1)
// Iterative dummy. Each step sums two digits and carry, writes sum % 10, carry becomes floor(sum/10). Extra node if carry remains. Output list is required; extra pointers are constant.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        int carry = 0;
        while (l1 != null || l2 != null || carry) {
            int sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
            tail.next = new ListNode(sum % 10);
            tail = tail.next;
            carry = (sum / 10);
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
        }
        return dummy.next;
    }
}
