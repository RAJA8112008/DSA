# Method 1: Brute
# Time: O(n) | Space: O(n)
# For every node, sum the two children (0 if null) and compare. Recurse both sides. Extra list of all nodes first.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def is_sum_tree(root):
    nodes = []
    def go(node):
        if node is None:
            return
        nodes.append(node)
        go(node.left)
        go(node.right)
    go(root)
    for n in nodes:
        if n.left is None and n.right is None:
            continue
        left = n.left.val if n.left else 0
        right = n.right.val if n.right else 0
        if n.val != left + right:
            return False
    return True


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Postorder boolean. Null and leaves are true. Then check val == left+right and both subtrees hold.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def is_sum_tree(root):
    if root is None:
        return True
    if root.left is None and root.right is None:
        return True
    left = root.left.val if root.left else 0
    right = root.right.val if root.right else 0
    return root.val == left + right and is_sum_tree(root.left) and is_sum_tree(root.right)


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Return a pair (ok, val) so a failed subtree aborts. Same checks, one value returned upward.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def is_sum_tree(root):
    def go(node):
        if node is None:
            return True, 0
        if node.left is None and node.right is None:
            return True, node.val
        lok, lv = go(node.left)
        rok, rv = go(node.right)
        ok = lok and rok and node.val == lv + rv
        return ok, node.val
    ok, _ = go(root)
    return ok
