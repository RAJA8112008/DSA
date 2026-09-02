// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Inorder keys, then insert in sorted order into a fresh BST. That rebuilds a stick. Shows why you must pick mids, not insert in order.

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

void inorderVals(struct Node* node, int* keys, int* n) {
    if (!node) return;
    inorderVals(node->left, keys, n);
    keys[(*n)++] = node->val;
    inorderVals(node->right, keys, n);
}
struct Node* insertVal(struct Node* node, int val) {
    if (!node) return newNode(val);
    if (val < node->val) node->left = insertVal(node->left, val);
    else node->right = insertVal(node->right, val);
    return node;
}
struct Node* balanceBST(struct Node* root) {
    int keys[10005], n = 0, i;
    struct Node* out = NULL;
    inorderVals(root, keys, &n);
    for (i = 0; i < n; i++) out = insertVal(out, keys[i]);
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Inorder into an array, then mid-as-root rebuild. Height is log n. Extra array of keys (or of nodes if you reuse them).

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

void collectNodes(struct Node* node, struct Node** nodes, int* n) {
    if (!node) return;
    collectNodes(node->left, nodes, n);
    nodes[(*n)++] = node;
    collectNodes(node->right, nodes, n);
}
struct Node* buildNodes(struct Node** nodes, int lo, int hi) {
    if (lo > hi) return NULL;
    int mid = lo + (hi - lo) / 2;
    struct Node* node = nodes[mid];
    node->left = buildNodes(nodes, lo, mid - 1);
    node->right = buildNodes(nodes, mid + 1, hi);
    return node;
}
struct Node* balanceBST(struct Node* root) {
    struct Node* nodes[10005];
    int n = 0;
    collectNodes(root, nodes, &n);
    return buildNodes(nodes, 0, n - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// DSW: rotate every left child to the right to make a vine (linked list of right pointers). Then repeatedly rotate the vine to fold it into a balanced tree. In-place, O(1) extra besides recursion-free loops.

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

int vine(struct Node* dummy) {
    struct Node* tail = dummy;
    struct Node* rest = dummy->right;
    int n = 0;
    while (rest) {
        if (rest->left) {
            struct Node* old = rest;
            rest = rest->left;
            old->left = rest->right;
            rest->right = old;
            tail->right = rest;
        } else {
            tail = rest;
            rest = rest->right;
            n++;
        }
    }
    return n;
}
void compress(struct Node* dummy, int count) {
    struct Node* parent = dummy;
    int i;
    for (i = 0; i < count; i++) {
        struct Node* child = parent->right;
        parent->right = child->right;
        child->right = parent->right->left;
        parent->right->left = child;
        parent = parent->right;
    }
}
struct Node* balanceBST(struct Node* root) {
    struct Node dummy;
    int n, m;
    dummy.val = 0; dummy.left = NULL; dummy.right = root;
    n = vine(&dummy);
    m = 1;
    while (m * 2 + 1 <= n) m = m * 2 + 1;
    compress(&dummy, n - m);
    for (m /= 2; m >= 1; m /= 2) compress(&dummy, m);
    return dummy.right;
}
