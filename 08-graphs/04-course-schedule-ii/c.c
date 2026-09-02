// Method 1: Brute
// Time: O(n! · e) | Space: O(n)
// Generate every permutation of courses and test the prereq edges. Correct for tiny n, unusable at interview sizes. Shows you know 'order' means a permutation that respects edges.

#include <stdlib.h>
int ok_ord(int* order, int n, int** edges, int e) {
  int* pos = (int*)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) pos[order[i]] = i;
  int good = 1;
  for (int i = 0; i < e; i++) if (pos[edges[i][1]] > pos[edges[i][0]]) good = 0;
  free(pos);
  return good;
}
int* ans_g; int found_g;
void dfs_fo(int n, int** edges, int e, int* used, int* path, int plen) {
  if (found_g) return;
  if (plen == n) {
    if (ok_ord(path, n, edges, e)) { for (int i=0;i<n;i++) ans_g[i]=path[i]; found_g=1; }
    return;
  }
  for (int i = 0; i < n; i++) {
    if (used[i]) continue;
    used[i]=1; path[plen]=i; dfs_fo(n, edges, e, used, path, plen+1);
    used[i]=0;
  }
}
int* findOrder(int numCourses, int** prerequisites, int e, int* returnSize) {
  ans_g = (int*)malloc(sizeof(int)*numCourses); found_g = 0;
  int* used = (int*)calloc(numCourses, sizeof(int));
  int* path = (int*)malloc(sizeof(int)*numCourses);
  dfs_fo(numCourses, prerequisites, e, used, path, 0);
  *returnSize = found_g ? numCourses : 0;
  return ans_g;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// DFS 3-color. After all outgoing edges are done, push the course. Reverse of that list is a topo order. Empty array if a cycle is found.

#include <stdlib.h>
int cycle_g;
void dfs_fo2(int** g, int* deg, int u, int* state, int* out, int* on) {
  if (state[u] == 1) { cycle_g = 1; return; }
  if (state[u] == 2) return;
  state[u] = 1;
  for (int i = 0; i < deg[u]; i++) dfs_fo2(g, deg, g[u][i], state, out, on);
  state[u] = 2;
  out[(*on)++] = u;
}
int* findOrder(int numCourses, int** prerequisites, int e, int* returnSize) {
  int* deg = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < e; i++) deg[prerequisites[i][1]]++;
  int** g = (int**)malloc(sizeof(int*)*numCourses);
  for (int i = 0; i < numCourses; i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i = 0; i < e; i++) g[prerequisites[i][1]][deg[prerequisites[i][1]]++] = prerequisites[i][0];
  int* state = (int*)calloc(numCourses, sizeof(int));
  int* out = (int*)malloc(sizeof(int)*numCourses); int on = 0;
  cycle_g = 0;
  for (int i = 0; i < numCourses; i++) dfs_fo2(g, deg, i, state, out, &on);
  if (cycle_g) { *returnSize = 0; return out; }
  for (int i = 0; i < on/2; i++) { int t=out[i]; out[i]=out[on-1-i]; out[on-1-i]=t; }
  *returnSize = numCourses;
  return out;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's BFS builds the order directly: indegree 0 first. If the order is shorter than n, a cycle blocked some courses. No reverse step, no recursion.

#include <stdlib.h>
int* findOrder(int numCourses, int** prerequisites, int e, int* returnSize) {
  int* deg = (int*)calloc(numCourses, sizeof(int));
  int* indeg = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < e; i++) deg[prerequisites[i][1]]++;
  int** g = (int**)malloc(sizeof(int*)*numCourses);
  for (int i = 0; i < numCourses; i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i = 0; i < e; i++) { g[prerequisites[i][1]][deg[prerequisites[i][1]]++] = prerequisites[i][0]; indeg[prerequisites[i][0]]++; }
  int* q = (int*)malloc(sizeof(int)*numCourses); int h=0,t=0;
  for (int i = 0; i < numCourses; i++) if (!indeg[i]) q[t++]=i;
  int* order = (int*)malloc(sizeof(int)*numCourses); int p=0;
  while (h<t) {
    int u=q[h++]; order[p++]=u;
    for (int i=0;i<deg[u];i++) { int v=g[u][i]; indeg[v]--; if (!indeg[v]) q[t++]=v; }
  }
  *returnSize = (p==numCourses) ? numCourses : 0;
  return order;
}
