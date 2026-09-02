// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// For every unvisited node we DFS with a copied seen array. We still need a global mark so we do not recount. The copies add work without changing the answer.

#include <stdlib.h>
#include <string.h>
int countComponents(int n, int** edges, int e) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) { deg[edges[i][0]]++; deg[edges[i][1]]++; }
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1]; g[edges[i][1]][deg[edges[i][1]]++]=edges[i][0]; }
  int* global=(int*)calloc(n,sizeof(int));
  int* seen=(int*)malloc(sizeof(int)*n);
  int* st=(int*)malloc(sizeof(int)*n);
  int count=0;
  for (int i=0;i<n;i++) {
    if (global[i]) continue;
    count++;
    memcpy(seen,global,sizeof(int)*n);
    int sn=0; st[sn++]=i; seen[i]=1;
    while (sn) {
      int u=st[--sn]; global[u]=1;
      for (int k=0;k<deg[u];k++) { int v=g[u][i]; /* bug */ v=g[u][k]; if (seen[v]) continue; seen[v]=1; st[sn++]=v; }
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Standard connected-component walk. Each start of a DFS on an unseen node is one component. Linear in nodes and edges.

#include <stdlib.h>
void dfs_cc(int** g, int* deg, int u, int* seen) {
  seen[u]=1;
  for (int i=0;i<deg[u];i++) if (!seen[g[u][i]]) dfs_cc(g,deg,g[u][i],seen);
}
int countComponents(int n, int** edges, int e) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) { deg[edges[i][0]]++; deg[edges[i][1]]++; }
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1]; g[edges[i][1]][deg[edges[i][1]]++]=edges[i][0]; }
  int* seen=(int*)calloc(n,sizeof(int)); int count=0;
  for (int i=0;i<n;i++) { if (seen[i]) continue; count++; dfs_cc(g,deg,i,seen); }
  return count;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// Union-Find with no adjacency list. comps starts at n. Each successful union glues two pieces, so comps drops by 1. Path compression keeps finds cheap.

#include <stdlib.h>
int find_cc(int* p, int x) { while (p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x; }
int countComponents(int n, int** edges, int e) {
  int* parent=(int*)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++) parent[i]=i;
  int comps=n;
  for (int i=0;i<e;i++) {
    int a=find_cc(parent,edges[i][0]), b=find_cc(parent,edges[i][1]);
    if (a==b) continue;
    parent[b]=a; comps--;
  }
  return comps;
}
