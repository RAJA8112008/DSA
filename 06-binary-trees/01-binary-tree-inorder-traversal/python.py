# Method 1: Brute
# Time: O(n) | Space: O(n)
# Recursive inorder: walk left, push this value, walk right. Matches the definition. Extra memory is the output array plus O(h) call stack.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def inorderTraversal(root):
    out = []
    def go(node):
        if not node:
            return
        go(node.left)
        out.append(node.val)
        go(node.right)
    go(root)
    return out


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# Iterative stack: go left until null, pop, record val, go right. Same visit order as recursion without depending on engine stack limits as much; still O(h) extra.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def inorderTraversal(root):
    out = []
    stack = []
    cur = root
    while cur  or  len(stack):
        while cur:
            stack.append(cur)
            cur = cur.left
        cur = stack.pop()
        out.append(cur.val)
        cur = cur.right
    return out


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Morris: if there is no left, visit and go right. Else find the predecessor (rightmost in left). If pred.right is null, thread it to cur and go left. If it already points at cur, unthread, visit, go right. Auxiliary space O(1) besides the output list.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def inorderTraversal(root):
    out = []
    cur = root
    while cur:
        if not cur.left:
            out.append(cur.val)
            cur = cur.right
        else:
            pred = cur.left
            while pred.right  and  pred.right != cur:
                pred = pred.right
            if not pred.right:
                pred.right = cur
                cur = cur.left
            else:
                pred.right = None
                out.append(cur.val)
                cur = cur.right
    return out
