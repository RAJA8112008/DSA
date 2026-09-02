// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build undirected graph on values (unique). BFS from start. Answer is the max distance.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function amountOfTime(root, start) {
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
  const q = [[start, 0]];
  seen[start] = true;
  let best = 0;
  while (q.length) {
    const pair = q.shift();
    const u = pair[0], d = pair[1];
    if (d > best) best = d;
    const nbrs = g[u] || [];
    for (let i = 0; i < nbrs.length; i++) {
      if (seen[nbrs[i]]) continue;
      seen[nbrs[i]] = true;
      q.push([nbrs[i], d + 1]);
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent pointers, BFS from the start node (find it first). Minutes = max distance.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function amountOfTime(root, start) {
  const parent = new Map();
  let src = null;
  function mark(node, p) {
    if (!node) return;
    parent.set(node, p);
    if (node.val === start) src = node;
    mark(node.left, node);
    mark(node.right, node);
  }
  mark(root, null);
  const seen = new Set();
  const q = [[src, 0]];
  seen.add(src);
  let best = 0;
  while (q.length) {
    const pair = q.shift();
    const node = pair[0], d = pair[1];
    if (d > best) best = d;
    const nbr = [node.left, node.right, parent.get(node)];
    for (let i = 0; i < 3; i++) {
      const nx = nbr[i];
      if (!nx || seen.has(nx)) continue;
      seen.add(nx);
      q.push([nx, d + 1]);
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS returns height of the subtree. When the start node is found, ans is max(height below, distance going up through the parent). One traversal, no graph.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function amountOfTime(root, start) {
  let ans = 0;
  function dfs(node) {
    if (!node) return 0;
    const L = dfs(node.left);
    const R = dfs(node.right);
    if (node.val === start) {
      ans = Math.max(ans, L, R);
      return -1;
    }
    if (L < 0) {
      ans = Math.max(ans, R - L);
      return L - 1;
    }
    if (R < 0) {
      ans = Math.max(ans, L - R);
      return R - 1;
    }
    return 1 + Math.max(L, R);
  }
  dfs(root);
  return ans;
}
