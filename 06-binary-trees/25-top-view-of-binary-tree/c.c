// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect every (hd, depth, val), sort, keep the first (smallest depth) per hd.

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

typedef struct { int hd, d, val; } Item;
int cmpItem(const void* a, const void* b) {
    const Item* x = (const Item*)a, *y = (const Item*)b;
    if (x->hd != y->hd) return x->hd - y->hd;
    return x->d - y->d;
}
void goItems(struct Node* node, int hd, int d, Item* items, int* n) {
    if (!node) return;
    items[*n].hd = hd; items[*n].d = d; items[*n].val = node->val; (*n)++;
    goItems(node->left, hd - 1, d + 1, items, n);
    goItems(node->right, hd + 1, d + 1, items, n);
}
int* topView(struct Node* root, int* returnSize) {
    static Item items[10005];
    static int out[10005];
    int n = 0, on = 0, i, prev, started = 0;
    goItems(root, 0, 0, items, &n);
    qsort(items, n, sizeof(Item), cmpItem);
    for (i = 0; i < n; i++) {
        if (!started || items[i].hd != prev) { out[on++] = items[i].val; prev = items[i].hd; started = 1; }
    }
    *returnSize = on;
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS. The first time an hd appears, record it. Then emit from min hd to max hd.

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

int* topView(struct Node* root, int* returnSize) {
    static int first[8005];
    static int seen[8005];
    static int out[4005];
    struct Node* qn[10005];
    int qh[10005], qs = 0, qe = 0, minH = 0, maxH = 0, off = 4000, i, h, n;
    if (!root) { *returnSize = 0; return out; }
    for (i = 0; i < 8005; i++) seen[i] = 0;
    qn[qe] = root; qh[qe++] = 0;
    while (qs < qe) {
        struct Node* node = qn[qs];
        int hd = qh[qs++];
        if (!seen[hd + off]) { seen[hd + off] = 1; first[hd + off] = node->val; }
        if (hd < minH) minH = hd;
        if (hd > maxH) maxH = hd;
        if (node->left) { qn[qe] = node->left; qh[qe++] = hd - 1; }
        if (node->right) { qn[qe] = node->right; qh[qe++] = hd + 1; }
    }
    n = 0;
    for (h = minH; h <= maxH; h++) out[n++] = first[h + off];
    *returnSize = n;
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS with depth. Keep a node for hd only if this depth is smaller. Then scan min..max hd. No queue.

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

int bestVal[8005], bestD[8005], seenHd[8005];
void goTop(struct Node* node, int hd, int d, int* minH, int* maxH) {
    int off = 4000;
    if (!node) return;
    if (!seenHd[hd + off] || d < bestD[hd + off]) {
        seenHd[hd + off] = 1;
        bestD[hd + off] = d;
        bestVal[hd + off] = node->val;
    }
    if (hd < *minH) *minH = hd;
    if (hd > *maxH) *maxH = hd;
    goTop(node->left, hd - 1, d + 1, minH, maxH);
    goTop(node->right, hd + 1, d + 1, minH, maxH);
}
int* topView(struct Node* root, int* returnSize) {
    static int out[4005];
    int minH = 0, maxH = 0, h, n = 0, i;
    if (!root) { *returnSize = 0; return out; }
    for (i = 0; i < 8005; i++) seenHd[i] = 0;
    goTop(root, 0, 0, &minH, &maxH);
    for (h = minH; h <= maxH; h++) out[n++] = bestVal[h + 4000];
    *returnSize = n;
    return out;
}
