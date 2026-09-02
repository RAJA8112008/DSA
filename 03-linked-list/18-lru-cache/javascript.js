// Method 1: Brute
// Time: O(n) get/put | Space: O(capacity)
// Store pairs in an array. get scans, splices the hit to the end. put updates or appends, then shift if over capacity. Simple, linear per operation.

class LRUCache {
  constructor(capacity) {
    this.capacity = capacity;
    this.data = [];
  }

  get(key) {
    const i = this.data.findIndex((x) => x.key === key);
    if (i < 0) return -1;
    const item = this.data.splice(i, 1)[0];
    this.data.push(item);
    return item.value;
  }

  put(key, value) {
    const i = this.data.findIndex((x) => x.key === key);
    if (i >= 0) this.data.splice(i, 1);
    this.data.push({ key: key, value: value });
    if (this.data.length > this.capacity) this.data.shift();
  }
}


// Method 2: Optimal
// Time: O(1) get/put | Space: O(capacity)
// Map keeps insertion order. On get/put, delete then set so the key is newest. Evict map.keys().next().value, the oldest. O(1) amortized in modern JS engines.

class LRUCache {
  constructor(capacity) {
    this.capacity = capacity;
    this.map = new Map();
  }

  get(key) {
    if (!this.map.has(key)) return -1;
    const value = this.map.get(key);
    this.map.delete(key);
    this.map.set(key, value);
    return value;
  }

  put(key, value) {
    if (this.map.has(key)) this.map.delete(key);
    this.map.set(key, value);
    if (this.map.size > this.capacity) {
      const oldest = this.map.keys().next().value;
      this.map.delete(oldest);
    }
  }
}


// Method 3: More optimal
// Time: O(1) get/put | Space: O(capacity)
// Classic interview design: Map from key to node, plus sentinel doubly linked list. Most recent after head, LRU before tail. Move-to-front on get/put. Evict tail.prev. Shows O(1) without relying on Map order.

function DNode(key, val) {
  this.key = key;
  this.val = val;
  this.prev = null;
  this.next = null;
}

class LRUCache {
  constructor(capacity) {
    this.capacity = capacity;
    this.map = new Map();
    this.head = new DNode(0, 0);
    this.tail = new DNode(0, 0);
    this.head.next = this.tail;
    this.tail.prev = this.head;
  }

  _add(node) {
    node.next = this.head.next;
    node.prev = this.head;
    this.head.next.prev = node;
    this.head.next = node;
  }

  _remove(node) {
    node.prev.next = node.next;
    node.next.prev = node.prev;
  }

  get(key) {
    if (!this.map.has(key)) return -1;
    const node = this.map.get(key);
    this._remove(node);
    this._add(node);
    return node.val;
  }

  put(key, value) {
    if (this.map.has(key)) {
      this._remove(this.map.get(key));
      this.map.delete(key);
    }
    const node = new DNode(key, value);
    this._add(node);
    this.map.set(key, node);
    if (this.map.size > this.capacity) {
      const lru = this.tail.prev;
      this._remove(lru);
      this.map.delete(lru.key);
    }
  }
}
