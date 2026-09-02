# Method 1: Brute
# Time: O(n) | Space: O(n)
# Copy values, rotate the array with splice/concat or new indexes, rebuild. Extra array.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def rotateRight(head, k):
    if not head:
        return head
    vals = []
    p = head
    while p:
        vals.append(p.val)
        p = p.next
    k = k % len(vals)
    rotated = vals[len(vals) - k).concat(vals[0:len(vals) - k]:]
    dummy = ListNode(0)
    tail = dummy
    for v in rotated:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recursive helper finds length and the tail, then a second walk cuts at n-k. Stack for the first walk is O(n). Same idea as counting, with recursion instead of a loop for length.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def rotateRight(head, k):
    if not head  or  not head.next:
        return head
    box = {"n": 0, "tail": None}
    def count(node):
        if not node:
            return
        box["n"] += 1
        box["tail"] = node
        count(node.next)
    count(head)
    k = k % box["n"]
    if k == 0:
        return head
    steps = box["n"] - k
    cur = head
    for i in range(1, steps):
        cur = cur.next
    newHead = cur.next
    cur.next = None
    box["tail"].next = head
    return newHead


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Find tail and n in one walk, close the ring, walk n - k % n steps from head, cut. Constant extra space, one extra pass after the count.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def rotateRight(head, k):
    if not head  or  not head.next:
        return head
    n = 1
    tail = head
    while tail.next:
        tail = tail.next
        n += 1
    k = k % n
    if k == 0:
        return head
    tail.next = head
    steps = n - k
    newTail = head
    for i in range(1, steps):
        newTail = newTail.next
    newHead = newTail.next
    newTail.next = None
    return newHead
