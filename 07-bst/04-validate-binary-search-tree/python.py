# Method 1: Brute
# Time: O(n) | Space: O(n)
# Inorder dump all values, then check each pair is strictly increasing. Extra array holds the whole walk.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def is_valid_bst(root):
    vals = []
    def go(node):
        if node is None:
            return
        go(node.left)
        vals.append(node.val)
        go(node.right)
    go(root)
    for i in range(1, len(vals)):
        if vals[i] <= vals[i - 1]:
            return False
    return True


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Each node must lie in (lo, hi). Left child inherits hi = node.val; right inherits lo = node.val. Use a type wider than int so INT_MIN / INT_MAX are legal node values.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def is_valid_bst(root):
    def ok(node, lo, hi):
        if node is None:
            return True
        if node.val <= lo or node.val >= hi:
            return False
        return ok(node.left, lo, node.val) and ok(node.right, node.val, hi)
    return ok(root, float("-inf"), float("inf"))


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Iterative inorder. Track the previous value. If the current node is not greater, the tree is invalid. No extra value array.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def is_valid_bst(root):
    stack = []
    cur = root
    prev = None
    while cur is not None or stack:
        while cur is not None:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        if prev is not None and cur.val <= prev:
            return False
        prev = cur.val
        cur = cur.right
    return True
