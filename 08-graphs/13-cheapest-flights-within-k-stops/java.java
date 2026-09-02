// Method 1: Brute
// Time: O(n^K) | Space: O(n + e)
// DFS every path with a copied visiting array and a remaining-stop budget. Exponential in K. Easy to write, too slow when K is 20 and the graph is dense.

import java.util.*;
class Solution {
  int best;
  void dfs(List<int[]>[] g, int u, int cost, int stops, boolean[] visiting, int dst) {
    if (cost >= best) return;
    if (u == dst) { best = cost; return; }
    if (stops < 0) return;
    boolean[] copy=visiting.clone(); copy[u]=true;
    for (int[] e : g[u]) if (!copy[e[0]]) dfs(g, e[0], cost+e[1], stops-1, copy, dst);
  }
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    List<int[]>[] g=new ArrayList[n];
    for (int i=0;i<n;i++) g[i]=new ArrayList<int[]>();
    for (int[] f : flights) g[f[0]].add(new int[]{f[1], f[2]});
    best=Integer.MAX_VALUE/4;
    dfs(g, src, 0, k, new boolean[n], dst);
    return best>=Integer.MAX_VALUE/4 ? -1 : best;
  }
}


// Method 2: Optimal
// Time: O(K · e) | Space: O(n)
// Bellman-Ford: relax every flight K+1 times. Copy dist each round so you only use paths with one more flight. Classic for 'at most K edges'.

import java.util.*;
class Solution {
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    int INF=Integer.MAX_VALUE/4;
    int[] dist=new int[n]; Arrays.fill(dist, INF); dist[src]=0;
    for (int round=0; round<=k; round++) {
      int[] next=dist.clone();
      for (int[] f : flights) {
        int u=f[0], v=f[1], w=f[2];
        if (dist[u]==INF) continue;
        if (dist[u]+w < next[v]) next[v]=dist[u]+w;
      }
      dist=next;
    }
    return dist[dst]==INF ? -1 : dist[dst];
  }
}


// Method 3: More optimal
// Time: O(K · e log (K n)) | Space: O(n · K + e)
// Dijkstra on state (city, stops used). A min-heap pops cheapest cost first. best[city][stops] prunes worse repeats. Faster on sparse graphs when K is small.

class Solution {
  java.util.ArrayList<int[]> heap=new java.util.ArrayList<int[]>();
  void push(int[] x) {
    heap.add(x); int i=heap.size()-1;
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
  public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
    java.util.List<int[]>[] g=new java.util.ArrayList[n];
    for (int i=0;i<n;i++) g[i]=new java.util.ArrayList<int[]>();
    for (int[] f : flights) g[f[0]].add(new int[]{f[1], f[2]});
    int INF=Integer.MAX_VALUE/4;
    int[][] best=new int[n][k+2];
    for (int i=0;i<n;i++) java.util.Arrays.fill(best[i], INF);
    best[src][0]=0; push(new int[]{0,src,0});
    while (!heap.isEmpty()) {
      int[] cur=pop(); int cost=cur[0], u=cur[1], used=cur[2];
      if (u==dst) return cost;
      if (used>k) continue;
      for (int[] e : g[u]) {
        int nc=cost+e[1];
        if (nc>=best[e[0]][used+1]) continue;
        best[e[0]][used+1]=nc; push(new int[]{nc,e[0],used+1});
      }
    }
    return -1;
  }
}
