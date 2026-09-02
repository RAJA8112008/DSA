# Method 1: Brute
# Time: O(n·m) | Space: O(1)
# For each node in A, walk all of B looking for the same object. No extra set. Quadratic time.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def getIntersectionNode(headA, headB):
    a = headA
    while a:
        b = headB
        while b:
            if a == b:
                return a
            b = b.next
        a = a.next
    return None


# Method 2: Optimal
# Time: O(n+m) | Space: O(n)
# Put every node of A in a Set. Walk B; the first node in the set is the intersection. Linear time, extra memory for A.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def getIntersectionNode(headA, headB):
    seen = set()
    a = headA
    while a:
        seen.add(a)
        a = a.next
    b = headB
    while b:
        if (b in seen):
            return b
        b = b.next
    return None


# Method 3: More optimal
# Time: O(n+m) | Space: O(1)
# Pointer a walks A then B. Pointer b walks B then A. They travel the same total length and meet at the first shared node, or both hit null. No set.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def getIntersectionNode(headA, headB):
    a = headA
    b = headB
    while a != b:
        a = (a.next if a else headB)
        b = (b.next if b else headA)
    return a
