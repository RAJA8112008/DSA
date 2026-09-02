// Method 1: Brute
// Time: O(n) init, O(1) next | Space: O(n)
// Flatten inorder into an array at construction. next/hasNext are index moves. Simple, but you pay linear memory before the first call.

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

typedef struct {
    int vals[10005];
    int n, i;
} BSTIterator;
void goIt(struct Node* node, BSTIterator* it) {
    if (!node) return;
    goIt(node->left, it);
    it->vals[it->n++] = node->val;
    goIt(node->right, it);
}
BSTIterator* bSTIteratorCreate(struct Node* root) {
    BSTIterator* it = (BSTIterator*)calloc(1, sizeof(BSTIterator));
    goIt(root, it);
    return it;
}
int bSTIteratorNext(BSTIterator* it) { return it->vals[it->i++]; }
bool bSTIteratorHasNext(BSTIterator* it) { return it->i < it->n; }
void bSTIteratorFree(BSTIterator* it) { free(it); }


// Method 2: Optimal
// Time: O(h) init, amortized O(1) next | Space: O(h)
// Stack holds the path to the next node. Construction pushes the left spine. next() pops, then pushes the left spine of the right child.

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

typedef struct {
    struct Node* stack[10005];
    int sp;
} BSTIterator;
void pushLeft(BSTIterator* it, struct Node* node) {
    while (node) { it->stack[it->sp++] = node; node = node->left; }
}
BSTIterator* bSTIteratorCreate(struct Node* root) {
    BSTIterator* it = (BSTIterator*)calloc(1, sizeof(BSTIterator));
    pushLeft(it, root);
    return it;
}
int bSTIteratorNext(BSTIterator* it) {
    struct Node* node = it->stack[--it->sp];
    pushLeft(it, node->right);
    return node->val;
}
bool bSTIteratorHasNext(BSTIterator* it) { return it->sp > 0; }
void bSTIteratorFree(BSTIterator* it) { free(it); }


// Method 3: More optimal
// Time: amortized O(1) next | Space: O(1)
// Morris: thread predecessor.right to the current node, walk without a stack. Unthread before yielding so the tree is restored. Extra memory is a handful of pointers.

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

typedef struct { struct Node* cur; } BSTIterator;
BSTIterator* bSTIteratorCreate(struct Node* root) {
    BSTIterator* it = (BSTIterator*)malloc(sizeof(BSTIterator));
    it->cur = root;
    return it;
}
int bSTIteratorNext(BSTIterator* it) {
    while (it->cur) {
        if (!it->cur->left) {
            int val = it->cur->val;
            it->cur = it->cur->right;
            return val;
        }
        struct Node* pred = it->cur->left;
        while (pred->right && pred->right != it->cur) pred = pred->right;
        if (!pred->right) {
            pred->right = it->cur;
            it->cur = it->cur->left;
        } else {
            pred->right = NULL;
            int val = it->cur->val;
            it->cur = it->cur->right;
            return val;
        }
    }
    return 0;
}
bool bSTIteratorHasNext(BSTIterator* it) { return it->cur != NULL; }
void bSTIteratorFree(BSTIterator* it) { free(it); }
