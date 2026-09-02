# Method 1: Brute
# Time: O(n) | Space: O(h)
# DFS every node. Add val when it is inside the interval. Correct on a plain binary tree too.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def range_sum_bst(root, low, high):
    if root is None:
        return 0
    add = root.val if low <= root.val <= high else 0
    return add + range_sum_bst(root.left, low, high) + range_sum_bst(root.right, low, high)


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Prune: skip left when node is below low, skip right when node is above high. Best case you only walk the in-range corridor.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def range_sum_bst(root, low, high):
    if root is None:
        return 0
    if root.val < low:
        return range_sum_bst(root.right, low, high)
    if root.val > high:
        return range_sum_bst(root.left, low, high)
    return root.val + range_sum_bst(root.left, low, high) + range_sum_bst(root.right, low, high)


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Explicit stack, same prune. No recursion. Push only children that can still hold in-range keys.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def range_sum_bst(root, low, high):
    total = 0
    stack = []
    if root:
        stack.append(root)
    while stack:
        node = stack.pop()
        if low <= node.val <= high:
            total += node.val
        if node.left and node.val > low:
            stack.append(node.left)
        if node.right and node.val < high:
            stack.append(node.right)
    return total
