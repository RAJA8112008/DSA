// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order lists, then pick the first value of each list.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function leftView(root) {
  if (!root) return [];
  const levels = [];
  const q = [root];
  while (q.length) {
    const n = q.length;
    const row = [];
    for (let i = 0; i < n; i++) {
      const node = q.shift();
      row.push(node.val);
      if (node.left) q.push(node.left);
      if (node.right) q.push(node.right);
    }
    levels.push(row);
  }
  return levels.map(function (row) { return row[0]; });
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// BFS. When i == 0 in the level loop, that node is the left view. w is the widest level.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function leftView(root) {
  if (!root) return [];
  const out = [];
  const q = [root];
  while (q.length) {
    const n = q.length;
    for (let i = 0; i < n; i++) {
      const node = q.shift();
      if (i === 0) out.push(node.val);
      if (node.left) q.push(node.left);
      if (node.right) q.push(node.right);
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS left-first. If depth == out.length this is the first node at that depth. Recursion stack only.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function leftView(root) {
  const out = [];
  function go(node, d) {
    if (!node) return;
    if (d === out.length) out.push(node.val);
    go(node.left, d + 1);
    go(node.right, d + 1);
  }
  go(root, 0);
  return out;
}
