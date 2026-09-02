// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From each start, DFS with a copied onPath array. You repeat walks that 3-color would cache as 'finished'. Extra copies are the brute cost.

class Solution {
  bool dfs(vector<vector<int>>& g, int u, vector<int> onPath) {
    if (onPath[u]) return true;
    onPath[u]=1;
    for (int v : g[u]) if (dfs(g, v, onPath)) return true;
    return false;
  }
public:
  bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) g[e[0]].push_back(e[1]);
    for (int i=0;i<n;i++) if (dfs(g, i, vector<int>(n))) return true;
    return false;
  }
};


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Colors 0/1/2. A neighbor that is still 1 is a back edge, so a cycle. Nodes marked 2 are skipped. Each edge once.

class Solution {
  bool dfs(vector<vector<int>>& g, int u, vector<int>& state) {
    if (state[u]==1) return true;
    if (state[u]==2) return false;
    state[u]=1;
    for (int v : g[u]) if (dfs(g, v, state)) return true;
    state[u]=2;
    return false;
  }
public:
  bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) g[e[0]].push_back(e[1]);
    vector<int> state(n);
    for (int i=0;i<n;i++) if (state[i]==0 && dfs(g, i, state)) return true;
    return false;
  }
};


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm. Peel indegree 0. If the number of peeled nodes is less than n, leftover nodes sit in a cycle. Iterative, same linear time.

class Solution {
public:
  bool hasCycle(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    vector<int> indeg(n);
    for (auto& e : edges) { g[e[0]].push_back(e[1]); indeg[e[1]]++; }
    queue<int> q;
    for (int i=0;i<n;i++) if (indeg[i]==0) q.push(i);
    int peeled=0;
    while (!q.empty()) {
      int u=q.front(); q.pop(); peeled++;
      for (int v : g[u]) { indeg[v]--; if (indeg[v]==0) q.push(v); }
    }
    return peeled != n;
  }
};
