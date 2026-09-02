# Method 1: Brute
# Time: O(n) | Space: O(n)
# Walk from head. The first node already in the Set is the start of the cycle. If you reach null, there is no cycle.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def detectCycle(head):
    seen = set()
    cur = head
    while cur:
        if (cur in seen):
            return cur
        seen.add(cur)
        cur = cur.next
    return None


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Floyd finds a node inside the cycle. Walk that loop once into a Set. Then walk from head until you hit a node in the set. Extra memory is the cycle length.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def detectCycle(head):
    slow = head
    fast = head
    meet = None
    while fast  and  fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            meet = slow
            break
    if not meet:
        return None
    inCycle = set()
    p = meet
    while True:
        inCycle.add(p)
        p = p.next
        if not (p != meet):
            break
    q = head
    while not (q in inCycle):
        q = q.next
    return q


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# After slow and fast meet, put one pointer at head. Walk both one step at a time. They meet at the cycle start. Proof: distance from head to start equals distance from meet to start around the loop. No extra set.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def detectCycle(head):
    slow = head
    fast = head
    while fast  and  fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            p = head
            while p != slow:
                p = p.next
                slow = slow.next
            return p
    return None
