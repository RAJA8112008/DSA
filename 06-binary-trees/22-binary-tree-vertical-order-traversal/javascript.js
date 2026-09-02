// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// DFS push [col, row, val]. Sort by col, then row, then val. Group into lists. Matches LeetCode 987.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function verticalTraversal(root) {
  const items = [];
  function go(node, row, col) {
    if (!node) return;
    items.push([col, row, node.val]);
    go(node.left, row + 1, col - 1);
    go(node.right, row + 1, col + 1);
  }
  go(root, 0, 0);
  items.sort(function (a, b) {
    if (a[0] !== b[0]) return a[0] - b[0];
    if (a[1] !== b[1]) return a[1] - b[1];
    return a[2] - b[2];
  });
  const out = [];
  for (let i = 0; i < items.length; i++) {
    if (!out.length || items[i][0] !== items[i - 1][0]) out.push([]);
    out[out.length - 1].push(items[i][2]);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n log w) | Space: O(n)
// BFS so row order is natural. TreeMap / sorted map of columns. GFG order (no value sort). w is the number of columns.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function verticalOrder(root) {
  if (!root) return [];
  const cols = {};
  let minH = 0, maxH = 0;
  const q = [[root, 0]];
  while (q.length) {
    const pair = q.shift();
    const node = pair[0], hd = pair[1];
    if (!cols[hd]) cols[hd] = [];
    cols[hd].push(node.val);
    if (hd < minH) minH = hd;
    if (hd > maxH) maxH = hd;
    if (node.left) q.push([node.left, hd - 1]);
    if (node.right) q.push([node.right, hd + 1]);
  }
  const out = [];
  for (let h = minH; h <= maxH; h++) out.push(cols[h]);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same BFS. Record min and max hd, then emit columns in a plain loop. No log w map.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function verticalOrder(root) {
  if (!root) return [];
  const nodes = [root];
  const hds = [0];
  let minH = 0, maxH = 0;
  for (let i = 0; i < nodes.length; i++) {
    const node = nodes[i], hd = hds[i];
    if (hd < minH) minH = hd;
    if (hd > maxH) maxH = hd;
    if (node.left) { nodes.push(node.left); hds.push(hd - 1); }
    if (node.right) { nodes.push(node.right); hds.push(hd + 1); }
  }
  const out = [];
  for (let h = minH; h <= maxH; h++) out.push([]);
  for (let i = 0; i < nodes.length; i++) out[hds[i] - minH].push(nodes[i].val);
  return out;
}
