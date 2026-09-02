# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Collect every (hd, depth, val), sort, keep the first (smallest depth) per hd.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def top_view(root):
    items = []
    def go(node, hd, d):
        if node is None:
            return
        items.append((hd, d, node.val))
        go(node.left, hd - 1, d + 1)
        go(node.right, hd + 1, d + 1)
    go(root, 0, 0)
    items.sort()
    out, prev = [], None
    for hd, d, val in items:
        if prev != hd:
            out.append(val)
            prev = hd
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# BFS. The first time an hd appears, record it. Then emit from min hd to max hd.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def top_view(root):
    if root is None:
        return []
    from collections import deque
    first = {}
    min_h = max_h = 0
    q = deque([(root, 0)])
    while q:
        node, hd = q.popleft()
        if hd not in first:
            first[hd] = node.val
        min_h = min(min_h, hd)
        max_h = max(max_h, hd)
        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))
    return [first[h] for h in range(min_h, max_h + 1)]


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# DFS with depth. Keep a node for hd only if this depth is smaller. Then scan min..max hd. No queue.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def top_view(root):
    best_val, best_d = {}, {}
    min_h = max_h = 0
    def go(node, hd, d):
        nonlocal min_h, max_h
        if node is None:
            return
        if hd not in best_d or d < best_d[hd]:
            best_d[hd] = d
            best_val[hd] = node.val
        min_h = min(min_h, hd)
        max_h = max(max_h, hd)
        go(node.left, hd - 1, d + 1)
        go(node.right, hd + 1, d + 1)
    go(root, 0, 0)
    return [best_val[h] for h in range(min_h, max_h + 1)] if root else []
