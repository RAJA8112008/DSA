// Method 1: Brute
// Time: O(n) | Space: O(n)
// Ignore the BST. DFS every node into a list, then scan for val. Correct on any binary tree, but you throw away the ordering.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function searchBST(root, val) {
  const nodes = [];
  function go(node) {
    if (!node) return;
    nodes.push(node);
    go(node.left);
    go(node.right);
  }
  go(root);
  for (let i = 0; i < nodes.length; i++) {
    if (nodes[i].val === val) return nodes[i];
  }
  return null;
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse on one child. Each call compares val with the node and drops a whole subtree. Stack depth is the height.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function searchBST(root, val) {
  if (!root || root.val === val) return root;
  if (val < root.val) return searchBST(root.left, val);
  return searchBST(root.right, val);
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same comparisons in a while loop. No call stack. Returns the node or null when the walk falls off.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function searchBST(root, val) {
  let cur = root;
  while (cur && cur.val !== val) {
    cur = val < cur.val ? cur.left : cur.right;
  }
  return cur;
}
