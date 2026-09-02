# Method 1: Brute
# Time: O(n) | Space: O(n)
# Inorder dump into an array, then check each pair is strictly increasing. Extra O(n) array.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isValidBST(root):
    vals = []
    def inorder(node):
        if not node:
            return
        inorder(node.left)
        vals.append(node.val)
        inorder(node.right)
    inorder(root)
    for i in range(1, len(vals)):
        if vals[i] <= vals[i - 1]:
            return False
    return True


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Each node must lie in (low, high). Left child gets high = node.val. Right child gets low = node.val. Use -Infinity / Infinity at the root. Recursion O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isValidBST(root):
    def ok(node, low, high):
        if not node:
            return True
        if node.val <= low  or  node.val >= high:
            return False
        return ok(node.left, low, node.val)  and  ok(node.right, node.val, high)
    return ok(root, float('-inf'), float('inf'))


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Iterative inorder. prev holds the last visited value. If node.val <= prev, fail. No extra values array.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isValidBST(root):
    stack = []
    cur = root
    prev = float('-inf')
    hasPrev = False
    while cur  or  len(stack):
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        if hasPrev  and  cur.val <= prev:
            return False
        prev = cur.val
        hasPrev = True
        cur = cur.right
    return True
