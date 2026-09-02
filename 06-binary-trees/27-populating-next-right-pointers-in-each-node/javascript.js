// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order queue. For each level, node.next = the next polled node, last.next = null.

function Node(val, left, right, next) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
  this.next = next === undefined ? null : next;
}

function connect(root) {
  if (!root) return null;
  const q = [root];
  while (q.length) {
    const n = q.length;
    for (let i = 0; i < n; i++) {
      const node = q.shift();
      if (i + 1 < n) node.next = q[0];
      if (node.left) q.push(node.left);
      if (node.right) q.push(node.right);
    }
  }
  return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// On a perfect tree, left.next = right, and right.next = node.next.left. Recurse both children. Uses the next links already set on this level.

function Node(val, left, right, next) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
  this.next = next === undefined ? null : next;
}

function connect(root) {
  if (!root || !root.left) return root;
  root.left.next = root.right;
  if (root.next) root.right.next = root.next.left;
  connect(root.left);
  connect(root.right);
  return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative: leftmost starts at root. Walk the level via next. Wire children, then leftmost = leftmost.left. No recursion, no queue.

function Node(val, left, right, next) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
  this.next = next === undefined ? null : next;
}

function connect(root) {
  if (!root) return null;
  let leftmost = root;
  while (leftmost.left) {
    let cur = leftmost;
    while (cur) {
      cur.left.next = cur.right;
      if (cur.next) cur.right.next = cur.next.left;
      cur = cur.next;
    }
    leftmost = leftmost.left;
  }
  return root;
}
