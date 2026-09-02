// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order into rows, then map each row to its last value. Extra storage for every node value.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function rightSideView(root) {
  if (!root) return [];
  const levels = [];
  const queue = [root];
  while (queue.length) {
    const n = queue.length;
    const row = [];
    for (let i = 0; i < n; i++) {
      const node = queue.shift();
      row.push(node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
    levels.push(row);
  }
  return levels.map(function (row) {
    return row[row.length - 1];
  });
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS visit right child first. If depth === ans.length, this is the first node seen at that depth from the right. Recursion O(h).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function rightSideView(root) {
  const ans = [];
  function dfs(node, d) {
    if (!node) return;
    if (d === ans.length) ans.push(node.val);
    dfs(node.right, d + 1);
    dfs(node.left, d + 1);
  }
  dfs(root, 0);
  return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(w)
// BFS. For each level of size n, the last shifted node is the right-side value. Only the answer plus the queue, no full row arrays.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function rightSideView(root) {
  if (!root) return [];
  const ans = [];
  const queue = [root];
  while (queue.length) {
    const n = queue.length;
    for (let i = 0; i < n; i++) {
      const node = queue.shift();
      if (i === n - 1) ans.push(node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    }
  }
  return ans;
}
