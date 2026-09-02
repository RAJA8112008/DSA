# Method 1: Brute
# Time: O(n) | Space: O(w)
# BFS. Width of a level is the queue size (actual nodes). Max over levels. Matches GFG's non-null count.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def width_of_binary_tree(root):
    if root is None:
        return 0
    from collections import deque
    best = 0
    q = deque([root])
    while q:
        n = len(q)
        best = max(best, n)
        for _ in range(n):
            node = q.popleft()
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
    return best


# Method 2: Optimal
# Time: O(n) | Space: O(w)
# LeetCode width: BFS with heap indices. Subtract the first index of the level so numbers stay small. Width = last - first + 1.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def width_of_binary_tree(root):
    if root is None:
        return 0
    from collections import deque
    best = 0
    q = deque([(root, 0)])
    while q:
        first = q[0][1]
        last = first
        for _ in range(len(q)):
            node, idx = q.popleft()
            idx -= first
            last = idx
            if node.left:
                q.append((node.left, idx * 2 + 1))
            if node.right:
                q.append((node.right, idx * 2 + 2))
        best = max(best, last + 1)
    return best


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# DFS with (depth, normalized index). Store the first index seen at each depth. Width = idx - first[depth] + 1. Recursion only.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def width_of_binary_tree(root):
    first = {}
    best = [0]
    def go(node, d, idx):
        if node is None:
            return
        if d not in first:
            first[d] = idx
        pos = idx - first[d]
        best[0] = max(best[0], pos + 1)
        go(node.left, d + 1, pos * 2 + 1)
        go(node.right, d + 1, pos * 2 + 2)
    go(root, 0, 0)
    return best[0]
