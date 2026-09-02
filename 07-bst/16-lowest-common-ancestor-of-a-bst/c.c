// Method 1: Brute
// Time: O(n) | Space: O(n)
// Treat it as a binary tree: recurse. If both sides return a node, this is LCA. If one side does, that node is LCA. Ignores ordering.

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

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    if (!root || root == p || root == q) return root;
    struct Node* left = lowestCommonAncestor(root->left, p, q);
    struct Node* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// If both values are less than root, recurse left. Both greater, recurse right. Else root is the split point.

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

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    if (p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    if (p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same split rule in a loop. No recursion. Walk until p and q sit on different sides (or one equals the node).

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

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    struct Node* cur = root;
    while (cur) {
        if (p->val < cur->val && q->val < cur->val) cur = cur->left;
        else if (p->val > cur->val && q->val > cur->val) cur = cur->right;
        else return cur;
    }
    return NULL;
}
