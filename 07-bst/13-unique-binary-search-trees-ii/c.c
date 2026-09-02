// Method 1: Brute
// Time: O(n · n!) | Space: O(n · n!)
// Generate every permutation of 1..n, insert into a BST, serialize the shape, keep one copy per unique serialization. Correct but factorial.

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

struct Node* insertVal(struct Node* node, int val) {
    if (!node) return newNode(val);
    if (val < node->val) node->left = insertVal(node->left, val);
    else node->right = insertVal(node->right, val);
    return node;
}
struct Node* cloneT(struct Node* node) {
    if (!node) return NULL;
    struct Node* c = newNode(node->val);
    c->left = cloneT(node->left);
    c->right = cloneT(node->right);
    return c;
}
void serialBuf(struct Node* node, char* b, int* p) {
    if (!node) { b[(*p)++] = '#'; b[(*p)++] = ','; return; }
    *p += sprintf(b + *p, "%d,", node->val);
    serialBuf(node->left, b, p);
    serialBuf(node->right, b, p);
}
void permGen(int* nums, int n, int i, char seen[][256], int* sn, struct Node** out, int* on) {
    int j, t, k, pos;
    char buf[256];
    if (i == n) {
        struct Node* root = NULL;
        for (k = 0; k < n; k++) root = insertVal(root, nums[k]);
        pos = 0;
        serialBuf(root, buf, &pos);
        buf[pos] = 0;
        for (k = 0; k < *sn; k++) if (strcmp(seen[k], buf) == 0) return;
        strcpy(seen[(*sn)++], buf);
        out[(*on)++] = cloneT(root);
        return;
    }
    for (j = i; j < n; j++) {
        t = nums[i]; nums[i] = nums[j]; nums[j] = t;
        permGen(nums, n, i + 1, seen, sn, out, on);
        t = nums[i]; nums[i] = nums[j]; nums[j] = t;
    }
}
struct Node** generateTrees(int n, int* returnSize) {
    int nums[12], i, sn = 0, on = 0;
    char seen[4000][256];
    static struct Node* out[4000];
    for (i = 0; i < n; i++) nums[i] = i + 1;
    permGen(nums, n, 0, seen, &sn, out, &on);
    *returnSize = on;
    return out;
}


// Method 2: Optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// For each root i in [lo, hi], cartesian product of left trees and right trees. Empty range yields a single null tree so a missing child is represented once.

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

int buildTrees(int lo, int hi, struct Node** out) {
    int i, L, R, ln, rn, n = 0;
    struct Node* lefts[400], *rights[400];
    if (lo > hi) { out[n++] = NULL; return n; }
    for (i = lo; i <= hi; i++) {
        ln = buildTrees(lo, i - 1, lefts);
        rn = buildTrees(i + 1, hi, rights);
        for (L = 0; L < ln; L++) for (R = 0; R < rn; R++) {
            struct Node* node = newNode(i);
            node->left = lefts[L];
            node->right = rights[R];
            out[n++] = node;
        }
    }
    return n;
}
struct Node** generateTrees(int n, int* returnSize) {
    static struct Node* out[4000];
    if (!n) { *returnSize = 0; return out; }
    *returnSize = buildTrees(1, n, out);
    return out;
}


// Method 3: More optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// Memoize [lo, hi]. Shared ranges (for example all trees on 3,4,5) are built once. Catalan many trees still must be allocated.

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

struct Memo { int lo, hi, n; struct Node* trees[400]; };
struct Memo memos[80];
int memon;
int lookup(int lo, int hi) {
    int i;
    for (i = 0; i < memon; i++) if (memos[i].lo == lo && memos[i].hi == hi) return i;
    return -1;
}
int buildMemo(int lo, int hi, struct Node** out) {
    int id = lookup(lo, hi), i, L, R, ln, rn, n = 0;
    struct Node* lefts[400], *rights[400];
    if (id >= 0) {
        for (i = 0; i < memos[id].n; i++) out[i] = memos[id].trees[i];
        return memos[id].n;
    }
    if (lo > hi) { out[n++] = NULL; }
    else {
        for (i = lo; i <= hi; i++) {
            ln = buildMemo(lo, i - 1, lefts);
            rn = buildMemo(i + 1, hi, rights);
            for (L = 0; L < ln; L++) for (R = 0; R < rn; R++) {
                struct Node* node = newNode(i);
                node->left = lefts[L];
                node->right = rights[R];
                out[n++] = node;
            }
        }
    }
    memos[memon].lo = lo; memos[memon].hi = hi; memos[memon].n = n;
    for (i = 0; i < n; i++) memos[memon].trees[i] = out[i];
    memon++;
    return n;
}
struct Node** generateTrees(int n, int* returnSize) {
    static struct Node* out[4000];
    memon = 0;
    if (!n) { *returnSize = 0; return out; }
    *returnSize = buildMemo(1, n, out);
    return out;
}
