// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Store every node in inorder, copy values, sort the copy, write sorted values back. Structure is unchanged; you sort instead of finding the pair.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function recoverTree(root) {
  const nodes = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    nodes.push(node);
    go(node.right);
  }
  go(root);
  const vals = nodes.map(function (n) { return n.val; });
  vals.sort(function (a, b) { return a - b; });
  for (let i = 0; i < nodes.length; i++) nodes[i].val = vals[i];
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder with a prev pointer. first is the previous node at the first drop. second is the current node at every drop (so adjacent swaps still work). Swap first.val and second.val.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function recoverTree(root) {
  let first = null;
  let second = null;
  let prev = null;
  function go(node) {
    if (!node) return;
    go(node.left);
    if (prev && prev.val > node.val) {
      if (!first) first = prev;
      second = node;
    }
    prev = node;
    go(node.right);
  }
  go(root);
  const tmp = first.val;
  first.val = second.val;
  second.val = tmp;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with the same first/second logic. Thread and unthread predecessor links so you do not keep a stack.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function recoverTree(root) {
  let first = null;
  let second = null;
  let prev = null;
  let cur = root;
  function visit(node) {
    if (prev && prev.val > node.val) {
      if (!first) first = prev;
      second = node;
    }
    prev = node;
  }
  while (cur) {
    if (!cur.left) {
      visit(cur);
      cur = cur.right;
    } else {
      let pred = cur.left;
      while (pred.right && pred.right !== cur) pred = pred.right;
      if (!pred.right) {
        pred.right = cur;
        cur = cur.left;
      } else {
        pred.right = null;
        visit(cur);
        cur = cur.right;
      }
    }
  }
  const tmp = first.val;
  first.val = second.val;
  second.val = tmp;
}
