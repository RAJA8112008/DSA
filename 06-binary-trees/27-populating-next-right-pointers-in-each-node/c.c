// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order queue. For each level, node.next = the next polled node, last.next = null.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
    return n;
}

struct Node* connect(struct Node* root) {
    struct Node* q[10005];
    int qs, qe;
    if (!root) return NULL;
    qs = 0; qe = 0;
    q[qe++] = root;
    while (qs < qe) {
        int n = qe - qs, i;
        for (i = 0; i < n; i++) {
            struct Node* node = q[qs++];
            if (i + 1 < n) node->next = q[qs];
            if (node->left) q[qe++] = node->left;
            if (node->right) q[qe++] = node->right;
        }
    }
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// On a perfect tree, left.next = right, and right.next = node.next.left. Recurse both children. Uses the next links already set on this level.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
    return n;
}

struct Node* connect(struct Node* root) {
    if (!root || !root->left) return root;
    root->left->next = root->right;
    if (root->next) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative: leftmost starts at root. Walk the level via next. Wire children, then leftmost = leftmost.left. No recursion, no queue.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    n->next = NULL;
    return n;
}

struct Node* connect(struct Node* root) {
    struct Node* leftmost;
    struct Node* cur;
    if (!root) return NULL;
    leftmost = root;
    while (leftmost->left) {
        cur = leftmost;
        while (cur) {
            cur->left->next = cur->right;
            if (cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}
