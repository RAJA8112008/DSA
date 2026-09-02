# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# DFS push [col, row, val]. Sort by col, then row, then val. Group into lists. Matches LeetCode 987.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def vertical_traversal(root):
    items = []
    def go(node, row, col):
        if node is None:
            return
        items.append((col, row, node.val))
        go(node.left, row + 1, col - 1)
        go(node.right, row + 1, col + 1)
    go(root, 0, 0)
    items.sort()
    out = []
    prev = None
    for col, row, val in items:
        if prev != col:
            out.append([])
            prev = col
        out[-1].append(val)
    return out


# Method 2: Optimal
# Time: O(n log w) | Space: O(n)
# BFS so row order is natural. TreeMap / sorted map of columns. GFG order (no value sort). w is the number of columns.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def vertical_order(root):
    if root is None:
        return []
    from collections import deque, defaultdict
    cols = defaultdict(list)
    min_h = max_h = 0
    q = deque([(root, 0)])
    while q:
        node, hd = q.popleft()
        cols[hd].append(node.val)
        min_h = min(min_h, hd)
        max_h = max(max_h, hd)
        if node.left:
            q.append((node.left, hd - 1))
        if node.right:
            q.append((node.right, hd + 1))
    return [cols[h] for h in range(min_h, max_h + 1)]


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Same BFS. Record min and max hd, then emit columns in a plain loop. No log w map.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def vertical_order(root):
    if root is None:
        return []
    nodes = [root]
    hds = [0]
    min_h = max_h = 0
    i = 0
    while i < len(nodes):
        node, hd = nodes[i], hds[i]
        min_h = min(min_h, hd)
        max_h = max(max_h, hd)
        if node.left:
            nodes.append(node.left)
            hds.append(hd - 1)
        if node.right:
            nodes.append(node.right)
            hds.append(hd + 1)
        i += 1
    out = [[] for _ in range(max_h - min_h + 1)]
    for node, hd in zip(nodes, hds):
        out[hd - min_h].append(node.val)
    return out
