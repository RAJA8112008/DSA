// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Root is preorder[0]. Scan inorder for it, slice left/right arrays, recurse. Slicing and scanning are O(n) per node.

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

struct Node* buildTree(int* preorder, int preordern, int* inorder, int inordern) {
    if (!preordern) {
        return NULL;
    }
    int rootVal = preorder[0];
    struct Node* root = newNode(rootVal);
    struct Node* mid = /*index*/(rootVal);
    root->left = buildTree(preorder, inorder);
    root->right = buildTree(preorder);
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// HashMap of inorder indexes. Recurse with (preL, preR, inL, inR) bounds. Each node created once; map lookup O(1).

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

struct Node* buildTree_build(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return NULL;
    }
    struct Node* root = newNode(preorder[preL]);
    struct Node* mid = idx[root->val];
    int leftSize = mid - inL;
    root->left = buildTree_build(preL + 1, preL + leftSize, inL, mid - 1);
    root->right = buildTree_build(preL + leftSize + 1, preR, mid + 1, inR);
    return root;
}

struct Node* buildTree(int* preorder, int preordern, int* inorder, int inordern) {
    int idxK[10005], idxV[10005], idxn = 0;
    for (int i = 0; i < inordern; i++) {
        idxK[idxn] = inorder[i]; idxV[idxn++] = i;
    }
    return buildTree_build(0, preordern - 1, 0, inordern - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Advance a preorder index and an inorder index. build(stop) creates a node, builds left until inorder hits this val, then right until stop. No hashmap; O(h) stack only besides the tree.

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

struct Node* buildTree_build(int stop) {
    if (p >= preordern) {
        return NULL;
    }
    if (inorder[i] == stop) {
        i++;
        return NULL;
    }
    struct Node* root = newNode(preorder[p++]);
    root->left = buildTree_build(root->val);
    root->right = buildTree_build(stop);
    return root;
}

struct Node* buildTree(int* preorder, int preordern, int* inorder, int inordern) {
    struct Node* p = 0;
    int i = 0;
    return buildTree_build();
}
