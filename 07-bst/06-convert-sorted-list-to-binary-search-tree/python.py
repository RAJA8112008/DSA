# Method 1: Brute
# Time: O(n) | Space: O(n)
# Walk the list into an array, then build from mid indices. Extra O(n) memory for the copy.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def sorted_list_to_bst(head):
    nums = []
    while head:
        nums.append(head.val)
        head = head.next
    def build(lo, hi):
        if lo > hi:
            return None
        mid = (lo + hi) // 2
        node = TreeNode(nums[mid])
        node.left = build(lo, mid - 1)
        node.right = build(mid + 1, hi)
        return node
    return build(0, len(nums) - 1)


# Method 2: Optimal
# Time: O(n log n) | Space: O(log n)
# Slow/fast finds the mid. Cut prev.next so the left half is a shorter list. Recurse on left half, mid node, and right half. No array, but each level rescans the list.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def sorted_list_to_bst(head):
    if head is None:
        return None
    if head.next is None:
        return TreeNode(head.val)
    prev = None
    slow = head
    fast = head
    while fast and fast.next:
        prev = slow
        slow = slow.next
        fast = fast.next.next
    prev.next = None
    node = TreeNode(slow.val)
    node.left = sorted_list_to_bst(head)
    node.right = sorted_list_to_bst(slow.next)
    return node


# Method 3: More optimal
# Time: O(n) | Space: O(log n)
# Count n. Inorder-build: recurse left of size n/2, consume the current list node as the root, then recurse right. The list pointer only moves forward. Each node is visited once.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
def sorted_list_to_bst(head):
    n = 0
    cur = head
    while cur:
        n += 1
        cur = cur.next
    cur = head
    def build(count):
        nonlocal cur
        if count <= 0:
            return None
        left = build((count - 1) // 2)
        node = TreeNode(cur.val)
        cur = cur.next
        node.left = left
        node.right = build(count // 2)
        return node
    return build(n)
