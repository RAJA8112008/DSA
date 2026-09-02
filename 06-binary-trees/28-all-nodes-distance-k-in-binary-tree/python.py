# Method 1: Brute
# Time: O(n) | Space: O(n)
# Undirected graph of val->neighbors (vals are unique on LC). BFS from target.val for K steps.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def distance_k(root, target, k):
    from collections import defaultdict, deque
    g = defaultdict(list)
    def build(node):
        if node is None:
            return
        if node.left:
            g[node.val].append(node.left.val)
            g[node.left.val].append(node.val)
            build(node.left)
        if node.right:
            g[node.val].append(node.right.val)
            g[node.right.val].append(node.val)
            build(node.right)
    build(root)
    seen = {target.val}
    q = deque([(target.val, 0)])
    out = []
    while q:
        u, d = q.popleft()
        if d == k:
            out.append(u)
            continue
        for v in g[u]:
            if v not in seen:
                seen.add(v)
                q.append((v, d + 1))
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Parent map from nodes (not values). BFS from the target node with a visited set of pointers. Collect at distance k.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def distance_k(root, target, k):
    from collections import deque
    parent = {}
    def mark(node, p):
        if node is None:
            return
        parent[node] = p
        mark(node.left, node)
        mark(node.right, node)
    mark(root, None)
    seen = {target}
    q = deque([(target, 0)])
    out = []
    while q:
        node, d = q.popleft()
        if d == k:
            out.append(node.val)
            continue
        for nx in (node.left, node.right, parent.get(node)):
            if nx is not None and nx not in seen:
                seen.add(nx)
                q.append((nx, d + 1))
    return out


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# DFS returns distance from this subtree to target, or -1. When a child reports dist, walk the other child at k - dist - 2, and maybe record this node. Downward walk from target collects depth k.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def distance_k(root, target, k):
    out = []
    def collect(node, dist):
        if node is None or dist < 0:
            return
        if dist == 0:
            out.append(node.val)
            return
        collect(node.left, dist - 1)
        collect(node.right, dist - 1)
    def dfs(node):
        if node is None:
            return -1
        if node is target:
            collect(node, k)
            return 0
        left = dfs(node.left)
        if left >= 0:
            if left + 1 == k:
                out.append(node.val)
            else:
                collect(node.right, k - left - 2)
            return left + 1
        right = dfs(node.right)
        if right >= 0:
            if right + 1 == k:
                out.append(node.val)
            else:
                collect(node.left, k - right - 2)
            return right + 1
        return -1
    dfs(root)
    return out
