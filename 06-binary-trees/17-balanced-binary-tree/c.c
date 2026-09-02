// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node recompute both heights and recurse isBalanced on children. Height work repeats on the same nodes.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

bool isBalanced_height(struct Node* node) {
    if (!node) {
        return 0;
    }
    return 1 + MAX(isBalanced_height(node->left), isBalanced_height(node->right));
}

bool isBalanced(struct Node* root) {
    if (!root) {
        return true;
    }
    if (abs(isBalanced_height(root->left) - isBalanced_height(root->right)) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder returns height. If a child is already unbalanced or |lh-rh|>1, return -1 and bubble up. One visit per node.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

bool isBalanced_walk(struct Node* node) {
    if (!node) {
        return 0;
    }
    struct Node* lh = isBalanced_walk(node->left);
    if (lh < 0) {
        return -1;
    }
    struct Node* rh = isBalanced_walk(node->right);
    if (rh < 0) {
        return -1;
    }
    if (abs(lh - rh) > 1) {
        return -1;
    }
    return 1 + MAX(lh, rh);
}

bool isBalanced(struct Node* root) {
    return isBalanced_walk(root) >= 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder with a height map. After both children, check |lh-rh| and store height. No recursion.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

bool isBalanced(struct Node* root) {
    if (!root) {
        return true;
    }
    struct Node* stack[10005]; int stackn = 0; stack[stackn++] = root;
    struct Node* heightK[10005]; int heightV[10005]; int heightn = 0;
    heightK[heightn] = NULL; heightV[heightn++] = 0;
    while (stackn) {
        struct Node* node = stack[stackn - 1];
        if (node->left && !containsPtr(height, heightn, node->left)) {
            stack[stackn++] = node->left;
            continue;
        }
        if (node->right && !containsPtr(height, heightn, node->right)) {
            stack[stackn++] = node->right;
            continue;
        }
        stack[--stackn];
        struct Node* lh = height[node->left] || 0;
        struct Node* rh = height[node->right] || 0;
        if (abs(lh - rh) > 1) {
            return false;
        }
        heightK[heightn] = node; heightV[heightn++] = 1 + MAX(lh, rh);
    }
    return true;
}
