# Method 1: Brute
# Time: O(n) | Space: O(n)
# Full level-order into rows, then map each row to its last value. Extra storage for every node value.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def rightSideView(root):
    if not root:
        return []
    levels = []
    queue = [root]
    while len(queue):
        n = len(queue)
        row = []
        for i in range(n):
            node = queue.pop(0)
            row.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        levels.append(row)
    return levels.map(function (row) {
    return row[-1];
  })


# Method 2: Optimal
# Time: O(n) | Space: O(h)
# DFS visit right child first. If depth === ans.length, this is the first node seen at that depth from the right. Recursion O(h).

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def rightSideView(root):
    ans = []
    def dfs(node, d):
        if not node:
            return
        if d == len(ans):
            ans.append(node.val)
        dfs(node.right, d + 1)
        dfs(node.left, d + 1)
    dfs(root, 0)
    return ans


# Method 3: More optimal
# Time: O(n) | Space: O(w)
# BFS. For each level of size n, the last shifted node is the right-side value. Only the answer plus the queue, no full row arrays.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def rightSideView(root):
    if not root:
        return []
    ans = []
    queue = [root]
    while len(queue):
        n = len(queue)
        for i in range(n):
            node = queue.pop(0)
            if i == n - 1:
                ans.append(node.val)
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
    return ans
