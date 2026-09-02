// Method 1: Brute
// Time: O(n·m) | Space: O(n)
// Push every node of root into an array, then isSameTree against subRoot for each. Extra array plus O(n*m) compares.

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

bool isSubtree_same(struct Node* a, struct Node* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b || a->val != b->val) {
        return false;
    }
    return isSubtree_same(a->left, b->left) && isSubtree_same(a->right, b->right);
}

bool isSubtree_collect(struct Node* node) {
    if (!node) {
        return;
    }
    nodes[nodesn++] = node;
    isSubtree_collect(node->left);
    isSubtree_collect(node->right);
}

bool isSubtree(struct Node* root, struct Node* subRoot) {
    struct Node* nodes[10005]; int nodesn = 0;
    isSubtree_collect(root);
    for (int _i = 0; _i < nodesn; _i++) { struct Node* node = nodes[_i];
        if (isSubtree_same(node, subRoot)) {
            return true;
        }
    }
    return false;
}


// Method 2: Optimal
// Time: O(n·m) | Space: O(h)
// No extra node list. If this node matches as a tree, true. Else try left or right. Worst case still O(n*m), typical interview code.

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

bool isSubtree_same(struct Node* a, struct Node* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b || a->val != b->val) {
        return false;
    }
    return isSubtree_same(a->left, b->left) && isSubtree_same(a->right, b->right);
}

bool isSubtree(struct Node* root, struct Node* subRoot) {
    if (!root) {
        return false;
    }
    if (isSubtree_same(root, subRoot)) {
        return true;
    }
    return (isSubtree(root->left, subRoot) != NULL ? isSubtree(root->left, subRoot) : isSubtree(root->right, subRoot));
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(n+m)
// Serialize with parentheses so each subtree is a unique string. Check whether ser(subRoot) is a substring of ser(root). Linear in the size of the strings (and typical includes).

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

bool isSubtree_ser(struct Node* node) {
    if (!node) {
        return "N";
    }
    return "(" + node->val + "," + isSubtree_ser(node->left) + "," + isSubtree_ser(node->right) + ")";
}

bool isSubtree(struct Node* root, struct Node* subRoot) {
    return isSubtree_ser(root).indexOf(isSubtree_ser(subRoot)) != -1;
}
