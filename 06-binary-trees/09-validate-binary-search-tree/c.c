// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump into an array, then check each pair is strictly increasing. Extra O(n) array.

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

bool isValidBST_inorder(struct Node* node) {
    if (!node) {
        return;
    }
    isValidBST_inorder(node->left);
    vals[valsn++] = node->val;
    isValidBST_inorder(node->right);
}

bool isValidBST(struct Node* root) {
    int vals[10005]; int valsn = 0;
    isValidBST_inorder(root);
    for (int i = 1; i < valsn; i++) {
        if (vals[i] <= vals[i - 1]) {
            return false;
        }
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (low, high). Left child gets high = node.val. Right child gets low = node.val. Use -Infinity / Infinity at the root. Recursion O(h).

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

bool isValidBST_ok(struct Node* node, int low, int high) {
    if (!node) {
        return true;
    }
    if (node->val <= low || node->val >= high) {
        return false;
    }
    return isValidBST_ok(node->left, low, node->val) && isValidBST_ok(node->right, node->val, high);
}

bool isValidBST(struct Node* root) {
    return isValidBST_ok(root, INT_MIN, INT_MAX);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. prev holds the last visited value. If node.val <= prev, fail. No extra values array.

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

bool isValidBST(struct Node* root) {
    struct Node* stack[10005]; int stackn = 0;
    struct Node* cur = root;
    struct Node* prev = INT_MIN;
    bool hasPrev = false;
    while (cur || stackn) {
        while (cur) {
            stack[stackn++] = cur;
            cur = cur->left;
        }
        cur = stack[--stackn];
        if (hasPrev && cur->val <= prev) {
            return false;
        }
        prev = cur->val;
        hasPrev = true;
        cur = cur->right;
    }
    return true;
}
