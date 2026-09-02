# Method 1: Brute
# Time: O(n) | Space: O(n)
# BFS into an array of every node, then swap left/right on each. Extra list of n pointers.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def invertTree(root):
    if not root:
        return root
    nodes = []
    queue = [root]
    while len(queue):
        node = queue.pop(0)
        nodes.append(node)
        if node.left:
            queue.append(node.left)
        if node.right:
            queue.append(node.right)
    for node in nodes:
        tmp = node.left
        node.left = node.right
        node.right = tmp
    return root


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Recurse: invert children, then swap this node's left and right (order of swap vs recurse both work). Stack O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def invertTree(root):
    if not root:
        return None
    invertTree(root.left)
    invertTree(root.right)
    tmp = root.left
    root.left = root.right
    root.right = tmp
    return root


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Iterative stack. Pop a node, swap children, push non-null children. Same work, no recursion. Queue instead of stack is also fine.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def invertTree(root):
    if not root:
        return None
    stack = [root]
    while len(stack):
        node = stack.pop()
        tmp = node.left
        node.left = node.right
        node.right = tmp
        if node.left:
            stack.append(node.left)
        if node.right:
            stack.append(node.right)
    return root
