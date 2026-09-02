// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS preorder into an array (node, child, next). Then walk the array and set next/prev, clear child. Extra array of every node.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
    struct Node* child;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->prev = NULL;
    n->next = NULL;
    n->child = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* flatten_dfs(struct Node* node) {
    while (node) {
        nodes[nodesn++] = node;
        if (node->child) {
            flatten_dfs(node->child);
        }
        node = node->next;
    }
}

struct Node* flatten(struct Node* head) {
    struct Node* nodes[10005]; int nodesn = 0;
    flatten_dfs(head);
    for (int i = 0; i < nodesn; i++) {
        nodes[i].prev = i == 0 ? NULL : nodes[i - 1];
        nodes[i].next = i == nodesn - 1 ? NULL : nodes[i + 1];
        nodes[i].child = NULL;
    }
    return nodes[0] || NULL;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse: if a node has a child, flatten the child, hang it after the node, find the child's tail, attach the old next. Stack depth follows nesting.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
    struct Node* child;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->prev = NULL;
    n->next = NULL;
    n->child = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* flatten_go(struct Node* node) {
    struct Node* cur = node;
    struct Node* last = node;
    while (cur) {
        struct Node* next = cur->next;
        if (cur->child) {
            struct Node* childLast = flatten_go(cur->child);
            cur->next = cur->child;
            cur->child.prev = cur;
            cur->child = NULL;
            if (childLast) {
                childLast->next = next;
                if (next) {
                    next->prev = childLast;
                }
                last = childLast;
            }
        }
        else {
            last = cur;
        }
        cur = next;
    }
    return last;
}

struct Node* flatten(struct Node* head) {
    flatten_go(head);
    return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Walk with one pointer. On a child, find that child's current tail (no recurse), splice the whole child between cur and cur.next, clear child. Then continue. Auxiliary space O(1).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* prev;
    struct Node* next;
    struct Node* child;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->prev = NULL;
    n->next = NULL;
    n->child = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* flatten(struct Node* head) {
    struct Node* cur = head;
    while (cur) {
        if (cur->child) {
            struct Node* tail = cur->child;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = cur->next;
            if (cur->next) {
                cur->next.prev = tail;
            }
            cur->next = cur->child;
            cur->child.prev = cur;
            cur->child = NULL;
        }
        cur = cur->next;
    }
    return head;
}
