# Method 1: Brute
# Time: O(n²) | Space: O(h)
# For each node, DFS the rest of the tree looking for k - val. Nested walks. No extra set.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def find_target(root, k):
    def exists(node, skip, val):
        if node is None:
            return False
        if node is not skip and node.val == val:
            return True
        return exists(node.left, skip, val) or exists(node.right, skip, val)
    def go(node):
        if node is None:
            return False
        if exists(root, node, k - node.val):
            return True
        return go(node.left) or go(node.right)
    return go(root)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Hash set of visited values. DFS: if k - val is in the set, done; else add val and continue. Works on any binary tree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def find_target(root, k):
    seen = set()
    def go(node):
        if node is None:
            return False
        if (k - node.val) in seen:
            return True
        seen.add(node.val)
        return go(node.left) or go(node.right)
    return go(root)


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Inorder array is sorted. Two pointers from both ends. Uses the BST. Space is still linear for the array; two iterators would drop it to O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def find_target(root, k):
    vals = []
    def go(node):
        if node is None:
            return
        go(node.left)
        vals.append(node.val)
        go(node.right)
    go(root)
    i, j = 0, len(vals) - 1
    while i < j:
        s = vals[i] + vals[j]
        if s == k:
            return True
        if s < k:
            i += 1
        else:
            j -= 1
    return False
