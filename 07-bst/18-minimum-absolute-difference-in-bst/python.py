# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Dump all values, then compare every pair. Extra array and quadratic checks.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def get_minimum_difference(root):
    vals = []
    def go(node):
        if node is None:
            return
        vals.append(node.val)
        go(node.left)
        go(node.right)
    go(root)
    best = float("inf")
    for i in range(len(vals)):
        for j in range(i + 1, len(vals)):
            d = abs(vals[i] - vals[j])
            if d < best:
                best = d
    return best


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Inorder. Compare each node with the previous inorder value. The min of those adjacent gaps is the global min.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def get_minimum_difference(root):
    prev = [None]
    best = [float("inf")]
    def go(node):
        if node is None:
            return
        go(node.left)
        if prev[0] is not None:
            best[0] = min(best[0], node.val - prev[0])
        prev[0] = node.val
        go(node.right)
    go(root)
    return best[0]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Morris inorder with a previous pointer. Same adjacent-gap logic, no stack.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def get_minimum_difference(root):
    prev = None
    best = float("inf")
    cur = root
    while cur:
        if cur.left is None:
            if prev is not None:
                best = min(best, cur.val - prev)
            prev = cur.val
            cur = cur.right
        else:
            pred = cur.left
            while pred.right and pred.right is not cur:
                pred = pred.right
            if pred.right is None:
                pred.right = cur
                cur = cur.left
            else:
                pred.right = None
                if prev is not None:
                    best = min(best, cur.val - prev)
                prev = cur.val
                cur = cur.right
    return best
