# Method 1: Brute
# Time: O(n) | Space: O(n)
# Encode the left subtree left-to-right with nulls, encode the right subtree right-to-left with nulls, compare. Extra arrays.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSymmetric(root):
    if not root:
        return True
    def enc(node, leftFirst, out):
        if not node:
            out.append("N")
            return
        out.append(str(node.val))
        if leftFirst:
            enc(node.left, True, out)
            enc(node.right, True, out)
        else:
            enc(node.right, False, out)
            enc(node.left, False, out)
    a = []
    b = []
    enc(root.left, True, a)
    enc(root.right, False, b)
    if len(a) != len(b):
        return False
    for i in range(len(a)):
        if a[i] != b[i]:
            return False
    return True


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# mirror(a,b): both null ok; one null fail; vals equal and mirror(a.left,b.right) and mirror(a.right,b.left). Recurse from root.left and root.right.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSymmetric(root):
    def mirror(a, b):
        if not a  and  not b:
            return True
        if not a  or  not b  or  a.val != b.val:
            return False
        return mirror(a.left, b.right)  and  mirror(a.right, b.left)
    if not root:
        return True
    return mirror(root.left, root.right)


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Queue of node pairs. Dequeue a and b, check, enqueue a.left with b.right and a.right with b.left. Iterative mirror test.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSymmetric(root):
    if not root:
        return True
    queue = [root.left, root.right]
    while len(queue):
        a = queue.pop(0)
        b = queue.pop(0)
        if not a  and  not b:
            continue
        if not a  or  not b  or  a.val != b.val:
            return False
        queue.append(a.left, b.right)
        queue.append(a.right, b.left)
    return True
