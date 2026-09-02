// Method 1: Brute
// Time: O(n) | Space: O(n)
// For every node, sum the two children (0 if null) and compare. Recurse both sides. Extra list of all nodes first.

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

void collectN(struct Node* node, struct Node** nodes, int* n) {
    if (!node) return;
    nodes[(*n)++] = node;
    collectN(node->left, nodes, n);
    collectN(node->right, nodes, n);
}
bool isSumTree(struct Node* root) {
    struct Node* nodes[10005];
    int n = 0, i;
    collectN(root, nodes, &n);
    for (i = 0; i < n; i++) {
        struct Node* p = nodes[i];
        int L, R;
        if (!p->left && !p->right) continue;
        L = p->left ? p->left->val : 0;
        R = p->right ? p->right->val : 0;
        if (p->val != L + R) return false;
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder boolean. Null and leaves are true. Then check val == left+right and both subtrees hold.

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

bool isSumTree(struct Node* root) {
    int L, R;
    if (!root) return true;
    if (!root->left && !root->right) return true;
    L = root->left ? root->left->val : 0;
    R = root->right ? root->right->val : 0;
    return root->val == L + R && isSumTree(root->left) && isSumTree(root->right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Return a pair (ok, val) so a failed subtree aborts. Same checks, one value returned upward.

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

int goSum(struct Node* node, bool* ok) {
    int L, R;
    if (!node) return 0;
    if (!node->left && !node->right) return node->val;
    L = goSum(node->left, ok);
    R = goSum(node->right, ok);
    if (node->val != L + R) *ok = false;
    return node->val;
}
bool isSumTree(struct Node* root) {
    bool ok = true;
    goSum(root, &ok);
    return ok;
}
