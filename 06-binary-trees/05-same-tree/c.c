// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode each tree as a preorder array with N for null, then compare the arrays. Extra strings/arrays for both trees.

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

bool isSameTree_enc(struct Node* node, char** out, int* outn) {
    if (!node) {
        out[outn++] = "N";
        return;
    }
    out[outn++] = /*str*/(node->val);
    isSameTree_enc(node->left, out);
    isSameTree_enc(node->right, out);
}

bool isSameTree(struct Node* p, struct Node* q) {
    struct Node* a[10005]; int an = 0;
    struct Node* b[10005]; int bn = 0;
    isSameTree_enc(p, a);
    isSameTree_enc(q, b);
    if (an != bn) {
        return false;
    }
    for (int i = 0; i < an; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If both null, true. If one null or vals differ, false. Else both lefts and both rights. Stack O(h).

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

bool isSameTree(struct Node* p, struct Node* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative: stack of pairs. Pop two nodes, check null/val, push children pairs. Same complexity, no recursion.

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

bool isSameTree(struct Node* p, struct Node* q) {
    struct Node* stack[10005]; int stackn = 0; stack[stackn++] = [p, q];
    while (stackn) {
        int pair = stack[--stackn];
        struct Node* a = pair[0];
        struct Node* b = pair[1];
        if (!a && !b) {
            continue;
        }
        if (!a || !b || a->val != b->val) {
            return false;
        }
        stack[stackn++] = [a->left, b->left];
        stack[stackn++] = [a->right, b->right];
    }
    return true;
}
