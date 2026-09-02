# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Root is preorder[0]. Scan inorder for it, slice left/right arrays, recurse. Slicing and scanning are O(n) per node.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def buildTree(preorder, inorder):
    if not len(preorder):
        return None
    rootVal = preorder[0]
    root = TreeNode(rootVal)
    mid = inorder.index(rootVal)
    root.left = buildTree(preorder[1:mid + 1], inorder[0:mid])
    root.right = buildTree(preorder[mid + 1):inorder[mid + 1]:]
    return root


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# HashMap of inorder indexes. Recurse with (preL, preR, inL, inR) bounds. Each node created once; map lookup O(1).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def buildTree(preorder, inorder):
    idx = {}
    for i in range(len(inorder)):
        idx[inorder[i]] = i
    def build(preL, preR, inL, inR):
        if preL > preR:
            return None
        root = TreeNode(preorder[preL])
        mid = idx.get(root.val)
        leftSize = mid - inL
        root.left = build(preL + 1, preL + leftSize, inL, mid - 1)
        root.right = build(preL + leftSize + 1, preR, mid + 1, inR)
        return root
    return build(0, len(preorder) - 1, 0, len(inorder) - 1)


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# Advance a preorder index and an inorder index. build(stop) creates a node, builds left until inorder hits this val, then right until stop. No hashmap; O(h) stack only besides the tree.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def buildTree(preorder, inorder):
    p = 0
    i = 0
    def build(stop):
        if p >= len(preorder):
            return None
        if inorder[i] == stop:
            i += 1
            return None
        root = TreeNode(preorder[p += 1])
        root.left = build(root.val)
        root.right = build(stop)
        return root
    return build()
