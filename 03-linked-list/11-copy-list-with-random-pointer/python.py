# Method 1: Brute
# Time: O(n) | Space: O(n)
# First pass: clone every node into a Map, next and random left null. Second pass: wire next and random through the map. Two walks, extra map of n nodes.

class Node:
    def __init__(self, val=0, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random
def copyRandomList(head):
    map = {}
    cur = head
    while cur:
        map[cur] = Node(cur.val)
        cur = cur.next
    cur = head
    while cur:
        copy = map.get(cur)
        copy.next = (map.get(cur.next) if cur.next else None)
        copy.random = (map.get(cur.random) if cur.random else None)
        cur = cur.next
    return (map.get(head) if head else None)


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One recursive walk with a Map. If the node is already cloned, return it (handles random cycles). Otherwise clone, then fill next and random. Still O(n) extra map plus stack.

class Node:
    def __init__(self, val=0, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random
def copyRandomList(head):
    map = {}
    def copy(node):
        if not node:
            return None
        if (node in map):
            return map.get(node)
        cloned = Node(node.val)
        map[node] = cloned
        cloned.next = copy(node.next)
        cloned.random = copy(node.random)
        return cloned
    return copy(head)


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Weave: original -> copy -> original.next. Set copy.random from original.random.next. Unweave into two lists. Extra space is the copies themselves, no hash map. (O(1) auxiliary.)

class Node:
    def __init__(self, val=0, next=None, random=None):
        self.val = val
        self.next = next
        self.random = random
def copyRandomList(head):
    if not head:
        return None
    cur = head
    while cur:
        copy = Node(cur.val, cur.next, None)
        cur.next = copy
        cur = copy.next
    cur = head
    while cur:
        if cur.random:
            cur.next.random = cur.random.next
        cur = cur.next.next
    newHead = head.next
    cur = head
    while cur:
        copy = cur.next
        cur.next = copy.next
        copy.next = (copy.next.next if copy.next else None)
        cur = cur.next
    return newHead
