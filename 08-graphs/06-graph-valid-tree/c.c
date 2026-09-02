// Method 1: Brute
// Time: O(n + e) | Space: O(n + e)
// Build the list, then from node 0 DFS with a fresh onPath copy at each step to catch a cycle. Count how many nodes were seen. Extra copies are the brute part; the idea (connected + acyclic) is right.

#include <stdlib.h>
#include <string.h>
int seen_vt[10005];
int dfs_vt(int** g, int* deg, int u, int parent, int* onPath, int n) {
  if (onPath[u]) return 0;
  int* copy=(int*)malloc(sizeof(int)*n); memcpy(copy,onPath,sizeof(int)*n);
  copy[u]=1; seen_vt[u]=1;
  for (int i=0;i<deg[u];i++) {
    int v=g[u][i]; if (v==parent) continue;
    if (!dfs_vt(g,deg,v,u,copy,n)) { free(copy); return 0; }
  }
  free(copy); return 1;
}
int validTree(int n, int** edges, int e) {
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) { deg[edges[i][0]]++; deg[edges[i][1]]++; }
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1]; g[edges[i][1]][deg[edges[i][1]]++]=edges[i][0]; }
  memset(seen_vt,0,sizeof(int)*n);
  int* on=(int*)calloc(n,sizeof(int));
  if (!dfs_vt(g,deg,0,-1,on,n)) return 0;
  for (int i=0;i<n;i++) if (!seen_vt[i]) return 0;
  return 1;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A tree must have n-1 edges. Then one BFS/DFS from 0 must reach every node. If it does, there is no extra edge and no missing node, so no cycle.

#include <stdlib.h>
int validTree(int n, int** edges, int e) {
  if (e != n-1) return 0;
  int* deg=(int*)calloc(n,sizeof(int));
  for (int i=0;i<e;i++) { deg[edges[i][0]]++; deg[edges[i][1]]++; }
  int** g=(int**)malloc(sizeof(int*)*n);
  for (int i=0;i<n;i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i=0;i<e;i++) { g[edges[i][0]][deg[edges[i][0]]++]=edges[i][1]; g[edges[i][1]][deg[edges[i][1]]++]=edges[i][0]; }
  int* seen=(int*)calloc(n,sizeof(int));
  int* q=(int*)malloc(sizeof(int)*n); int h=0,t=0,count=0;
  q[t++]=0; seen[0]=1;
  while (h<t) { int u=q[h++]; count++;
    for (int i=0;i<deg[u];i++) { int v=g[u][i]; if (seen[v]) continue; seen[v]=1; q[t++]=v; }
  }
  return count==n;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Union-Find. If two ends already share a parent, that edge is a cycle. After n-1 successful unions you have one component. No adjacency list needed.

#include <stdlib.h>
int find_vt(int* p, int x) { while (p[x]!=x) { p[x]=p[p[x]]; x=p[x]; } return x; }
int validTree(int n, int** edges, int e) {
  if (e != n-1) return 0;
  int* parent=(int*)malloc(sizeof(int)*n);
  for (int i=0;i<n;i++) parent[i]=i;
  for (int i=0;i<e;i++) {
    int a=find_vt(parent,edges[i][0]), b=find_vt(parent,edges[i][1]);
    if (a==b) return 0;
    parent[b]=a;
  }
  return 1;
}
