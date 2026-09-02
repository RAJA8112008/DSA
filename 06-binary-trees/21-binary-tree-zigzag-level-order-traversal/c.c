// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order into lists. Reverse rows whose index is odd. Extra reverse pass per odd level.

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

int** zigzagLevelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    static int rows[64][256];
    static int cols[64];
    static int* ptrs[64];
    struct Node* q[10005];
    int qs = 0, qe = 0, rc = 0, i;
    *returnSize = 0;
    if (!root) { *returnColumnSizes = cols; return ptrs; }
    q[qe++] = root;
    while (qs < qe) {
        int n = qe - qs;
        cols[rc] = n;
        for (i = 0; i < n; i++) {
            struct Node* node = q[qs++];
            rows[rc][i] = node->val;
            if (node->left) q[qe++] = node->left;
            if (node->right) q[qe++] = node->right;
        }
        if (rc % 2 == 1) {
            for (i = 0; i < n / 2; i++) {
                int t = rows[rc][i];
                rows[rc][i] = rows[rc][n - 1 - i];
                rows[rc][n - 1 - i] = t;
            }
        }
        ptrs[rc] = rows[rc];
        rc++;
    }
    *returnSize = rc;
    *returnColumnSizes = cols;
    return ptrs;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Deque of nodes. Even levels poll from the front and offer children left-then-right at the back. Odd levels poll from the back and offer children right-then-left at the front.

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

int** zigzagLevelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    static int rows[64][256];
    static int cols[64];
    static int* ptrs[64];
    struct Node* dq[10005];
    int head = 5000, tail = 5000, rc = 0, leftToRight = 1, i;
    *returnSize = 0;
    if (!root) { *returnColumnSizes = cols; return ptrs; }
    dq[tail++] = root;
    while (head < tail) {
        int n = tail - head;
        cols[rc] = n;
        for (i = 0; i < n; i++) {
            struct Node* node;
            if (leftToRight) node = dq[head++];
            else node = dq[--tail];
            rows[rc][i] = node->val;
            if (leftToRight) {
                if (node->left) dq[tail++] = node->left;
                if (node->right) dq[tail++] = node->right;
            } else {
                if (node->right) dq[--head] = node->right;
                if (node->left) dq[--head] = node->left;
            }
        }
        ptrs[rc] = rows[rc];
        rc++;
        leftToRight = !leftToRight;
    }
    *returnSize = rc;
    *returnColumnSizes = cols;
    return ptrs;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with depth. Append a new list when you first reach a depth. Push on even depths, unshift on odd depths. Recursion stack only.

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

void goZig(struct Node* node, int d, int rows[][256], int* cols, int* rc) {
    if (!node) return;
    if (d == *rc) { cols[d] = 0; (*rc)++; }
    if (d % 2 == 0) rows[d][cols[d]++] = node->val;
    else {
        int i;
        for (i = cols[d]; i > 0; i--) rows[d][i] = rows[d][i - 1];
        rows[d][0] = node->val;
        cols[d]++;
    }
    goZig(node->left, d + 1, rows, cols, rc);
    goZig(node->right, d + 1, rows, cols, rc);
}
int** zigzagLevelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    static int rows[64][256];
    static int cols[64];
    static int* ptrs[64];
    int rc = 0, i;
    goZig(root, 0, rows, cols, &rc);
    for (i = 0; i < rc; i++) ptrs[i] = rows[i];
    *returnSize = rc;
    *returnColumnSizes = cols;
    return ptrs;
}
