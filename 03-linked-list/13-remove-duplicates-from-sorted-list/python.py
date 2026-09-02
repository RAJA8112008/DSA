# Method 1: Brute
# Time: O(n) | Space: O(n)
# Walk and push a value only when it differs from the last kept one, then rebuild. Extra array of uniques.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def deleteDuplicates(head):
    vals = []
    cur = head
    while cur:
        if len(vals) == 0  or  vals[-1] != cur.val:
            vals.append(cur.val)
        cur = cur.next
    dummy = ListNode(0)
    tail = dummy
    for v in vals:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recurse on head.next first. If the next node has the same val, skip it. Stack is O(n).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def deleteDuplicates(head):
    if not head  or  not head.next:
        return head
    head.next = deleteDuplicates(head.next)
    if head.next  and  head.next.val == head.val:
        return head.next
    return head


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# One pointer. While the next node duplicates, skip it. Then advance. In-place, constant extra space.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def deleteDuplicates(head):
    cur = head
    while cur  and  cur.next:
        if cur.val == cur.next.val:
            cur.next = cur.next.next
        else:
            cur = cur.next
    return head
