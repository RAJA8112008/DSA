# Method 1: Brute
# Time: O(n) | Space: O(n)
# Ignore the BST. DFS every node into a list, then scan for val. Correct on any binary tree, but you throw away the ordering.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def search_bst(root, val):
    nodes = []
    def go(node):
        if node is None:
            return
        nodes.append(node)
        go(node.left)
        go(node.right)
    go(root)
    for node in nodes:
        if node.val == val:
            return node
    return None


# Method 2: Optimal
# Time: O(h) | Space: O(h)
# Recurse on one child. Each call compares val with the node and drops a whole subtree. Stack depth is the height.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def search_bst(root, val):
    if root is None or root.val == val:
        return root
    if val < root.val:
        return search_bst(root.left, val)
    return search_bst(root.right, val)


# Method 3: More optimal
# Time: O(h) | Space: O(1)
# Same comparisons in a while loop. No call stack. Returns the node or null when the walk falls off.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def search_bst(root, val):
    cur = root
    while cur is not None and cur.val != val:
        cur = cur.left if val < cur.val else cur.right
    return cur
