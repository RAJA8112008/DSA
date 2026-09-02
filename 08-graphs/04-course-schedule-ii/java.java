// Method 1: Brute
// Time: O(n! · e) | Space: O(n)
// Generate every permutation of courses and test the prereq edges. Correct for tiny n, unusable at interview sizes. Shows you know 'order' means a permutation that respects edges.

import java.util.*;
class Solution {
  int[] ans;
  boolean ok(int[] order, int[][] edges, int n) {
    int[] pos = new int[n];
    for (int i = 0; i < order.length; i++) pos[order[i]] = i;
    for (int[] e : edges) if (pos[e[1]] > pos[e[0]]) return false;
    return true;
  }
  void dfs(int n, int[][] edges, boolean[] used, ArrayList<Integer> path) {
    if (ans != null) return;
    if (path.size() == n) {
      int[] o = new int[n];
      for (int i = 0; i < n; i++) o[i] = path.get(i);
      if (ok(o, edges, n)) ans = o;
      return;
    }
    for (int i = 0; i < n; i++) {
      if (used[i]) continue;
      used[i] = true; path.add(i); dfs(n, edges, used, path);
      path.remove(path.size()-1); used[i] = false;
    }
  }
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    ans = null;
    dfs(numCourses, prerequisites, new boolean[numCourses], new ArrayList<Integer>());
    return ans != null ? ans : new int[0];
  }
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// DFS 3-color. After all outgoing edges are done, push the course. Reverse of that list is a topo order. Empty array if a cycle is found.

import java.util.*;
class Solution {
  boolean cycle;
  void dfs(List<List<Integer>> g, int u, int[] state, List<Integer> out) {
    if (state[u] == 1) { cycle = true; return; }
    if (state[u] == 2) return;
    state[u] = 1;
    for (int v : g.get(u)) dfs(g, v, state, out);
    state[u] = 2;
    out.add(u);
  }
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    for (int i = 0; i < numCourses; i++) g.add(new ArrayList<Integer>());
    for (int[] e : prerequisites) g.get(e[1]).add(e[0]);
    int[] state = new int[numCourses];
    List<Integer> out = new ArrayList<Integer>();
    cycle = false;
    for (int i = 0; i < numCourses; i++) dfs(g, i, state, out);
    if (cycle) return new int[0];
    Collections.reverse(out);
    int[] a = new int[numCourses];
    for (int i = 0; i < numCourses; i++) a[i] = out.get(i);
    return a;
  }
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's BFS builds the order directly: indegree 0 first. If the order is shorter than n, a cycle blocked some courses. No reverse step, no recursion.

import java.util.*;
class Solution {
  public int[] findOrder(int numCourses, int[][] prerequisites) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    int[] indeg = new int[numCourses];
    for (int i = 0; i < numCourses; i++) g.add(new ArrayList<Integer>());
    for (int[] e : prerequisites) { g.get(e[1]).add(e[0]); indeg[e[0]]++; }
    ArrayDeque<Integer> q = new ArrayDeque<Integer>();
    for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.addLast(i);
    int[] order = new int[numCourses]; int p = 0;
    while (!q.isEmpty()) {
      int u = q.pollFirst(); order[p++] = u;
      for (int v : g.get(u)) { indeg[v]--; if (indeg[v] == 0) q.addLast(v); }
    }
    return p == numCourses ? order : new int[0];
  }
}
