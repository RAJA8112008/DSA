// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// Collect every root-to-leaf path, then keep those whose sum equals target. Path copies dominate memory.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function pathSum(root, targetSum) {
  const paths = [];
  function go(node, path) {
    if (!node) return;
    path.push(node.val);
    if (!node.left && !node.right) paths.push(path.slice());
    go(node.left, path);
    go(node.right, path);
    path.pop();
  }
  go(root, []);
  return paths.filter(function (p) {
    let s = 0;
    for (let i = 0; i < p.length; i++) s += p[i];
    return s === targetSum;
  });
}


// Method 2: Optimal
// Time: O(n²) | Space: O(h)
// Backtracking. remain starts at targetSum. At a leaf, if remain == node.val, snapshot the path. Copying a path is O(h); total output can be O(n²).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function pathSum(root, targetSum) {
  const out = [];
  function go(node, remain, path) {
    if (!node) return;
    path.push(node.val);
    if (!node.left && !node.right && remain === node.val) out.push(path.slice());
    go(node.left, remain - node.val, path);
    go(node.right, remain - node.val, path);
    path.pop();
  }
  go(root, targetSum, []);
  return out;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Iterative stack of {node, remain, path}. Same snapshots at leaves. Avoids call-stack overflow on a stick, still copies paths.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function pathSum(root, targetSum) {
  if (!root) return [];
  const out = [];
  const stack = [{ node: root, remain: targetSum, path: [root.val] }];
  while (stack.length) {
    const cur = stack.pop();
    const node = cur.node;
    if (!node.left && !node.right && cur.remain === node.val) out.push(cur.path);
    if (node.right) stack.push({ node: node.right, remain: cur.remain - node.val, path: cur.path.concat([node.right.val]) });
    if (node.left) stack.push({ node: node.left, remain: cur.remain - node.val, path: cur.path.concat([node.left.val]) });
  }
  return out;
}
