// Method 1: Brute
// Time: O(n) | Space: O(h)
// DFS every node. Add val when it is inside the interval. Correct on a plain binary tree too.

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

int rangeSumBST(struct Node* root, int low, int high) {
    if (!root) return 0;
    int add = (root->val >= low && root->val <= high) ? root->val : 0;
    return add + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Prune: skip left when node is below low, skip right when node is above high. Best case you only walk the in-range corridor.

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

int rangeSumBST(struct Node* root, int low, int high) {
    if (!root) return 0;
    if (root->val < low) return rangeSumBST(root->right, low, high);
    if (root->val > high) return rangeSumBST(root->left, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Explicit stack, same prune. No recursion. Push only children that can still hold in-range keys.

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

int rangeSumBST(struct Node* root, int low, int high) {
    int sum = 0;
    struct Node* stack[10005];
    int sp = 0;
    if (root) stack[sp++] = root;
    while (sp) {
        struct Node* node = stack[--sp];
        if (node->val >= low && node->val <= high) sum += node->val;
        if (node->left && node->val > low) stack[sp++] = node->left;
        if (node->right && node->val < high) stack[sp++] = node->right;
    }
    return sum;
}
