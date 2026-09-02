// Method 1: Brute
// Time: O(n) | Space: O(h)
// DFS every node. Add val when it is inside the interval. Correct on a plain binary tree too.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function rangeSumBST(root, low, high) {
  if (!root) return 0;
  const add = root.val >= low && root.val <= high ? root.val : 0;
  return add + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Prune: skip left when node is below low, skip right when node is above high. Best case you only walk the in-range corridor.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function rangeSumBST(root, low, high) {
  if (!root) return 0;
  if (root.val < low) return rangeSumBST(root.right, low, high);
  if (root.val > high) return rangeSumBST(root.left, low, high);
  return root.val + rangeSumBST(root.left, low, high) + rangeSumBST(root.right, low, high);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Explicit stack, same prune. No recursion. Push only children that can still hold in-range keys.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function rangeSumBST(root, low, high) {
  let sum = 0;
  const stack = [];
  if (root) stack.push(root);
  while (stack.length) {
    const node = stack.pop();
    if (node.val >= low && node.val <= high) sum += node.val;
    if (node.left && node.val > low) stack.push(node.left);
    if (node.right && node.val < high) stack.push(node.right);
  }
  return sum;
}
