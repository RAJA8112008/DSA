// Method 1: Brute
// Time: O(n^e) | Space: O(n + e)
// DFS every simple path, copying the visiting array so cycles stop. Keep the best arrival time per node. Exponential on dense graphs.

import java.util.*;
class Solution {
  void dfs(List<int[]>[] g, int u, int d, int[] dist, boolean[] visiting) {
    if (d >= dist[u]) return;
    dist[u]=d;
    boolean[] copy=visiting.clone(); copy[u]=true;
    for (int[] e : g[u]) if (!copy[e[0]]) dfs(g, e[0], d+e[1], dist, copy);
  }
  public int networkDelayTime(int[][] times, int n, int k) {
    List<int[]>[] g=new ArrayList[n+1];
    for (int i=0;i<=n;i++) g[i]=new ArrayList<int[]>();
    for (int[] t : times) g[t[0]].add(new int[]{t[1], t[2]});
    int[] dist=new int[n+1];
    Arrays.fill(dist, Integer.MAX_VALUE/4);
    dfs(g, k, 0, dist, new boolean[n+1]);
    int ans=0;
    for (int i=1;i<=n;i++) ans=Math.max(ans, dist[i]);
    return ans >= Integer.MAX_VALUE/4 ? -1 : ans;
  }
}


// Method 2: Optimal
// Time: O(n² + e) | Space: O(n + e)
// Dijkstra without a heap: each round scan all nodes for the unvisited one with smallest dist. Fine when n is a few hundred. Classic O(n²) Dijkstra.

import java.util.*;
class Solution {
  public int networkDelayTime(int[][] times, int n, int k) {
    List<int[]>[] g=new ArrayList[n+1];
    for (int i=0;i<=n;i++) g[i]=new ArrayList<int[]>();
    for (int[] t : times) g[t[0]].add(new int[]{t[1], t[2]});
    int INF=Integer.MAX_VALUE/4;
    int[] dist=new int[n+1]; boolean[] used=new boolean[n+1];
    Arrays.fill(dist, INF); dist[k]=0;
    for (int round=0; round<n; round++) {
      int u=-1;
      for (int i=1;i<=n;i++) {
        if (used[i]) continue;
        if (u==-1 || dist[i]<dist[u]) u=i;
      }
      if (u==-1 || dist[u]==INF) break;
      used[u]=true;
      for (int[] e : g[u]) if (dist[u]+e[1] < dist[e[0]]) dist[e[0]]=dist[u]+e[1];
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=Math.max(ans, dist[i]);
    return ans>=INF ? -1 : ans;
  }
}


// Method 3: More optimal
// Time: O((n + e) log n) | Space: O(n + e)
// Dijkstra with a binary min-heap of [distance, node]. Skip stale pops. This is the usual interview solution for sparse graphs.

class Solution {
  java.util.ArrayList<int[]> heap=new java.util.ArrayList<int[]>();
  void push(int d, int u) {
    heap.add(new int[]{d,u}); int i=heap.size()-1;
    while (i>0) { int p=(i-1)>>1; if (heap.get(i)[0]>=heap.get(p)[0]) break;
      int[] t=heap.get(i); heap.set(i,heap.get(p)); heap.set(p,t); i=p; }
  }
  int[] pop() {
    int[] top=heap.get(0); int[] last=heap.remove(heap.size()-1);
    if (!heap.isEmpty()) { heap.set(0,last); int i=0;
      while (true) { int s=i,l=i*2+1,r=l+1;
        if (l<heap.size()&&heap.get(l)[0]<heap.get(s)[0]) s=l;
        if (r<heap.size()&&heap.get(r)[0]<heap.get(s)[0]) s=r;
        if (s==i) break; int[] t=heap.get(i); heap.set(i,heap.get(s)); heap.set(s,t); i=s; } }
    return top;
  }
  public int networkDelayTime(int[][] times, int n, int k) {
    java.util.List<int[]>[] g=new java.util.ArrayList[n+1];
    for (int i=0;i<=n;i++) g[i]=new java.util.ArrayList<int[]>();
    for (int[] t : times) g[t[0]].add(new int[]{t[1], t[2]});
    int INF=Integer.MAX_VALUE/4;
    int[] dist=new int[n+1]; java.util.Arrays.fill(dist, INF); dist[k]=0;
    push(0,k);
    while (!heap.isEmpty()) {
      int[] cur=pop(); int d=cur[0], u=cur[1];
      if (d>dist[u]) continue;
      for (int[] e : g[u]) if (d+e[1]<dist[e[0]]) { dist[e[0]]=d+e[1]; push(dist[e[0]], e[0]); }
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=Math.max(ans, dist[i]);
    return ans>=INF ? -1 : ans;
  }
}
