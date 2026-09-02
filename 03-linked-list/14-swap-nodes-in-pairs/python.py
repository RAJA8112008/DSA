# Method 1: Brute
# Time: O(n) | Space: O(n)
# Collect nodes, swap each pair of indexes, relink in that order. Extra array.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def swapPairs(head):
    nodes = []
    cur = head
    while cur:
        nodes.append(cur)
        cur = cur.next
    i = 0
    while i + 1 < len(nodes):
        t = nodes[i]
        nodes[i] = nodes[i + 1]
        nodes[i + 1] = t
        i += 2
    dummy = ListNode(0)
    tail = dummy
    for node in nodes:
        tail.next = node
        tail = tail.next
    tail.next = None
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# If fewer than two nodes, return head. Else first = head, second = head.next, first.next = swapPairs(second.next), second.next = first, return second. Stack O(n/2).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def swapPairs(head):
    if not head  or  not head.next:
        return head
    first = head
    second = head.next
    first.next = swapPairs(second.next)
    second.next = first
    return second


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Dummy before head. prev, a, b: prev.next = b, a.next = b.next, b.next = a, then prev = a. Iterative, constant extra space.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def swapPairs(head):
    dummy = ListNode(0, head)
    prev = dummy
    while prev.next  and  prev.next.next:
        a = prev.next
        b = a.next
        prev.next = b
        a.next = b.next
        b.next = a
        prev = a
    return dummy.next
