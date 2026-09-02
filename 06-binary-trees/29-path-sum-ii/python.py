# Method 1: Brute
# Time: O(n²) | Space: O(n²)
# Collect every root-to-leaf path, then keep those whose sum equals target. Path copies dominate memory.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def path_sum(root, target_sum):
    paths = []
    def go(node, path):
        if node is None:
            return
        path.append(node.val)
        if node.left is None and node.right is None:
            paths.append(list(path))
        go(node.left, path)
        go(node.right, path)
        path.pop()
    go(root, [])
    return [p for p in paths if sum(p) == target_sum]


# Method 2: Optimal
# Time: O(n²) | Space: O(h)
# Backtracking. remain starts at targetSum. At a leaf, if remain == node.val, snapshot the path. Copying a path is O(h); total output can be O(n²).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def path_sum(root, target_sum):
    out = []
    def go(node, remain, path):
        if node is None:
            return
        path.append(node.val)
        if node.left is None and node.right is None and remain == node.val:
            out.append(list(path))
        go(node.left, remain - node.val, path)
        go(node.right, remain - node.val, path)
        path.pop()
    go(root, target_sum, [])
    return out


# Method 3: More optimal
# Time: O(n²) | Space: O(n²)
# Iterative stack of {node, remain, path}. Same snapshots at leaves. Avoids call-stack overflow on a stick, still copies paths.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def path_sum(root, target_sum):
    if root is None:
        return []
    out = []
    stack = [(root, target_sum, [root.val])]
    while stack:
        node, remain, path = stack.pop()
        if node.left is None and node.right is None and remain == node.val:
            out.append(path)
        if node.right:
            stack.append((node.right, remain - node.val, path + [node.right.val]))
        if node.left:
            stack.append((node.left, remain - node.val, path + [node.left.val]))
    return out
