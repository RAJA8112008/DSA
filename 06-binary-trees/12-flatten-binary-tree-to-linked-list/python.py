# Method 1: Brute
# Time: O(n) | Space: O(n)
# Preorder collect nodes into an array. Then set each left to null and next.right to the following node. Extra array.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def flatten(root):
    nodes = []
    def pre(node):
        if not node:
            return
        nodes.append(node)
        pre(node.left)
        pre(node.right)
    pre(root)
    for i in range(len(nodes)):
        nodes[i].left = None
        nodes[i].right = (nodes[i + 1] if i + 1 < len(nodes) else None)


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Recurse right, then left, keep a tail pointer of the already flattened suffix. Hang this node in front. Stack O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def flatten(root):
    box = {"tail": None}
    def go(node):
        if not node:
            return
        go(node.right)
        go(node.left)
        node.right = box["tail"]
        node.left = None
        box["tail"] = node
    go(root)


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# While cur exists: if it has a left, find rightmost of left, attach cur.right there, move left to right, clear left. Then cur = cur.right. No extra stack.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def flatten(root):
    cur = root
    while cur:
        if cur.left:
            pred = cur.left
            while pred.right:
                pred = pred.right
            pred.right = cur.right
            cur.right = cur.left
            cur.left = None
        cur = cur.right
