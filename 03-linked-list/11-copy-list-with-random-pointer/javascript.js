// Method 1: Brute
// Time: O(n) | Space: O(n)
// First pass: clone every node into a Map, next and random left null. Second pass: wire next and random through the map. Two walks, extra map of n nodes.

function Node(val, next, random) {
  this.val = val;
  this.next = next === undefined ? null : next;
  this.random = random === undefined ? null : random;
}

function copyRandomList(head) {
  const map = new Map();
  let cur = head;
  while (cur) {
    map.set(cur, new Node(cur.val));
    cur = cur.next;
  }
  cur = head;
  while (cur) {
    const copy = map.get(cur);
    copy.next = cur.next ? map.get(cur.next) : null;
    copy.random = cur.random ? map.get(cur.random) : null;
    cur = cur.next;
  }
  return head ? map.get(head) : null;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One recursive walk with a Map. If the node is already cloned, return it (handles random cycles). Otherwise clone, then fill next and random. Still O(n) extra map plus stack.

function Node(val, next, random) {
  this.val = val;
  this.next = next === undefined ? null : next;
  this.random = random === undefined ? null : random;
}

function copyRandomList(head) {
  const map = new Map();
  function copy(node) {
    if (!node) return null;
    if (map.has(node)) return map.get(node);
    const cloned = new Node(node.val);
    map.set(node, cloned);
    cloned.next = copy(node.next);
    cloned.random = copy(node.random);
    return cloned;
  }
  return copy(head);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Weave: original -> copy -> original.next. Set copy.random from original.random.next. Unweave into two lists. Extra space is the copies themselves, no hash map. (O(1) auxiliary.)

function Node(val, next, random) {
  this.val = val;
  this.next = next === undefined ? null : next;
  this.random = random === undefined ? null : random;
}

function copyRandomList(head) {
  if (!head) return null;
  let cur = head;
  while (cur) {
    const copy = new Node(cur.val, cur.next, null);
    cur.next = copy;
    cur = copy.next;
  }
  cur = head;
  while (cur) {
    if (cur.random) cur.next.random = cur.random.next;
    cur = cur.next.next;
  }
  const newHead = head.next;
  cur = head;
  while (cur) {
    const copy = cur.next;
    cur.next = copy.next;
    copy.next = copy.next ? copy.next.next : null;
    cur = cur.next;
  }
  return newHead;
}
