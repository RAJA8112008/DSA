# Method 1: Brute
# Time: O(n) | Space: O(n)
# Collect every root-to-leaf path into arrays, return the longest length. Extra memory for all paths.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def maxDepth(root):
    paths = []
    def go(node, path):
        if not node:
            return
        path.append(node.val)
        if not node.left  and  not node.right:
            paths.append(len(path))
        go(node.left, path)
        go(node.right, path)
        path.pop()
    go(root, [])
    return (max(paths) if len(paths) else 0)


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Recursive height: null is 0, else 1 + max of children. One visit per node. Stack O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def maxDepth(root):
    if not root:
        return 0
    return 1 + max(maxDepth(root.left), maxDepth(root.right))


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Iterative stack of {node, depth}. Track the max depth seen. Same complexity, no engine recursion. BFS would use O(width) instead of O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def maxDepth(root):
    if not root:
        return 0
    best = 0
    stack = [{ node: root, d: 1 }]
    while len(stack):
        node, d = stack.pop()["node"], stack.pop()["d"]
        if d > best:
            best = d
        if node.left:
            stack.append({ node: node.left, d: d + 1 })
        if node.right:
            stack.append({ node: node.right, d: d + 1 })
    return best
