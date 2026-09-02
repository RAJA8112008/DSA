# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Store every node in inorder, copy values, sort the copy, write sorted values back. Structure is unchanged; you sort instead of finding the pair.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def recover_tree(root):
    nodes = []
    def go(node):
        if node is None:
            return
        go(node.left)
        nodes.append(node)
        go(node.right)
    go(root)
    vals = sorted(n.val for n in nodes)
    for i, node in enumerate(nodes):
        node.val = vals[i]


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Inorder with a prev pointer. first is the previous node at the first drop. second is the current node at every drop (so adjacent swaps still work). Swap first.val and second.val.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def recover_tree(root):
    first = second = prev = None
    def go(node):
        nonlocal first, second, prev
        if node is None:
            return
        go(node.left)
        if prev and prev.val > node.val:
            if first is None:
                first = prev
            second = node
        prev = node
        go(node.right)
    go(root)
    first.val, second.val = second.val, first.val


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Morris inorder with the same first/second logic. Thread and unthread predecessor links so you do not keep a stack.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def recover_tree(root):
    first = second = prev = None
    cur = root
    def visit(node):
        nonlocal first, second, prev
        if prev and prev.val > node.val:
            if first is None:
                first = prev
            second = node
        prev = node
    while cur:
        if cur.left is None:
            visit(cur)
            cur = cur.right
        else:
            pred = cur.left
            while pred.right and pred.right is not cur:
                pred = pred.right
            if pred.right is None:
                pred.right = cur
                cur = cur.left
            else:
                pred.right = None
                visit(cur)
                cur = cur.right
    first.val, second.val = second.val, first.val
