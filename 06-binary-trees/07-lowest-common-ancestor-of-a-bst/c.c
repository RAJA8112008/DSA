// Method 1: Brute
// Time: O(h) | Space: O(h)
// Walk BST paths into two arrays of nodes, then scan from the start until they differ. Extra path arrays.

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

struct Node* lowestCommonAncestor_pathTo(struct Node* node, struct Node* target) {
    int path[10005]; int pathn = 0;
    struct Node* cur = node;
    while (cur) {
        path[pathn++] = cur;
        if (cur == target || cur->val == target->val) {
            break;
        }
        cur = target->val < cur->val ? cur->left : cur->right;
    }
    return path;
}

struct Node* lowestCommonAncestor(struct Node* root, struct Node* p, struct Node* q) {
    struct Node* a = lowestCommonAncestor_pathTo(root, p);
    struct Node* b = lowestCommonAncestor_pathTo(root, q);
    int i = 0;
    while (i < an && i < bn && a[i] == b[i]) {
        i++;
    }
    return a[i - 1];
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recursive BST walk. Split point is the LCA. Stack O(h).

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
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    }
    if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    }
    return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same split logic in a loop. No recursion. Constant extra space.

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
    struct Node* cur = root;
    while (cur) {
        if (p->val < cur->val && q->val < cur->val) {
            cur = cur->left;
        }
        else if (p->val > cur->val && q->val > cur->val) {
            cur = cur->right;
        }
        else {
            return cur;
        }
    }
    return NULL;
}
