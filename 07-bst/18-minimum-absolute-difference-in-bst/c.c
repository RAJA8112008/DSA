// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Dump all values, then compare every pair. Extra array and quadratic checks.

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

void collectVals(struct Node* node, int* vals, int* n) {
    if (!node) return;
    vals[(*n)++] = node->val;
    collectVals(node->left, vals, n);
    collectVals(node->right, vals, n);
}
int getMinimumDifference(struct Node* root) {
    int vals[10005], n = 0, i, j, d, best = INT_MAX;
    collectVals(root, vals, &n);
    for (i = 0; i < n; i++) for (j = i + 1; j < n; j++) {
        d = vals[i] - vals[j];
        if (d < 0) d = -d;
        if (d < best) best = d;
    }
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder. Compare each node with the previous inorder value. The min of those adjacent gaps is the global min.

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

void minDiffGo(struct Node* node, struct Node** prev, int* best) {
    if (!node) return;
    minDiffGo(node->left, prev, best);
    if (*prev) {
        int d = node->val - (*prev)->val;
        if (d < *best) *best = d;
    }
    *prev = node;
    minDiffGo(node->right, prev, best);
}
int getMinimumDifference(struct Node* root) {
    struct Node* prev = NULL;
    int best = INT_MAX;
    minDiffGo(root, &prev, &best);
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with a previous pointer. Same adjacent-gap logic, no stack.

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

int getMinimumDifference(struct Node* root) {
    struct Node* prev = NULL;
    int best = INT_MAX;
    struct Node* cur = root;
    while (cur) {
        if (!cur->left) {
            if (prev) {
                int d = cur->val - prev->val;
                if (d < best) best = d;
            }
            prev = cur;
            cur = cur->right;
        } else {
            struct Node* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) { pred->right = cur; cur = cur->left; }
            else {
                pred->right = NULL;
                if (prev) {
                    int d = cur->val - prev->val;
                    if (d < best) best = d;
                }
                prev = cur;
                cur = cur->right;
            }
        }
    }
    return best;
}
