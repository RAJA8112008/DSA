// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// For every unvisited node we DFS with a copied seen array. We still need a global mark so we do not recount. The copies add work without changing the answer.

function countComponents(n, edges) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < edges.length; i++) {
    g[edges[i][0]].push(edges[i][1]);
    g[edges[i][1]].push(edges[i][0]);
  }
  const global = Array(n).fill(false);
  let count = 0;
  for (let i = 0; i < n; i++) {
    if (global[i]) continue;
    count++;
    const seen = global.slice();
    const stack = [i];
    seen[i] = true;
    while (stack.length) {
      const u = stack.pop();
      global[u] = true;
      for (let k = 0; k < g[u].length; k++) {
        const v = g[u][k];
        if (seen[v]) continue;
        seen[v] = true;
        stack.push(v);
      }
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Standard connected-component walk. Each start of a DFS on an unseen node is one component. Linear in nodes and edges.

function countComponents(n, edges) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < edges.length; i++) {
    g[edges[i][0]].push(edges[i][1]);
    g[edges[i][1]].push(edges[i][0]);
  }
  const seen = Array(n).fill(false);
  function dfs(u) {
    seen[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      if (!seen[g[u][i]]) dfs(g[u][i]);
    }
  }
  let count = 0;
  for (let i = 0; i < n; i++) {
    if (seen[i]) continue;
    count++;
    dfs(i);
  }
  return count;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// Union-Find with no adjacency list. comps starts at n. Each successful union glues two pieces, so comps drops by 1. Path compression keeps finds cheap.

function countComponents(n, edges) {
  const parent = Array.from({ length: n }, function (_, i) { return i; });
  function find(x) {
    while (parent[x] !== x) {
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }
  let comps = n;
  for (let i = 0; i < edges.length; i++) {
    const a = find(edges[i][0]);
    const b = find(edges[i][1]);
    if (a === b) continue;
    parent[b] = a;
    comps--;
  }
  return comps;
}
