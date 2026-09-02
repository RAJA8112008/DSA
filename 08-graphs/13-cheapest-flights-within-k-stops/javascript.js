// Method 1: Brute
// Time: O(n^K) | Space: O(n + e)
// DFS every path with a copied visiting array and a remaining-stop budget. Exponential in K. Easy to write, too slow when K is 20 and the graph is dense.

function findCheapestPrice(n, flights, src, dst, k) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < flights.length; i++) {
    g[flights[i][0]].push([flights[i][1], flights[i][2]]);
  }
  let best = Infinity;
  function dfs(u, cost, stops, visiting) {
    if (cost >= best) return;
    if (u === dst) { best = cost; return; }
    if (stops < 0) return;
    const copy = visiting.slice();
    copy[u] = true;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i][0], w = g[u][i][1];
      if (copy[v]) continue;
      dfs(v, cost + w, stops - 1, copy);
    }
  }
  dfs(src, 0, k, Array(n).fill(false));
  return best === Infinity ? -1 : best;
}


// Method 2: Optimal
// Time: O(K · e) | Space: O(n)
// Bellman-Ford: relax every flight K+1 times. Copy dist each round so you only use paths with one more flight. Classic for 'at most K edges'.

function findCheapestPrice(n, flights, src, dst, k) {
  let dist = Array(n).fill(Infinity);
  dist[src] = 0;
  for (let round = 0; round <= k; round++) {
    const next = dist.slice();
    for (let i = 0; i < flights.length; i++) {
      const u = flights[i][0], v = flights[i][1], w = flights[i][2];
      if (dist[u] === Infinity) continue;
      if (dist[u] + w < next[v]) next[v] = dist[u] + w;
    }
    dist = next;
  }
  return dist[dst] === Infinity ? -1 : dist[dst];
}


// Method 3: More optimal
// Time: O(K · e log (K n)) | Space: O(n · K + e)
// Dijkstra on state (city, stops used). A min-heap pops cheapest cost first. best[city][stops] prunes worse repeats. Faster on sparse graphs when K is small.

function findCheapestPrice(n, flights, src, dst, k) {
  const g = Array.from({ length: n }, function () { return []; });
  for (let i = 0; i < flights.length; i++) {
    g[flights[i][0]].push([flights[i][1], flights[i][2]]);
  }
  const best = Array.from({ length: n }, function () {
    return Array(k + 2).fill(Infinity);
  });
  const heap = [];
  function push(x) {
    heap.push(x);
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
  best[src][0] = 0;
  push([0, src, 0]);
  while (heap.length) {
    const cur = pop();
    const cost = cur[0], u = cur[1], used = cur[2];
    if (u === dst) return cost;
    if (used > k) continue;
    for (let i = 0; i < g[u].length; i++) {
      const v = g[u][i][0], w = g[u][i][1];
      const nc = cost + w;
      if (nc >= best[v][used + 1]) continue;
      best[v][used + 1] = nc;
      push([nc, v, used + 1]);
    }
  }
  return -1;
}
