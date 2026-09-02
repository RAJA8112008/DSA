// Method 1: Brute
// Time: O(n²) | Space: O(h)
// For each node, DFS the rest of the tree looking for k - val. Nested walks. No extra set.

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

bool existsSkip(struct Node* node, struct Node* skip, int val) {
    if (!node) return false;
    if (node != skip && node->val == val) return true;
    return existsSkip(node->left, skip, val) || existsSkip(node->right, skip, val);
}
bool goFind(struct Node* root, struct Node* node, int k) {
    if (!node) return false;
    if (existsSkip(root, node, k - node->val)) return true;
    return goFind(root, node->left, k) || goFind(root, node->right, k);
}
bool findTarget(struct Node* root, int k) { return goFind(root, root, k); }


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Hash set of visited values. DFS: if k - val is in the set, done; else add val and continue. Works on any binary tree.

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

bool goSeen(struct Node* node, int k, int* seen, int* n) {
    int i;
    if (!node) return false;
    for (i = 0; i < *n; i++) if (seen[i] == k - node->val) return true;
    seen[(*n)++] = node->val;
    return goSeen(node->left, k, seen, n) || goSeen(node->right, k, seen, n);
}
bool findTarget(struct Node* root, int k) {
    int seen[10005], n = 0;
    return goSeen(root, k, seen, &n);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Inorder array is sorted. Two pointers from both ends. Uses the BST. Space is still linear for the array; two iterators would drop it to O(h).

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
bool findTarget(struct Node* root, int k) {
    int vals[10005], n = 0, i, j, s;
    inorderVals(root, vals, &n);
    i = 0; j = n - 1;
    while (i < j) {
        s = vals[i] + vals[j];
        if (s == k) return true;
        if (s < k) i++;
        else j--;
    }
    return false;
}
