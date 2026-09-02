// Method 1: Brute
// Time: O(n) | Space: O(w)
// BFS. Width of a level is the queue size (actual nodes). Max over levels. Matches GFG's non-null count.

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

int widthOfBinaryTree(struct Node* root) {
    struct Node* q[10005];
    int qs, qe, best = 0;
    if (!root) return 0;
    qs = 0; qe = 0;
    q[qe++] = root;
    while (qs < qe) {
        int n = qe - qs, i;
        if (n > best) best = n;
        for (i = 0; i < n; i++) {
            struct Node* node = q[qs++];
            if (node->left) q[qe++] = node->left;
            if (node->right) q[qe++] = node->right;
        }
    }
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// LeetCode width: BFS with heap indices. Subtract the first index of the level so numbers stay small. Width = last - first + 1.

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

int widthOfBinaryTree(struct Node* root) {
    struct Node* qn[10005];
    unsigned long long qi[10005];
    int qs, qe, best = 0, i, n;
    unsigned long long first, last, idx;
    if (!root) return 0;
    qs = 0; qe = 0;
    qn[qe] = root; qi[qe++] = 0;
    while (qs < qe) {
        n = qe - qs;
        first = qi[qs];
        last = first;
        for (i = 0; i < n; i++) {
            struct Node* node = qn[qs];
            idx = qi[qs++] - first;
            last = idx;
            if (node->left) { qn[qe] = node->left; qi[qe++] = idx * 2 + 1; }
            if (node->right) { qn[qe] = node->right; qi[qe++] = idx * 2 + 2; }
        }
        if ((int)last + 1 > best) best = (int)last + 1;
    }
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with (depth, normalized index). Store the first index seen at each depth. Width = idx - first[depth] + 1. Recursion only.

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

void goW(struct Node* node, int d, unsigned long long idx, unsigned long long* first, int* seen, int* best) {
    unsigned long long pos;
    if (!node) return;
    if (!seen[d]) { seen[d] = 1; first[d] = idx; }
    pos = idx - first[d];
    if ((int)pos + 1 > *best) *best = (int)pos + 1;
    goW(node->left, d + 1, pos * 2 + 1, first, seen, best);
    goW(node->right, d + 1, pos * 2 + 2, first, seen, best);
}
int widthOfBinaryTree(struct Node* root) {
    unsigned long long first[64];
    int seen[64] = {0};
    int best = 0;
    goW(root, 0, 0, first, seen, &best);
    return best;
}
