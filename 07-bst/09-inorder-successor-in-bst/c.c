// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder list of nodes, find p, return the next entry. Extra linear memory.

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
struct Node* inorderSuccessor(struct Node* root, struct Node* p) {
    struct Node* nodes[10005];
    int n = 0;
    collectNodes(root, nodes, &n);
    for (int i = 0; i < n; i++)
        if (nodes[i] == p) return i + 1 < n ? nodes[i + 1] : NULL;
    return NULL;
}


// Method 2: Optimal
// Time: O(h) | Space: O(1)
// Walk from the root. Whenever the current node is greater than p, it is a candidate successor — go left to hunt a closer one. Otherwise go right.

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

struct Node* inorderSuccessor(struct Node* root, struct Node* p) {
    struct Node* succ = NULL;
    struct Node* cur = root;
    while (cur) {
        if (p->val < cur->val) { succ = cur; cur = cur->left; }
        else cur = cur->right;
    }
    return succ;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// If p has a right child, successor is leftmost there — O(h) on that spine only. Else fall back to the root walk. Same worst case, often shorter.

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

struct Node* inorderSuccessor(struct Node* root, struct Node* p) {
    if (p->right) {
        struct Node* n = p->right;
        while (n->left) n = n->left;
        return n;
    }
    struct Node* succ = NULL;
    struct Node* cur = root;
    while (cur) {
        if (p->val < cur->val) { succ = cur; cur = cur->left; }
        else cur = cur->right;
    }
    return succ;
}
