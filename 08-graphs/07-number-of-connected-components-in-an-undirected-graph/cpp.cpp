// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// For every unvisited node we DFS with a copied seen array. We still need a global mark so we do not recount. The copies add work without changing the answer.

class Solution {
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
    vector<int> global(n); int count=0;
    for (int i=0;i<n;i++) {
      if (global[i]) continue;
      count++;
      vector<int> seen=global;
      vector<int> st; st.push_back(i); seen[i]=1;
      while (!st.empty()) {
        int u=st.back(); st.pop_back(); global[u]=1;
        for (int v : g[u]) { if (seen[v]) continue; seen[v]=1; st.push_back(v); }
      }
    }
    return count;
  }
};


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Standard connected-component walk. Each start of a DFS on an unseen node is one component. Linear in nodes and edges.

class Solution {
  void dfs(vector<vector<int>>& g, int u, vector<int>& seen) {
    seen[u]=1; for (int v : g[u]) if (!seen[v]) dfs(g,v,seen);
  }
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (auto& e : edges) { g[e[0]].push_back(e[1]); g[e[1]].push_back(e[0]); }
    vector<int> seen(n); int count=0;
    for (int i=0;i<n;i++) { if (seen[i]) continue; count++; dfs(g,i,seen); }
    return count;
  }
};


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// Union-Find with no adjacency list. comps starts at n. Each successful union glues two pieces, so comps drops by 1. Path compression keeps finds cheap.

class Solution {
  int find(vector<int>& p, int x) { while (p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x; }
public:
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<int> parent(n); iota(parent.begin(), parent.end(), 0);
    int comps=n;
    for (auto& e : edges) {
      int a=find(parent,e[0]), b=find(parent,e[1]);
      if (a==b) continue;
      parent[b]=a; comps--;
    }
    return comps;
  }
};
