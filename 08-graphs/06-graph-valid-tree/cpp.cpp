// Method 1: Brute
// Time: O(n + e) | Space: O(n + e)
// Build the list, then from node 0 DFS with a fresh onPath copy at each step to catch a cycle. Count how many nodes were seen. Extra copies are the brute part; the idea (connected + acyclic) is right.

class Solution {
  vector<int> seen;
  bool dfs(vector<vector<int>>& g, int u, int parent, vector<int> onPath) {
    if (onPath[u]) return false;
    onPath[u]=1; seen[u]=1;
    for (int v : g[u]) {
      if (v==parent) continue;
      if (!dfs(g, v, u, onPath)) return false;
    }
    return true;
  }
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
    seen.assign(n, 0);
    if (!dfs(g, 0, -1, vector<int>(n))) return false;
    for (int i=0;i<n;i++) if (!seen[i]) return false;
    return true;
  }
};


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A tree must have n-1 edges. Then one BFS/DFS from 0 must reach every node. If it does, there is no extra edge and no missing node, so no cycle.

class Solution {
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if ((int)edges.size() != n-1) return false;
    vector<vector<int>> g(n);
    for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
    vector<int> seen(n); queue<int> q; q.push(0); seen[0]=1; int count=0;
    while (!q.empty()) {
      int u=q.front(); q.pop(); count++;
      for (int v : g[u]) { if (seen[v]) continue; seen[v]=1; q.push(v); }
    }
    return count == n;
  }
};


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Union-Find. If two ends already share a parent, that edge is a cycle. After n-1 successful unions you have one component. No adjacency list needed.

class Solution {
  int find(vector<int>& p, int x) {
    while (p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x;
  }
public:
  bool validTree(int n, vector<vector<int>>& edges) {
    if ((int)edges.size()!=n-1) return false;
    vector<int> parent(n); iota(parent.begin(), parent.end(), 0);
    for (auto& e : edges) {
      int a=find(parent,e[0]), b=find(parent,e[1]);
      if (a==b) return false;
      parent[b]=a;
    }
    return true;
  }
};
