// Method 1: Brute
// Time: O(n) | Space: O(h)
// Classic 1 + count(left) + count(right). Ignores the complete-tree promise. Fine for small n.

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

int countNodes(struct Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Method 2: Optimal
// Time: O(log² n) | Space: O(log n)
// Measure leftmost and rightmost depths. If equal, subtree is perfect: (1 << h) - 1. Else 1 + count(left) + count(right). Each level does O(log n) height work.

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

int countNodes(struct Node* root) {
    if (!root) {
        return 0;
    }
    int lh = 0;
    int rh = 0;
    struct Node* l = root;
    struct Node* r = root;
    while (l) {
        lh++;
        l = l->left;
    }
    while (r) {
        rh++;
        r = r->right;
    }
    if (lh == rh) {
        return (1 << lh) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Method 3: More optimal
// Time: O(log² n) | Space: O(1)
// Height of leftmost path, then binary search the last level: exists(index) walks h-1 bits from the root. Count = full upper levels + how many last-level nodes exist. Iterative, O(1) extra besides the tree.

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

int countNodes_leftHeight(struct Node* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->left;
    }
    return h;
}

bool countNodes_exists(int index, int h, struct Node* node) {
    int lo = 0;
    int hi = (1 << (h - 1)) - 1;
    for (int i = 0; i < h - 1; i++) {
        struct Node* mid = ((lo + hi) / 2);
        if (index <= mid) {
            node = node->left;
            hi = mid;
        }
        else {
            node = node->right;
            lo = mid + 1;
        }
    }
    return node;
}

int countNodes(struct Node* root) {
    if (!root) {
        return 0;
    }
    int h = countNodes_leftHeight(root);
    int lastCount = 1 << (h - 1);
    int lo = 0;
    int hi = lastCount - 1;
    while (lo <= hi) {
        struct Node* mid = ((lo + hi) / 2);
        if (countNodes_exists(mid, h, root)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return lastCount - 1 + lo;
}
