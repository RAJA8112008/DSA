# Method 1: Brute
# Time: O(n) | Space: O(n)
# Push odd-position nodes, then even-position nodes, into arrays. Relink in that order. Extra arrays.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def oddEvenList(head):
    odds = []
    evens = []
    cur = head
    i = 1
    while cur:
        if i % 2 == 1:
            odds.append(cur)
        else:
            evens.append(cur)
        cur = cur.next
        i += 1
    nodes = (odds + evens)
    dummy = ListNode(0)
    tail = dummy
    for node in nodes:
        tail.next = node
        tail = tail.next
    tail.next = None
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recursive rewire: odd.next = even.next, even.next = that node's next, then recurse. Attach evenHead when even runs out. Stack O(n).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def oddEvenList(head):
    if not head  or  not head.next:
        return head
    evenHead = head.next
    def go(odd, even):
        if not even  or  not even.next:
            odd.next = evenHead
            return
        odd.next = even.next
        even.next = odd.next.next
        go(odd.next, even.next)
    go(head, evenHead)
    return head


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# odd and even pointers. odd.next = odd.next.next, even.next = even.next.next, until even is exhausted. odd.next = evenHead. In-place, constant extra space.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def oddEvenList(head):
    if not head  or  not head.next:
        return head
    odd = head
    even = head.next
    evenHead = even
    while even  and  even.next:
        odd.next = even.next
        odd = odd.next
        even.next = odd.next
        even = even.next
    odd.next = evenHead
    return head
