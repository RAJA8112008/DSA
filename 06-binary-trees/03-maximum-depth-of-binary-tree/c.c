// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every root-to-leaf path into arrays, return the longest length. Extra memory for all paths.

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

int maxDepth_go(struct Node* node, int* path, int* pathn) {
    if (!node) {
        return;
    }
    path[pathn++] = node->val;
    if (!node->left && !node->right) {
        paths[pathsn++] = pathn;
    }
    maxDepth_go(node->left, path);
    maxDepth_go(node->right, path);
    path[--pathn];
}

int maxDepth(struct Node* root) {
    int paths[10005]; int pathsn = 0;
    maxDepth_go(root, []);
    return pathsn ? /*max*/ : 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recursive height: null is 0, else 1 + max of children. One visit per node. Stack O(h).

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

int maxDepth(struct Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + MAX(maxDepth(root->left), maxDepth(root->right));
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of {node, depth}. Track the max depth seen. Same complexity, no engine recursion. BFS would use O(width) instead of O(h).

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

int maxDepth(struct Node* root) {
    if (!root) {
        return 0;
    }
    int best = 0;
    struct Node* stackN[10005]; int stackD[10005]; int stackn = 0;
    while (stackn) {
        /* unpack node,d */
        if (d > best) {
            best = d;
        }
        if (node->left) {
            stack[stackn++] = { node: node->left, d: d + 1 };
        }
        if (node->right) {
            stack[stackn++] = { node: node->right, d: d + 1 };
        }
    }
    return best;
}
