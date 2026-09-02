// Method 1: Brute
// Time: O(n^e) | Space: O(n + e)
// DFS every simple path, copying the visiting array so cycles stop. Keep the best arrival time per node. Exponential on dense graphs.

function networkDelayTime(times, n, k) {
  const g = Array.from({ length: n + 1 }, function () { return []; });
  for (let i = 0; i < times.length; i++) {
    g[times[i][0]].push([times[i][1], times[i][2]]);
  }
  const dist = Array(n + 1).fill(Infinity);
  function dfs(u, d, visiting) {
    if (d >= dist[u]) return;
    dist[u] = d;
    const copy = visiting.slice();
    copy[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i][0], w = g[u][i][1];
      if (copy[v]) continue;
      dfs(v, d + w, copy);
    }
  }
  dfs(k, 0, Array(n + 1).fill(false));
  let ans = 0;
  for (let i = 1; i <= n; i++) ans = Math.max(ans, dist[i]);
  return ans === Infinity ? -1 : ans;
}


// Method 2: Optimal
// Time: O(n² + e) | Space: O(n + e)
// Dijkstra without a heap: each round scan all nodes for the unvisited one with smallest dist. Fine when n is a few hundred. Classic O(n²) Dijkstra.

function networkDelayTime(times, n, k) {
  const g = Array.from({ length: n + 1 }, function () { return []; });
  for (let i = 0; i < times.length; i++) {
    g[times[i][0]].push([times[i][1], times[i][2]]);
  }
  const dist = Array(n + 1).fill(Infinity);
  const used = Array(n + 1).fill(false);
  dist[k] = 0;
  for (let round = 0; round < n; round++) {
    let u = -1;
    for (let i = 1; i <= n; i++) {
      if (used[i]) continue;
      if (u === -1 || dist[i] < dist[u]) u = i;
    }
    if (u === -1 || dist[u] === Infinity) break;
    used[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i][0], w = g[u][i][1];
      if (dist[u] + w < dist[v]) dist[v] = dist[u] + w;
    }
  }
  let ans = 0;
  for (let i = 1; i <= n; i++) ans = Math.max(ans, dist[i]);
  return ans === Infinity ? -1 : ans;
}


// Method 3: More optimal
// Time: O((n + e) log n) | Space: O(n + e)
// Dijkstra with a binary min-heap of [distance, node]. Skip stale pops. This is the usual interview solution for sparse graphs.

function networkDelayTime(times, n, k) {
  const g = Array.from({ length: n + 1 }, function () { return []; });
  for (let i = 0; i < times.length; i++) {
    g[times[i][0]].push([times[i][1], times[i][2]]);
  }
  const dist = Array(n + 1).fill(Infinity);
  dist[k] = 0;
  const heap = [];
  function push(item) {
    heap.push(item);
    let i = heap.length - 1;
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (heap[i][0] >= heap[p][0]) break;
      const t = heap[i]; heap[i] = heap[p]; heap[p] = t;
      i = p;
    }
  }
  function pop() {
    const top = heap[0];
    const last = heap.pop();
    if (!heap.length) return top;
    heap[0] = last;
    let i = 0;
    while (true) {
      let s = i;
      const l = i * 2 + 1, r = l + 1;
      if (l < heap.length && heap[l][0] < heap[s][0]) s = l;
      if (r < heap.length && heap[r][0] < heap[s][0]) s = r;
      if (s === i) break;
      const t = heap[i]; heap[i] = heap[s]; heap[s] = t;
      i = s;
    }
    return top;
  }
  push([0, k]);
  while (heap.length) {
    const cur = pop();
    const d = cur[0], u = cur[1];
    if (d > dist[u]) continue;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i][0], w = g[u][i][1];
      if (d + w < dist[v]) {
        dist[v] = d + w;
        push([dist[v], v]);
      }
    }
  }
  let ans = 0;
  for (let i = 1; i <= n; i++) ans = Math.max(ans, dist[i]);
  return ans === Infinity ? -1 : ans;
}
