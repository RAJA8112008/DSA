# Method 1: Brute
# Time: O(n) | Space: O(n)
# Build undirected graph on values (unique). BFS from start. Answer is the max distance.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def amount_of_time(root, start):
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
    seen = {start}
    q = deque([(start, 0)])
    best = 0
    while q:
        u, d = q.popleft()
        best = max(best, d)
        for v in g[u]:
            if v not in seen:
                seen.add(v)
                q.append((v, d + 1))
    return best


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Parent pointers, BFS from the start node (find it first). Minutes = max distance.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def amount_of_time(root, start):
    from collections import deque
    parent = {}
    src = [None]
    def mark(node, p):
        if node is None:
            return
        parent[node] = p
        if node.val == start:
            src[0] = node
        mark(node.left, node)
        mark(node.right, node)
    mark(root, None)
    seen = {src[0]}
    q = deque([(src[0], 0)])
    best = 0
    while q:
        node, d = q.popleft()
        best = max(best, d)
        for nx in (node.left, node.right, parent.get(node)):
            if nx is not None and nx not in seen:
                seen.add(nx)
                q.append((nx, d + 1))
    return best


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# DFS returns height of the subtree. When the start node is found, ans is max(height below, distance going up through the parent). One traversal, no graph.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def amount_of_time(root, start):
    ans = [0]
    def dfs(node):
        if node is None:
            return 0
        left = dfs(node.left)
        right = dfs(node.right)
        if node.val == start:
            ans[0] = max(ans[0], left, right)
            return -1
        if left < 0:
            ans[0] = max(ans[0], right - left)
            return left - 1
        if right < 0:
            ans[0] = max(ans[0], left - right)
            return right - 1
        return 1 + max(left, right)
    dfs(root)
    return ans[0]
