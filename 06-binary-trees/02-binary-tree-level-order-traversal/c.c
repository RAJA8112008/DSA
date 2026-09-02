// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS with a depth argument. Push val into levels[depth], creating the row if needed. Extra recursion stack plus the answer.

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

int** levelOrder_dfs(struct Node* node, int d) {
    if (!node) {
        return;
    }
    if (!levels[d]) {
        levels[d] = [];
    }
    levels[d].push(node->val);
    levelOrder_dfs(node->left, d + 1);
    levelOrder_dfs(node->right, d + 1);
}

int** levelOrder(struct Node* root) {
    int levels[512][512]; int levelsn = 0; int levelssz[512];
    levelOrder_dfs(root, 0);
    return levels;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS queue. Each node is stored with its depth. Rows grow as depth increases. Extra pair objects on the queue.

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

int** levelOrder(struct Node* root) {
    if (!root) {
        return NULL; /* empty */
    }
    int levels[512][512]; int levelsn = 0; int levelssz[512];
    struct Node* queueN[10005]; int queueD[10005]; int queuen = 0;
    while (queuen) {
        /* unpack node,d */
        if (!levels[d]) {
            levels[d] = [];
        }
        levels[d].push(node->val);
        if (node->left) {
            queue[queuet++] = { node: node->left, d: d + 1 };
        }
        if (node->right) {
            queue[queuet++] = { node: node->right, d: d + 1 };
        }
    }
    return levels;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS without storing depth. n = queue.length is the current row size. Process exactly those n nodes, enqueue children for the next row. Cleaner constant factors; still O(width) queue.

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

int** levelOrder(struct Node* root) {
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
    return levels;
}
