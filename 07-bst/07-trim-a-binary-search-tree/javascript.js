// Method 1: Brute
// Time: O(n) | Space: O(n)
// Gather every in-range key, sort, rebuild a balanced tree. Correct values, but new nodes and a different shape.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function trimBST(root, low, high) {
  const keys = [];
  function go(node) {
    if (!node) return;
    if (node.val >= low && node.val <= high) keys.push(node.val);
    go(node.left);
    go(node.right);
  }
  go(root);
  keys.sort(function (a, b) { return a - b; });
  function build(lo, hi) {
    if (lo > hi) return null;
    const mid = Math.floor((lo + hi) / 2);
    const node = new TreeNode(keys[mid]);
    node.left = build(lo, mid - 1);
    node.right = build(mid + 1, hi);
    return node;
  }
  return build(0, keys.length - 1);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder prune using the BST property. Reuse the original nodes. If the root is outside the window, drop it and return one trimmed child.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function trimBST(root, low, high) {
  if (!root) return null;
  if (root.val < low) return trimBST(root.right, low, high);
  if (root.val > high) return trimBST(root.left, low, high);
  root.left = trimBST(root.left, low, high);
  root.right = trimBST(root.right, low, high);
  return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Move the root iteratively until it sits inside [low, high], then recursively trim the two sides. Fewer frames when the original root is far outside the window.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function trimBST(root, low, high) {
  while (root && (root.val < low || root.val > high)) {
    root = root.val < low ? root.right : root.left;
  }
  if (!root) return null;
  function trim(node) {
    if (!node) return null;
    if (node.val < low) return trim(node.right);
    if (node.val > high) return trim(node.left);
    node.left = trim(node.left);
    node.right = trim(node.right);
    return node;
  }
  root.left = trim(root.left);
  root.right = trim(root.right);
  return root;
}
