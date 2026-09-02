# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Push values, sort the array, write them back onto the existing nodes. Extra array. Does not show list merge sort.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def sortList(head):
    vals = []
    cur = head
    while cur:
        vals.append(cur.val)
        cur = cur.next
    vals.sort()
    cur = head
    i = 0
    while cur:
        cur.val = vals[i]
        i += 1
        cur = cur.next
    return head


# Method 2: Optimal
# Time: O(n log n) | Space: O(log n)
# Top-down merge sort. Slow/fast splits the list, recurse both halves, merge sorted chains. Stack is O(log n) for balanced splits.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def sortList(head):
    if not head  or  not head.next:
        return head
    slow = head
    fast = head.next
    while fast  and  fast.next:
        slow = slow.next
        fast = fast.next.next
    mid = slow.next
    slow.next = None
    return merge(sortList(head), sortList(mid))
def merge(a, b):
    dummy = ListNode(0)
    tail = dummy
    while a  and  b:
        if a.val < b.val:
            tail.next = a
            a = a.next
        else:
            tail.next = b
            b = b.next
        tail = tail.next
    tail.next = a  or  b
    return dummy.next


# Method 3: More optimal
# Time: O(n log n) | Space: O(1)
# Bottom-up merge sort. Count n, then merge adjacent runs of size step, doubling step. split cuts a run. merge hangs the merged pair after prev. No recursion stack.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def sortList(head):
    if not head  or  not head.next:
        return head
    n = 0
    p = head
    while p:
        n += 1
        p = p.next
    dummy = ListNode(0, head)
    def split(start, len):
        p = start
        i = 1
        while p  and  i < len:
            p = p.next
            i += 1
        if not p:
            return None
        rest = p.next
        p.next = None
        return rest
    def merge(prev, a, b):
        tail = prev
        while a  and  b:
            if a.val < b.val:
                tail.next = a
                a = a.next
            else:
                tail.next = b
                b = b.next
            tail = tail.next
        tail.next = a  or  b
        while tail.next:
            tail = tail.next
        return tail
    step = 1
    while step < n:
        prev = dummy
        cur = dummy.next
        while cur:
            left = cur
            right = split(left, step)
            cur = split(right, step)
            prev = merge(prev, left, right)
        step *= 2
    return dummy.next
