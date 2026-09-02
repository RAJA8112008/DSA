# Method 1: Brute
# Time: O(h) | Space: O(h)
# Walk BST paths into two arrays of nodes, then scan from the start until they differ. Extra path arrays.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowestCommonAncestor(root, p, q):
    def pathTo(node, target):
        path = []
        cur = node
        while cur:
            path.append(cur)
            if cur == target  or  cur.val == target.val:
                break
            cur = (cur.left if target.val < cur.val else cur.right)
        return path
    a = pathTo(root, p)
    b = pathTo(root, q)
    i = 0
    while i < len(a)  and  i < len(b)  and  a[i] == b[i]:
        i += 1
    return a[i - 1]


# Method 2: Optimal
# Time: O(h) | Space: O(h)
# Recursive BST walk. Split point is the LCA. Stack O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowestCommonAncestor(root, p, q):
    if p.val < root.val  and  q.val < root.val:
        return lowestCommonAncestor(root.left, p, q)
    if p.val > root.val  and  q.val > root.val:
        return lowestCommonAncestor(root.right, p, q)
    return root


# Method 3: More optimal
# Time: O(h) | Space: O(1)
# Same split logic in a loop. No recursion. Constant extra space.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def lowestCommonAncestor(root, p, q):
    cur = root
    while cur:
        if p.val < cur.val  and  q.val < cur.val:
            cur = cur.left
        elif p.val > cur.val  and  q.val > cur.val:
            cur = cur.right
        else:
            return cur
    return None
