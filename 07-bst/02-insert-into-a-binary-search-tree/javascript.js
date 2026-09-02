// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every key, append val, sort, and rebuild a balanced tree from the middle. Extra arrays; you never use the existing shape.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function insertIntoBST(root, val) {
  const keys = [];
  function go(node) {
    if (!node) return;
    keys.push(node.val);
    go(node.left);
    go(node.right);
  }
  go(root);
  keys.push(val);
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
// Time: O(h) | Space: O(h)
// Recurse left or right and assign the returned child. When the child is null, allocate the new leaf. Root is returned unchanged unless the tree was empty.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function insertIntoBST(root, val) {
  if (!root) return new TreeNode(val);
  if (val < root.val) root.left = insertIntoBST(root.left, val);
  else root.right = insertIntoBST(root.right, val);
  return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative: if the tree is empty, return a new root. Else walk until the next child is null and attach there. No recursion.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function insertIntoBST(root, val) {
  const fresh = new TreeNode(val);
  if (!root) return fresh;
  let cur = root;
  while (true) {
    if (val < cur.val) {
      if (!cur.left) { cur.left = fresh; break; }
      cur = cur.left;
    } else {
      if (!cur.right) { cur.right = fresh; break; }
      cur = cur.right;
    }
  }
  return root;
}
