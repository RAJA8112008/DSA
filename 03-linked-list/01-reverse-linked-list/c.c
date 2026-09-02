// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy every value into an array, reverse the array, then build a brand new list. Easy to see, but it allocates n extra nodes and ignores that you can flip next in place.

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

struct Node* reverseList(struct Node* head) {
    int vals[10005]; int valsn = 0;
    struct Node* cur = head;
    while (cur) {
        vals[valsn++] = cur->val;
        cur = cur->next;
    }
    /* reverse */;
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    for (int _i = 0; _i < valsn; _i++) { int v = vals[_i];
        tail->next = newNode(v);
        tail = tail->next;
    }
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse to the end, then set head.next.next = head and cut head.next. The call stack holds every node, so space is O(n). Clear picture of 'suffix first'.

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

struct Node* reverseList(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    struct Node* newHead = reverseList(head->next);
    head->next.next = head;
    head->next = NULL;
    return newHead;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative three-pointer reverse. Each node is visited once. Extra memory is a few names, not the stack and not a new list. This is the usual interview target.

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

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* cur = head;
    while (cur) {
        struct Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
