// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From every course we DFS with a brand-new onPath array. We redo walks that a single 3-color pass would cache. Fine on tiny n, wasteful on large n.

class Solution {
  bool dfs(vector<vector<int>>& g, int u, vector<int> onPath) {
    if (onPath[u]) return false;
    onPath[u] = 1;
    for (int v : g[u]) if (!dfs(g, v, onPath)) return false;
    return true;
  }
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (auto& e : prerequisites) g[e[1]].push_back(e[0]);
    for (int i = 0; i < numCourses; i++)
      if (!dfs(g, i, vector<int>(numCourses))) return false;
    return true;
  }
};


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Three colors: 0 unseen, 1 on the current path, 2 done. Hitting a 1 is a cycle. Finished nodes are skipped, so each edge is walked once.

class Solution {
  bool dfs(vector<vector<int>>& g, int u, vector<int>& state) {
    if (state[u] == 1) return false;
    if (state[u] == 2) return true;
    state[u] = 1;
    for (int v : g[u]) if (!dfs(g, v, state)) return false;
    state[u] = 2;
    return true;
  }
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    for (auto& e : prerequisites) g[e[1]].push_back(e[0]);
    vector<int> state(numCourses);
    for (int i = 0; i < numCourses; i++) if (!dfs(g, i, state)) return false;
    return true;
  }
};


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm: peel indegree-0 courses. If you cannot peel all n courses, a cycle remains. Iterative, no recursion, same linear bound.

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> g(numCourses);
    vector<int> indeg(numCourses);
    for (auto& e : prerequisites) { g[e[1]].push_back(e[0]); indeg[e[0]]++; }
    queue<int> q;
    for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
    int taken = 0;
    while (!q.empty()) {
      int u = q.front(); q.pop(); taken++;
      for (int v : g[u]) { indeg[v]--; if (indeg[v] == 0) q.push(v); }
    }
    return taken == numCourses;
  }
};
