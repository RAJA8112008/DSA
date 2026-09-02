// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At every node, diameter candidate is height(left)+height(right). height itself walks the subtree, so nested walks are quadratic on a skewed tree.

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

int diameterOfBinaryTree_height(struct Node* node) {
    if (!node) {
        return 0;
    }
    return 1 + MAX(diameterOfBinaryTree_height(node->left), diameterOfBinaryTree_height(node->right));
}

int diameterOfBinaryTree_visit(struct Node* node) {
    if (!node) {
        return;
    }
    struct Node* through = height(node->left) + height(node->right);
    if (through > best) {
        best = through;
    }
    diameterOfBinaryTree_visit(node->left);
    diameterOfBinaryTree_visit(node->right);
}

int diameterOfBinaryTree(struct Node* root) {
    int best = 0;
    diameterOfBinaryTree_visit(root);
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS returns height. While returning, update best with leftHeight + rightHeight. Each node once.

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

int diameterOfBinaryTree_height(struct Node* node) {
    if (!node) {
        return 0;
    }
    struct Node* lh = diameterOfBinaryTree_height(node->left);
    struct Node* rh = diameterOfBinaryTree_height(node->right);
    if (lh + rh > best) {
        best = lh + rh;
    }
    return 1 + MAX(lh, rh);
}

int diameterOfBinaryTree(struct Node* root) {
    int best = 0;
    diameterOfBinaryTree_height(root);
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder. A Map stores height after both children are done. Update diameter from those heights. No call stack; extra map of n heights.

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

int diameterOfBinaryTree(struct Node* root) {
    if (!root) {
        return 0;
    }
    struct Node* stack[10005]; int stackn = 0; stack[stackn++] = root;
    struct Node* seen[10005]; int seenn = 0;
    struct Node* heightK[10005]; int heightV[10005]; int heightn = 0;
    heightK[heightn] = NULL; heightV[heightn++] = 0;
    int best = 0;
    while (stackn) {
        struct Node* node = stack[stackn - 1];
        if (node->left && !containsPtr(height, heightn, node->left) && !containsPtr(seen, seenn, node->left)) {
            stack[stackn++] = node->left;
            continue;
        }
        if (node->right && !containsPtr(height, heightn, node->right) && !containsPtr(seen, seenn, node->right)) {
            stack[stackn++] = node->right;
            continue;
        }
        stack[--stackn];
        seen[seenn++] = node;
        struct Node* lh = height[node->left] || 0;
        struct Node* rh = height[node->right] || 0;
        heightK[heightn] = node; heightV[heightn++] = 1 + MAX(lh, rh);
        if (lh + rh > best) {
            best = lh + rh;
        }
    }
    return best;
}
