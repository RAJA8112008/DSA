# Method 1: Brute
# Time: O(n) | Space: O(n)
# Inorder dump, then return vals[n - k]. Extra array of every key.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def kth_largest(root, k):
    vals = []
    def go(node):
        if node is None:
            return
        go(node.left)
        vals.append(node.val)
        go(node.right)
    go(root)
    return vals[len(vals) - k]


# Method 2: Optimal
# Time: O(h + k) | Space: O(h)
# Reverse inorder. Decrement k at each visit. When k hits 0, that value is the answer. Stop walking.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def kth_largest(root, k):
    ans = [0]
    def go(node):
        nonlocal k
        if node is None or k == 0:
            return
        go(node.right)
        if k == 0:
            return
        k -= 1
        if k == 0:
            ans[0] = node.val
            return
        go(node.left)
    go(root)
    return ans[0]


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Morris reverse inorder: thread the successor (leftmost of the right, via left pointers of the right spine). Visit without a stack, stop at k.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def kth_largest(root, k):
    cur = root
    while cur:
        if cur.right is None:
            k -= 1
            if k == 0:
                return cur.val
            cur = cur.left
        else:
            succ = cur.right
            while succ.left and succ.left is not cur:
                succ = succ.left
            if succ.left is None:
                succ.left = cur
                cur = cur.right
            else:
                succ.left = None
                k -= 1
                if k == 0:
                    return cur.val
                cur = cur.left
    return 0
