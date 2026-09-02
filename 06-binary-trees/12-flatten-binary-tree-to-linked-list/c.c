// Method 1: Brute
// Time: O(n) | Space: O(n)
// Preorder collect nodes into an array. Then set each left to null and next.right to the following node. Extra array.

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

struct Node* flatten_pre(struct Node* node) {
    if (!node) {
        return;
    }
    nodes[nodesn++] = node;
    flatten_pre(node->left);
    flatten_pre(node->right);
}

void flatten(struct Node* root) {
    struct Node* nodes[10005]; int nodesn = 0;
    flatten_pre(root);
    for (int i = 0; i < nodesn; i++) {
        nodes[i].left = NULL;
        nodes[i].right = i + 1 < nodesn ? nodes[i + 1] : NULL;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse right, then left, keep a tail pointer of the already flattened suffix. Hang this node in front. Stack O(h).

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

struct Node* flatten_go(struct Node* node) {
    if (!node) {
        return;
    }
    flatten_go(node->right);
    flatten_go(node->left);
    node->right = box_tail;
    node->left = NULL;
    box_tail = node;
}

void flatten(struct Node* root) {
    struct Node* box_tail = NULL;
    flatten_go(root);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// While cur exists: if it has a left, find rightmost of left, attach cur.right there, move left to right, clear left. Then cur = cur.right. No extra stack.

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

void flatten(struct Node* root) {
    struct Node* cur = root;
    while (cur) {
        if (cur->left) {
            struct Node* pred = cur->left;
            while (pred->right) {
                pred = pred->right;
            }
            pred->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}
