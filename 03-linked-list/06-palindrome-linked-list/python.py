# Method 1: Brute
# Time: O(n) | Space: O(n)
# Dump values into an array. Check index i against length-1-i. Extra memory is the array.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def isPalindrome(head):
    vals = []
    cur = head
    while cur:
        vals.append(cur.val)
        cur = cur.next
    i = 0
    j = len(vals) - 1
    while i < j:
        if vals[i] != vals[j]:
            return False
        i += 1
        j -= 1
    return True


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recurse to the tail. A shared front pointer walks forward as the stack walks back. First mismatch fails. Stack is O(n).

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def isPalindrome(head):
    box = {"front": head, "ok": True}
    def go(node):
        if not node:
            return
        go(node.next)
        if node.val != box["front"].val:
            box["ok"] = False
        box["front"] = box["front"].next
    go(head)
    return box["ok"]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Slow/fast to the mid, reverse the second half, compare first half with reversed half. Only a few pointers. Mutates the list; reverse again if you must restore.

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def isPalindrome(head):
    if not head  or  not head.next:
        return True
    slow = head
    fast = head
    while fast  and  fast.next:
        slow = slow.next
        fast = fast.next.next
    prev = None
    cur = slow
    while cur:
        next = cur.next
        cur.next = prev
        prev = cur
        cur = next
    a = head
    b = prev
    while b:
        if a.val != b.val:
            return False
        a = a.next
        b = b.next
    return True
