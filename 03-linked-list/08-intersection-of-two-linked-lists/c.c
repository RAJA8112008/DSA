// Method 1: Brute
// Time: O(n·m) | Space: O(1)
// For each node in A, walk all of B looking for the same object. No extra set. Quadratic time.

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

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    struct Node* a = headA;
    while (a) {
        struct Node* b = headB;
        while (b) {
            if (a == b) {
                return a;
            }
            b = b->next;
        }
        a = a->next;
    }
    return NULL;
}


// Method 2: Optimal
// Time: O(n+m) | Space: O(n)
// Put every node of A in a Set. Walk B; the first node in the set is the intersection. Linear time, extra memory for A.

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

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    struct Node* seen[10005]; int seenn = 0;
    struct Node* a = headA;
    while (a) {
        seen[seenn++] = a;
        a = a->next;
    }
    struct Node* b = headB;
    while (b) {
        if (containsPtr(seen, seenn, b)) {
            return b;
        }
        b = b->next;
    }
    return NULL;
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Pointer a walks A then B. Pointer b walks B then A. They travel the same total length and meet at the first shared node, or both hit null. No set.

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

struct Node* getIntersectionNode(struct Node* headA, struct Node* headB) {
    struct Node* a = headA;
    struct Node* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
