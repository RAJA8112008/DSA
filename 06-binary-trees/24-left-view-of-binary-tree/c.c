// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order lists, then pick the first value of each list.

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

int* leftView(struct Node* root, int* returnSize) {
    static int out[10005];
    struct Node* q[10005];
    int qs = 0, qe = 0, n = 0;
    if (!root) { *returnSize = 0; return out; }
    q[qe++] = root;
    while (qs < qe) {
        int sz = qe - qs, i;
        for (i = 0; i < sz; i++) {
            struct Node* node = q[qs++];
            if (i == 0) out[n++] = node->val;
            if (node->left) q[qe++] = node->left;
            if (node->right) q[qe++] = node->right;
        }
    }
    *returnSize = n;
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// BFS. When i == 0 in the level loop, that node is the left view. w is the widest level.

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

int* leftView(struct Node* root, int* returnSize) {
    static int out[10005];
    struct Node* q[10005];
    int qs = 0, qe = 0, n = 0;
    if (!root) { *returnSize = 0; return out; }
    q[qe++] = root;
    while (qs < qe) {
        int sz = qe - qs, i;
        for (i = 0; i < sz; i++) {
            struct Node* node = q[qs++];
            if (i == 0) out[n++] = node->val;
            if (node->left) q[qe++] = node->left;
            if (node->right) q[qe++] = node->right;
        }
    }
    *returnSize = n;
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS left-first. If depth == out.length this is the first node at that depth. Recursion stack only.

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

void goLeft(struct Node* node, int d, int* out, int* n) {
    if (!node) return;
    if (d == *n) out[(*n)++] = node->val;
    goLeft(node->left, d + 1, out, n);
    goLeft(node->right, d + 1, out, n);
}
int* leftView(struct Node* root, int* returnSize) {
    static int out[10005];
    int n = 0;
    goLeft(root, 0, out, &n);
    *returnSize = n;
    return out;
}
