// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode the left subtree left-to-right with nulls, encode the right subtree right-to-left with nulls, compare. Extra arrays.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSymmetric(root) {
  if (!root) return true;
  function enc(node, leftFirst, out) {
    if (!node) {
      out.push("N");
      return;
    }
    out.push(String(node.val));
    if (leftFirst) {
      enc(node.left, true, out);
      enc(node.right, true, out);
    } else {
      enc(node.right, false, out);
      enc(node.left, false, out);
    }
  }
  const a = [];
  const b = [];
  enc(root.left, true, a);
  enc(root.right, false, b);
  if (a.length !== b.length) return false;
  for (let i = 0; i < a.length; i++) {
    if (a[i] !== b[i]) return false;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// mirror(a,b): both null ok; one null fail; vals equal and mirror(a.left,b.right) and mirror(a.right,b.left). Recurse from root.left and root.right.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSymmetric(root) {
  function mirror(a, b) {
    if (!a && !b) return true;
    if (!a || !b || a.val !== b.val) return false;
    return mirror(a.left, b.right) && mirror(a.right, b.left);
  }
  if (!root) return true;
  return mirror(root.left, root.right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Queue of node pairs. Dequeue a and b, check, enqueue a.left with b.right and a.right with b.left. Iterative mirror test.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isSymmetric(root) {
  if (!root) return true;
  const queue = [root.left, root.right];
  while (queue.length) {
    const a = queue.shift();
    const b = queue.shift();
    if (!a && !b) continue;
    if (!a || !b || a.val !== b.val) return false;
    queue.push(a.left, b.right);
    queue.push(a.right, b.left);
  }
  return true;
}
