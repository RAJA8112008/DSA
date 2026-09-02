// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At every node, diameter candidate is height(left)+height(right). height itself walks the subtree, so nested walks are quadratic on a skewed tree.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function diameterOfBinaryTree(root) {
  function height(node) {
    if (!node) return 0;
    return 1 + Math.max(height(node.left), height(node.right));
  }
  let best = 0;
  function visit(node) {
    if (!node) return;
    const through = height(node.left) + height(node.right);
    if (through > best) best = through;
    visit(node.left);
    visit(node.right);
  }
  visit(root);
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS returns height. While returning, update best with leftHeight + rightHeight. Each node once.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function diameterOfBinaryTree(root) {
  let best = 0;
  function height(node) {
    if (!node) return 0;
    const lh = height(node.left);
    const rh = height(node.right);
    if (lh + rh > best) best = lh + rh;
    return 1 + Math.max(lh, rh);
  }
  height(root);
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder. A Map stores height after both children are done. Update diameter from those heights. No call stack; extra map of n heights.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function diameterOfBinaryTree(root) {
  if (!root) return 0;
  const stack = [root];
  const seen = new Set();
  const height = new Map();
  height.set(null, 0);
  let best = 0;
  while (stack.length) {
    const node = stack[stack.length - 1];
    if (node.left && !height.has(node.left) && !seen.has(node.left)) {
      stack.push(node.left);
      continue;
    }
    if (node.right && !height.has(node.right) && !seen.has(node.right)) {
      stack.push(node.right);
      continue;
    }
    stack.pop();
    seen.add(node);
    const lh = height.get(node.left) || 0;
    const rh = height.get(node.right) || 0;
    height.set(node, 1 + Math.max(lh, rh));
    if (lh + rh > best) best = lh + rh;
  }
  return best;
}
