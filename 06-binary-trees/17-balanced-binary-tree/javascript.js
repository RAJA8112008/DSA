// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node recompute both heights and recurse isBalanced on children. Height work repeats on the same nodes.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isBalanced(root) {
  function height(node) {
    if (!node) return 0;
    return 1 + Math.max(height(node.left), height(node.right));
  }
  if (!root) return true;
  if (Math.abs(height(root.left) - height(root.right)) > 1) return false;
  return isBalanced(root.left) && isBalanced(root.right);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder returns height. If a child is already unbalanced or |lh-rh|>1, return -1 and bubble up. One visit per node.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isBalanced(root) {
  function walk(node) {
    if (!node) return 0;
    const lh = walk(node.left);
    if (lh < 0) return -1;
    const rh = walk(node.right);
    if (rh < 0) return -1;
    if (Math.abs(lh - rh) > 1) return -1;
    return 1 + Math.max(lh, rh);
  }
  return walk(root) >= 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder with a height map. After both children, check |lh-rh| and store height. No recursion.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function isBalanced(root) {
  if (!root) return true;
  const stack = [root];
  const height = new Map();
  height.set(null, 0);
  while (stack.length) {
    const node = stack[stack.length - 1];
    if (node.left && !height.has(node.left)) {
      stack.push(node.left);
      continue;
    }
    if (node.right && !height.has(node.right)) {
      stack.push(node.right);
      continue;
    }
    stack.pop();
    const lh = height.get(node.left) || 0;
    const rh = height.get(node.right) || 0;
    if (Math.abs(lh - rh) > 1) return false;
    height.set(node, 1 + Math.max(lh, rh));
  }
  return true;
}
