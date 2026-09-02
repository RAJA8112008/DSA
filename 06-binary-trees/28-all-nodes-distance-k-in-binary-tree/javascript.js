// Method 1: Brute
// Time: O(n) | Space: O(n)
// Undirected graph of val->neighbors (vals are unique on LC). BFS from target.val for K steps.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function distanceK(root, target, k) {
  const g = {};
  function link(a, b) {
    if (!g[a]) g[a] = [];
    if (!g[b]) g[b] = [];
    g[a].push(b);
    g[b].push(a);
  }
  function build(node) {
    if (!node) return;
    if (node.left) { link(node.val, node.left.val); build(node.left); }
    if (node.right) { link(node.val, node.right.val); build(node.right); }
  }
  build(root);
  const seen = {};
  const q = [[target.val, 0]];
  seen[target.val] = true;
  const out = [];
  while (q.length) {
    const pair = q.shift();
    const u = pair[0], d = pair[1];
    if (d === k) { out.push(u); continue; }
    const nbrs = g[u] || [];
    for (let i = 0; i < nbrs.length; i++) {
      if (seen[nbrs[i]]) continue;
      seen[nbrs[i]] = true;
      q.push([nbrs[i], d + 1]);
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent map from nodes (not values). BFS from the target node with a visited set of pointers. Collect at distance k.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function distanceK(root, target, k) {
  const parent = new Map();
  function mark(node, p) {
    if (!node) return;
    parent.set(node, p);
    mark(node.left, node);
    mark(node.right, node);
  }
  mark(root, null);
  const seen = new Set();
  const q = [[target, 0]];
  seen.add(target);
  const out = [];
  while (q.length) {
    const pair = q.shift();
    const node = pair[0], d = pair[1];
    if (d === k) { out.push(node.val); continue; }
    const nbr = [node.left, node.right, parent.get(node)];
    for (let i = 0; i < 3; i++) {
      const nx = nbr[i];
      if (!nx || seen.has(nx)) continue;
      seen.add(nx);
      q.push([nx, d + 1]);
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS returns distance from this subtree to target, or -1. When a child reports dist, walk the other child at k - dist - 2, and maybe record this node. Downward walk from target collects depth k.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function distanceK(root, target, k) {
  const out = [];
  function collect(node, dist) {
    if (!node || dist < 0) return;
    if (dist === 0) { out.push(node.val); return; }
    collect(node.left, dist - 1);
    collect(node.right, dist - 1);
  }
  function dfs(node) {
    if (!node) return -1;
    if (node === target) {
      collect(node, k);
      return 0;
    }
    const L = dfs(node.left);
    if (L >= 0) {
      if (L + 1 === k) out.push(node.val);
      else collect(node.right, k - L - 2);
      return L + 1;
    }
    const R = dfs(node.right);
    if (R >= 0) {
      if (R + 1 === k) out.push(node.val);
      else collect(node.left, k - R - 2);
      return R + 1;
    }
    return -1;
  }
  dfs(root);
  return out;
}
