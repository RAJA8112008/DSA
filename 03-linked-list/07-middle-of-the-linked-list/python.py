# Method 1: Brute
# Time: O(n) | Space: O(n)
# Push every node into an array, then return the node at floor(length/2). Extra array of pointers.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def middleNode(head):
    nodes = []
    cur = head
    while cur:
        nodes.append(cur)
        cur = cur.next
    return nodes[(len(nodes) / 2)]


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recursive slow/fast: if fast cannot take two steps, slow is the middle. Stack depth is O(n).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def middleNode(head):
    def walk(slow, fast):
        if not fast  or  not fast.next:
            return slow
        return walk(slow.next, fast.next.next)
    return walk(head, head)


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Iterative tortoise and hare. When fast falls off, slow is the second middle on even length. Constant extra space.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def middleNode(head):
    slow = head
    fast = head
    while fast  and  fast.next:
        slow = slow.next
        fast = fast.next.next
    return slow
