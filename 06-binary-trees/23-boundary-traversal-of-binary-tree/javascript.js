// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect all nodes with (isLeft, isRight, isLeaf). Then emit left bound, leaves, reverse right bound, skipping duplicates via a seen set.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function boundaryTraversal(root) {
  if (!root) return [];
  const leftB = [], rightB = [], leaves = [];
  function isLeaf(n) { return n && !n.left && !n.right; }
  function go(node, onLeft, onRight) {
    if (!node) return;
    if (isLeaf(node)) { leaves.push(node.val); return; }
    if (onLeft) leftB.push(node.val);
    else if (onRight) rightB.push(node.val);
    go(node.left, onLeft, onRight && !node.right);
    go(node.right, onLeft && !node.left, onRight);
  }
  if (!isLeaf(root)) leftB.push(root.val);
  go(root.left, true, false);
  go(root.right, false, true);
  if (isLeaf(root)) leaves.push(root.val);
  rightB.reverse();
  return leftB.concat(leaves, rightB);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Three passes: left edge (stop before a leaf), all leaves, right edge into a stack then pop. Clear and classic interview split.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function boundaryTraversal(root) {
  if (!root) return [];
  function isLeaf(n) { return !n.left && !n.right; }
  const out = [];
  if (!isLeaf(root)) out.push(root.val);
  let cur = root.left;
  while (cur) {
    if (!isLeaf(cur)) out.push(cur.val);
    cur = cur.left ? cur.left : cur.right;
  }
  function leaves(node) {
    if (!node) return;
    if (isLeaf(node)) { out.push(node.val); return; }
    leaves(node.left);
    leaves(node.right);
  }
  leaves(root);
  const right = [];
  cur = root.right;
  while (cur) {
    if (!isLeaf(cur)) right.push(cur.val);
    cur = cur.right ? cur.right : cur.left;
  }
  while (right.length) out.push(right.pop());
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// One DFS. Pass whether this node is on the left bound, right bound, or a leaf. Append left-bound before children, leaves in the middle, right-bound after children (so they reverse themselves).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function boundaryTraversal(root) {
  if (!root) return [];
  const out = [];
  function isLeaf(n) { return !n.left && !n.right; }
  function go(node, leftB, rightB) {
    if (!node) return;
    if (isLeaf(node) || leftB) out.push(node.val);
    go(node.left, leftB, rightB && !node.right);
    go(node.right, leftB && !node.left, rightB);
    if (rightB && !isLeaf(node) && !leftB) out.push(node.val);
  }
  if (isLeaf(root)) return [root.val];
  out.push(root.val);
  go(root.left, true, false);
  go(root.right, false, true);
  return out;
}
