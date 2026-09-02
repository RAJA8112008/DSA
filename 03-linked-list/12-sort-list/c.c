// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Push values, sort the array, write them back onto the existing nodes. Extra array. Does not show list merge sort.

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

struct Node* sortList(struct Node* head) {
    int vals[10005]; int valsn = 0;
    struct Node* cur = head;
    while (cur) {
        vals[valsn++] = cur->val;
        cur = cur->next;
    }
    qsort(vals, valsn, sizeof(int), cmpInt);
    cur = head;
    int i = 0;
    while (cur) {
        cur->val = vals[i++];
        cur = cur->next;
    }
    return head;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Top-down merge sort. Slow/fast splits the list, recurse both halves, merge sorted chains. Stack is O(log n) for balanced splits.

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

struct Node* sortList(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
    }
    struct Node* mid = slow->next;
    slow->next = NULL;
    return merge(sortList(head), sortList(mid));
}

struct Node* merge(struct Node* a, struct Node* b) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        }
        else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a || b;
    return dummy->next;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(1)
// Bottom-up merge sort. Count n, then merge adjacent runs of size step, doubling step. split cuts a run. merge hangs the merged pair after prev. No recursion stack.

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

struct Node* sortList_split(struct Node* start, int len) {
    struct Node* p = start;
    for (int i = 1; p && i < len; i++) {
        p = p->next;
    }
    if (!p) {
        return NULL;
    }
    struct Node* rest = p->next;
    p->next = NULL;
    return rest;
}

struct Node* sortList_merge(struct Node* prev, struct Node* a, struct Node* b) {
    struct Node* tail = prev;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        }
        else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a || b;
    while (tail->next) {
        tail = tail->next;
    }
    return tail;
}

struct Node* sortList(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    int n = 0;
    struct Node* p = head;
    for (; p; p = p->next) {
        n++;
    }
    struct Node* dummy = newNode(0, head);
    for (int step = 1; step < n; step *= 2) {
        struct Node* prev = dummy;
        struct Node* cur = dummy->next;
        while (cur) {
            struct Node* left = cur;
            struct Node* right = sortList_split(left, step);
            cur = sortList_split(right, step);
            prev = sortList_merge(prev, left, right);
        }
    }
    return dummy->next;
}
