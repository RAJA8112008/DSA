// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// For every unvisited node we DFS with a copied seen array. We still need a global mark so we do not recount. The copies add work without changing the answer.

import java.util.*;
class Solution {
  public int countComponents(int n, int[][] edges) {
    List<List<Integer>> g = new ArrayList<List<Integer>>();
    for (int i=0;i<n;i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) { g.get(e[0]).add(e[1]); g.get(e[1]).add(e[0]); }
    boolean[] global = new boolean[n];
    int count=0;
    for (int i=0;i<n;i++) {
      if (global[i]) continue;
      count++;
      boolean[] seen=global.clone();
      ArrayDeque<Integer> stack=new ArrayDeque<Integer>();
      stack.push(i); seen[i]=true;
      while (!stack.isEmpty()) {
        int u=stack.pop(); global[u]=true;
        for (int v : g.get(u)) { if (seen[v]) continue; seen[v]=true; stack.push(v); }
      }
    }
    return count;
  }
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Standard connected-component walk. Each start of a DFS on an unseen node is one component. Linear in nodes and edges.

import java.util.*;
class Solution {
  void dfs(List<List<Integer>> g, int u, boolean[] seen) {
    seen[u]=true;
    for (int v : g.get(u)) if (!seen[v]) dfs(g, v, seen);
  }
  public int countComponents(int n, int[][] edges) {
    List<List<Integer>> g=new ArrayList<List<Integer>>();
    for (int i=0;i<n;i++) g.add(new ArrayList<Integer>());
    for (int[] e : edges) { g.get(e[0]).add(e[1]); g.get(e[1]).add(e[0]); }
    boolean[] seen=new boolean[n];
    int count=0;
    for (int i=0;i<n;i++) { if (seen[i]) continue; count++; dfs(g,i,seen); }
    return count;
  }
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// Union-Find with no adjacency list. comps starts at n. Each successful union glues two pieces, so comps drops by 1. Path compression keeps finds cheap.

class Solution {
  int find(int[] p, int x) { while (p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x; }
  public int countComponents(int n, int[][] edges) {
    int[] parent=new int[n];
    for (int i=0;i<n;i++) parent[i]=i;
    int comps=n;
    for (int[] e : edges) {
      int a=find(parent,e[0]), b=find(parent,e[1]);
      if (a==b) continue;
      parent[b]=a; comps--;
    }
    return comps;
  }
}
