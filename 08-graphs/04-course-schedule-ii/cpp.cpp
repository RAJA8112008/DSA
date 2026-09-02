// Method 1: Brute
// Time: O(n! · e) | Space: O(n)
// Generate every permutation of courses and test the prereq edges. Correct for tiny n, unusable at interview sizes. Shows you know 'order' means a permutation that respects edges.

class Solution {
  vector<int> ans;
  bool found;
  bool ok(vector<int>& order, vector<vector<int>>& edges, int n) {
    vector<int> pos(n);
    for (int i = 0; i < n; i++) pos[order[i]] = i;
    for (auto& e : edges) if (pos[e[1]] > pos[e[0]]) return false;
    return true;
  }
  void dfs(int n, vector<vector<int>>& edges, vector<int>& used, vector<int>& path) {
    if (found) return;
    if ((int)path.size() == n) { if (ok(path, edges, n)) { ans = path; found = true; } return; }
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      used[i]=1; path.push_back(i); dfs(n, edges, used, path);
      path.pop_back(); used[i]=0;
    }
  }
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    found = false; ans.clear();
    vector<int> used(numCourses), path;
    dfs(numCourses, prerequisites, used, path);
    return found ? ans : vector<int>{};
  }
};


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// DFS 3-color. After all outgoing edges are done, push the course. Reverse of that list is a topo order. Empty array if a cycle is found.

class Solution {
  bool cycle;
  void dfs(vector<vector<int>>& g, int u, vector<int>& state, vector<int>& out) {
    if (state[u] == 1) { cycle = true; return; }
    if (state[u] == 2) return;
    state[u] = 1;
    for (int v : g[u]) dfs(g, v, state, out);
    state[u] = 2;
    out.push_back(u);
  }
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (auto& e : prerequisites) g[e[1]].push_back(e[0]);
    vector<int> state(numCourses), out;
    cycle = false;
    for (int i = 0; i < numCourses; i++) dfs(g, i, state, out);
    if (cycle) return {};
    reverse(out.begin(), out.end());
    return out;
  }
};


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's BFS builds the order directly: indegree 0 first. If the order is shorter than n, a cycle blocked some courses. No reverse step, no recursion.

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses), order;
    for (auto& e : prerequisites) { g[e[1]].push_back(e[0]); indeg[e[0]]++; }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
    while (!q.empty()) {
      int u = q.front(); q.pop(); order.push_back(u);
      for (int v : g[u]) { indeg[v]--; if (indeg[v] == 0) q.push(v); }
    }
    return (int)order.size() == numCourses ? order : vector<int>{};
  }
};
