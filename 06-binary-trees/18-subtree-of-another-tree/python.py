# Method 1: Brute
# Time: O(n·m) | Space: O(n)
# Push every node of root into an array, then isSameTree against subRoot for each. Extra array plus O(n*m) compares.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSubtree(root, subRoot):
    def same(a, b):
        if not a  and  not b:
            return True
        if not a  or  not b  or  a.val != b.val:
            return False
        return same(a.left, b.left)  and  same(a.right, b.right)
    nodes = []
    def collect(node):
        if not node:
            return
        nodes.append(node)
        collect(node.left)
        collect(node.right)
    collect(root)
    for node in nodes:
        if same(node, subRoot):
            return True
    return False


# Method 2: Optimal
# Time: O(n·m) | Space: O(h)
# No extra node list. If this node matches as a tree, true. Else try left or right. Worst case still O(n*m), typical interview code.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSubtree(root, subRoot):
    def same(a, b):
        if not a  and  not b:
            return True
        if not a  or  not b  or  a.val != b.val:
            return False
        return same(a.left, b.left)  and  same(a.right, b.right)
    if not root:
        return False
    if same(root, subRoot):
        return True
    return isSubtree(root.left, subRoot)  or  isSubtree(root.right, subRoot)


# Method 3: More optimal
# Time: O(n+m) | Space: O(n+m)
# Serialize with parentheses so each subtree is a unique string. Check whether ser(subRoot) is a substring of ser(root). Linear in the size of the strings (and typical includes).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def isSubtree(root, subRoot):
    def ser(node):
        if not node:
            return "N"
        return "(" + node.val + "," + ser(node.left) + "," + ser(node.right) + ")"
    return ser(subRoot) in ser(root)
