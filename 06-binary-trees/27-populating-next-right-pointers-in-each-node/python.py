# Method 1: Brute
# Time: O(n) | Space: O(n)
# Level-order queue. For each level, node.next = the next polled node, last.next = null.

class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
def connect(root):
    if root is None:
        return None
    from collections import deque
    q = deque([root])
    while q:
        n = len(q)
        for i in range(n):
            node = q.popleft()
            if i + 1 < n:
                node.next = q[0]
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    return root


# Method 2: Optimal
# Time: O(n) | Space: O(1)
# On a perfect tree, left.next = right, and right.next = node.next.left. Recurse both children. Uses the next links already set on this level.

class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
def connect(root):
    if root is None or root.left is None:
        return root
    root.left.next = root.right
    if root.next:
        root.right.next = root.next.left
    connect(root.left)
    connect(root.right)
    return root


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Iterative: leftmost starts at root. Walk the level via next. Wire children, then leftmost = leftmost.left. No recursion, no queue.

class Node:
    def __init__(self, val=0, left=None, right=None, next=None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
def connect(root):
    if root is None:
        return None
    leftmost = root
    while leftmost.left:
        cur = leftmost
        while cur:
            cur.left.next = cur.right
            if cur.next:
                cur.right.next = cur.next.left
            cur = cur.next
        leftmost = leftmost.left
    return root
