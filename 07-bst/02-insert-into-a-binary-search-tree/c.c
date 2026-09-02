// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every key, append val, sort, and rebuild a balanced tree from the middle. Extra arrays; you never use the existing shape.

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

void collectKeys(struct Node* node, int* keys, int* n) {
    if (!node) return;
    keys[(*n)++] = node->val;
    collectKeys(node->left, keys, n);
    collectKeys(node->right, keys, n);
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
struct Node* insertIntoBST(struct Node* root, int val) {
    int keys[10005], n = 0;
    collectKeys(root, keys, &n);
    keys[n++] = val;
    qsort(keys, n, sizeof(int), cmpInt);
    return buildKeys(keys, 0, n - 1);
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse left or right and assign the returned child. When the child is null, allocate the new leaf. Root is returned unchanged unless the tree was empty.

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

struct Node* insertIntoBST(struct Node* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative: if the tree is empty, return a new root. Else walk until the next child is null and attach there. No recursion.

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

struct Node* insertIntoBST(struct Node* root, int val) {
    struct Node* fresh = newNode(val);
    if (!root) return fresh;
    struct Node* cur = root;
    while (1) {
        if (val < cur->val) {
            if (!cur->left) { cur->left = fresh; break; }
            cur = cur->left;
        } else {
            if (!cur->right) { cur->right = fresh; break; }
            cur = cur->right;
        }
    }
    return root;
}
