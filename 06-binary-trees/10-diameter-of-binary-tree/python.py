# Method 1: Brute
# Time: O(n²) | Space: O(h)
# At every node, diameter candidate is height(left)+height(right). height itself walks the subtree, so nested walks are quadratic on a skewed tree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def diameterOfBinaryTree(root):
    def height(node):
        if not node:
            return 0
        return 1 + max(height(node.left), height(node.right))
    best = 0
    def visit(node):
        if not node:
            return
        through = height(node.left) + height(node.right)
        if through > best:
            best = through
        visit(node.left)
        visit(node.right)
    visit(root)
    return best


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# DFS returns height. While returning, update best with leftHeight + rightHeight. Each node once.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def diameterOfBinaryTree(root):
    best = 0
    def height(node):
        if not node:
            return 0
        lh = height(node.left)
        rh = height(node.right)
        if lh + rh > best:
            best = lh + rh
        return 1 + max(lh, rh)
    height(root)
    return best


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Iterative postorder. A Map stores height after both children are done. Update diameter from those heights. No call stack; extra map of n heights.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def diameterOfBinaryTree(root):
    if not root:
        return 0
    stack = [root]
    seen = set()
    height = {}
    height[None] = 0
    best = 0
    while len(stack):
        node = stack[-1]
        if node.left  and  not (node.left in height)  and  not (node.left in seen):
            stack.append(node.left)
            continue
        if node.right  and  not (node.right in height)  and  not (node.right in seen):
            stack.append(node.right)
            continue
        stack.pop()
        seen.add(node)
        lh = height.get(node.left)  or  0
        rh = height.get(node.right)  or  0
        height[node] = 1 + max(lh, rh)
        if lh + rh > best:
            best = lh + rh
    return best
