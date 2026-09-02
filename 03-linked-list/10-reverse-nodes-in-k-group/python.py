# Method 1: Brute
# Time: O(n) | Space: O(n)
# Copy values, reverse each complete window of k in the array, rebuild a new list. Extra array and new nodes.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def reverseKGroup(head, k):
    vals = []
    p = head
    while p:
        vals.append(p.val)
        p = p.next
    i = 0
    while i + k <= len(vals):
        l = i
        r = i + k - 1
        while l < r:
            t = vals[l]
            vals[l] = vals[r]
            vals[r] = t
            l += 1
            r -= 1
        i += k
    dummy = ListNode(0)
    tail = dummy
    for v in vals:
        tail.next = ListNode(v)
        tail = tail.next
    return dummy.next


# Method 2: Optimal
# Time: O(n) | Space: O(n/k)
# If fewer than k nodes remain, return head. Else reverse the first k, then set the old head's next to reverseKGroup of the leftover. Recursion depth is number of groups.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def reverseKGroup(head, k):
    n = 0
    p = head
    while p  and  n < k:
        p = p.next
        n += 1
    if n < k:
        return head
    prev = None
    cur = head
    for i in range(k):
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    head.next = reverseKGroup(cur, k)
    return prev


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Dummy before head. For each group, reverse k nodes between groupPrev and groupNext, then slide groupPrev. No recursion. Constant extra pointers.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def reverseKGroup(head, k):
    dummy = ListNode(0, head)
    groupPrev = dummy
    def kth(start, k):
        n = start
        for i in range(k):
            if not n:
                return None
            n = n.next
        return n
    while True:
        groupLast = kth(groupPrev, k)
        if not groupLast:
            break
        groupNext = groupLast.next
        prev = groupNext
        cur = groupPrev.next
        while cur != groupNext:
            next = cur.next
            cur.next = prev
            prev = cur
            cur = next
        newGroupStart = groupPrev.next
        groupPrev.next = groupLast
        groupPrev = newGroupStart
    return dummy.next
