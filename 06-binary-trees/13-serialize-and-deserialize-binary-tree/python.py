# Method 1: Brute
# Time: O(n) | Space: O(n)
# JSON.stringify the nested {val,left,right} object and JSON.parse it back. Works for this node shape, hides the codec you are supposed to write, and is bulky.

import json

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def serialize(root):
    return json.dumps(_to_dict(root))
def deserialize(data):
    if data == "None":
        return None
    return json.loads(data)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Preorder join with commas, N for null. Deserialize consumes tokens with an index. Recursion rebuilds left then right.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def serialize(root):
    out = []
    def go(node):
        if not node:
            out.append("N")
            return
        out.append(str(node.val))
        go(node.left)
        go(node.right)
    go(root)
    return ",".join(out)
def deserialize(data):
    toks = data.split(",")
    i = 0
    def go():
        t = toks[i]
        i += 1
        if t == "N":
            return None
        node = TreeNode(int(t))
        node.left = go()
        node.right = go()
        return node
    return go()


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# BFS codec: queue writes val or N level by level. Deserialize uses a queue of parents and attaches children in order. Iterative, same linear cost, no recurse on serialize/deserialize.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def serialize(root):
    if not root:
        return "N"
    out = []
    queue = [root]
    while len(queue):
        node = queue.pop(0)
        if not node:
            out.append("N")
            continue
        out.append(str(node.val))
        queue.append(node.left)
        queue.append(node.right)
    return ",".join(out)
def deserialize(data):
    toks = data.split(",")
    if toks[0] == "N":
        return None
    root = TreeNode(int(toks[0]))
    queue = [root]
    i = 1
    while len(queue)  and  i < len(toks):
        node = queue.pop(0)
        if toks[i] != "N":
            node.left = TreeNode(int(toks[i]))
            queue.append(node.left)
        i += 1
        if i < len(toks)  and  toks[i] != "N":
            node.right = TreeNode(int(toks[i]))
            queue.append(node.right)
        i += 1
    return root
