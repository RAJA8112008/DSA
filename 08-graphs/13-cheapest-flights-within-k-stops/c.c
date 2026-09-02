// Method 1: Brute
// Time: O(n^K) | Space: O(n + e)
// DFS every path with a copied visiting array and a remaining-stop budget. Exponential in K. Easy to write, too slow when K is 20 and the graph is dense.

#include <stdlib.h>
#include <string.h>
#include <limits.h>
int best_cf;
void dfs_cf3(int** to, int** w, int* deg, int u, int cost, int stops, int* visiting, int n, int dst) {
  if (cost >= best_cf) return;
  if (u==dst) { best_cf=cost; return; }
  if (stops<0) return;
  int* copy=(int*)malloc(sizeof(int)*n); memcpy(copy,visiting,sizeof(int)*n); copy[u]=1;
  for (int i=0;i<deg[u];i++) if (!copy[to[u][i]]) dfs_cf3(to,w,deg,to[u][i],cost+w[u][i],stops-1,copy,n,dst);
  free(copy);
}
int findCheapestPrice(int n, int** flights, int e, int src, int dst, int k) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) deg[flights[i][0]]++;
  int** to=(int**)malloc(sizeof(int*)*n); int** ww=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { to[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); ww[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { int u=flights[i][0]; to[u][deg[u]]=flights[i][1]; ww[u][deg[u]]=flights[i][2]; deg[u]++; }
  best_cf=INT_MAX/4;
  int* vis=(int*)calloc(n,sizeof(int));
  dfs_cf3(to,ww,deg,src,0,k,vis,n,dst);
  return best_cf>=INT_MAX/4 ? -1 : best_cf;
}


// Method 2: Optimal
// Time: O(K · e) | Space: O(n)
// Bellman-Ford: relax every flight K+1 times. Copy dist each round so you only use paths with one more flight. Classic for 'at most K edges'.

#include <stdlib.h>
#include <limits.h>
int findCheapestPrice(int n, int** flights, int e, int src, int dst, int k) {
  int INF=INT_MAX/4;
  int* dist=(int*)malloc(sizeof(int)*n);
  int* next=(int*)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++) dist[i]=INF; dist[src]=0;
  for (int round=0; round<=k; round++) {
    for (int i=0;i<n;i++) next[i]=dist[i];
    for (int i=0;i<e;i++) {
      int u=flights[i][0], v=flights[i][1], w=flights[i][2];
      if (dist[u]==INF) continue;
      if (dist[u]+w < next[v]) next[v]=dist[u]+w;
    }
    int* tmp=dist; dist=next; next=tmp;
  }
  return dist[dst]==INF ? -1 : dist[dst];
}


// Method 3: More optimal
// Time: O(K · e log (K n)) | Space: O(n · K + e)
// Dijkstra on state (city, stops used). A min-heap pops cheapest cost first. best[city][stops] prunes worse repeats. Faster on sparse graphs when K is small.

#include <stdlib.h>
#include <limits.h>
void up3(int* a, int* b, int* c, int i) {
  while (i>0) { int p=(i-1)>>1; if (a[i]>=a[p]) break;
    int t=a[i]; a[i]=a[p]; a[p]=t; t=b[i]; b[i]=b[p]; b[p]=t; t=c[i]; c[i]=c[p]; c[p]=t; i=p; }
}
void down3(int* a, int* b, int* c, int n, int i) {
  while (1) { int s=i,l=i*2+1,r=l+1;
    if (l<n && a[l]<a[s]) s=l; if (r<n && a[r]<a[s]) s=r;
    if (s==i) break; int t=a[i]; a[i]=a[s]; a[s]=t; t=b[i]; b[i]=b[s]; b[s]=t; t=c[i]; c[i]=c[s]; c[s]=t; i=s; }
}
int findCheapestPrice(int n, int** flights, int e, int src, int dst, int k) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) deg[flights[i][0]]++;
  int** to=(int**)malloc(sizeof(int*)*n); int** ww=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { to[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); ww[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { int u=flights[i][0]; to[u][deg[u]]=flights[i][1]; ww[u][deg[u]]=flights[i][2]; deg[u]++; }
  int INF=INT_MAX/4;
  int** best=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { best[i]=(int*)malloc(sizeof(int)*(k+2)); for (int j=0;j<k+2;j++) best[i][j]=INF; }
  int cap=n*(k+3); int* ha=(int*)malloc(sizeof(int)*cap); int* hb=(int*)malloc(sizeof(int)*cap); int* hc=(int*)malloc(sizeof(int)*cap); int sz=0;
  best[src][0]=0; ha[sz]=0; hb[sz]=src; hc[sz]=0; sz++;
  while (sz) {
    int cost=ha[0], u=hb[0], used=hc[0];
    ha[0]=ha[--sz]; hb[0]=hb[sz]; hc[0]=hc[sz]; if (sz) down3(ha,hb,hc,sz,0);
    if (u==dst) return cost;
    if (used>k) continue;
    for (int i=0;i<deg[u];i++) {
      int nc=cost+ww[u][i];
      if (nc>=best[to[u][i]][used+1]) continue;
      best[to[u][i]][used+1]=nc;
      ha[sz]=nc; hb[sz]=to[u][i]; hc[sz]=used+1; sz++; up3(ha,hb,hc,sz-1);
    }
  }
  return -1;
}
