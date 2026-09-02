# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Collect (hd, depth, index, val), sort, keep the last per hd.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def bottom_view(root):
    items = []
    idx = [0]
    def go(node, hd, d):
        if node is None:
            return
        items.append((hd, d, idx[0], node.val))
        idx[0] += 1
        go(node.left, hd - 1, d + 1)
        go(node.right, hd + 1, d + 1)
    go(root, 0, 0)
    items.sort()
    out = []
    for i, it in enumerate(items):
        if i + 1 == len(items) or items[i][0] != items[i + 1][0]:
            out.append(it[3])
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# BFS overwrite per hd. Last write is the deepest (or the right one on a tie). Emit min..max.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def bottom_view(root):
    if root is None:
        return []
    from collections import deque
    last = {}
    min_h = max_h = 0
    q = deque([(root, 0)])
    while q:
        node, hd = q.popleft()
        last[hd] = node.val
        min_h = min(min_h, hd)
        max_h = max(max_h, hd)
        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))
    return [last[h] for h in range(min_h, max_h + 1)]


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# DFS: keep val for hd when depth >= stored depth (overwrite on tie so right-later wins if you visit right after left).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def bottom_view(root):
    if root is None:
        return []
    val, dep = {}, {}
    min_h = max_h = 0
    def go(node, hd, d):
        nonlocal min_h, max_h
        if node is None:
            return
        if hd not in dep or d >= dep[hd]:
            dep[hd] = d
            val[hd] = node.val
        min_h = min(min_h, hd)
        max_h = max(max_h, hd)
        go(node.left, hd - 1, d + 1)
        go(node.right, hd + 1, d + 1)
    go(root, 0, 0)
    return [val[h] for h in range(min_h, max_h + 1)]
