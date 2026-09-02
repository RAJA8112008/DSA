# Method 1: Brute
# Time: O(n²) | Space: O(h)
# At each node, maxDown on left and right is computed from scratch, then visit children. Nested tree walks.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def maxPathSum(root):
    def maxDown(node):
        if not node:
            return 0
        return node.val + max(0, maxDown(node.left), maxDown(node.right))
    best = float('-inf')
    def visit(node):
        if not node:
            return
        left = max(0, maxDown(node.left))
        right = max(0, maxDown(node.right))
        through = node.val + left + right
        if through > best:
            best = through
        visit(node.left)
        visit(node.right)
    visit(root)
    return best


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# gain(node) = val + max(0, gain(left), gain(right)) for continuing up. Through-node sum updates a boxed best. One DFS.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def maxPathSum(root):
    best = float('-inf')
    def gain(node):
        if not node:
            return 0
        left = max(0, gain(node.left))
        right = max(0, gain(node.right))
        through = node.val + left + right
        if through > best:
            best = through
        return node.val + max(left, right)
    gain(root)
    return best


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Same linear DFS, but dfs returns {gain, best} so there is no outer mutable. Parent combines through, left.best, and right.best. Cleaner to reason about.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def maxPathSum(root):
    def dfs(node):
        if not node:
            return {"gain": 0, "best": float('-inf')}
        L = dfs(node.left)
        R = dfs(node.right)
        left = max(0, L["gain"])
        right = max(0, R["gain"])
        through = node.val + left + right
        gain = node.val + max(left, right)
        best = max(through, L["best"], R["best"])
        return {"gain": gain, "best": best}
    return dfs(root)["best"]
