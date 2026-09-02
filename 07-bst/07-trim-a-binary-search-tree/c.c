// Method 1: Brute
// Time: O(n) | Space: O(n)
// Gather every in-range key, sort, rebuild a balanced tree. Correct values, but new nodes and a different shape.

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

void collectRange(struct Node* node, int low, int high, int* keys, int* n) {
    if (!node) return;
    if (node->val >= low && node->val <= high) keys[(*n)++] = node->val;
    collectRange(node->left, low, high, keys, n);
    collectRange(node->right, low, high, keys, n);
}
int cmpInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }
struct Node* buildKeys(int* keys, int lo, int hi) {
    if (lo > hi) return NULL;
    int mid = lo + (hi - lo) / 2;
    struct Node* node = newNode(keys[mid]);
    node->left = buildKeys(keys, lo, mid - 1);
    node->right = buildKeys(keys, mid + 1, hi);
    return node;
}
struct Node* trimBST(struct Node* root, int low, int high) {
    int keys[10005], n = 0;
    collectRange(root, low, high, keys, &n);
    qsort(keys, n, sizeof(int), cmpInt);
    return buildKeys(keys, 0, n - 1);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder prune using the BST property. Reuse the original nodes. If the root is outside the window, drop it and return one trimmed child.

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

struct Node* trimBST(struct Node* root, int low, int high) {
    if (!root) return NULL;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Move the root iteratively until it sits inside [low, high], then recursively trim the two sides. Fewer frames when the original root is far outside the window.

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

struct Node* trimSide(struct Node* node, int low, int high) {
    if (!node) return NULL;
    if (node->val < low) return trimSide(node->right, low, high);
    if (node->val > high) return trimSide(node->left, low, high);
    node->left = trimSide(node->left, low, high);
    node->right = trimSide(node->right, low, high);
    return node;
}
struct Node* trimBST(struct Node* root, int low, int high) {
    while (root && (root->val < low || root->val > high))
        root = root->val < low ? root->right : root->left;
    if (!root) return NULL;
    root->left = trimSide(root->left, low, high);
    root->right = trimSide(root->right, low, high);
    return root;
}
