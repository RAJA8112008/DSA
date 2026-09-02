// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push every node into an array, then return the node at floor(length/2). Extra array of pointers.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* middleNode(struct Node* head) {
    struct Node* nodes[10005]; int nodesn = 0;
    struct Node* cur = head;
    while (cur) {
        nodes[nodesn++] = cur;
        cur = cur->next;
    }
    return nodes[(nodesn / 2]];
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive slow/fast: if fast cannot take two steps, slow is the middle. Stack depth is O(n).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* middleNode_walk(int slow, int fast) {
    if (!fast || !fast->next) {
        return slow;
    }
    return middleNode_walk(slow->next, fast->next.next);
}

struct Node* middleNode(struct Node* head) {
    return middleNode_walk(head, head);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative tortoise and hare. When fast falls off, slow is the second middle on even length. Constant extra space.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* middleNode(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
    }
    return slow;
}
