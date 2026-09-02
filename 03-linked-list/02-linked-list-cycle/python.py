# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Keep an array of visited nodes. For each new node, scan the array for the same object. Correct, but the scan makes it quadratic.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def hasCycle(head):
    seen = []
    cur = head
    while cur:
        for i in range(len(seen)):
            if seen[i] == cur:
                return True
        seen.append(cur)
        cur = cur.next
    return False


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# A Set stores nodes you already walked. Add is O(1) on average. First repeat means a cycle. Extra memory equals the number of distinct nodes before a repeat.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def hasCycle(head):
    seen = set()
    cur = head
    while cur:
        if (cur in seen):
            return True
        seen.add(cur)
        cur = cur.next
    return False


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Floyd: slow +1, fast +2. No set. If they meet, there is a cycle. If fast hits null, there is not. Constant extra pointers.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def hasCycle(head):
    slow = head
    fast = head
    while fast  and  fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False
