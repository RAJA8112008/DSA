# Method 1: Brute
# Time: O(n) | Space: O(h)
# Classic 1 + count(left) + count(right). Ignores the complete-tree promise. Fine for small n.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def countNodes(root):
    if not root:
        return 0
    return 1 + countNodes(root.left) + countNodes(root.right)


# Method 2: Optimal
# Time: O(log² n) | Space: O(log n)
# Measure leftmost and rightmost depths. If equal, subtree is perfect: (1 << h) - 1. Else 1 + count(left) + count(right). Each level does O(log n) height work.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def countNodes(root):
    if not root:
        return 0
    lh = 0
    rh = 0
    l = root
    r = root
    while l:
        lh += 1
        l = l.left
    while r:
        rh += 1
        r = r.right
    if lh == rh:
        return (1 << lh) - 1
    return 1 + countNodes(root.left) + countNodes(root.right)


# Method 3: More optimal
# Time: O(log² n) | Space: O(1)
# Height of leftmost path, then binary search the last level: exists(index) walks h-1 bits from the root. Count = full upper levels + how many last-level nodes exist. Iterative, O(1) extra besides the tree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def countNodes(root):
    if not root:
        return 0
    def leftHeight(node):
        h = 0
        while node:
            h += 1
            node = node.left
        return h
    def exists(index, h, node):
        lo = 0
        hi = (1 << (h - 1)) - 1
        for i in range(h - 1):
            mid = ((lo + hi) / 2)
            if index <= mid:
                node = node.left
                hi = mid
            else:
                node = node.right
                lo = mid + 1
        return !not node
    h = leftHeight(root)
    lastCount = 1 << (h - 1)
    lo = 0
    hi = lastCount - 1
    while lo <= hi:
        mid = ((lo + hi) / 2)
        if exists(mid, h, root):
            lo = mid + 1
        else:
            hi = mid - 1
    return lastCount - 1 + lo
