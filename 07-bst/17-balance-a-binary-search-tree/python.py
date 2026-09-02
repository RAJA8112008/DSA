# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Inorder keys, then insert in sorted order into a fresh BST. That rebuilds a stick. Shows why you must pick mids, not insert in order.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def balance_bst(root):
    keys = []
    def go(node):
        if node is None:
            return
        go(node.left)
        keys.append(node.val)
        go(node.right)
    go(root)
    def insert(node, val):
        if node is None:
            return TreeNode(val)
        if val < node.val:
            node.left = insert(node.left, val)
        else:
            node.right = insert(node.right, val)
        return node
    out = None
    for val in keys:
        out = insert(out, val)
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Inorder into an array, then mid-as-root rebuild. Height is log n. Extra array of keys (or of nodes if you reuse them).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def balance_bst(root):
    nodes = []
    def go(node):
        if node is None:
            return
        go(node.left)
        nodes.append(node)
        go(node.right)
    go(root)
    def build(lo, hi):
        if lo > hi:
            return None
        mid = (lo + hi) // 2
        node = nodes[mid]
        node.left = build(lo, mid - 1)
        node.right = build(mid + 1, hi)
        return node
    return build(0, len(nodes) - 1)


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# DSW: rotate every left child to the right to make a vine (linked list of right pointers). Then repeatedly rotate the vine to fold it into a balanced tree. In-place, O(1) extra besides recursion-free loops.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def balance_bst(root):
    dummy = TreeNode(0)
    dummy.right = root
    def vine():
        tail = dummy
        rest = dummy.right
        n = 0
        while rest:
            if rest.left:
                old = rest
                rest = rest.left
                old.left = rest.right
                rest.right = old
                tail.right = rest
            else:
                tail = rest
                rest = rest.right
                n += 1
        return n
    def compress(count):
        parent = dummy
        for _ in range(count):
            child = parent.right
            parent.right = child.right
            child.right = parent.right.left
            parent.right.left = child
            parent = parent.right
    n = vine()
    m = 1
    while m * 2 + 1 <= n:
        m = m * 2 + 1
    compress(n - m)
    m //= 2
    while m >= 1:
        compress(m)
        m //= 2
    return dummy.right
