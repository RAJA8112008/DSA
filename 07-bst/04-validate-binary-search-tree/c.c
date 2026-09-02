// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump all values, then check each pair is strictly increasing. Extra array holds the whole walk.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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

void inorderVals(struct Node* node, int* vals, int* n) {
    if (!node) return;
    inorderVals(node->left, vals, n);
    vals[(*n)++] = node->val;
    inorderVals(node->right, vals, n);
}
bool isValidBST(struct Node* root) {
    int vals[10005], n = 0;
    inorderVals(root, vals, &n);
    for (int i = 1; i < n; i++) if (vals[i] <= vals[i - 1]) return false;
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (lo, hi). Left child inherits hi = node.val; right inherits lo = node.val. Use a type wider than int so INT_MIN / INT_MAX are legal node values.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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

bool okRange(struct Node* node, long long lo, long long hi) {
    if (!node) return true;
    if (node->val <= lo || node->val >= hi) return false;
    return okRange(node->left, lo, node->val) && okRange(node->right, node->val, hi);
}
bool isValidBST(struct Node* root) {
    return okRange(root, LLONG_MIN, LLONG_MAX);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. Track the previous value. If the current node is not greater, the tree is invalid. No extra value array.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

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

bool isValidBST(struct Node* root) {
    struct Node* stack[10005];
    int sp = 0;
    struct Node* cur = root;
    struct Node* prev = NULL;
    while (cur || sp) {
        while (cur) {
            stack[sp++] = cur;
            cur = cur->left;
        }
        cur = stack[--sp];
        if (prev && cur->val <= prev->val) return false;
        prev = cur;
        cur = cur->right;
    }
    return true;
}
