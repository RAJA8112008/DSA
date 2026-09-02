# Method 1: Brute
# Time: O(n) | Space: O(n)
# DFS preorder into an array (node, child, next). Then walk the array and set next/prev, clear child. Extra array of every node.

class Node:
    def __init__(self, val=0, prev=None, next=None, child=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
def flatten(head):
    nodes = []
    def dfs(node):
        while node:
            nodes.append(node)
            if node.child:
                dfs(node.child)
            node = node.next
    dfs(head)
    for i in range(len(nodes)):
        nodes[i].prev = i =(None if = 0 else nodes[i - 1])
        nodes[i].next = i =(None if = len(nodes) - 1 else nodes[i + 1])
        nodes[i].child = None
    return nodes[0]  or  None


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Recurse: if a node has a child, flatten the child, hang it after the node, find the child's tail, attach the old next. Stack depth follows nesting.

class Node:
    def __init__(self, val=0, prev=None, next=None, child=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
def flatten(head):
    def go(node):
        cur = node
        last = node
        while cur:
            next = cur.next
            if cur.child:
                childLast = go(cur.child)
                cur.next = cur.child
                cur.child.prev = cur
                cur.child = None
                if childLast:
                    childLast.next = next
                    if next:
                        next.prev = childLast
                    last = childLast
            else:
                last = cur
            cur = next
        return last
    go(head)
    return head


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Walk with one pointer. On a child, find that child's current tail (no recurse), splice the whole child between cur and cur.next, clear child. Then continue. Auxiliary space O(1).

class Node:
    def __init__(self, val=0, prev=None, next=None, child=None):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
def flatten(head):
    cur = head
    while cur:
        if cur.child:
            tail = cur.child
            while tail.next:
                tail = tail.next
            tail.next = cur.next
            if cur.next:
                cur.next.prev = tail
            cur.next = cur.child
            cur.child.prev = cur
            cur.child = None
        cur = cur.next
    return head
