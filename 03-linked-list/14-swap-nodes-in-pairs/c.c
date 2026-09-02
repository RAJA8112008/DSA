// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect nodes, swap each pair of indexes, relink in that order. Extra array.

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

struct Node* swapPairs(struct Node* head) {
    struct Node* nodes[10005]; int nodesn = 0;
    struct Node* cur = head;
    while (cur) {
        nodes[nodesn++] = cur;
        cur = cur->next;
    }
    for (int i = 0; i + 1 < nodesn; i += 2) {
        int t = nodes[i];
        nodes[i] = nodes[i + 1];
        nodes[i + 1] = t;
    }
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    for (int _i = 0; _i < nodesn; _i++) { struct Node* node = nodes[_i];
        tail->next = node;
        tail = tail->next;
    }
    tail->next = NULL;
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// If fewer than two nodes, return head. Else first = head, second = head.next, first.next = swapPairs(second.next), second.next = first, return second. Stack O(n/2).

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

struct Node* swapPairs(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    struct Node* first = head;
    struct Node* second = head->next;
    first->next = swapPairs(second->next);
    second->next = first;
    return second;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. prev, a, b: prev.next = b, a.next = b.next, b.next = a, then prev = a. Iterative, constant extra space.

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

struct Node* swapPairs(struct Node* head) {
    struct Node* dummy = newNode(0, head);
    struct Node* prev = dummy;
    while (prev->next && prev->next.next) {
        struct Node* a = prev->next;
        struct Node* b = a->next;
        prev->next = b;
        a->next = b->next;
        b->next = a;
        prev = a;
    }
    return dummy->next;
}
