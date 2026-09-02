// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode each tree as a preorder array with N for null, then compare the arrays. Extra strings/arrays for both trees.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSameTree(p, q) {
  function enc(node, out) {
    if (!node) {
      out.push("N");
      return;
    }
    out.push(String(node.val));
    enc(node.left, out);
    enc(node.right, out);
  }
  const a = [];
  const b = [];
  enc(p, a);
  enc(q, b);
  if (a.length !== b.length) return false;
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) return false;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If both null, true. If one null or vals differ, false. Else both lefts and both rights. Stack O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSameTree(p, q) {
  if (!p && !q) return true;
  if (!p || !q || p.val !== q.val) return false;
  return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative: stack of pairs. Pop two nodes, check null/val, push children pairs. Same complexity, no recursion.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSameTree(p, q) {
  const stack = [[p, q]];
  while (stack.length) {
    const pair = stack.pop();
    const a = pair[0];
    const b = pair[1];
    if (!a && !b) continue;
    if (!a || !b || a.val !== b.val) return false;
    stack.push([a.left, b.left]);
    stack.push([a.right, b.right]);
  }
  return true;
}
