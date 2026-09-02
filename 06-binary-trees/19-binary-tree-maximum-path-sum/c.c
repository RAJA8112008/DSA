// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node, maxDown on left and right is computed from scratch, then visit children. Nested tree walks.

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

int maxPathSum_maxDown(struct Node* node) {
    if (!node) {
        return 0;
    }
    return node->val + MAX(0, maxPathSum_maxDown(node->left), maxPathSum_maxDown(node->right));
}

int maxPathSum_visit(struct Node* node) {
    if (!node) {
        return;
    }
    struct Node* left = MAX(0, maxDown(node->left));
    struct Node* right = MAX(0, maxDown(node->right));
    int through = node->val + left + right;
    if (through > best) {
        best = through;
    }
    maxPathSum_visit(node->left);
    maxPathSum_visit(node->right);
}

int maxPathSum(struct Node* root) {
    int best = INT_MIN;
    maxPathSum_visit(root);
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// gain(node) = val + max(0, gain(left), gain(right)) for continuing up. Through-node sum updates a boxed best. One DFS.

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

int maxPathSum_gain(struct Node* node) {
    if (!node) {
        return 0;
    }
    struct Node* left = MAX(0, maxPathSum_gain(node->left));
    struct Node* right = MAX(0, maxPathSum_gain(node->right));
    int through = node->val + left + right;
    if (through > best) {
        best = through;
    }
    return node->val + MAX(left, right);
}

int maxPathSum(struct Node* root) {
    int best = INT_MIN;
    maxPathSum_gain(root);
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Same linear DFS, but dfs returns {gain, best} so there is no outer mutable. Parent combines through, left.best, and right.best. Cleaner to reason about.

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

int maxPathSum_dfs(struct Node* node) {
    if (!node) {
        /* return gain,best */
    }
    struct Node* L = maxPathSum_dfs(node->left);
    struct Node* R = maxPathSum_dfs(node->right);
    struct Node* left = MAX(0, L.gain);
    struct Node* right = MAX(0, R.gain);
    int through = node->val + left + right;
    int gain = node->val + MAX(left, right);
    int best = MAX(through, L.best, R.best);
    /* return gain,best */
}

int maxPathSum(struct Node* root) {
    return maxPathSum_dfs(root).best;
}
