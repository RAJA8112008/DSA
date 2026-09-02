// Method 1: Brute
// Time: O((n+m) log(n+m)) | Space: O(n+m)
// Collect every value, sort the array, rebuild. Simple, but sort is extra work and you throw away the original nodes.

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

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
    int vals[10005]; int valsn = 0;
    struct Node* p = list1;
    for (; p; p = p->next) {
        vals[valsn++] = p->val;
    }
    struct Node* p = list2;
    for (; p; p = p->next) {
        vals[valsn++] = p->val;
    }
    qsort(vals, valsn, sizeof(int), cmpInt);
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    for (int _i = 0; _i < valsn; _i++) { int v = vals[_i];
        tail->next = newNode(v);
        tail = tail->next;
    }
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n+m) | Space: O(n+m)
// Recurse: the smaller head is the next output node, then merge the rest. Linear comparisons. Stack depth is O(n+m).

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

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Dummy plus a tail pointer. Each step hangs the smaller remaining node. Leftover chain attaches at the end. Constant extra space besides the output, which reuses input nodes.

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

struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        }
        else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    tail->next = list1 || list2;
    return dummy->next;
}
