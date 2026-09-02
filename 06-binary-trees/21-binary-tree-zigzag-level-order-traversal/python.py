# Method 1: Brute
# Time: O(n) | Space: O(n)
# Level-order into lists. Reverse rows whose index is odd. Extra reverse pass per odd level.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def zigzag_level_order(root):
    if root is None:
        return []
    from collections import deque
    out = []
    q = deque([root])
    while q:
        row = []
        for _ in range(len(q)):
            node = q.popleft()
            row.append(node.val)
            if node.left:
                q.append(node.left)
            if node.right:
                q.append(node.right)
        if len(out) % 2 == 1:
            row.reverse()
        out.append(row)
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Deque of nodes. Even levels poll from the front and offer children left-then-right at the back. Odd levels poll from the back and offer children right-then-left at the front.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def zigzag_level_order(root):
    if root is None:
        return []
    from collections import deque
    out = []
    dq = deque([root])
    left_to_right = True
    while dq:
        row = []
        for _ in range(len(dq)):
            if left_to_right:
                node = dq.popleft()
                row.append(node.val)
                if node.left:
                    dq.append(node.left)
                if node.right:
                    dq.append(node.right)
            else:
                node = dq.pop()
                row.append(node.val)
                if node.right:
                    dq.appendleft(node.right)
                if node.left:
                    dq.appendleft(node.left)
        out.append(row)
        left_to_right = not left_to_right
    return out


# Method 3: More optimal
# Time: O(n) | Space: O(h)
# DFS with depth. Append a new list when you first reach a depth. Push on even depths, unshift on odd depths. Recursion stack only.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def zigzag_level_order(root):
    out = []
    def go(node, d):
        if node is None:
            return
        if d == len(out):
            out.append([])
        if d % 2 == 0:
            out[d].append(node.val)
        else:
            out[d].insert(0, node.val)
        go(node.left, d + 1)
        go(node.right, d + 1)
    go(root, 0)
    return out
