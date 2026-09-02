// Method 1: Brute
// Time: O(n + e) | Space: O(n + e)
// Build the list, then from node 0 DFS with a fresh onPath copy at each step to catch a cycle. Count how many nodes were seen. Extra copies are the brute part; the idea (connected + acyclic) is right.

function validTree(n, edges) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < edges.length; i++) {
    const u = edges[i][0], v = edges[i][1];
    g[u].push(v);
    g[v].push(u);
  }
  const seen = Array(n).fill(false);
  function dfs(u, parent, onPath) {
    if (onPath[u]) return false;
    const copy = onPath.slice();
    copy[u] = true;
    seen[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i];
      if (v === parent) continue;
      if (!dfs(v, u, copy)) return false;
    }
    return true;
  }
  if (!dfs(0, -1, Array(n).fill(false))) return false;
  for (let i = 0; i < n; i++) if (!seen[i]) return false;
  return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A tree must have n-1 edges. Then one BFS/DFS from 0 must reach every node. If it does, there is no extra edge and no missing node, so no cycle.

function validTree(n, edges) {
  if (edges.length !== n - 1) return false;
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < edges.length; i++) {
    g[edges[i][0]].push(edges[i][1]);
    g[edges[i][1]].push(edges[i][0]);
  }
  const seen = Array(n).fill(false);
  const q = [0];
  seen[0] = true;
  let count = 0;
  while (q.length) {
    const u = q.shift();
    count++;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i];
      if (seen[v]) continue;
      seen[v] = true;
      q.push(v);
    }
  }
  return count === n;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Union-Find. If two ends already share a parent, that edge is a cycle. After n-1 successful unions you have one component. No adjacency list needed.

function validTree(n, edges) {
  if (edges.length !== n - 1) return false;
  const parent = Array.from({ length: n }, function (_, i) { return i; });
  function find(x) {
    while (parent[x] !== x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  for (let i = 0; i < edges.length; i++) {
    const a = find(edges[i][0]);
    const b = find(edges[i][1]);
    if (a === b) return false;
    parent[b] = a;
  }
  return true;
}
