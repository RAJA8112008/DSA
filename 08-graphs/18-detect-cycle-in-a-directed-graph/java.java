// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From each start, DFS with a copied onPath array. You repeat walks that 3-color would cache as 'finished'. Extra copies are the brute cost.

import java.util.*;
class Solution {
  boolean dfs(List<List<Integer>> g, int u, boolean[] onPath) {
    if (onPath[u]) return true;
    boolean[] copy=onPath.clone(); copy[u]=true;
    for (int v : g.get(u)) if (dfs(g, v, copy)) return true;
    return false;
  }
  public boolean hasCycle(int n, int[][] edges) {
    List<List<Integer>> g=new ArrayList<List<Integer>>();
    for (int i=0;i<n;i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) g.get(e[0]).add(e[1]);
    for (int i=0;i<n;i++) if (dfs(g, i, new boolean[n])) return true;
    return false;
  }
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Colors 0/1/2. A neighbor that is still 1 is a back edge, so a cycle. Nodes marked 2 are skipped. Each edge once.

import java.util.*;
class Solution {
  boolean dfs(List<List<Integer>> g, int u, int[] state) {
    if (state[u]==1) return true;
    if (state[u]==2) return false;
    state[u]=1;
    for (int v : g.get(u)) if (dfs(g, v, state)) return true;
    state[u]=2;
    return false;
  }
  public boolean hasCycle(int n, int[][] edges) {
    List<List<Integer>> g=new ArrayList<List<Integer>>();
    for (int i=0;i<n;i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) g.get(e[0]).add(e[1]);
    int[] state=new int[n];
    for (int i=0;i<n;i++) if (state[i]==0 && dfs(g, i, state)) return true;
    return false;
  }
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm. Peel indegree 0. If the number of peeled nodes is less than n, leftover nodes sit in a cycle. Iterative, same linear time.

import java.util.*;
class Solution {
  public boolean hasCycle(int n, int[][] edges) {
    List<List<Integer>> g=new ArrayList<List<Integer>>();
    int[] indeg=new int[n];
    for (int i=0;i<n;i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) { g.get(e[0]).add(e[1]); indeg[e[1]]++; }
    ArrayDeque<Integer> q=new ArrayDeque<Integer>();
    for (int i=0;i<n;i++) if (indeg[i]==0) q.addLast(i);
    int peeled=0;
    while (!q.isEmpty()) {
      int u=q.pollFirst(); peeled++;
      for (int v : g.get(u)) { indeg[v]--; if (indeg[v]==0) q.addLast(v); }
    }
    return peeled != n;
  }
}
