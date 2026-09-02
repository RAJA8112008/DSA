// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump all values, then check each pair is strictly increasing. Extra array holds the whole walk.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isValidBST(root) {
  const vals = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    vals.push(node.val);
    go(node.right);
  }
  go(root);
  for (let i = 1; i < vals.length; i++) {
    if (vals[i] <= vals[i - 1]) return false;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (lo, hi). Left child inherits hi = node.val; right inherits lo = node.val. Use a type wider than int so INT_MIN / INT_MAX are legal node values.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isValidBST(root) {
  function ok(node, lo, hi) {
    if (!node) return true;
    if (node.val <= lo || node.val >= hi) return false;
    return ok(node.left, lo, node.val) && ok(node.right, node.val, hi);
  }
  return ok(root, -Infinity, Infinity);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. Track the previous value. If the current node is not greater, the tree is invalid. No extra value array.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isValidBST(root) {
  const stack = [];
  let cur = root;
  let prev = null;
  while (cur || stack.length) {
    while (cur) {
      stack.push(cur);
      cur = cur.left;
    }
    cur = stack.pop();
    if (prev !== null && cur.val <= prev) return false;
    prev = cur.val;
    cur = cur.right;
  }
  return true;
}
