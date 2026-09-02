# Method 1: Brute
# Time: O(n) init, O(1) next | Space: O(n)
# Flatten inorder into an array at construction. next/hasNext are index moves. Simple, but you pay linear memory before the first call.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class BSTIterator:
    def __init__(self, root):
        self.vals = []
        self.i = 0
        def go(node):
            if node is None:
                return
            go(node.left)
            self.vals.append(node.val)
            go(node.right)
        go(root)
    def next(self):
        val = self.vals[self.i]
        self.i += 1
        return val
    def has_next(self):
        return self.i < len(self.vals)


# Method 2: Optimal
# Time: O(h) init, amortized O(1) next | Space: O(h)
# Stack holds the path to the next node. Construction pushes the left spine. next() pops, then pushes the left spine of the right child.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class BSTIterator:
    def __init__(self, root):
        self.stack = []
        self._push_left(root)
    def _push_left(self, node):
        while node:
            self.stack.append(node)
            node = node.left
    def next(self):
        node = self.stack.pop()
        self._push_left(node.right)
        return node.val
    def has_next(self):
        return len(self.stack) > 0


# Method 3: More optimal
# Time: amortized O(1) next | Space: O(1)
# Morris: thread predecessor.right to the current node, walk without a stack. Unthread before yielding so the tree is restored. Extra memory is a handful of pointers.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class BSTIterator:
    def __init__(self, root):
        self.cur = root
    def next(self):
        while self.cur:
            if self.cur.left is None:
                val = self.cur.val
                self.cur = self.cur.right
                return val
            pred = self.cur.left
            while pred.right and pred.right is not self.cur:
                pred = pred.right
            if pred.right is None:
                pred.right = self.cur
                self.cur = self.cur.left
            else:
                pred.right = None
                val = self.cur.val
                self.cur = self.cur.right
                return val
        return 0
    def has_next(self):
        return self.cur is not None
