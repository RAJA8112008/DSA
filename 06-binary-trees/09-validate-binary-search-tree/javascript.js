// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump into an array, then check each pair is strictly increasing. Extra O(n) array.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isValidBST(root) {
  const vals = [];
  function inorder(node) {
    if (!node) return;
    inorder(node.left);
    vals.push(node.val);
    inorder(node.right);
  }
  inorder(root);
  for (let i = 1; i < vals.length; i++) {
    if (vals[i] <= vals[i - 1]) return false;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (low, high). Left child gets high = node.val. Right child gets low = node.val. Use -Infinity / Infinity at the root. Recursion O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isValidBST(root) {
  function ok(node, low, high) {
    if (!node) return true;
    if (node.val <= low || node.val >= high) return false;
    return ok(node.left, low, node.val) && ok(node.right, node.val, high);
  }
  return ok(root, -Infinity, Infinity);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. prev holds the last visited value. If node.val <= prev, fail. No extra values array.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isValidBST(root) {
  const stack = [];
  let cur = root;
  let prev = -Infinity;
  let hasPrev = false;
  while (cur || stack.length) {
    while (cur) {
      stack.push(cur);
      cur = cur.left;
    }
    cur = stack.pop();
    if (hasPrev && cur.val <= prev) return false;
    prev = cur.val;
    hasPrev = true;
    cur = cur.right;
  }
  return true;
}
