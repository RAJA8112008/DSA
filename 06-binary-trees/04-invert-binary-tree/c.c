// Method 1: Brute
// Time: O(n) | Space: O(n)
// BFS into an array of every node, then swap left/right on each. Extra list of n pointers.

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

struct Node* invertTree(struct Node* root) {
    if (!root) {
        return root;
    }
    struct Node* nodes[10005]; int nodesn = 0;
    struct Node* queue[10005]; int queueh = 0, queuet = 0; queue[queuet++] = root;
    while (queuen) {
        struct Node* node = queue[queueh++];
        nodes[nodesn++] = node;
        if (node->left) {
            queue[queuet++] = node->left;
        }
        if (node->right) {
            queue[queuet++] = node->right;
        }
    }
    for (int _i = 0; _i < nodesn; _i++) { struct Node* node = nodes[_i];
        struct Node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse: invert children, then swap this node's left and right (order of swap vs recurse both work). Stack O(h).

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

struct Node* invertTree(struct Node* root) {
    if (!root) {
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    struct Node* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack. Pop a node, swap children, push non-null children. Same work, no recursion. Queue instead of stack is also fine.

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

struct Node* invertTree(struct Node* root) {
    if (!root) {
        return NULL;
    }
    struct Node* stack[10005]; int stackn = 0; stack[stackn++] = root;
    while (stackn) {
        struct Node* node = stack[--stackn];
        struct Node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left) {
            stack[stackn++] = node->left;
        }
        if (node->right) {
            stack[stackn++] = node->right;
        }
    }
    return root;
}
