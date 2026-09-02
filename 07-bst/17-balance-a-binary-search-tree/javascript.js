// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Inorder keys, then insert in sorted order into a fresh BST. That rebuilds a stick. Shows why you must pick mids, not insert in order.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function balanceBST(root) {
  const keys = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    keys.push(node.val);
    go(node.right);
  }
  go(root);
  function insert(node, val) {
    if (!node) return new TreeNode(val);
    if (val < node.val) node.left = insert(node.left, val);
    else node.right = insert(node.right, val);
    return node;
  }
  let out = null;
  for (let i = 0; i < keys.length; i++) out = insert(out, keys[i]);
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Inorder into an array, then mid-as-root rebuild. Height is log n. Extra array of keys (or of nodes if you reuse them).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function balanceBST(root) {
  const nodes = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    nodes.push(node);
    go(node.right);
  }
  go(root);
  function build(lo, hi) {
    if (lo > hi) return null;
    const mid = Math.floor((lo + hi) / 2);
    const node = nodes[mid];
    node.left = build(lo, mid - 1);
    node.right = build(mid + 1, hi);
    return node;
  }
  return build(0, nodes.length - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// DSW: rotate every left child to the right to make a vine (linked list of right pointers). Then repeatedly rotate the vine to fold it into a balanced tree. In-place, O(1) extra besides recursion-free loops.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function balanceBST(root) {
  const dummy = new TreeNode(0);
  dummy.right = root;
  function rotateLeft(parent) {
    const child = parent.right;
    parent.right = child.right;
    child.right = parent.right.left;
    parent.right.left = child;
  }
  function rotateRight(parent) {
    const child = parent.right;
    parent.right = child.left;
    child.left = parent.right.right;
    parent.right.right = child;
  }
  function vine() {
    let tail = dummy;
    let rest = dummy.right;
    let n = 0;
    while (rest) {
      if (rest.left) {
        const old = rest;
        rest = rest.left;
        old.left = rest.right;
        rest.right = old;
        tail.right = rest;
      } else {
        tail = rest;
        rest = rest.right;
        n++;
      }
    }
    return n;
  }
  function compress(count) {
    let parent = dummy;
    for (let i = 0; i < count; i++) {
      const child = parent.right;
      parent.right = child.right;
      child.right = parent.right.left;
      parent.right.left = child;
      parent = parent.right;
    }
  }
  const n = vine();
  let m = 1;
  while (m * 2 + 1 <= n) m = m * 2 + 1;
  compress(n - m);
  for (m = m / 2; m >= 1; m = Math.floor(m / 2)) compress(m);
  return dummy.right;
}
