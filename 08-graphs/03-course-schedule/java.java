// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From every course we DFS with a brand-new onPath array. We redo walks that a single 3-color pass would cache. Fine on tiny n, wasteful on large n.

import java.util.*;
class Solution {
  boolean dfs(List<List<Integer>> g, int u, boolean[] onPath) {
    if (onPath[u]) return false;
    boolean[] copy = onPath.clone();
    copy[u] = true;
    for (int v : g.get(u)) if (!dfs(g, v, copy)) return false;
    return true;
  }
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    for (int i = 0; i < numCourses; i++) g.add(new ArrayList<Integer>());
    for (int[] e : prerequisites) g.get(e[1]).add(e[0]);
    for (int i = 0; i < numCourses; i++)
      if (!dfs(g, i, new boolean[numCourses])) return false;
    return true;
  }
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Three colors: 0 unseen, 1 on the current path, 2 done. Hitting a 1 is a cycle. Finished nodes are skipped, so each edge is walked once.

import java.util.*;
class Solution {
  boolean dfs(List<List<Integer>> g, int u, int[] state) {
    if (state[u] == 1) return false;
    if (state[u] == 2) return true;
    state[u] = 1;
    for (int v : g.get(u)) if (!dfs(g, v, state)) return false;
    state[u] = 2;
    return true;
  }
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    for (int i = 0; i < numCourses; i++) g.add(new ArrayList<Integer>());
    for (int[] e : prerequisites) g.get(e[1]).add(e[0]);
    int[] state = new int[numCourses];
    for (int i = 0; i < numCourses; i++) if (!dfs(g, i, state)) return false;
    return true;
  }
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm: peel indegree-0 courses. If you cannot peel all n courses, a cycle remains. Iterative, no recursion, same linear bound.

import java.util.*;
class Solution {
  public boolean canFinish(int numCourses, int[][] prerequisites) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    int[] indeg = new int[numCourses];
    for (int i = 0; i < numCourses; i++) g.add(new ArrayList<Integer>());
    for (int[] e : prerequisites) { g.get(e[1]).add(e[0]); indeg[e[0]]++; }
    ArrayDeque<Integer> q = new ArrayDeque<Integer>();
    for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.addLast(i);
    int taken = 0;
    while (!q.isEmpty()) {
      int u = q.pollFirst(); taken++;
      for (int v : g.get(u)) { indeg[v]--; if (indeg[v] == 0) q.addLast(v); }
    }
    return taken == numCourses;
  }
}
