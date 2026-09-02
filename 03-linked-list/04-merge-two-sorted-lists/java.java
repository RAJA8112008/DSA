// Method 1: Brute
// Time: O((n+m) log(n+m)) | Space: O(n+m)
// Collect every value, sort the array, rebuild. Simple, but sort is extra work and you throw away the original nodes.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        List<Integer> vals = new ArrayList<>();
        ListNode p = list1;
        for (; p != null; p = p.next) {
            vals.add(p.val);
        }
        ListNode p = list2;
        for (; p != null; p = p.next) {
            vals.add(p.val);
        }
        Collections.sort(vals);
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
// Time: O(n+m) | Space: O(n+m)
// Recurse: the smaller head is the next output node, then merge the rest. Linear comparisons. Stack depth is O(n+m).

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        }
        if (list2 == null) {
            return list1;
        }
        if (list1.val < list2.val) {
            list1.next = mergeTwoLists(list1.next, list2);
            return list1;
        }
        list2.next = mergeTwoLists(list1, list2.next);
        return list2;
    }
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Dummy plus a tail pointer. Each step hangs the smaller remaining node. Leftover chain attaches at the end. Constant extra space besides the output, which reuses input nodes.

import java.util.*;

class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        while (list1 != null && list2 != null) {
            if (list1.val < list2.val) {
                tail.next = list1;
                list1 = list1.next;
            }
            else {
                tail.next = list2;
                list2 = list2.next;
            }
            tail = tail.next;
        }
        tail.next = list1 || list2;
        return dummy.next;
    }
}
