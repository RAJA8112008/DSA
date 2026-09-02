// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// DFS push [col, row, val]. Sort by col, then row, then val. Group into lists. Matches LeetCode 987.

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

typedef struct { int col, row, val; } Item;
int cmpItem(const void* a, const void* b) {
    const Item* x = (const Item*)a, *y = (const Item*)b;
    if (x->col != y->col) return x->col - y->col;
    if (x->row != y->row) return x->row - y->row;
    return x->val - y->val;
}
void goItems(struct Node* node, int row, int col, Item* items, int* n) {
    if (!node) return;
    items[*n].col = col; items[*n].row = row; items[*n].val = node->val; (*n)++;
    goItems(node->left, row + 1, col - 1, items, n);
    goItems(node->right, row + 1, col + 1, items, n);
}
int** verticalTraversal(struct Node* root, int* returnSize, int** returnColumnSizes) {
    static Item items[10005];
    static int rows[400][64];
    static int cols[400];
    static int* ptrs[400];
    int n = 0, rc = 0, i, prev, started = 0;
    goItems(root, 0, 0, items, &n);
    qsort(items, n, sizeof(Item), cmpItem);
    for (i = 0; i < n; i++) {
        if (!started || items[i].col != prev) { cols[rc] = 0; prev = items[i].col; started = 1; rc++; }
        rows[rc - 1][cols[rc - 1]++] = items[i].val;
    }
    for (i = 0; i < rc; i++) ptrs[i] = rows[i];
    *returnSize = rc;
    *returnColumnSizes = cols;
    return ptrs;
}


// Method 2: Optimal
// Time: O(n log w) | Space: O(n)
// BFS so row order is natural. TreeMap / sorted map of columns. GFG order (no value sort). w is the number of columns.

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

int** verticalOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    static int bucket[8005][64];
    static int bn[8005];
    static int rows[400][64];
    static int cols[400];
    static int* ptrs[400];
    struct Node* qn[10005];
    int qh[10005], qs = 0, qe = 0, minH = 0, maxH = 0, off = 4000, i, h, rc;
    *returnSize = 0;
    if (!root) { *returnColumnSizes = cols; return ptrs; }
    for (i = 0; i < 8005; i++) bn[i] = 0;
    qn[qe] = root; qh[qe++] = 0;
    while (qs < qe) {
        struct Node* node = qn[qs];
        int hd = qh[qs++];
        bucket[hd + off][bn[hd + off]++] = node->val;
        if (hd < minH) minH = hd;
        if (hd > maxH) maxH = hd;
        if (node->left) { qn[qe] = node->left; qh[qe++] = hd - 1; }
        if (node->right) { qn[qe] = node->right; qh[qe++] = hd + 1; }
    }
    rc = 0;
    for (h = minH; h <= maxH; h++) {
        cols[rc] = bn[h + off];
        for (i = 0; i < bn[h + off]; i++) rows[rc][i] = bucket[h + off][i];
        ptrs[rc] = rows[rc];
        rc++;
    }
    *returnSize = rc;
    *returnColumnSizes = cols;
    return ptrs;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same BFS. Record min and max hd, then emit columns in a plain loop. No log w map.

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

int** verticalOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    static int rows[400][64];
    static int cols[400];
    static int* ptrs[400];
    struct Node* nodes[10005];
    int hds[10005], n = 0, i, minH = 0, maxH = 0, rc;
    *returnSize = 0;
    if (!root) { *returnColumnSizes = cols; return ptrs; }
    nodes[n] = root; hds[n++] = 0;
    for (i = 0; i < n; i++) {
        if (hds[i] < minH) minH = hds[i];
        if (hds[i] > maxH) maxH = hds[i];
        if (nodes[i]->left) { nodes[n] = nodes[i]->left; hds[n++] = hds[i] - 1; }
        if (nodes[i]->right) { nodes[n] = nodes[i]->right; hds[n++] = hds[i] + 1; }
    }
    rc = maxH - minH + 1;
    for (i = 0; i < rc; i++) cols[i] = 0;
    for (i = 0; i < n; i++) rows[hds[i] - minH][cols[hds[i] - minH]++] = nodes[i]->val;
    for (i = 0; i < rc; i++) ptrs[i] = rows[i];
    *returnSize = rc;
    *returnColumnSizes = cols;
    return ptrs;
}
