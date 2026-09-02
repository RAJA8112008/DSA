// Method 1: Brute
// Time: O(n) | Space: O(n)
// Preorder collect nodes into an array. Then set each left to null and next.right to the following node. Extra array.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function flatten(root) {
  const nodes = [];
  function pre(node) {
    if (!node) return;
    nodes.push(node);
    pre(node.left);
    pre(node.right);
  }
  pre(root);
  for (let i = 0; i < nodes.length; i++) {
    nodes[i].left = null;
    nodes[i].right = i + 1 < nodes.length ? nodes[i + 1] : null;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse right, then left, keep a tail pointer of the already flattened suffix. Hang this node in front. Stack O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function flatten(root) {
  const box = { tail: null };
  function go(node) {
    if (!node) return;
    go(node.right);
    go(node.left);
    node.right = box.tail;
    node.left = null;
    box.tail = node;
  }
  go(root);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// While cur exists: if it has a left, find rightmost of left, attach cur.right there, move left to right, clear left. Then cur = cur.right. No extra stack.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function flatten(root) {
  let cur = root;
  while (cur) {
    if (cur.left) {
      let pred = cur.left;
      while (pred.right) pred = pred.right;
      pred.right = cur.right;
      cur.right = cur.left;
      cur.left = null;
    }
    cur = cur.right;
  }
}
