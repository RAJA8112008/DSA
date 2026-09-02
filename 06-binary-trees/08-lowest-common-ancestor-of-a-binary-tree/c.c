// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records the path to p and the path to q as arrays. Last common entry is the LCA. Extra path storage.

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

bool lowestCommonAncestor_find(struct Node* node, struct Node* target, int* path, int* pathn) {
    if (!node) {
        return false;
    }
    path[pathn++] = node;
    if (node == target) {
        return true;
    }
    if (lowestCommonAncestor_find(node->left, target, path) || lowestCommonAncestor_find(node->right, target, path)) {
        return true;
    }
    path[--pathn];
    return false;
}

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    struct Node* a[10005]; int an = 0;
    struct Node* b[10005]; int bn = 0;
    lowestCommonAncestor_find(root, p, a);
    lowestCommonAncestor_find(root, q, b);
    int i = 0;
    while (i < an && i < bn && a[i] == b[i]) {
        i++;
    }
    return a[i - 1];
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If node is null, p, or q, return node. Recurse left and right. If both sides return non-null, node is LCA. Else return the non-null side. One DFS.

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

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    struct Node* left = lowestCommonAncestor(root->left, p, q);
    struct Node* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
        return root;
    }
    return (left != NULL ? left : right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative stack builds a parent map. Collect ancestors of p in a Set. Walk q's parent chain until a node is in the set. No recursion; extra map of n parents.

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

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    struct Node* parentK[10005]; struct Node* parentV[10005]; int parentn = 0;
    parentK[parentn] = root; parentV[parentn++] = NULL;
    struct Node* stack[10005]; int stackn = 0; stack[stackn++] = root;
    while (!containsPtr(parent, parentn, p) || !containsPtr(parent, parentn, q)) {
        struct Node* node = stack[--stackn];
        if (node->left) {
            parentK[parentn] = node->left; parentV[parentn++] = node;
            stack[stackn++] = node->left;
        }
        if (node->right) {
            parentK[parentn] = node->right; parentV[parentn++] = node;
            stack[stackn++] = node->right;
        }
    }
    struct Node* seen[10005]; int seenn = 0;
    struct Node* cur = p;
    while (cur) {
        seen[seenn++] = cur;
        cur = parent[cur];
    }
    cur = q;
    while (!containsPtr(seen, seenn, cur)) {
        cur = parent[cur];
    }
    return cur;
}
