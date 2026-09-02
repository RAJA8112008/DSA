// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every root-to-leaf path into arrays, return the longest length. Extra memory for all paths.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function maxDepth(root) {
  const paths = [];
  function go(node, path) {
    if (!node) return;
    path.push(node.val);
    if (!node.left && !node.right) paths.push(path.length);
    go(node.left, path);
    go(node.right, path);
    path.pop();
  }
  go(root, []);
  return paths.length ? Math.max.apply(null, paths) : 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recursive height: null is 0, else 1 + max of children. One visit per node. Stack O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function maxDepth(root) {
  if (!root) return 0;
  return 1 + Math.max(maxDepth(root.left), maxDepth(root.right));
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of {node, depth}. Track the max depth seen. Same complexity, no engine recursion. BFS would use O(width) instead of O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function maxDepth(root) {
  if (!root) return 0;
  let best = 0;
  const stack = [{ node: root, d: 1 }];
  while (stack.length) {
    const { node, d } = stack.pop();
    if (d > best) best = d;
    if (node.left) stack.push({ node: node.left, d: d + 1 });
    if (node.right) stack.push({ node: node.right, d: d + 1 });
  }
  return best;
}
