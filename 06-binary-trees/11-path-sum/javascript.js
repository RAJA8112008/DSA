// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records every root-to-leaf path as an array, sums each, compares to target. Extra storage for all paths.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function hasPathSum(root, targetSum) {
  const sums = [];
  function go(node, path) {
    if (!node) return;
    path.push(node.val);
    if (!node.left && !node.right) {
      let s = 0;
      for (const v of path) s += v;
      sums.push(s);
    }
    go(node.left, path);
    go(node.right, path);
    path.pop();
  }
  go(root, []);
  return sums.indexOf(targetSum) !== -1;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse with remaining. At a leaf, remaining === node.val. Else try left or right with remaining - val.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function hasPathSum(root, targetSum) {
  if (!root) return false;
  if (!root.left && !root.right) return root.val === targetSum;
  const rest = targetSum - root.val;
  return hasPathSum(root.left, rest) || hasPathSum(root.right, rest);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of node plus remaining sum. Same check at leaves. No recursion.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function hasPathSum(root, targetSum) {
  if (!root) return false;
  const stack = [{ node: root, left: targetSum }];
  while (stack.length) {
    const { node, left } = stack.pop();
    if (!node.left && !node.right && node.val === left) return true;
    if (node.left) stack.push({ node: node.left, left: left - node.val });
    if (node.right) stack.push({ node: node.right, left: left - node.val });
  }
  return false;
}
