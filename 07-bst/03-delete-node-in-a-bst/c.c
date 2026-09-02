// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump every key except key, then rebuild a balanced BST from the sorted list. Simple, but you throw away the original shape.

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

void collectExcept(struct Node* node, int key, int* keys, int* n) {
    if (!node) return;
    if (node->val != key) keys[(*n)++] = node->val;
    collectExcept(node->left, key, keys, n);
    collectExcept(node->right, key, keys, n);
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
struct Node* deleteNode(struct Node* root, int key) {
    int keys[10005], n = 0;
    collectExcept(root, key, keys, &n);
    qsort(keys, n, sizeof(int), cmpInt);
    return buildKeys(keys, 0, n - 1);
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse to the node. Leaf or one child: return the other child. Two children: copy leftmost of right into node.val, then delete that successor from the right subtree.

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

struct Node* deleteNode(struct Node* root, int key) {
    if (!root) return NULL;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        struct Node* succ = root->right;
        while (succ->left) succ = succ->left;
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative search with a parent pointer. Splice zero/one-child nodes directly. For two children, copy the successor value then unlink the successor (it has no left child).

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

struct Node* spliceNode(struct Node* root, struct Node* parent, struct Node* node, struct Node* child) {
    if (!parent) return child;
    if (parent->left == node) parent->left = child;
    else parent->right = child;
    return root;
}
struct Node* deleteNode(struct Node* root, int key) {
    struct Node* parent = NULL;
    struct Node* cur = root;
    while (cur && cur->val != key) {
        parent = cur;
        cur = key < cur->val ? cur->left : cur->right;
    }
    if (!cur) return root;
    if (!cur->left) return spliceNode(root, parent, cur, cur->right);
    if (!cur->right) return spliceNode(root, parent, cur, cur->left);
    struct Node* sp = cur;
    struct Node* succ = cur->right;
    while (succ->left) { sp = succ; succ = succ->left; }
    cur->val = succ->val;
    if (sp->left == succ) sp->left = succ->right;
    else sp->right = succ->right;
    return root;
}
