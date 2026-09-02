// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder list of nodes, find p, return the next entry. Extra linear memory.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function inorderSuccessor(root, p) {
  const nodes = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    nodes.push(node);
    go(node.right);
  }
  go(root);
  for (let i = 0; i < nodes.length; i++) {
    if (nodes[i] === p) return i + 1 < nodes.length ? nodes[i + 1] : null;
  }
  return null;
}


// Method 2: Optimal
// Time: O(h) | Space: O(1)
// Walk from the root. Whenever the current node is greater than p, it is a candidate successor — go left to hunt a closer one. Otherwise go right.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function inorderSuccessor(root, p) {
  let succ = null;
  let cur = root;
  while (cur) {
    if (p.val < cur.val) {
      succ = cur;
      cur = cur.left;
    } else {
      cur = cur.right;
    }
  }
  return succ;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// If p has a right child, successor is leftmost there — O(h) on that spine only. Else fall back to the root walk. Same worst case, often shorter.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function inorderSuccessor(root, p) {
  if (p.right) {
    let n = p.right;
    while (n.left) n = n.left;
    return n;
  }
  let succ = null;
  let cur = root;
  while (cur) {
    if (p.val < cur.val) {
      succ = cur;
      cur = cur.left;
    } else {
      cur = cur.right;
    }
  }
  return succ;
}
