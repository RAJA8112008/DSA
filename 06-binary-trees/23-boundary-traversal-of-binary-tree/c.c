// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect all nodes with (isLeft, isRight, isLeaf). Then emit left bound, leaves, reverse right bound, skipping duplicates via a seen set.

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

int isLeaf(struct Node* n) { return n && !n->left && !n->right; }
void goBound(struct Node* node, int onLeft, int onRight, int* leftB, int* ln, int* rightB, int* rn, int* leaves, int* lf) {
    if (!node) return;
    if (isLeaf(node)) { leaves[(*lf)++] = node->val; return; }
    if (onLeft) leftB[(*ln)++] = node->val;
    else if (onRight) rightB[(*rn)++] = node->val;
    goBound(node->left, onLeft, onRight && !node->right, leftB, ln, rightB, rn, leaves, lf);
    goBound(node->right, onLeft && !node->left, onRight, leftB, ln, rightB, rn, leaves, lf);
}
int* boundaryTraversal(struct Node* root, int* returnSize) {
    static int out[10005], leftB[10005], rightB[10005], leaves[10005];
    int ln = 0, rn = 0, lf = 0, i;
    if (!root) { *returnSize = 0; return out; }
    if (!isLeaf(root)) leftB[ln++] = root->val;
    goBound(root->left, 1, 0, leftB, &ln, rightB, &rn, leaves, &lf);
    goBound(root->right, 0, 1, leftB, &ln, rightB, &rn, leaves, &lf);
    if (isLeaf(root)) leaves[lf++] = root->val;
    for (i = 0; i < ln; i++) out[i] = leftB[i];
    for (i = 0; i < lf; i++) out[ln + i] = leaves[i];
    for (i = 0; i < rn; i++) out[ln + lf + i] = rightB[rn - 1 - i];
    *returnSize = ln + lf + rn;
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Three passes: left edge (stop before a leaf), all leaves, right edge into a stack then pop. Clear and classic interview split.

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

int isLeafN(struct Node* n) { return !n->left && !n->right; }
void leavesN(struct Node* node, int* out, int* n) {
    if (!node) return;
    if (isLeafN(node)) { out[(*n)++] = node->val; return; }
    leavesN(node->left, out, n);
    leavesN(node->right, out, n);
}
int* boundaryTraversal(struct Node* root, int* returnSize) {
    static int out[10005], right[10005];
    int n = 0, rn = 0;
    struct Node* cur;
    if (!root) { *returnSize = 0; return out; }
    if (!isLeafN(root)) out[n++] = root->val;
    cur = root->left;
    while (cur) {
        if (!isLeafN(cur)) out[n++] = cur->val;
        cur = cur->left ? cur->left : cur->right;
    }
    leavesN(root, out, &n);
    cur = root->right;
    while (cur) {
        if (!isLeafN(cur)) right[rn++] = cur->val;
        cur = cur->right ? cur->right : cur->left;
    }
    while (rn) out[n++] = right[--rn];
    *returnSize = n;
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// One DFS. Pass whether this node is on the left bound, right bound, or a leaf. Append left-bound before children, leaves in the middle, right-bound after children (so they reverse themselves).

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

int isLeafN(struct Node* n) { return !n->left && !n->right; }
void goBound2(struct Node* node, int leftB, int rightB, int* out, int* n) {
    if (!node) return;
    if (isLeafN(node) || leftB) out[(*n)++] = node->val;
    goBound2(node->left, leftB, rightB && !node->right, out, n);
    goBound2(node->right, leftB && !node->left, rightB, out, n);
    if (rightB && !isLeafN(node) && !leftB) out[(*n)++] = node->val;
}
int* boundaryTraversal(struct Node* root, int* returnSize) {
    static int out[10005];
    int n = 0;
    if (!root) { *returnSize = 0; return out; }
    if (isLeafN(root)) { out[n++] = root->val; *returnSize = n; return out; }
    out[n++] = root->val;
    goBound2(root->left, 1, 0, out, &n);
    goBound2(root->right, 0, 1, out, &n);
    *returnSize = n;
    return out;
}
