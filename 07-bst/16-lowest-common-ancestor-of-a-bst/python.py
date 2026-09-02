# Method 1: Brute
# Time: O(n) | Space: O(n)
# Treat it as a binary tree: recurse. If both sides return a node, this is LCA. If one side does, that node is LCA. Ignores ordering.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowest_common_ancestor(root, p, q):
    if root is None or root is p or root is q:
        return root
    left = lowest_common_ancestor(root.left, p, q)
    right = lowest_common_ancestor(root.right, p, q)
    if left and right:
        return root
    return left if left else right


# Method 2: Optimal
# Time: O(h) | Space: O(h)
# If both values are less than root, recurse left. Both greater, recurse right. Else root is the split point.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowest_common_ancestor(root, p, q):
    if p.val < root.val and q.val < root.val:
        return lowest_common_ancestor(root.left, p, q)
    if p.val > root.val and q.val > root.val:
        return lowest_common_ancestor(root.right, p, q)
    return root


# Method 3: More optimal
# Time: O(h) | Space: O(1)
# Same split rule in a loop. No recursion. Walk until p and q sit on different sides (or one equals the node).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowest_common_ancestor(root, p, q):
    cur = root
    while cur:
        if p.val < cur.val and q.val < cur.val:
            cur = cur.left
        elif p.val > cur.val and q.val > cur.val:
            cur = cur.right
        else:
            return cur
    return None
