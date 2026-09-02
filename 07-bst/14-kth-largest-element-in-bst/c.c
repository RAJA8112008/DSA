// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump, then return vals[n - k]. Extra array of every key.

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
int kthLargest(struct Node* root, int k) {
    int vals[10005], n = 0;
    inorderVals(root, vals, &n);
    return vals[n - k];
}


// Method 2: Optimal
// Time: O(h + k) | Space: O(h)
// Reverse inorder. Decrement k at each visit. When k hits 0, that value is the answer. Stop walking.

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

void kthGo(struct Node* node, int* k, int* ans) {
    if (!node || *k == 0) return;
    kthGo(node->right, k, ans);
    if (*k == 0) return;
    (*k)--;
    if (*k == 0) { *ans = node->val; return; }
    kthGo(node->left, k, ans);
}
int kthLargest(struct Node* root, int k) {
    int ans = 0;
    kthGo(root, &k, &ans);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris reverse inorder: thread the successor (leftmost of the right, via left pointers of the right spine). Visit without a stack, stop at k.

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

int kthLargest(struct Node* root, int k) {
    struct Node* cur = root;
    while (cur) {
        if (!cur->right) {
            if (--k == 0) return cur->val;
            cur = cur->left;
        } else {
            struct Node* succ = cur->right;
            while (succ->left && succ->left != cur) succ = succ->left;
            if (!succ->left) { succ->left = cur; cur = cur->right; }
            else {
                succ->left = NULL;
                if (--k == 0) return cur->val;
                cur = cur->left;
            }
        }
    }
    return 0;
}
