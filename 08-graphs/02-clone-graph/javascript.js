// Method 1: Brute
// Time: O(n + e) | Space: O(n)
// One shared old-to-new map is required so a node is cloned once. The extra Set copy on every call is wasted; it does not change correctness. Drop the copies and you get Optimal.

function cloneGraph(node) {
  if (!node) return null;
  const map = new Map();

  function dfs(cur, seenCopy) {
    if (map.has(cur)) return map.get(cur);
    const copy = { val: cur.val, neighbors: [] };
    map.set(cur, copy);
    const nextSeen = new Set(seenCopy);
    nextSeen.add(cur);
    for (let i = 0; i < cur.neighbors.length; i++) {
      copy.neighbors.push(dfs(cur.neighbors[i], nextSeen));
    }
    return copy;
  }

  return dfs(node, new Set());
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n)
// One Map from old node to new node. DFS creates the clone, then fills neighbors. Each node and edge is processed once.

function cloneGraph(node) {
  if (!node) return null;
  const map = new Map();

  function dfs(cur) {
    if (map.has(cur)) return map.get(cur);
    const copy = { val: cur.val, neighbors: [] };
    map.set(cur, copy);
    for (let i = 0; i < cur.neighbors.length; i++) {
      copy.neighbors.push(dfs(cur.neighbors[i]));
    }
    return copy;
  }

  return dfs(node);
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// BFS with the same map avoids deep recursion on a long chain. Complexity matches DFS. Prefer this when the graph can be a long path.

function cloneGraph(node) {
  if (!node) return null;
  const map = new Map();
  map.set(node, { val: node.val, neighbors: [] });
  const q = [node];
  while (q.length) {
    const cur = q.shift();
    const copy = map.get(cur);
    for (let i = 0; i < cur.neighbors.length; i++) {
      const nei = cur.neighbors[i];
      if (!map.has(nei)) {
        map.set(nei, { val: nei.val, neighbors: [] });
        q.push(nei);
      }
      copy.neighbors.push(map.get(nei));
    }
  }
  return map.get(node);
}
