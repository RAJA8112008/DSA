// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect every (hd, depth, val), sort, keep the first (smallest depth) per hd.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function topView(root) {
  const items = [];
  function go(node, hd, d) {
    if (!node) return;
    items.push([hd, d, node.val]);
    go(node.left, hd - 1, d + 1);
    go(node.right, hd + 1, d + 1);
  }
  go(root, 0, 0);
  items.sort(function (a, b) {
    if (a[0] !== b[0]) return a[0] - b[0];
    return a[1] - b[1];
  });
  const out = [];
  let prev = null;
  for (let i = 0; i < items.length; i++) {
    if (prev === null || items[i][0] !== prev) {
      out.push(items[i][2]);
      prev = items[i][0];
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS. The first time an hd appears, record it. Then emit from min hd to max hd.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function topView(root) {
  if (!root) return [];
  const first = {};
  let minH = 0, maxH = 0;
  const q = [[root, 0]];
  while (q.length) {
    const pair = q.shift();
    const node = pair[0], hd = pair[1];
    if (first[hd] === undefined) first[hd] = node.val;
    if (hd < minH) minH = hd;
    if (hd > maxH) maxH = hd;
    if (node.left) q.push([node.left, hd - 1]);
    if (node.right) q.push([node.right, hd + 1]);
  }
  const out = [];
  for (let h = minH; h <= maxH; h++) out.push(first[h]);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS with depth. Keep a node for hd only if this depth is smaller. Then scan min..max hd. No queue.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function topView(root) {
  const bestVal = {};
  const bestD = {};
  let minH = 0, maxH = 0;
  function go(node, hd, d) {
    if (!node) return;
    if (bestD[hd] === undefined || d < bestD[hd]) {
      bestD[hd] = d;
      bestVal[hd] = node.val;
    }
    if (hd < minH) minH = hd;
    if (hd > maxH) maxH = hd;
    go(node.left, hd - 1, d + 1);
    go(node.right, hd + 1, d + 1);
  }
  go(root, 0, 0);
  const out = [];
  for (let h = minH; h <= maxH; h++) out.push(bestVal[h]);
  return out;
}
