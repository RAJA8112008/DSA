# Method 1: Brute
# Time: O(n) | Space: O(n)
# DFS records every root-to-leaf path as an array, sums each, compares to target. Extra storage for all paths.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def hasPathSum(root, targetSum):
    sums = []
    def go(node, path):
        if not node:
            return
        path.append(node.val)
        if not node.left  and  not node.right:
            s = 0
            for v in path:
                s += v
            sums.append(s)
        go(node.left, path)
        go(node.right, path)
        path.pop()
    go(root, [])
    return (targetSum in sums)


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Recurse with remaining. At a leaf, remaining === node.val. Else try left or right with remaining - val.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def hasPathSum(root, targetSum):
    if not root:
        return False
    if not root.left  and  not root.right:
        return root.val == targetSum
    rest = targetSum - root.val
    return hasPathSum(root.left, rest)  or  hasPathSum(root.right, rest)


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Iterative stack of node plus remaining sum. Same check at leaves. No recursion.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def hasPathSum(root, targetSum):
    if not root:
        return False
    stack = [{ node: root, left: targetSum }]
    while len(stack):
        node, left = stack.pop()["node"], stack.pop()["left"]
        if not node.left  and  not node.right  and  node.val == left:
            return True
        if node.left:
            stack.append({ node: node.left, left: left - node.val })
        if node.right:
            stack.append({ node: node.right, left: left - node.val })
    return False
