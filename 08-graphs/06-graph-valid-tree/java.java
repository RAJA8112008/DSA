// Method 1: Brute
// Time: O(n + e) | Space: O(n + e)
// Build the list, then from node 0 DFS with a fresh onPath copy at each step to catch a cycle. Count how many nodes were seen. Extra copies are the brute part; the idea (connected + acyclic) is right.

import java.util.*;
class Solution {
  boolean[] seen;
  boolean dfs(List<List<Integer>> g, int u, int parent, boolean[] onPath) {
    if (onPath[u]) return false;
    boolean[] copy = onPath.clone(); copy[u] = true; seen[u] = true;
    for (int v : g.get(u)) {
      if (v == parent) continue;
      if (!dfs(g, v, u, copy)) return false;
    }
    return true;
  }
  public boolean validTree(int n, int[][] edges) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    for (int i = 0; i < n; i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) { g.get(e[0]).add(e[1]); g.get(e[1]).add(e[0]); }
    seen = new boolean[n];
    if (!dfs(g, 0, -1, new boolean[n])) return false;
    for (boolean s : seen) if (!s) return false;
    return true;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A tree must have n-1 edges. Then one BFS/DFS from 0 must reach every node. If it does, there is no extra edge and no missing node, so no cycle.

import java.util.*;
class Solution {
  public boolean validTree(int n, int[][] edges) {
    if (edges.length != n - 1) return false;
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    for (int i = 0; i < n; i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) { g.get(e[0]).add(e[1]); g.get(e[1]).add(e[0]); }
    boolean[] seen = new boolean[n];
    ArrayDeque<Integer> q = new ArrayDeque<Integer>();
    q.addLast(0); seen[0]=true; int count=0;
    while (!q.isEmpty()) {
      int u=q.pollFirst(); count++;
      for (int v : g.get(u)) { if (seen[v]) continue; seen[v]=true; q.addLast(v); }
    }
    return count == n;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Union-Find. If two ends already share a parent, that edge is a cycle. After n-1 successful unions you have one component. No adjacency list needed.

class Solution {
  int find(int[] parent, int x) {
    while (parent[x] != x) { parent[x]=parent[parent[x]]; x=parent[x]; }
    return x;
  }
  public boolean validTree(int n, int[][] edges) {
    if (edges.length != n-1) return false;
    int[] parent = new int[n];
    for (int i=0;i<n;i++) parent[i]=i;
    for (int[] e : edges) {
      int a=find(parent,e[0]), b=find(parent,e[1]);
      if (a==b) return false;
      parent[b]=a;
    }
    return true;
  }
}
