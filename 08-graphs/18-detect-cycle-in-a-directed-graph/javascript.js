// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From each start, DFS with a copied onPath array. You repeat walks that 3-color would cache as 'finished'. Extra copies are the brute cost.

function hasCycle(n, edges) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < edges.length; i++) g[edges[i][0]].push(edges[i][1]);

  function dfs(u, onPath) {
    if (onPath[u]) return true;
    const copy = onPath.slice();
    copy[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      if (dfs(g[u][i], copy)) return true;
    }
    return false;
  }

  for (let i = 0; i < n; i++) {
    if (dfs(i, Array(n).fill(false))) return true;
  }
  return false;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Colors 0/1/2. A neighbor that is still 1 is a back edge, so a cycle. Nodes marked 2 are skipped. Each edge once.

function hasCycle(n, edges) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < edges.length; i++) g[edges[i][0]].push(edges[i][1]);
  const state = Array(n).fill(0);
  function dfs(u) {
    if (state[u] === 1) return true;
    if (state[u] === 2) return false;
    state[u] = 1;
    for (let i = 0; i < g[u].length; i++) {
      if (dfs(g[u][i])) return true;
    }
    state[u] = 2;
    return false;
  }
  for (let i = 0; i < n; i++) {
    if (state[i] === 0 && dfs(i)) return true;
  }
  return false;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm. Peel indegree 0. If the number of peeled nodes is less than n, leftover nodes sit in a cycle. Iterative, same linear time.

function hasCycle(n, edges) {
  const g = Array.from({ length: n }, function () { return []; });
  const indeg = Array(n).fill(0);
  for (let i = 0; i < edges.length; i++) {
    g[edges[i][0]].push(edges[i][1]);
    indeg[edges[i][1]]++;
  }
  const q = [];
  for (let i = 0; i < n; i++) if (indeg[i] === 0) q.push(i);
  let peeled = 0;
  while (q.length) {
    const u = q.shift();
    peeled++;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i];
      indeg[v]--;
      if (indeg[v] === 0) q.push(v);
    }
  }
  return peeled !== n;
}
