# Method 1: Brute
# Time: O(n) | Space: O(n)
# DFS records the path to p and the path to q as arrays. Last common entry is the LCA. Extra path storage.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowestCommonAncestor(root, p, q):
    def find(node, target, path):
        if not node:
            return False
        path.append(node)
        if node == target:
            return True
        if find(node.left, target, path)  or  find(node.right, target, path):
            return True
        path.pop()
        return False
    a = []
    b = []
    find(root, p, a)
    find(root, q, b)
    i = 0
    while i < len(a)  and  i < len(b)  and  a[i] == b[i]:
        i += 1
    return a[i - 1]


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# If node is null, p, or q, return node. Recurse left and right. If both sides return non-null, node is LCA. Else return the non-null side. One DFS.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowestCommonAncestor(root, p, q):
    if not root  or  root == p  or  root == q:
        return root
    left = lowestCommonAncestor(root.left, p, q)
    right = lowestCommonAncestor(root.right, p, q)
    if left  and  right:
        return root
    return left  or  right


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Iterative stack builds a parent map. Collect ancestors of p in a Set. Walk q's parent chain until a node is in the set. No recursion; extra map of n parents.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowestCommonAncestor(root, p, q):
    parent = {}
    parent[root] = None
    stack = [root]
    while not (p in parent)  or  not (q in parent):
        node = stack.pop()
        if node.left:
            parent[node.left] = node
            stack.append(node.left)
        if node.right:
            parent[node.right] = node
            stack.append(node.right)
    seen = set()
    cur = p
    while cur:
        seen.add(cur)
        cur = parent.get(cur)
    cur = q
    while not (cur in seen):
        cur = parent.get(cur)
    return cur
