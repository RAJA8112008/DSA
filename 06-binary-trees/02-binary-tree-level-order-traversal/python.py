# Method 1: Brute
# Time: O(n) | Space: O(n)
# DFS with a depth argument. Push val into levels[depth], creating the row if needed. Extra recursion stack plus the answer.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def levelOrder(root):
    levels = []
    def dfs(node, d):
        if not node:
            return
        if not levels[d]:
            levels[d] = []
        levels[d].push(node.val)
        dfs(node.left, d + 1)
        dfs(node.right, d + 1)
    dfs(root, 0)
    return levels


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# BFS queue. Each node is stored with its depth. Rows grow as depth increases. Extra pair objects on the queue.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def levelOrder(root):
    if not root:
        return []
    levels = []
    queue = [{ node: root, d: 0 }]
    while len(queue):
        node, d = queue.pop(0)["node"], queue.pop(0)["d"]
        if not levels[d]:
            levels[d] = []
        levels[d].push(node.val)
        if node.left:
            queue.append({ node: node.left, d: d + 1 })
        if node.right:
            queue.append({ node: node.right, d: d + 1 })
    return levels


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# BFS without storing depth. n = queue.length is the current row size. Process exactly those n nodes, enqueue children for the next row. Cleaner constant factors; still O(width) queue.

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
def levelOrder(root):
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
    return levels
