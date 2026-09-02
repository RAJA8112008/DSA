// Method 1: Brute
// Time: O(n^e) | Space: O(n + e)
// DFS every simple path, copying the visiting array so cycles stop. Keep the best arrival time per node. Exponential on dense graphs.

#include <stdlib.h>
#include <string.h>
#include <limits.h>
void dfs_nd(int** to, int** w, int* deg, int u, int d, int* dist, int* visiting, int n) {
  if (d >= dist[u]) return;
  dist[u]=d;
  int* copy=(int*)malloc(sizeof(int)*(n+1)); memcpy(copy, visiting, sizeof(int)*(n+1));
  copy[u]=1;
  for (int i=0;i<deg[u];i++) if (!copy[to[u][i]]) dfs_nd(to,w,deg,to[u][i],d+w[u][i],dist,copy,n);
  free(copy);
}
int networkDelayTime(int** times, int e, int n, int k) {
  int* deg=(int*)calloc(n+1,sizeof(int));
  for (int i=0;i<e;i++) deg[times[i][0]]++;
  int** to=(int**)malloc(sizeof(int*)*(n+1));
  int** ww=(int**)malloc(sizeof(int*)*(n+1));
  for (int i=0;i<=n;i++) { to[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); ww[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { int u=times[i][0]; to[u][deg[u]]=times[i][1]; ww[u][deg[u]]=times[i][2]; deg[u]++; }
  int* dist=(int*)malloc(sizeof(int)*(n+1));
  for (int i=0;i<=n;i++) dist[i]=INT_MAX/4;
  int* vis=(int*)calloc(n+1,sizeof(int));
  dfs_nd(to,ww,deg,k,0,dist,vis,n);
  int ans=0;
  for (int i=1;i<=n;i++) if (dist[i]>ans) ans=dist[i];
  return ans>=INT_MAX/4 ? -1 : ans;
}


// Method 2: Optimal
// Time: O(n² + e) | Space: O(n + e)
// Dijkstra without a heap: each round scan all nodes for the unvisited one with smallest dist. Fine when n is a few hundred. Classic O(n²) Dijkstra.

#include <stdlib.h>
#include <limits.h>
int networkDelayTime(int** times, int e, int n, int k) {
  int* deg=(int*)calloc(n+1,sizeof(int));
  for (int i=0;i<e;i++) deg[times[i][0]]++;
  int** to=(int**)malloc(sizeof(int*)*(n+1));
  int** ww=(int**)malloc(sizeof(int*)*(n+1));
  for (int i=0;i<=n;i++) { to[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); ww[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { int u=times[i][0]; to[u][deg[u]]=times[i][1]; ww[u][deg[u]]=times[i][2]; deg[u]++; }
  int INF=INT_MAX/4;
  int* dist=(int*)malloc(sizeof(int)*(n+1));
  int* used=(int*)calloc(n+1,sizeof(int));
  for (int i=0;i<=n;i++) dist[i]=INF; dist[k]=0;
  for (int round=0; round<n; round++) {
    int u=-1;
    for (int i=1;i<=n;i++) { if (used[i]) continue; if (u==-1||dist[i]<dist[u]) u=i; }
    if (u==-1 || dist[u]==INF) break;
    used[u]=1;
    for (int i=0;i<deg[u];i++) if (dist[u]+ww[u][i] < dist[to[u][i]]) dist[to[u][i]]=dist[u]+ww[u][i];
  }
  int ans=0;
  for (int i=1;i<=n;i++) if (dist[i]>ans) ans=dist[i];
  return ans>=INF ? -1 : ans;
}


// Method 3: More optimal
// Time: O((n + e) log n) | Space: O(n + e)
// Dijkstra with a binary min-heap of [distance, node]. Skip stale pops. This is the usual interview solution for sparse graphs.

#include <stdlib.h>
#include <limits.h>
void uph(int* k, int* v, int i) {
  while (i>0) { int p=(i-1)>>1; if (k[i]>=k[p]) break; int t=k[i]; k[i]=k[p]; k[p]=t; t=v[i]; v[i]=v[p]; v[p]=t; i=p; }
}
void downh(int* k, int* v, int n, int i) {
  while (1) { int s=i,l=i*2+1,r=l+1;
    if (l<n && k[l]<k[s]) s=l; if (r<n && k[r]<k[s]) s=r;
    if (s==i) break; int t=k[i]; k[i]=k[s]; k[s]=t; t=v[i]; v[i]=v[s]; v[s]=t; i=s; }
}
int networkDelayTime(int** times, int e, int n, int k) {
  int* deg=(int*)calloc(n+1,sizeof(int));
  for (int i=0;i<e;i++) deg[times[i][0]]++;
  int** to=(int**)malloc(sizeof(int*)*(n+1));
  int** ww=(int**)malloc(sizeof(int*)*(n+1));
  for (int i=0;i<=n;i++) { to[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); ww[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { int u=times[i][0]; to[u][deg[u]]=times[i][1]; ww[u][deg[u]]=times[i][2]; deg[u]++; }
  int INF=INT_MAX/4;
  int* dist=(int*)malloc(sizeof(int)*(n+1));
  for (int i=0;i<=n;i++) dist[i]=INF; dist[k]=0;
  int cap=e*2+8; int* hk=(int*)malloc(sizeof(int)*cap); int* hv=(int*)malloc(sizeof(int)*cap); int sz=0;
  hk[sz]=0; hv[sz]=k; sz++;
  while (sz) {
    int d=hk[0], u=hv[0];
    hk[0]=hk[--sz]; hv[0]=hv[sz]; if (sz) downh(hk,hv,sz,0);
    if (d>dist[u]) continue;
    for (int i=0;i<deg[u];i++) if (d+ww[u][i]<dist[to[u][i]]) {
      dist[to[u][i]]=d+ww[u][i];
      hk[sz]=dist[to[u][i]]; hv[sz]=to[u][i]; sz++; uph(hk,hv,sz-1);
    }
  }
  int ans=0;
  for (int i=1;i<=n;i++) if (dist[i]>ans) ans=dist[i];
  return ans>=INF ? -1 : ans;
}
