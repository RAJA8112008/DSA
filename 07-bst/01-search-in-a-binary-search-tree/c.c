// Method 1: Brute
// Time: O(n) | Space: O(n)
// Ignore the BST. DFS every node into a list, then scan for val. Correct on any binary tree, but you throw away the ordering.

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

void goCollect(struct Node* node, struct Node** nodes, int* n) {
    if (!node) return;
    nodes[(*n)++] = node;
    goCollect(node->left, nodes, n);
    goCollect(node->right, nodes, n);
}
struct Node* searchBST(struct Node* root, int val) {
    struct Node* nodes[10005];
    int n = 0;
    goCollect(root, nodes, &n);
    for (int i = 0; i < n; i++) if (nodes[i]->val == val) return nodes[i];
    return NULL;
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse on one child. Each call compares val with the node and drops a whole subtree. Stack depth is the height.

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

struct Node* searchBST(struct Node* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same comparisons in a while loop. No call stack. Returns the node or null when the walk falls off.

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

struct Node* searchBST(struct Node* root, int val) {
    struct Node* cur = root;
    while (cur && cur->val != val) cur = val < cur->val ? cur->left : cur->right;
    return cur;
}
