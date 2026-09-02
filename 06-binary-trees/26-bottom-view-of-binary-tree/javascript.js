// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect (hd, depth, index, val), sort, keep the last per hd.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function bottomView(root) {
  const items = [];
  let idx = 0;
  function go(node, hd, d) {
    if (!node) return;
    items.push([hd, d, idx++, node.val]);
    go(node.left, hd - 1, d + 1);
    go(node.right, hd + 1, d + 1);
  }
  go(root, 0, 0);
  items.sort(function (a, b) {
    if (a[0] !== b[0]) return a[0] - b[0];
    if (a[1] !== b[1]) return a[1] - b[1];
    return a[2] - b[2];
  });
  const out = [];
  for (let i = 0; i < items.length; i++) {
    if (i + 1 === items.length || items[i][0] !== items[i + 1][0]) out.push(items[i][3]);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS overwrite per hd. Last write is the deepest (or the right one on a tie). Emit min..max.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function bottomView(root) {
  if (!root) return [];
  const last = {};
  let minH = 0, maxH = 0;
  const q = [[root, 0]];
  while (q.length) {
    const pair = q.shift();
    const node = pair[0], hd = pair[1];
    last[hd] = node.val;
    if (hd < minH) minH = hd;
    if (hd > maxH) maxH = hd;
    if (node.left) q.push([node.left, hd - 1]);
    if (node.right) q.push([node.right, hd + 1]);
  }
  const out = [];
  for (let h = minH; h <= maxH; h++) out.push(last[h]);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS: keep val for hd when depth >= stored depth (overwrite on tie so right-later wins if you visit right after left).

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function bottomView(root) {
  const val = {};
  const dep = {};
  let minH = 0, maxH = 0;
  function go(node, hd, d) {
    if (!node) return;
    if (dep[hd] === undefined || d >= dep[hd]) {
      dep[hd] = d;
      val[hd] = node.val;
    }
    if (hd < minH) minH = hd;
    if (hd > maxH) maxH = hd;
    go(node.left, hd - 1, d + 1);
    go(node.right, hd + 1, d + 1);
  }
  go(root, 0, 0);
  const out = [];
  for (let h = minH; h <= maxH; h++) out.push(val[h]);
  return out;
}
