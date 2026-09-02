# Method 1: Brute
# Time: O(n) | Space: O(n)
# Full level-order lists, then pick the first value of each list.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def left_view(root):
    if root is None:
        return []
    from collections import deque
    levels = []
    q = deque([root])
    while q:
        row = []
        for _ in range(len(q)):
            node = q.popleft()
            row.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        levels.append(row)
    return [row[0] for row in levels]


# Method 2: Optimal
# Time: O(n) | Space: O(w)
# BFS. When i == 0 in the level loop, that node is the left view. w is the widest level.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def left_view(root):
    if root is None:
        return []
    from collections import deque
    out = []
    q = deque([root])
    while q:
        n = len(q)
        for i in range(n):
            node = q.popleft()
            if i == 0:
                out.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    return out


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# DFS left-first. If depth == out.length this is the first node at that depth. Recursion stack only.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def left_view(root):
    out = []
    def go(node, d):
        if node is None:
            return
        if d == len(out):
            out.append(node.val)
        go(node.left, d + 1)
        go(node.right, d + 1)
    go(root, 0)
    return out
