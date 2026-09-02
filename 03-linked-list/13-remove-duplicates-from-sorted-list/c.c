// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk and push a value only when it differs from the last kept one, then rebuild. Extra array of uniques.

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

struct Node* deleteDuplicates(struct Node* head) {
    int vals[10005]; int valsn = 0;
    struct Node* cur = head;
    while (cur) {
        if (valsn == 0 || vals[valsn - 1] != cur->val) {
            vals[valsn++] = cur->val;
        }
        cur = cur->next;
    }
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
// Recurse on head.next first. If the next node has the same val, skip it. Stack is O(n).

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

struct Node* deleteDuplicates(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    head->next = deleteDuplicates(head->next);
    if (head->next && head->next.val == head->val) {
        return head->next;
    }
    return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pointer. While the next node duplicates, skip it. Then advance. In-place, constant extra space.

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

struct Node* deleteDuplicates(struct Node* head) {
    struct Node* cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next.val) {
            cur->next = cur->next.next;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}
