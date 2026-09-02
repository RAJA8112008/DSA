// Method 1: Brute
// Time: O(n·(n + e)) | Space: O(n + e)
// From every course we DFS with a brand-new onPath array. We redo walks that a single 3-color pass would cache. Fine on tiny n, wasteful on large n.

#include <stdlib.h>
#include <string.h>
int dfs_cf(int** g, int* deg, int u, int* onPath, int n) {
  if (onPath[u]) return 0;
  int* copy = (int*)malloc(sizeof(int)*n);
  memcpy(copy, onPath, sizeof(int)*n);
  copy[u] = 1;
  for (int i = 0; i < deg[u]; i++) if (!dfs_cf(g, deg, g[u][i], copy, n)) { free(copy); return 0; }
  free(copy);
  return 1;
}
int canFinish(int numCourses, int** prerequisites, int e) {
  int* deg = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < e; i++) deg[prerequisites[i][1]]++;
  int** g = (int**)malloc(sizeof(int*)*numCourses);
  for (int i = 0; i < numCourses; i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i = 0; i < e; i++) g[prerequisites[i][1]][deg[prerequisites[i][1]]++] = prerequisites[i][0];
  int* on = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < numCourses; i++) {
    memset(on, 0, sizeof(int)*numCourses);
    if (!dfs_cf(g, deg, i, on, numCourses)) return 0;
  }
  return 1;
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n + e)
// Three colors: 0 unseen, 1 on the current path, 2 done. Hitting a 1 is a cycle. Finished nodes are skipped, so each edge is walked once.

#include <stdlib.h>
int dfs_cf2(int** g, int* deg, int u, int* state) {
  if (state[u] == 1) return 0;
  if (state[u] == 2) return 1;
  state[u] = 1;
  for (int i = 0; i < deg[u]; i++) if (!dfs_cf2(g, deg, g[u][i], state)) return 0;
  state[u] = 2;
  return 1;
}
int canFinish(int numCourses, int** prerequisites, int e) {
  int* deg = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < e; i++) deg[prerequisites[i][1]]++;
  int** g = (int**)malloc(sizeof(int*)*numCourses);
  for (int i = 0; i < numCourses; i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i = 0; i < e; i++) g[prerequisites[i][1]][deg[prerequisites[i][1]]++] = prerequisites[i][0];
  int* state = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < numCourses; i++) if (!dfs_cf2(g, deg, i, state)) return 0;
  return 1;
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n + e)
// Kahn's algorithm: peel indegree-0 courses. If you cannot peel all n courses, a cycle remains. Iterative, no recursion, same linear bound.

#include <stdlib.h>
int canFinish(int numCourses, int** prerequisites, int e) {
  int* deg = (int*)calloc(numCourses, sizeof(int));
  int* indeg = (int*)calloc(numCourses, sizeof(int));
  for (int i = 0; i < e; i++) deg[prerequisites[i][1]]++;
  int** g = (int**)malloc(sizeof(int*)*numCourses);
  for (int i = 0; i < numCourses; i++) { g[i]=(int*)malloc(sizeof(int)*(deg[i]?deg[i]:1)); deg[i]=0; }
  for (int i = 0; i < e; i++) { g[prerequisites[i][1]][deg[prerequisites[i][1]]++] = prerequisites[i][0]; indeg[prerequisites[i][0]]++; }
  int* q = (int*)malloc(sizeof(int)*numCourses); int h=0,t=0;
  for (int i = 0; i < numCourses; i++) if (!indeg[i]) q[t++]=i;
  int taken = 0;
  while (h < t) {
    int u = q[h++]; taken++;
    for (int i = 0; i < deg[u]; i++) { int v=g[u][i]; indeg[v]--; if (!indeg[v]) q[t++]=v; }
  }
  return taken == numCourses;
}
