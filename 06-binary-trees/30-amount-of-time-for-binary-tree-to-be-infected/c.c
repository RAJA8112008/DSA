// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build undirected graph on values (unique). BFS from start. Answer is the max distance.

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

void addE(int u, int v, int adj[][8], int* deg) {
    adj[u][deg[u]++] = v;
    adj[v][deg[v]++] = u;
}
void buildG2(struct Node* node, int adj[][8], int* deg) {
    if (!node) return;
    if (node->left) { addE(node->val, node->left->val, adj, deg); buildG2(node->left, adj, deg); }
    if (node->right) { addE(node->val, node->right->val, adj, deg); buildG2(node->right, adj, deg); }
}
int amountOfTime(struct Node* root, int start) {
    int adj[100005][8], deg[100005], seen[100005];
    int qv[10005], qd[10005], qs = 0, qe = 0, best = 0, i;
    for (i = 0; i < 100005; i++) { deg[i] = 0; seen[i] = 0; }
    buildG2(root, adj, deg);
    qv[qe] = start; qd[qe++] = 0; seen[start] = 1;
    while (qs < qe) {
        int u = qv[qs], d = qd[qs++];
        if (d > best) best = d;
        for (i = 0; i < deg[u]; i++) {
            int v = adj[u][i];
            if (seen[v]) continue;
            seen[v] = 1;
            qv[qe] = v; qd[qe++] = d + 1;
        }
    }
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent pointers, BFS from the start node (find it first). Minutes = max distance.

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

int amountOfTime(struct Node* root, int start) {
    struct Pair { struct Node* node; struct Node* p; } par[10005];
    struct Node *qn[10005], *seen[10005], *src = NULL, *nbr[3];
    int pn = 0, qs = 0, qe = 0, sn = 0, qd[10005], best = 0, i;
    void mark(struct Node* node, struct Node* p);
    /* iterative mark via recursion helper inlined below */
    struct Node* stackN[10005], *stackP[10005];
    int sp = 0;
    stackN[sp] = root; stackP[sp] = NULL; sp++;
    while (sp) {
        struct Node* node = stackN[--sp];
        struct Node* p = stackP[sp];
        if (!node) continue;
        par[pn].node = node; par[pn].p = p; pn++;
        if (node->val == start) src = node;
        stackN[sp] = node->right; stackP[sp] = node; sp++;
        stackN[sp] = node->left; stackP[sp] = node; sp++;
    }
    qn[qe] = src; qd[qe++] = 0; seen[sn++] = src;
    while (qs < qe) {
        struct Node* node = qn[qs];
        int d = qd[qs++];
        struct Node* p = NULL;
        if (d > best) best = d;
        for (i = 0; i < pn; i++) if (par[i].node == node) { p = par[i].p; break; }
        nbr[0] = node->left; nbr[1] = node->right; nbr[2] = p;
        for (i = 0; i < 3; i++) {
            int found = 0, j;
            if (!nbr[i]) continue;
            for (j = 0; j < sn; j++) if (seen[j] == nbr[i]) found = 1;
            if (found) continue;
            seen[sn++] = nbr[i];
            qn[qe] = nbr[i]; qd[qe++] = d + 1;
        }
    }
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS returns height of the subtree. When the start node is found, ans is max(height below, distance going up through the parent). One traversal, no graph.

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

int burnDfs(struct Node* node, int start, int* ans) {
    int L, R;
    if (!node) return 0;
    L = burnDfs(node->left, start, ans);
    R = burnDfs(node->right, start, ans);
    if (node->val == start) {
        if (L > *ans) *ans = L;
        if (R > *ans) *ans = R;
        return -1;
    }
    if (L < 0) { if (R - L > *ans) *ans = R - L; return L - 1; }
    if (R < 0) { if (L - R > *ans) *ans = L - R; return R - 1; }
    return 1 + (L > R ? L : R);
}
int amountOfTime(struct Node* root, int start) {
    int ans = 0;
    burnDfs(root, start, &ans);
    return ans;
}
