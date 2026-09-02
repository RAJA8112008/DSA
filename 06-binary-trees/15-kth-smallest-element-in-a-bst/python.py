# Method 1: Brute
# Time: O(n) | Space: O(n)
# Full inorder into an array, return vals[k-1]. Always walks the whole tree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def kthSmallest(root, k):
    vals = []
    def inorder(node):
        if not node:
            return
        inorder(node.left)
        vals.append(node.val)
        inorder(node.right)
    inorder(root)
    return vals[k - 1]


# Method 2: Optimal
# Time: O(h+k) | Space: O(h)
# Recursive inorder with a counter. When count hits k, record val and stop expanding. Better when k is small.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def kthSmallest(root, k):
    box = {"count": 0, "ans": 0}
    def go(node):
        if not node  or  box["count"] >= k:
            return
        go(node.left)
        box["count"] += 1
        if box["count"] == k:
            box["ans"] = node.val
            return
        go(node.right)
    go(root)
    return box["ans"]


# Method 3: More optimal
# Time: O(h+k) | Space: O(h)
# Iterative inorder. Each pop is the next smallest. After k pops, return that val. Easy to stop early; no extra values array.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def kthSmallest(root, k):
    stack = []
    cur = root
    while True:
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        k -= 1
        if k == 0:
            return cur.val
        cur = cur.right
