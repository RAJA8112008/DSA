# Method 1: Brute
# Time: O(n · n!) | Space: O(n · n!)
# Generate every permutation of 1..n, insert into a BST, serialize the shape, keep one copy per unique serialization. Correct but factorial.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def generate_trees(n):
    def insert(node, val):
        if node is None:
            return TreeNode(val)
        if val < node.val:
            node.left = insert(node.left, val)
        else:
            node.right = insert(node.right, val)
        return node
    def clone(node):
        if node is None:
            return None
        c = TreeNode(node.val)
        c.left = clone(node.left)
        c.right = clone(node.right)
        return c
    def serial(node):
        if node is None:
            return "#"
        return str(node.val) + "," + serial(node.left) + "," + serial(node.right)
    nums = list(range(1, n + 1))
    seen = {}
    out = []
    def perm(i):
        if i == len(nums):
            root = None
            for v in nums:
                root = insert(root, v)
            s = serial(root)
            if s not in seen:
                seen[s] = True
                out.append(clone(root))
            return
        for j in range(i, len(nums)):
            nums[i], nums[j] = nums[j], nums[i]
            perm(i + 1)
            nums[i], nums[j] = nums[j], nums[i]
    perm(0)
    return out


# Method 2: Optimal
# Time: O(C(n) · n) | Space: O(C(n) · n)
# For each root i in [lo, hi], cartesian product of left trees and right trees. Empty range yields a single null tree so a missing child is represented once.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def generate_trees(n):
    def build(lo, hi):
        if lo > hi:
            return [None]
        out = []
        for i in range(lo, hi + 1):
            lefts = build(lo, i - 1)
            rights = build(i + 1, hi)
            for left in lefts:
                for right in rights:
                    node = TreeNode(i)
                    node.left = left
                    node.right = right
                    out.append(node)
        return out
    if n == 0:
        return []
    return build(1, n)


# Method 3: More optimal
# Time: O(C(n) · n) | Space: O(C(n) · n)
# Memoize [lo, hi]. Shared ranges (for example all trees on 3,4,5) are built once. Catalan many trees still must be allocated.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def generate_trees(n):
    memo = {}
    def build(lo, hi):
        key = (lo, hi)
        if key in memo:
            return memo[key]
        if lo > hi:
            memo[key] = [None]
            return memo[key]
        out = []
        for i in range(lo, hi + 1):
            for left in build(lo, i - 1):
                for right in build(i + 1, hi):
                    node = TreeNode(i)
                    node.left = left
                    node.right = right
                    out.append(node)
        memo[key] = out
        return out
    if n == 0:
        return []
    return build(1, n)
