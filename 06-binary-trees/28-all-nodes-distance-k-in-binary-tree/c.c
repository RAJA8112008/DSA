// Method 1: Brute
// Time: O(n) | Space: O(n)
// Undirected graph of val->neighbors (vals are unique on LC). BFS from target.val for K steps.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void addEdge(int u, int v, int adj[][8], int* deg) {
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}
void buildG(struct Node* node, int adj[][8], int* deg) {
    if (!node) return;
    if (node->left) { addEdge(node->val, node->left->val, adj, deg); buildG(node->left, adj, deg); }
    if (node->right) { addEdge(node->val, node->right->val, adj, deg); buildG(node->right, adj, deg); }
}
int* distanceK(struct Node* root, struct Node* target, int k, int* returnSize) {
    static int adj[600][8], deg[600], seen[600], qv[600], qd[600], out[600];
    int qs = 0, qe = 0, n = 0, i;
    for (i = 0; i < 600; i++) { deg[i] = 0; seen[i] = 0; }
    buildG(root, adj, deg);
    qv[qe] = target->val; qd[qe++] = 0; seen[target->val] = 1;
    while (qs < qe) {
        int u = qv[qs], d = qd[qs++];
        if (d == k) { out[n++] = u; continue; }
        for (i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (seen[v]) continue;
            seen[v] = 1;
            qv[qe] = v; qd[qe++] = d + 1;
        }
    }
    *returnSize = n;
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent map from nodes (not values). BFS from the target node with a visited set of pointers. Collect at distance k.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct Pair { struct Node* node; struct Node* p; };
void markP(struct Node* node, struct Node* p, struct Pair* par, int* n) {
    if (!node) return;
    par[*n].node = node; par[*n].p = p; (*n)++;
    markP(node->left, node, par, n);
    markP(node->right, node, par, n);
}
struct Node* findP(struct Pair* par, int n, struct Node* x) {
    int i;
    for (i = 0; i < n; i++) if (par[i].node == x) return par[i].p;
    return NULL;
}
int containsN(struct Node** a, int n, struct Node* x) {
    int i;
    for (i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}
int* distanceK(struct Node* root, struct Node* target, int k, int* returnSize) {
    static struct Pair par[10005];
    static struct Node* qn[10005];
    static struct Node* seen[10005];
    static int qd[10005], out[10005];
    int pn = 0, qs = 0, qe = 0, sn = 0, n = 0, i;
    struct Node* nbr[3];
    markP(root, NULL, par, &pn);
    qn[qe] = target; qd[qe++] = 0; seen[sn++] = target;
    while (qs < qe) {
        struct Node* node = qn[qs];
        int d = qd[qs++];
        if (d == k) { out[n++] = node->val; continue; }
        nbr[0] = node->left; nbr[1] = node->right; nbr[2] = findP(par, pn, node);
        for (i = 0; i < 3; i++) {
            if (!nbr[i] || containsN(seen, sn, nbr[i])) continue;
            seen[sn++] = nbr[i];
            qn[qe] = nbr[i]; qd[qe++] = d + 1;
        }
    }
    *returnSize = n;
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS returns distance from this subtree to target, or -1. When a child reports dist, walk the other child at k - dist - 2, and maybe record this node. Downward walk from target collects depth k.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void collect(struct Node* node, int dist, int* out, int* n) {
    if (!node || dist < 0) return;
    if (dist == 0) { out[(*n)++] = node->val; return; }
    collect(node->left, dist - 1, out, n);
    collect(node->right, dist - 1, out, n);
}
int dfsK(struct Node* node, struct Node* target, int k, int* out, int* n) {
    int L, R;
    if (!node) return -1;
    if (node == target) { collect(node, k, out, n); return 0; }
    L = dfsK(node->left, target, k, out, n);
    if (L >= 0) {
        if (L + 1 == k) out[(*n)++] = node->val;
        else collect(node->right, k - L - 2, out, n);
        return L + 1;
    }
    R = dfsK(node->right, target, k, out, n);
    if (R >= 0) {
        if (R + 1 == k) out[(*n)++] = node->val;
        else collect(node->left, k - R - 2, out, n);
        return R + 1;
    }
    return -1;
}
int* distanceK(struct Node* root, struct Node* target, int k, int* returnSize) {
    static int out[10005];
    int n = 0;
    dfsK(root, target, k, out, &n);
    *returnSize = n;
    return out;
}
