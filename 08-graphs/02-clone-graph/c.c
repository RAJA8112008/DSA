// Method 1: Brute
// Time: O(n + e) | Space: O(n)
// One shared old-to-new map is required so a node is cloned once. The extra Set copy on every call is wasted; it does not change correctness. Drop the copies and you get Optimal.

#include <stdlib.h>
struct Node { int val; int numNeighbors; struct Node** neighbors; };
struct Pair { struct Node* old; struct Node* neu; };
struct Node* cloneGraph(struct Node* node) {
  if (!node) return NULL;
  struct Pair map[128]; int mn = 0;
  struct Node* stack[128]; int sn = 0;
  /* DFS with extra seen copies: we still share one map so each node clones once */
  struct Node* seenbuf[64][128]; int seenlen[64]; int depth = 0;
  struct Node* dfs(struct Node* cur, struct Node** seenCopy, int slen) {
    for (int i = 0; i < mn; i++) if (map[i].old == cur) return map[i].neu;
    struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
    copy->val = cur->val; copy->numNeighbors = 0;
    copy->neighbors = (struct Node**)malloc(sizeof(struct Node*)*(cur->numNeighbors?cur->numNeighbors:1));
    map[mn].old = cur; map[mn].neu = copy; mn++;
    struct Node* nextSeen[128];
    for (int i = 0; i < slen; i++) nextSeen[i] = seenCopy[i];
    nextSeen[slen] = cur; slen++;
    for (int i = 0; i < cur->numNeighbors; i++)
      copy->neighbors[copy->numNeighbors++] = dfs(cur->neighbors[i], nextSeen, slen);
    return copy;
  }
  struct Node* emptyS[1];
  return dfs(node, emptyS, 0);
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n)
// One Map from old node to new node. DFS creates the clone, then fills neighbors. Each node and edge is processed once.

#include <stdlib.h>
struct Node { int val; int numNeighbors; struct Node** neighbors; };
struct Pair { struct Node* old; struct Node* neu; };
struct Pair gmap[128]; int gmn;
struct Node* dfs_clone(struct Node* cur) {
  for (int i = 0; i < gmn; i++) if (gmap[i].old == cur) return gmap[i].neu;
  struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
  copy->val = cur->val; copy->numNeighbors = cur->numNeighbors;
  copy->neighbors = (struct Node**)malloc(sizeof(struct Node*)*(cur->numNeighbors?cur->numNeighbors:1));
  gmap[gmn].old = cur; gmap[gmn].neu = copy; gmn++;
  for (int i = 0; i < cur->numNeighbors; i++) copy->neighbors[i] = dfs_clone(cur->neighbors[i]);
  return copy;
}
struct Node* cloneGraph(struct Node* node) {
  if (!node) return NULL;
  gmn = 0;
  return dfs_clone(node);
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// BFS with the same map avoids deep recursion on a long chain. Complexity matches DFS. Prefer this when the graph can be a long path.

#include <stdlib.h>
struct Node { int val; int numNeighbors; struct Node** neighbors; };
struct Pair { struct Node* old; struct Node* neu; };
struct Node* lookup(struct Pair* map, int mn, struct Node* k) {
  for (int i = 0; i < mn; i++) if (map[i].old == k) return map[i].neu;
  return NULL;
}
struct Node* cloneGraph(struct Node* node) {
  if (!node) return NULL;
  struct Pair map[128]; int mn = 0;
  struct Node* copy0 = (struct Node*)malloc(sizeof(struct Node));
  copy0->val = node->val; copy0->numNeighbors = 0;
  copy0->neighbors = (struct Node**)malloc(sizeof(struct Node*)*(node->numNeighbors?node->numNeighbors:1));
  map[mn].old = node; map[mn].neu = copy0; mn++;
  struct Node* q[128]; int h=0, t=0; q[t++] = node;
  while (h < t) {
    struct Node* cur = q[h++];
    struct Node* copy = lookup(map, mn, cur);
    for (int i = 0; i < cur->numNeighbors; i++) {
      struct Node* nei = cur->neighbors[i];
      if (!lookup(map, mn, nei)) {
        struct Node* nc = (struct Node*)malloc(sizeof(struct Node));
        nc->val = nei->val; nc->numNeighbors = 0;
        nc->neighbors = (struct Node**)malloc(sizeof(struct Node*)*(nei->numNeighbors?nei->numNeighbors:1));
        map[mn].old = nei; map[mn].neu = nc; mn++;
        q[t++] = nei;
      }
      copy->neighbors[copy->numNeighbors++] = lookup(map, mn, nei);
    }
  }
  return copy0;
}
