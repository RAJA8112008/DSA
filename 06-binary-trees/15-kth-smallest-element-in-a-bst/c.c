// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full inorder into an array, return vals[k-1]. Always walks the whole tree.

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

int kthSmallest_inorder(struct Node* node) {
    if (!node) {
        return;
    }
    kthSmallest_inorder(node->left);
    vals[valsn++] = node->val;
    kthSmallest_inorder(node->right);
}

int kthSmallest(struct Node* root, int k) {
    int vals[10005]; int valsn = 0;
    kthSmallest_inorder(root);
    return vals[k - 1];
}


// Method 2: Optimal
// Time: O(h+k) | Space: O(h)
// Recursive inorder with a counter. When count hits k, record val and stop expanding. Better when k is small.

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

int kthSmallest_go(struct Node* node) {
    if (!node || box.count >= k) {
        return;
    }
    kthSmallest_go(node->left);
    box_count++;
    if (box.count == k) {
        box_ans = node->val;
        return;
    }
    kthSmallest_go(node->right);
}

int kthSmallest(struct Node* root, int k) {
    int box_count = 0;
    int box_ans = 0;
    kthSmallest_go(root);
    return box.ans;
}


// Method 3: More optimal
// Time: O(h+k) | Space: O(h)
// Iterative inorder. Each pop is the next smallest. After k pops, return that val. Easy to stop early; no extra values array.

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

int kthSmallest(struct Node* root, int k) {
    struct Node* stack[10005]; int stackn = 0;
    struct Node* cur = root;
    while (true) {
        while (cur) {
            stack[stackn++] = cur;
            cur = cur->left;
        }
        cur = stack[--stackn];
        k--;
        if (k == 0) {
            return cur->val;
        }
        cur = cur->right;
    }
}
