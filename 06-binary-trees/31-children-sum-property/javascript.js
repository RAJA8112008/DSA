// Method 1: Brute
// Time: O(n) | Space: O(n)
// For every node, sum the two children (0 if null) and compare. Recurse both sides. Extra list of all nodes first.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSumTree(root) {
  const nodes = [];
  function go(node) {
    if (!node) return;
    nodes.push(node);
    go(node.left);
    go(node.right);
  }
  go(root);
  for (let i = 0; i < nodes.length; i++) {
    const n = nodes[i];
    if (!n.left && !n.right) continue;
    const L = n.left ? n.left.val : 0;
    const R = n.right ? n.right.val : 0;
    if (n.val !== L + R) return false;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder boolean. Null and leaves are true. Then check val == left+right and both subtrees hold.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSumTree(root) {
  if (!root) return true;
  if (!root.left && !root.right) return true;
  const L = root.left ? root.left.val : 0;
  const R = root.right ? root.right.val : 0;
  return root.val === L + R && isSumTree(root.left) && isSumTree(root.right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Return a pair (ok, val) so a failed subtree aborts. Same checks, one value returned upward.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSumTree(root) {
  function go(node) {
    if (!node) return { ok: true, val: 0 };
    if (!node.left && !node.right) return { ok: true, val: node.val };
    const L = go(node.left);
    const R = go(node.right);
    const ok = L.ok && R.ok && node.val === L.val + R.val;
    return { ok: ok, val: node.val };
  }
  return go(root).ok;
}
