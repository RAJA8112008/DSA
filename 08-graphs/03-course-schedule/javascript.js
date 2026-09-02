// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From every course we DFS with a brand-new onPath array. We redo walks that a single 3-color pass would cache. Fine on tiny n, wasteful on large n.

function canFinish(numCourses, prerequisites) {
  const g = Array.from({ length: numCourses }, function () { return []; });
  for (let i = 0; i < prerequisites.length; i++) {
    const a = prerequisites[i][0];
    const b = prerequisites[i][1];
    g[b].push(a);
  }

  function dfs(u, onPath) {
    if (onPath[u]) return false;
    const copy = onPath.slice();
    copy[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      if (!dfs(g[u][i], copy)) return false;
    }
    return true;
  }

  for (let i = 0; i < numCourses; i++) {
    if (!dfs(i, Array(numCourses).fill(false))) return false;
  }
  return true;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Three colors: 0 unseen, 1 on the current path, 2 done. Hitting a 1 is a cycle. Finished nodes are skipped, so each edge is walked once.

function canFinish(numCourses, prerequisites) {
  const g = Array.from({ length: numCourses }, function () { return []; });
  for (let i = 0; i < prerequisites.length; i++) {
    g[prerequisites[i][1]].push(prerequisites[i][0]);
  }
  const state = Array(numCourses).fill(0);

  function dfs(u) {
    if (state[u] === 1) return false;
    if (state[u] === 2) return true;
    state[u] = 1;
    for (let i = 0; i < g[u].length; i++) {
      if (!dfs(g[u][i])) return false;
    }
    state[u] = 2;
    return true;
  }

  for (let i = 0; i < numCourses; i++) {
    if (!dfs(i)) return false;
  }
  return true;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm: peel indegree-0 courses. If you cannot peel all n courses, a cycle remains. Iterative, no recursion, same linear bound.

function canFinish(numCourses, prerequisites) {
  const g = Array.from({ length: numCourses }, function () { return []; });
  const indeg = Array(numCourses).fill(0);
  for (let i = 0; i < prerequisites.length; i++) {
    const a = prerequisites[i][0];
    const b = prerequisites[i][1];
    g[b].push(a);
    indeg[a]++;
  }
  const q = [];
  for (let i = 0; i < numCourses; i++) if (indeg[i] === 0) q.push(i);
  let taken = 0;
  while (q.length) {
    const u = q.shift();
    taken++;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i];
      indeg[v]--;
      if (indeg[v] === 0) q.push(v);
    }
  }
  return taken === numCourses;
}
