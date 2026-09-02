// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, reverse each complete window of k in the array, rebuild a new list. Extra array and new nodes.

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

struct Node* reverseKGroup(struct Node* head, int k) {
    int vals[10005]; int valsn = 0;
    struct Node* p = head;
    for (; p; p = p->next) {
        vals[valsn++] = p->val;
    }
    for (int i = 0; i + k <= valsn; i += k) {
        int l = i;
        int r = i + k - 1;
        while (l < r) {
            int t = vals[l];
            vals[l] = vals[r];
            vals[r] = t;
            l++;
            r--;
        }
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
// Time: O(n) | Space: O(n/k)
// If fewer than k nodes remain, return head. Else reverse the first k, then set the old head's next to reverseKGroup of the leftover. Recursion depth is number of groups.

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

struct Node* reverseKGroup(struct Node* head, int k) {
    int n = 0;
    struct Node* p = head;
    while (p && n < k) {
        p = p->next;
        n++;
    }
    if (n < k) {
        return head;
    }
    struct Node* prev = NULL;
    struct Node* cur = head;
    for (int i = 0; i < k; i++) {
        struct Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = reverseKGroup(cur, k);
    return prev;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. For each group, reverse k nodes between groupPrev and groupNext, then slide groupPrev. No recursion. Constant extra pointers.

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

struct Node* reverseKGroup_kth(struct Node* start, int k) {
    struct Node* n = start;
    for (int i = 0; i < k; i++) {
        if (!n) {
            return NULL;
        }
        n = n->next;
    }
    return n;
}

struct Node* reverseKGroup(struct Node* head, int k) {
    struct Node* dummy = newNode(0, head);
    struct Node* groupPrev = dummy;
    while (true) {
        struct Node* groupLast = reverseKGroup_kth(groupPrev, k);
        if (!groupLast) {
            break;
        }
        struct Node* groupNext = groupLast->next;
        struct Node* prev = groupNext;
        struct Node* cur = groupPrev->next;
        while (cur != groupNext) {
            struct Node* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        struct Node* newGroupStart = groupPrev->next;
        groupPrev->next = groupLast;
        groupPrev = newGroupStart;
    }
    return dummy->next;
}
