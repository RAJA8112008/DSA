// Method 1: Brute
// Time: O(n) | Space: O(n)
// Recursive inorder: walk left, push this value, walk right. Matches the definition. Extra memory is the output array plus O(h) call stack.

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

int* inorderTraversal_go(struct Node* node) {
    if (!node) {
        return;
    }
    inorderTraversal_go(node->left);
    out[outn++] = node->val;
    inorderTraversal_go(node->right);
}

int* inorderTraversal(struct Node* root) {
    struct Node* out[10005]; int outn = 0;
    inorderTraversal_go(root);
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Iterative stack: go left until null, pop, record val, go right. Same visit order as recursion without depending on engine stack limits as much; still O(h) extra.

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

int* inorderTraversal(struct Node* root) {
    struct Node* out[10005]; int outn = 0;
    struct Node* stack[10005]; int stackn = 0;
    struct Node* cur = root;
    while (cur || stackn) {
        while (cur) {
            stack[stackn++] = cur;
            cur = cur->left;
        }
        cur = stack[--stackn];
        out[outn++] = cur->val;
        cur = cur->right;
    }
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris: if there is no left, visit and go right. Else find the predecessor (rightmost in left). If pred.right is null, thread it to cur and go left. If it already points at cur, unthread, visit, go right. Auxiliary space O(1) besides the output list.

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

int* inorderTraversal(struct Node* root) {
    struct Node* out[10005]; int outn = 0;
    struct Node* cur = root;
    while (cur) {
        if (!cur->left) {
            out[outn++] = cur->val;
            cur = cur->right;
        }
        else {
            struct Node* pred = cur->left;
            while (pred->right && pred->right != cur) {
                pred = pred->right;
            }
            if (!pred->right) {
                pred->right = cur;
                cur = cur->left;
            }
            else {
                pred->right = NULL;
                out[outn++] = cur->val;
                cur = cur->right;
            }
        }
    }
    return out;
}
