// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Insert 0..n-1 in order into an empty BST. Each insert walks a growing right spine, so you get a linked list of height n.

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

struct Node* insertVal(struct Node* node, int val) {
    if (!node) return newNode(val);
    if (val < node->val) node->left = insertVal(node->left, val);
    else node->right = insertVal(node->right, val);
    return node;
}
struct Node* sortedArrayToBST(int* nums, int numsSize) {
    struct Node* root = NULL;
    for (int i = 0; i < numsSize; i++) root = insertVal(root, nums[i]);
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Slice the array around mid each call. Balanced, but each slice copies O(n) elements across the tree of calls.

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

struct Node* buildArr(int* nums, int lo, int hi) {
    if (lo > hi) return NULL;
    int mid = lo + (hi - lo) / 2;
    struct Node* node = newNode(nums[mid]);
    node->left = buildArr(nums, lo, mid - 1);
    node->right = buildArr(nums, mid + 1, hi);
    return node;
}
struct Node* sortedArrayToBST(int* nums, int numsSize) {
    return buildArr(nums, 0, numsSize - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(log n)
// Pass inclusive indices. Each node is created once. Recursion depth is the height of the balanced tree.

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

struct Node* buildArr(int* nums, int lo, int hi) {
    if (lo > hi) return NULL;
    int mid = lo + (hi - lo) / 2;
    struct Node* node = newNode(nums[mid]);
    node->left = buildArr(nums, lo, mid - 1);
    node->right = buildArr(nums, mid + 1, hi);
    return node;
}
struct Node* sortedArrayToBST(int* nums, int numsSize) {
    return buildArr(nums, 0, numsSize - 1);
}
