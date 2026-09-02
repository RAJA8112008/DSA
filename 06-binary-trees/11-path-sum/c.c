// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records every root-to-leaf path as an array, sums each, compares to target. Extra storage for all paths.

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

bool hasPathSum_go(struct Node* node, int* path, int* pathn) {
    if (!node) {
        return;
    }
    path[pathn++] = node->val;
    if (!node->left && !node->right) {
        int s = 0;
        for (int _i = 0; _i < pathn; _i++) { struct Node* v = path[_i];
            s += v;
        }
        sums[sumsn++] = s;
    }
    hasPathSum_go(node->left, path);
    hasPathSum_go(node->right, path);
    path[--pathn];
}

bool hasPathSum(struct Node* root, int targetSum) {
    int sums[10005]; int sumsn = 0;
    hasPathSum_go(root, []);
    return /*index*/(targetSum) != -1;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse with remaining. At a leaf, remaining === node.val. Else try left or right with remaining - val.

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

bool hasPathSum(struct Node* root, int targetSum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    struct Node* rest = targetSum - root->val;
    return (hasPathSum(root->left, rest) != NULL ? hasPathSum(root->left, rest) : hasPathSum(root->right, rest));
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of node plus remaining sum. Same check at leaves. No recursion.

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

bool hasPathSum(struct Node* root, int targetSum) {
    if (!root) {
        return false;
    }
    struct Node* stackN[10005]; int stackD[10005]; int stackn = 0;
    while (stackn) {
        /* unpack node,left */
        if (!node->left && !node->right && node->val == left) {
            return true;
        }
        if (node->left) {
            stack[stackn++] = { node: node->left, left: left - node->val };
        }
        if (node->right) {
            stack[stackn++] = { node: node->right, left: left - node->val };
        }
    }
    return false;
}
