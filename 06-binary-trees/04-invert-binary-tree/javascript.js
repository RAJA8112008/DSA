// Method 1: Brute
// Time: O(n) | Space: O(n)
// BFS into an array of every node, then swap left/right on each. Extra list of n pointers.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function invertTree(root) {
  if (!root) return root;
  const nodes = [];
  const queue = [root];
  while (queue.length) {
    const node = queue.shift();
    nodes.push(node);
    if (node.left) queue.push(node.left);
    if (node.right) queue.push(node.right);
  }
  for (const node of nodes) {
    const tmp = node.left;
    node.left = node.right;
    node.right = tmp;
  }
  return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse: invert children, then swap this node's left and right (order of swap vs recurse both work). Stack O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function invertTree(root) {
  if (!root) return null;
  invertTree(root.left);
  invertTree(root.right);
  const tmp = root.left;
  root.left = root.right;
  root.right = tmp;
  return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack. Pop a node, swap children, push non-null children. Same work, no recursion. Queue instead of stack is also fine.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function invertTree(root) {
  if (!root) return null;
  const stack = [root];
  while (stack.length) {
    const node = stack.pop();
    const tmp = node.left;
    node.left = node.right;
    node.right = tmp;
    if (node.left) stack.push(node.left);
    if (node.right) stack.push(node.right);
  }
  return root;
}
