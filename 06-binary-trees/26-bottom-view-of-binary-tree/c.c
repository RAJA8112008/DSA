// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect (hd, depth, index, val), sort, keep the last per hd.

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

typedef struct { int hd, d, idx, val; } Item;
int cmpItem4(const void* a, const void* b) {
    const Item* x = (const Item*)a, *y = (const Item*)b;
    if (x->hd != y->hd) return x->hd - y->hd;
    if (x->d != y->d) return x->d - y->d;
    return x->idx - y->idx;
}
void goItems4(struct Node* node, int hd, int d, Item* items, int* n) {
    if (!node) return;
    items[*n].hd = hd; items[*n].d = d; items[*n].idx = *n; items[*n].val = node->val; (*n)++;
    goItems4(node->left, hd - 1, d + 1, items, n);
    goItems4(node->right, hd + 1, d + 1, items, n);
}
int* bottomView(struct Node* root, int* returnSize) {
    static Item items[10005];
    static int out[4005];
    int n = 0, on = 0, i;
    goItems4(root, 0, 0, items, &n);
    qsort(items, n, sizeof(Item), cmpItem4);
    for (i = 0; i < n; i++)
        if (i + 1 == n || items[i].hd != items[i + 1].hd) out[on++] = items[i].val;
    *returnSize = on;
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS overwrite per hd. Last write is the deepest (or the right one on a tie). Emit min..max.

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

int* bottomView(struct Node* root, int* returnSize) {
    static int last[8005];
    static int out[4005];
    struct Node* qn[10005];
    int qh[10005], qs = 0, qe = 0, minH = 0, maxH = 0, off = 4000, h, n;
    if (!root) { *returnSize = 0; return out; }
    qn[qe] = root; qh[qe++] = 0;
    while (qs < qe) {
        struct Node* node = qn[qs];
        int hd = qh[qs++];
        last[hd + off] = node->val;
        if (hd < minH) minH = hd;
        if (hd > maxH) maxH = hd;
        if (node->left) { qn[qe] = node->left; qh[qe++] = hd - 1; }
        if (node->right) { qn[qe] = node->right; qh[qe++] = hd + 1; }
    }
    n = 0;
    for (h = minH; h <= maxH; h++) out[n++] = last[h + off];
    *returnSize = n;
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS: keep val for hd when depth >= stored depth (overwrite on tie so right-later wins if you visit right after left).

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

int botVal[8005], botDep[8005], botSeen[8005];
void goBot(struct Node* node, int hd, int d, int* minH, int* maxH) {
    int off = 4000;
    if (!node) return;
    if (!botSeen[hd + off] || d >= botDep[hd + off]) {
        botSeen[hd + off] = 1;
        botDep[hd + off] = d;
        botVal[hd + off] = node->val;
    }
    if (hd < *minH) *minH = hd;
    if (hd > *maxH) *maxH = hd;
    goBot(node->left, hd - 1, d + 1, minH, maxH);
    goBot(node->right, hd + 1, d + 1, minH, maxH);
}
int* bottomView(struct Node* root, int* returnSize) {
    static int out[4005];
    int minH = 0, maxH = 0, h, n = 0, i;
    if (!root) { *returnSize = 0; return out; }
    for (i = 0; i < 8005; i++) botSeen[i] = 0;
    goBot(root, 0, 0, &minH, &maxH);
    for (h = minH; h <= maxH; h++) out[n++] = botVal[h + 4000];
    *returnSize = n;
    return out;
}
