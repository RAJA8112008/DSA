# Method 1: Brute
# Time: O(n) | Space: O(n)
# Copy every value into an array, reverse the array, then build a brand new list. Easy to see, but it allocates n extra nodes and ignores that you can flip next in place.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def reverseList(head):
    vals = []
    cur = head
    while cur:
        vals.append(cur.val)
        cur = cur.next
    vals.reverse()
    dummy = ListNode(0)
    tail = dummy
    for v in vals:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recurse to the end, then set head.next.next = head and cut head.next. The call stack holds every node, so space is O(n). Clear picture of 'suffix first'.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def reverseList(head):
    if not head  or  not head.next:
        return head
    newHead = reverseList(head.next)
    head.next.next = head
    head.next = None
    return newHead


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Iterative three-pointer reverse. Each node is visited once. Extra memory is a few names, not the stack and not a new list. This is the usual interview target.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def reverseList(head):
    prev = None
    cur = head
    while cur:
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    return prev
