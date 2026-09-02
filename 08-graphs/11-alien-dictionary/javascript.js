// Method 1: Brute
// Time: O(k! · n · L) | Space: O(k)
// Collect unique letters, try every permutation, test it against consecutive word pairs. Fine for 3 letters, dead at 20. Proves you know the constraints.

function alienOrder(words) {
  const letters = [];
  const seen = {};
  for (let w = 0; w < words.length; w++) {
    for (let i = 0; i < words[w].length; i++) {
      const ch = words[w][i];
      if (!seen[ch]) { seen[ch] = true; letters.push(ch); }
    }
  }
  function valid(order) {
    const rank = {};
    for (let i = 0; i < order.length; i++) rank[order[i]] = i;
    for (let i = 0; i < words.length - 1; i++) {
      const a = words[i], b = words[i + 1];
      const n = Math.min(a.length, b.length);
      let diff = false;
      for (let j = 0; j < n; j++) {
        if (a[j] !== b[j]) {
          if (rank[a[j]] > rank[b[j]]) return false;
          diff = true;
          break;
        }
      }
      if (!diff && a.length > b.length) return false;
    }
    return true;
  }
  let ans = "";
  function dfs(used, path) {
    if (ans) return;
    if (path.length === letters.length) {
      const s = path.join("");
      if (valid(s)) ans = s;
      return;
    }
    for (let i = 0; i < letters.length; i++) {
      if (used[i]) continue;
      used[i] = true;
      path.push(letters[i]);
      dfs(used, path);
      path.pop();
      used[i] = false;
    }
  }
  dfs(Array(letters.length).fill(false), []);
  return ans;
}


// Method 2: Optimal
// Time: O(n·L + k) | Space: O(k²)
// Build a letter graph from the first mismatch of each consecutive pair. Reject prefix violations. DFS 3-color topo, then reverse the postorder.

function alienOrder(words) {
  const g = {};
  const state = {};
  for (let w = 0; w < words.length; w++) {
    for (let i = 0; i < words[w].length; i++) {
      const ch = words[w][i];
      if (!g[ch]) { g[ch] = new Set(); state[ch] = 0; }
    }
  }
  for (let i = 0; i < words.length - 1; i++) {
    const a = words[i], b = words[i + 1];
    const n = Math.min(a.length, b.length);
    let found = false;
    for (let j = 0; j < n; j++) {
      if (a[j] !== b[j]) {
        g[a[j]].add(b[j]);
        found = true;
        break;
      }
    }
    if (!found && a.length > b.length) return "";
  }
  const out = [];
  let cycle = false;
  function dfs(u) {
    if (state[u] === 1) { cycle = true; return; }
    if (state[u] === 2) return;
    state[u] = 1;
    const nei = Array.from(g[u]);
    for (let i = 0; i < nei.length; i++) dfs(nei[i]);
    state[u] = 2;
    out.push(u);
  }
  const keys = Object.keys(g);
  for (let i = 0; i < keys.length; i++) dfs(keys[i]);
  if (cycle) return "";
  return out.reverse().join("");
}


// Method 3: More optimal
// Time: O(n·L + k) | Space: O(k²)
// Same graph, Kahn's BFS. Letters with indegree 0 come first. If you cannot emit every unique letter, there is a cycle. Iterative and easy to explain.

function alienOrder(words) {
  const g = {};
  const indeg = {};
  for (let w = 0; w < words.length; w++) {
    for (let i = 0; i < words[w].length; i++) {
      const ch = words[w][i];
      if (!g[ch]) { g[ch] = new Set(); indeg[ch] = 0; }
    }
  }
  for (let i = 0; i < words.length - 1; i++) {
    const a = words[i], b = words[i + 1];
    const n = Math.min(a.length, b.length);
    let found = false;
    for (let j = 0; j < n; j++) {
      if (a[j] !== b[j]) {
        if (!g[a[j]].has(b[j])) {
          g[a[j]].add(b[j]);
          indeg[b[j]]++;
        }
        found = true;
        break;
      }
    }
    if (!found && a.length > b.length) return "";
  }
  const q = [];
  const keys = Object.keys(indeg);
  for (let i = 0; i < keys.length; i++) if (indeg[keys[i]] === 0) q.push(keys[i]);
  let order = "";
  while (q.length) {
    const u = q.shift();
    order += u;
    const nei = Array.from(g[u]);
    for (let i = 0; i < nei.length; i++) {
      const v = nei[i];
      indeg[v]--;
      if (indeg[v] === 0) q.push(v);
    }
  }
  return order.length === keys.length ? order : "";
}
