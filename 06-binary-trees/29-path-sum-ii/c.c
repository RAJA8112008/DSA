// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// Collect every root-to-leaf path, then keep those whose sum equals target. Path copies dominate memory.

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

void goPaths(struct Node* node, int* path, int plen, int paths[][256], int* plenOut, int* pn) {
    if (!node) return;
    path[plen++] = node->val;
    if (!node->left && !node->right) {
        int i;
        plenOut[*pn] = plen;
        for (i = 0; i < plen; i++) paths[*pn][i] = path[i];
        (*pn)++;
    }
    goPaths(node->left, path, plen, paths, plenOut, pn);
    goPaths(node->right, path, plen, paths, plenOut, pn);
}
int** pathSum(struct Node* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    static int paths[256][256], plenOut[256], *ptrs[256], cols[256], path[256];
    int pn = 0, i, j, n = 0;
    goPaths(root, path, 0, paths, plenOut, &pn);
    for (i = 0; i < pn; i++) {
        int s = 0;
        for (j = 0; j < plenOut[i]; j++) s += paths[i][j];
        if (s == targetSum) {
            cols[n] = plenOut[i];
            ptrs[n] = paths[i];
            n++;
        }
    }
    *returnSize = n;
    *returnColumnSizes = cols;
    return ptrs;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(h)
// Backtracking. remain starts at targetSum. At a leaf, if remain == node.val, snapshot the path. Copying a path is O(h); total output can be O(n²).

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

void goSum(struct Node* node, int remain, int* path, int plen, int out[][256], int* olen, int* n) {
    if (!node) return;
    path[plen++] = node->val;
    if (!node->left && !node->right && remain == node->val) {
        int i;
        olen[*n] = plen;
        for (i = 0; i < plen; i++) out[*n][i] = path[i];
        (*n)++;
    }
    goSum(node->left, remain - node->val, path, plen, out, olen, n);
    goSum(node->right, remain - node->val, path, plen, out, olen, n);
}
int** pathSum(struct Node* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    static int store[256][256], olen[256], *ptrs[256], path[256];
    int n = 0, i;
    goSum(root, targetSum, path, 0, store, olen, &n);
    for (i = 0; i < n; i++) ptrs[i] = store[i];
    *returnSize = n;
    *returnColumnSizes = olen;
    return ptrs;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Iterative stack of {node, remain, path}. Same snapshots at leaves. Avoids call-stack overflow on a stick, still copies paths.

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

int** pathSum(struct Node* root, int targetSum, int* returnSize, int** returnColumnSizes) {
    static int store[256][256], olen[256], *ptrs[256];
    struct Node* sn[256];
    int sr[256], spath[256][256], slen[256];
    int sp = 0, n = 0, i;
    if (!root) { *returnSize = 0; *returnColumnSizes = olen; return ptrs; }
    sn[sp] = root; sr[sp] = targetSum; spath[sp][0] = root->val; slen[sp] = 1; sp++;
    while (sp) {
        sp--;
        struct Node* node = sn[sp];
        int remain = sr[sp], plen = slen[sp];
        int path[256];
        for (i = 0; i < plen; i++) path[i] = spath[sp][i];
        if (!node->left && !node->right && remain == node->val) {
            olen[n] = plen;
            for (i = 0; i < plen; i++) store[n][i] = path[i];
            ptrs[n] = store[n];
            n++;
        }
        if (node->right) {
            sn[sp] = node->right; sr[sp] = remain - node->val;
            for (i = 0; i < plen; i++) spath[sp][i] = path[i];
            spath[sp][plen] = node->right->val; slen[sp] = plen + 1; sp++;
        }
        if (node->left) {
            sn[sp] = node->left; sr[sp] = remain - node->val;
            for (i = 0; i < plen; i++) spath[sp][i] = path[i];
            spath[sp][plen] = node->left->val; slen[sp] = plen + 1; sp++;
        }
    }
    *returnSize = n;
    *returnColumnSizes = olen;
    return ptrs;
}
