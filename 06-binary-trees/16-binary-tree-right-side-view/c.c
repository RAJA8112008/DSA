// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order into rows, then map each row to its last value. Extra storage for every node value.

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

int* rightSideView(struct Node* root) {
    if (!root) {
        return NULL; /* empty */
    }
    int levels[512][512]; int levelsn = 0; int levelssz[512];
    struct Node* queue[10005]; int queueh = 0, queuet = 0; queue[queuet++] = root;
    while (queuen) {
        int n = queuen;
        int row[10005]; int rown = 0;
        for (int i = 0; i < n; i++) {
            struct Node* node = queue[queueh++];
            row[rown++] = node->val;
            if (node->left) {
                queue[queuet++] = node->left;
            }
            if (node->right) {
                queue[queuet++] = node->right;
            }
        }
        levels[levelsn++] = row;
    }
    return /* last of each row */;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS visit right child first. If depth === ans.length, this is the first node seen at that depth from the right. Recursion O(h).

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

int* rightSideView_dfs(struct Node* node, int d) {
    if (!node) {
        return;
    }
    if (d == ansn) {
        ans[ansn++] = node->val;
    }
    rightSideView_dfs(node->right, d + 1);
    rightSideView_dfs(node->left, d + 1);
}

int* rightSideView(struct Node* root) {
    int ans[10005]; int ansn = 0;
    rightSideView_dfs(root, 0);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(w)
// BFS. For each level of size n, the last shifted node is the right-side value. Only the answer plus the queue, no full row arrays.

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

int* rightSideView(struct Node* root) {
    if (!root) {
        return NULL; /* empty */
    }
    int ans[10005]; int ansn = 0;
    struct Node* queue[10005]; int queueh = 0, queuet = 0; queue[queuet++] = root;
    while (queuen) {
        int n = queuen;
        for (int i = 0; i < n; i++) {
            struct Node* node = queue[queueh++];
            if (i == n - 1) {
                ans[ansn++] = node->val;
            }
            if (node->left) {
                queue[queuet++] = node->left;
            }
            if (node->right) {
                queue[queuet++] = node->right;
            }
        }
    }
    return ans;
}
