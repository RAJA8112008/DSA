// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Store every node in inorder, copy values, sort the copy, write sorted values back. Structure is unchanged; you sort instead of finding the pair.

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
int cmpInt(const void* a, const void* b) { return *(int*)a - *(int*)b; }
void recoverTree(struct Node* root) {
    struct Node* nodes[10005];
    int n = 0, vals[10005];
    collectNodes(root, nodes, &n);
    for (int i = 0; i < n; i++) vals[i] = nodes[i]->val;
    qsort(vals, n, sizeof(int), cmpInt);
    for (int i = 0; i < n; i++) nodes[i]->val = vals[i];
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder with a prev pointer. first is the previous node at the first drop. second is the current node at every drop (so adjacent swaps still work). Swap first.val and second.val.

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

void recoverGo(struct Node* node, struct Node** first, struct Node** second, struct Node** prev) {
    if (!node) return;
    recoverGo(node->left, first, second, prev);
    if (*prev && (*prev)->val > node->val) {
        if (!*first) *first = *prev;
        *second = node;
    }
    *prev = node;
    recoverGo(node->right, first, second, prev);
}
void recoverTree(struct Node* root) {
    struct Node *first = NULL, *second = NULL, *prev = NULL;
    recoverGo(root, &first, &second, &prev);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with the same first/second logic. Thread and unthread predecessor links so you do not keep a stack.

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

void recoverTree(struct Node* root) {
    struct Node *first = NULL, *second = NULL, *prev = NULL, *cur = root;
    while (cur) {
        if (!cur->left) {
            if (prev && prev->val > cur->val) {
                if (!first) first = prev;
                second = cur;
            }
            prev = cur;
            cur = cur->right;
        } else {
            struct Node* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) { pred->right = cur; cur = cur->left; }
            else {
                pred->right = NULL;
                if (prev && prev->val > cur->val) {
                    if (!first) first = prev;
                    second = cur;
                }
                prev = cur;
                cur = cur->right;
            }
        }
    }
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
}
