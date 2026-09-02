// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From each start, DFS with a copied onPath array. You repeat walks that 3-color would cache as 'finished'. Extra copies are the brute cost.

#include <stdlib.h>
#include <string.h>
int dfs_hc(int** g, int* deg, int u, int* onPath, int n) {
  if (onPath[u]) return 1;
  int* copy=(int*)malloc(sizeof(int)*n); memcpy(copy,onPath,sizeof(int)*n); copy[u]=1;
  for (int i=0;i<deg[u];i++) if (dfs_hc(g,deg,g[u][i],copy,n)) { free(copy); return 1; }
  free(copy); return 0;
}
int hasCycle(int n, int** edges, int e) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) deg[edges[i][0]]++;
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1];
  int* on=(int*)calloc(n,sizeof(int));
  for (int i=0;i<n;i++) { memset(on,0,sizeof(int)*n); if (dfs_hc(g,deg,i,on,n)) return 1; }
  return 0;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Colors 0/1/2. A neighbor that is still 1 is a back edge, so a cycle. Nodes marked 2 are skipped. Each edge once.

#include <stdlib.h>
int dfs_hc2(int** g, int* deg, int u, int* state) {
  if (state[u]==1) return 1;
  if (state[u]==2) return 0;
  state[u]=1;
  for (int i=0;i<deg[u];i++) if (dfs_hc2(g,deg,g[u][i],state)) return 1;
  state[u]=2;
  return 0;
}
int hasCycle(int n, int** edges, int e) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) deg[edges[i][0]]++;
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1];
  int* state=(int*)calloc(n,sizeof(int));
  for (int i=0;i<n;i++) if (state[i]==0 && dfs_hc2(g,deg,i,state)) return 1;
  return 0;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm. Peel indegree 0. If the number of peeled nodes is less than n, leftover nodes sit in a cycle. Iterative, same linear time.

#include <stdlib.h>
int hasCycle(int n, int** edges, int e) {
  int* deg=(int*)calloc(n,sizeof(int));
  int* indeg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) deg[edges[i][0]]++;
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1]; indeg[edges[i][1]]++; }
  int* q=(int*)malloc(sizeof(int)*n); int h=0,t=0;
  for (int i=0;i<n;i++) if (!indeg[i]) q[t++]=i;
  int peeled=0;
  while (h<t) {
    int u=q[h++]; peeled++;
    for (int i=0;i<deg[u];i++) { int v=g[u][i]; indeg[v]--; if (!indeg[v]) q[t++]=v; }
  }
  return peeled != n;
}
