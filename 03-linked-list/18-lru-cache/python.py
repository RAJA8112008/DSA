# Method 1: Brute
# Time: O(n) get/put | Space: O(capacity)
# Store pairs in an array. get scans, splices the hit to the end. put updates or appends, then shift if over capacity. Simple, linear per operation.

class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.data = []

    def get(self, key):
        i = -1
        for idx, x in enumerate(self.data):
            if x["key"] == key:
                i = idx
                break
        if i < 0:
            return -1
        item = self.data.pop(i)
        self.data.append(item)
        return item["value"]

    def put(self, key, value):
        i = -1
        for idx, x in enumerate(self.data):
            if x["key"] == key:
                i = idx
                break
        if i >= 0:
            self.data.pop(i)
        self.data.append({"key": key, "value": value})
        if len(self.data) > self.capacity:
            self.data.pop(0)


# Method 2: Optimal
# Time: O(1) get/put | Space: O(capacity)
# Map keeps insertion order. On get/put, delete then set so the key is newest. Evict map.keys().next().value, the oldest. O(1) amortized in modern JS engines.

class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.map = {}
        self.order = []

    def get(self, key):
        if key not in self.map:
            return -1
        value = self.map[key]
        self.order.remove(key)
        self.order.append(key)
        return value

    def put(self, key, value):
        if key in self.map:
            self.order.remove(key)
        self.map[key] = value
        self.order.append(key)
        if len(self.map) > self.capacity:
            oldest = self.order.pop(0)
            del self.map[oldest]


# Method 3: More optimal
# Time: O(1) get/put | Space: O(capacity)
# Classic interview design: Map from key to node, plus sentinel doubly linked list. Most recent after head, LRU before tail. Move-to-front on get/put. Evict tail.prev. Shows O(1) without relying on Map order.

class DNode:
    def __init__(self, key=0, val=0):
        self.key = key
        self.val = val
        self.prev = None
        self.next = None

class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.map = {}
        self.head = DNode(0, 0)
        self.tail = DNode(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def _add(self, node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node
        self.head.next = node

    def _remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev

    def get(self, key):
        if key not in self.map:
            return -1
        node = self.map[key]
        self._remove(node)
        self._add(node)
        return node.val

    def put(self, key, value):
        if key in self.map:
            self._remove(self.map[key])
            del self.map[key]
        node = DNode(key, value)
        self._add(node)
        self.map[key] = node
        if len(self.map) > self.capacity:
            lru = self.tail.prev
            self._remove(lru)
            del self.map[lru.key]
