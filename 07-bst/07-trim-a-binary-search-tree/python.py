# Method 1: Brute
# Time: O(n) | Space: O(n)
# Gather every in-range key, sort, rebuild a balanced tree. Correct values, but new nodes and a different shape.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def trim_bst(root, low, high):
    keys = []
    def go(node):
        if node is None:
            return
        if low <= node.val <= high:
            keys.append(node.val)
        go(node.left)
        go(node.right)
    go(root)
    keys.sort()
    def build(lo, hi):
        if lo > hi:
            return None
        mid = (lo + hi) // 2
        node = TreeNode(keys[mid])
        node.left = build(lo, mid - 1)
        node.right = build(mid + 1, hi)
        return node
    return build(0, len(keys) - 1)


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Postorder prune using the BST property. Reuse the original nodes. If the root is outside the window, drop it and return one trimmed child.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def trim_bst(root, low, high):
    if root is None:
        return None
    if root.val < low:
        return trim_bst(root.right, low, high)
    if root.val > high:
        return trim_bst(root.left, low, high)
    root.left = trim_bst(root.left, low, high)
    root.right = trim_bst(root.right, low, high)
    return root


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Move the root iteratively until it sits inside [low, high], then recursively trim the two sides. Fewer frames when the original root is far outside the window.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def trim_bst(root, low, high):
    while root is not None and (root.val < low or root.val > high):
        root = root.right if root.val < low else root.left
    if root is None:
        return None
    def trim(node):
        if node is None:
            return None
        if node.val < low:
            return trim(node.right)
        if node.val > high:
            return trim(node.left)
        node.left = trim(node.left)
        node.right = trim(node.right)
        return node
    root.left = trim(root.left)
    root.right = trim(root.right)
    return root
