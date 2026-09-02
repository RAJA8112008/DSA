# Method 1: Brute
# Time: O(n) | Space: O(n)
# Encode each tree as a preorder array with N for null, then compare the arrays. Extra strings/arrays for both trees.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSameTree(p, q):
    def enc(node, out):
        if not node:
            out.append("N")
            return
        out.append(str(node.val))
        enc(node.left, out)
        enc(node.right, out)
    a = []
    b = []
    enc(p, a)
    enc(q, b)
    if len(a) != len(b):
        return False
    for i in range(len(a)):
        if a[i] != b[i]:
            return False
    return True


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# If both null, true. If one null or vals differ, false. Else both lefts and both rights. Stack O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSameTree(p, q):
    if not p  and  not q:
        return True
    if not p  or  not q  or  p.val != q.val:
        return False
    return isSameTree(p.left, q.left)  and  isSameTree(p.right, q.right)


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Iterative: stack of pairs. Pop two nodes, check null/val, push children pairs. Same complexity, no recursion.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSameTree(p, q):
    stack = [[p, q]]
    while len(stack):
        pair = stack.pop()
        a = pair[0]
        b = pair[1]
        if not a  and  not b:
            continue
        if not a  or  not b  or  a.val != b.val:
            return False
        stack.append([a.left, b.left])
        stack.append([a.right, b.right])
    return True
