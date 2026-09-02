# Method 1: Brute
# Time: O(n) | Space: O(n)
# Collect every key, append val, sort, and rebuild a balanced tree from the middle. Extra arrays; you never use the existing shape.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def insert_into_bst(root, val):
    keys = []
    def go(node):
        if node is None:
            return
        keys.append(node.val)
        go(node.left)
        go(node.right)
    go(root)
    keys.append(val)
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
# Time: O(h) | Space: O(h)
# Recurse left or right and assign the returned child. When the child is null, allocate the new leaf. Root is returned unchanged unless the tree was empty.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def insert_into_bst(root, val):
    if root is None:
        return TreeNode(val)
    if val < root.val:
        root.left = insert_into_bst(root.left, val)
    else:
        root.right = insert_into_bst(root.right, val)
    return root


# Method 3: More optimal
# Time: O(h) | Space: O(1)
# Iterative: if the tree is empty, return a new root. Else walk until the next child is null and attach there. No recursion.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def insert_into_bst(root, val):
    fresh = TreeNode(val)
    if root is None:
        return fresh
    cur = root
    while True:
        if val < cur.val:
            if cur.left is None:
                cur.left = fresh
                break
            cur = cur.left
        else:
            if cur.right is None:
                cur.right = fresh
                break
            cur = cur.right
    return root
