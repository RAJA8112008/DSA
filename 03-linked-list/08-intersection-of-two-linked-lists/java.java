// Method 1: Brute
// Time: O(n·m) | Space: O(1)
// For each node in A, walk all of B looking for the same object. No extra set. Quadratic time.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        while (a != null) {
            ListNode b = headB;
            while (b != null) {
                if (a == b) {
                    return a;
                }
                b = b.next;
            }
            a = a.next;
        }
        return null;
    }
}


// Method 2: Optimal
// Time: O(n+m) | Space: O(n)
// Put every node of A in a Set. Walk B; the first node in the set is the intersection. Linear time, extra memory for A.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> seen = new HashSet<>();
        ListNode a = headA;
        while (a != null) {
            seen.add(a);
            a = a.next;
        }
        ListNode b = headB;
        while (b != null) {
            if (seen.contains(b)) {
                return b;
            }
            b = b.next;
        }
        return null;
    }
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Pointer a walks A then B. Pointer b walks B then A. They travel the same total length and meet at the first shared node, or both hit null. No set.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode a = headA;
        ListNode b = headB;
        while (a != b) {
            a = a ? a.next : headB;
            b = b ? b.next : headA;
        }
        return a;
    }
}
