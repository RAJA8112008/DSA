// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode the left subtree left-to-right with nulls, encode the right subtree right-to-left with nulls, compare. Extra arrays.

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

bool isSymmetric_enc(struct Node* node, bool leftFirst, char** out, int* outn) {
    if (!node) {
        out[outn++] = "N";
        return;
    }
    out[outn++] = /*str*/(node->val);
    if (leftFirst) {
        isSymmetric_enc(node->left, true, out);
        isSymmetric_enc(node->right, true, out);
    }
    else {
        isSymmetric_enc(node->right, false, out);
        isSymmetric_enc(node->left, false, out);
    }
}

bool isSymmetric(struct Node* root) {
    if (!root) {
        return true;
    }
    struct Node* a[10005]; int an = 0;
    struct Node* b[10005]; int bn = 0;
    isSymmetric_enc(root->left, true, a);
    isSymmetric_enc(root->right, false, b);
    if (an != bn) {
        return false;
    }
    for (int i = 0; i < an; i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// mirror(a,b): both null ok; one null fail; vals equal and mirror(a.left,b.right) and mirror(a.right,b.left). Recurse from root.left and root.right.

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

bool isSymmetric_mirror(struct Node* a, struct Node* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b || a->val != b->val) {
        return false;
    }
    return isSymmetric_mirror(a->left, b->right) && isSymmetric_mirror(a->right, b->left);
}

bool isSymmetric(struct Node* root) {
    if (!root) {
        return true;
    }
    return isSymmetric_mirror(root->left, root->right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Queue of node pairs. Dequeue a and b, check, enqueue a.left with b.right and a.right with b.left. Iterative mirror test.

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

bool isSymmetric(struct Node* root) {
    if (!root) {
        return true;
    }
    struct Node* queue[10005]; int queueh = 0, queuet = 0; queue[queuet++] = root->left, root->right;
    while (queuen) {
        struct Node* a = queue[queueh++];
        struct Node* b = queue[queueh++];
        if (!a && !b) {
            continue;
        }
        if (!a || !b || a->val != b->val) {
            return false;
        }
        queue[queuet++] = a->left, b->right;
        queue[queuet++] = a->right, b->left;
    }
    return true;
}
