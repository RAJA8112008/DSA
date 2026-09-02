# Method 1: Brute
# Time: O(n) | Space: O(n)
# Inorder dump every key except key, then rebuild a balanced BST from the sorted list. Simple, but you throw away the original shape.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def delete_node(root, key):
    keys = []
    def go(node):
        if node is None:
            return
        if node.val != key:
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
# Time: O(h) | Space: O(h)
# Recurse to the node. Leaf or one child: return the other child. Two children: copy leftmost of right into node.val, then delete that successor from the right subtree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def delete_node(root, key):
    if root is None:
        return None
    if key < root.val:
        root.left = delete_node(root.left, key)
    elif key > root.val:
        root.right = delete_node(root.right, key)
    else:
        if root.left is None:
            return root.right
        if root.right is None:
            return root.left
        succ = root.right
        while succ.left:
            succ = succ.left
        root.val = succ.val
        root.right = delete_node(root.right, succ.val)
    return root


# Method 3: More optimal
# Time: O(h) | Space: O(1)
# Iterative search with a parent pointer. Splice zero/one-child nodes directly. For two children, copy the successor value then unlink the successor (it has no left child).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def delete_node(root, key):
    def splice(parent, node, child):
        if parent is None:
            return child
        if parent.left is node:
            parent.left = child
        else:
            parent.right = child
        return root
    parent = None
    cur = root
    while cur is not None and cur.val != key:
        parent = cur
        cur = cur.left if key < cur.val else cur.right
    if cur is None:
        return root
    if cur.left is None:
        return splice(parent, cur, cur.right)
    if cur.right is None:
        return splice(parent, cur, cur.left)
    sp = cur
    succ = cur.right
    while succ.left:
        sp = succ
        succ = succ.left
    cur.val = succ.val
    if sp.left is succ:
        sp.left = succ.right
    else:
        sp.right = succ.right
    return root
