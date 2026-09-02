// Method 1: Brute
// Time: O(n! · e) | Space: O(n)
// Generate every permutation of courses and test the prereq edges. Correct for tiny n, unusable at interview sizes. Shows you know 'order' means a permutation that respects edges.

function findOrder(numCourses, prerequisites) {
  const edges = prerequisites;
  function ok(order) {
    const pos = Array(numCourses);
    for (let i = 0; i < order.length; i++) pos[order[i]] = i;
    for (let i = 0; i < edges.length; i++) {
      const a = edges[i][0], b = edges[i][1];
      if (pos[b] > pos[a]) return false;
    }
    return true;
  }
  const used = Array(numCourses).fill(false);
  const path = [];
  let ans = null;
  function dfs() {
    if (ans) return;
    if (path.length === numCourses) {
      if (ok(path)) ans = path.slice();
      return;
    }
    for (let i = 0; i < numCourses; i++) {
      if (used[i]) continue;
      used[i] = true;
      path.push(i);
      dfs();
      path.pop();
      used[i] = false;
    }
  }
  dfs();
  return ans || [];
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// DFS 3-color. After all outgoing edges are done, push the course. Reverse of that list is a topo order. Empty array if a cycle is found.

function findOrder(numCourses, prerequisites) {
  const g = Array.from({ length: numCourses }, function () { return []; });
  for (let i = 0; i < prerequisites.length; i++) {
    g[prerequisites[i][1]].push(prerequisites[i][0]);
  }
  const state = Array(numCourses).fill(0);
  const out = [];
  let cycle = false;

  function dfs(u) {
    if (state[u] === 1) { cycle = true; return; }
    if (state[u] === 2) return;
    state[u] = 1;
    for (let i = 0; i < g[u].length; i++) dfs(g[u][i]);
    state[u] = 2;
    out.push(u);
  }

  for (let i = 0; i < numCourses; i++) dfs(i);
  if (cycle) return [];
  out.reverse();
  return out;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's BFS builds the order directly: indegree 0 first. If the order is shorter than n, a cycle blocked some courses. No reverse step, no recursion.

function findOrder(numCourses, prerequisites) {
  const g = Array.from({ length: numCourses }, function () { return []; });
  const indeg = Array(numCourses).fill(0);
  for (let i = 0; i < prerequisites.length; i++) {
    const a = prerequisites[i][0], b = prerequisites[i][1];
    g[b].push(a);
    indeg[a]++;
  }
  const q = [];
  for (let i = 0; i < numCourses; i++) if (indeg[i] === 0) q.push(i);
  const order = [];
  while (q.length) {
    const u = q.shift();
    order.push(u);
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i];
      indeg[v]--;
      if (indeg[v] === 0) q.push(v);
    }
  }
  return order.length === numCourses ? order : [];
}
