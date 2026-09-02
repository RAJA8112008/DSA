# Method 1: Brute
# Time: O(n) | Space: O(n)
# Store every node in an array. Remove index length-n, then relink the remaining nodes in order. Extra array of pointers.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def removeNthFromEnd(head, n):
    nodes = []
    cur = head
    while cur:
        nodes.append(cur)
        cur = cur.next
    del nodes[len(nodes) - n]
    dummy = ListNode(0)
    tail = dummy
    for node in nodes:
        tail.next = node
        tail = tail.next
    tail.next = None
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recursive walk to the end, counting on the way back. When the counter hits n, skip that node from the parent. Stack is O(n).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def removeNthFromEnd(head, n):
    def go(node):
        if not node:
            return 0
        fromEnd = go(node.next) + 1
        if fromEnd == n + 1:
            node.next = node.next.next
        return fromEnd
    dummy = ListNode(0, head)
    go(dummy)
    return dummy.next


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Dummy head. Fast walks n+1 steps so the gap is n nodes. Then slow and fast move together. When fast is null, slow sits before the victim. Unlink and return dummy.next. One pass, constant extra space.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def removeNthFromEnd(head, n):
    dummy = ListNode(0, head)
    fast = dummy
    slow = dummy
    for i in range(n + 1):
        fast = fast.next
    while fast:
        fast = fast.next
        slow = slow.next
    slow.next = slow.next.next
    return dummy.next
