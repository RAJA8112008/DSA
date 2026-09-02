// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Dump all values, then compare every pair. Extra array and quadratic checks.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function getMinimumDifference(root) {
  const vals = [];
  function go(node) {
    if (!node) return;
    vals.push(node.val);
    go(node.left);
    go(node.right);
  }
  go(root);
  let best = Infinity;
  for (let i = 0; i < vals.length; i++) {
    for (let j = i + 1; j < vals.length; j++) {
      const d = Math.abs(vals[i] - vals[j]);
      if (d < best) best = d;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder. Compare each node with the previous inorder value. The min of those adjacent gaps is the global min.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function getMinimumDifference(root) {
  let prev = null;
  let best = Infinity;
  function go(node) {
    if (!node) return;
    go(node.left);
    if (prev !== null) best = Math.min(best, node.val - prev);
    prev = node.val;
    go(node.right);
  }
  go(root);
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with a previous pointer. Same adjacent-gap logic, no stack.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function getMinimumDifference(root) {
  let prev = null;
  let best = Infinity;
  let cur = root;
  while (cur) {
    if (!cur.left) {
      if (prev !== null) best = Math.min(best, cur.val - prev);
      prev = cur.val;
      cur = cur.right;
    } else {
      let pred = cur.left;
      while (pred.right && pred.right !== cur) pred = pred.right;
      if (!pred.right) {
        pred.right = cur;
        cur = cur.left;
      } else {
        pred.right = null;
        if (prev !== null) best = Math.min(best, cur.val - prev);
        prev = cur.val;
        cur = cur.right;
      }
    }
  }
  return best;
}
