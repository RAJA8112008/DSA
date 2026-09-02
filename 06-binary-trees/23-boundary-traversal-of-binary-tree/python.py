# Method 1: Brute
# Time: O(n) | Space: O(n)
# Collect all nodes with (isLeft, isRight, isLeaf). Then emit left bound, leaves, reverse right bound, skipping duplicates via a seen set.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def boundary_traversal(root):
    if root is None:
        return []
    left_b, right_b, leaves = [], [], []
    def is_leaf(n):
        return n is not None and n.left is None and n.right is None
    def go(node, on_left, on_right):
        if node is None:
            return
        if is_leaf(node):
            leaves.append(node.val)
            return
        if on_left:
            left_b.append(node.val)
        elif on_right:
            right_b.append(node.val)
        go(node.left, on_left, on_right and node.right is None)
        go(node.right, on_left and node.left is None, on_right)
    if not is_leaf(root):
        left_b.append(root.val)
    go(root.left, True, False)
    go(root.right, False, True)
    if is_leaf(root):
        leaves.append(root.val)
    right_b.reverse()
    return left_b + leaves + right_b


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Three passes: left edge (stop before a leaf), all leaves, right edge into a stack then pop. Clear and classic interview split.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def boundary_traversal(root):
    if root is None:
        return []
    def is_leaf(n):
        return n.left is None and n.right is None
    out = []
    if not is_leaf(root):
        out.append(root.val)
    cur = root.left
    while cur:
        if not is_leaf(cur):
            out.append(cur.val)
        cur = cur.left if cur.left else cur.right
    def leaves(node):
        if node is None:
            return
        if is_leaf(node):
            out.append(node.val)
            return
        leaves(node.left)
        leaves(node.right)
    leaves(root)
    right = []
    cur = root.right
    while cur:
        if not is_leaf(cur):
            right.append(cur.val)
        cur = cur.right if cur.right else cur.left
    while right:
        out.append(right.pop())
    return out


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# One DFS. Pass whether this node is on the left bound, right bound, or a leaf. Append left-bound before children, leaves in the middle, right-bound after children (so they reverse themselves).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def boundary_traversal(root):
    if root is None:
        return []
    def is_leaf(n):
        return n.left is None and n.right is None
    out = []
    def go(node, left_b, right_b):
        if node is None:
            return
        if is_leaf(node) or left_b:
            out.append(node.val)
        go(node.left, left_b, right_b and node.right is None)
        go(node.right, left_b and node.left is None, right_b)
        if right_b and not is_leaf(node) and not left_b:
            out.append(node.val)
    if is_leaf(root):
        return [root.val]
    out.append(root.val)
    go(root.left, True, False)
    go(root.right, False, True)
    return out
