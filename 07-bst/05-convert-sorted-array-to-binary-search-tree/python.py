# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Insert 0..n-1 in order into an empty BST. Each insert walks a growing right spine, so you get a linked list of height n.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def sorted_array_to_bst(nums):
    def insert(node, val):
        if node is None:
            return TreeNode(val)
        if val < node.val:
            node.left = insert(node.left, val)
        else:
            node.right = insert(node.right, val)
        return node
    root = None
    for val in nums:
        root = insert(root, val)
    return root


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Slice the array around mid each call. Balanced, but each slice copies O(n) elements across the tree of calls.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def sorted_array_to_bst(nums):
    if not nums:
        return None
    mid = len(nums) // 2
    node = TreeNode(nums[mid])
    node.left = sorted_array_to_bst(nums[:mid])
    node.right = sorted_array_to_bst(nums[mid + 1:])
    return node


# Method 3: More optimal
# Time: O(n) | Space: O(log n)
# Pass inclusive indices. Each node is created once. Recursion depth is the height of the balanced tree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def sorted_array_to_bst(nums):
    def build(lo, hi):
        if lo > hi:
            return None
        mid = (lo + hi) // 2
        node = TreeNode(nums[mid])
        node.left = build(lo, mid - 1)
        node.right = build(mid + 1, hi)
        return node
    return build(0, len(nums) - 1)
