# Method 1: Brute
# Time: O(n²) | Space: O(h)
# At each node recompute both heights and recurse isBalanced on children. Height work repeats on the same nodes.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isBalanced(root):
    def height(node):
        if not node:
            return 0
        return 1 + max(height(node.left), height(node.right))
    if not root:
        return True
    if abs(height(root.left) - height(root.right)) > 1:
        return False
    return isBalanced(root.left)  and  isBalanced(root.right)


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Postorder returns height. If a child is already unbalanced or |lh-rh|>1, return -1 and bubble up. One visit per node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isBalanced(root):
    def walk(node):
        if not node:
            return 0
        lh = walk(node.left)
        if lh < 0:
            return -1
        rh = walk(node.right)
        if rh < 0:
            return -1
        if abs(lh - rh) > 1:
            return -1
        return 1 + max(lh, rh)
    return walk(root) >= 0


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Iterative postorder with a height map. After both children, check |lh-rh| and store height. No recursion.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isBalanced(root):
    if not root:
        return True
    stack = [root]
    height = {}
    height[None] = 0
    while len(stack):
        node = stack[-1]
        if node.left  and  not (node.left in height):
            stack.append(node.left)
            continue
        if node.right  and  not (node.right in height):
            stack.append(node.right)
            continue
        stack.pop()
        lh = height.get(node.left)  or  0
        rh = height.get(node.right)  or  0
        if abs(lh - rh) > 1:
            return False
        height[node] = 1 + max(lh, rh)
    return True
