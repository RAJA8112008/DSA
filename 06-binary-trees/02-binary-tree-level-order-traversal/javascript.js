// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS with a depth argument. Push val into levels[depth], creating the row if needed. Extra recursion stack plus the answer.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function levelOrder(root) {
  const levels = [];
  function dfs(node, d) {
    if (!node) return;
    if (!levels[d]) levels[d] = [];
    levels[d].push(node.val);
    dfs(node.left, d + 1);
    dfs(node.right, d + 1);
  }
  dfs(root, 0);
  return levels;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS queue. Each node is stored with its depth. Rows grow as depth increases. Extra pair objects on the queue.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function levelOrder(root) {
  if (!root) return [];
  const levels = [];
  const queue = [{ node: root, d: 0 }];
  while (queue.length) {
    const { node, d } = queue.shift();
    if (!levels[d]) levels[d] = [];
    levels[d].push(node.val);
    if (node.left) queue.push({ node: node.left, d: d + 1 });
    if (node.right) queue.push({ node: node.right, d: d + 1 });
  }
  return levels;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS without storing depth. n = queue.length is the current row size. Process exactly those n nodes, enqueue children for the next row. Cleaner constant factors; still O(width) queue.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function levelOrder(root) {
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
  return levels;
}
