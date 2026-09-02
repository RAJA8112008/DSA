// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump every key except key, then rebuild a balanced BST from the sorted list. Simple, but you throw away the original shape.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function deleteNode(root, key) {
  const keys = [];
  function go(node) {
    if (!node) return;
    if (node.val !== key) keys.push(node.val);
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
// Time: O(h) | Space: O(h)
// Recurse to the node. Leaf or one child: return the other child. Two children: copy leftmost of right into node.val, then delete that successor from the right subtree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function deleteNode(root, key) {
  if (!root) return null;
  if (key < root.val) root.left = deleteNode(root.left, key);
  else if (key > root.val) root.right = deleteNode(root.right, key);
  else {
    if (!root.left) return root.right;
    if (!root.right) return root.left;
    let succ = root.right;
    while (succ.left) succ = succ.left;
    root.val = succ.val;
    root.right = deleteNode(root.right, succ.val);
  }
  return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative search with a parent pointer. Splice zero/one-child nodes directly. For two children, copy the successor value then unlink the successor (it has no left child).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function deleteNode(root, key) {
  function splice(parent, node, child) {
    if (!parent) return child;
    if (parent.left === node) parent.left = child;
    else parent.right = child;
    return root;
  }
  let parent = null;
  let cur = root;
  while (cur && cur.val !== key) {
    parent = cur;
    cur = key < cur.val ? cur.left : cur.right;
  }
  if (!cur) return root;
  if (!cur.left) return splice(parent, cur, cur.right);
  if (!cur.right) return splice(parent, cur, cur.left);
  let sp = cur;
  let succ = cur.right;
  while (succ.left) {
    sp = succ;
    succ = succ.left;
  }
  cur.val = succ.val;
  if (sp.left === succ) sp.left = succ.right;
  else sp.right = succ.right;
  return root;
}
