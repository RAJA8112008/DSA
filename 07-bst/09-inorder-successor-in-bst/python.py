# Method 1: Brute
# Time: O(n) | Space: O(n)
# Inorder list of nodes, find p, return the next entry. Extra linear memory.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def inorder_successor(root, p):
    nodes = []
    def go(node):
        if node is None:
            return
        go(node.left)
        nodes.append(node)
        go(node.right)
    go(root)
    for i, node in enumerate(nodes):
        if node is p:
            return nodes[i + 1] if i + 1 < len(nodes) else None
    return None


# Method 2: Optimal
# Time: O(h) | Space: O(1)
# Walk from the root. Whenever the current node is greater than p, it is a candidate successor — go left to hunt a closer one. Otherwise go right.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def inorder_successor(root, p):
    succ = None
    cur = root
    while cur:
        if p.val < cur.val:
            succ = cur
            cur = cur.left
        else:
            cur = cur.right
    return succ


# Method 3: More optimal
# Time: O(h) | Space: O(1)
# If p has a right child, successor is leftmost there — O(h) on that spine only. Else fall back to the root walk. Same worst case, often shorter.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def inorder_successor(root, p):
    if p.right:
        n = p.right
        while n.left:
            n = n.left
        return n
    succ = None
    cur = root
    while cur:
        if p.val < cur.val:
            succ = cur
            cur = cur.left
        else:
            cur = cur.right
    return succ
