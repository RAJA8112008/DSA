// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push odd-position nodes, then even-position nodes, into arrays. Relink in that order. Extra arrays.

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

struct Node* oddEvenList(struct Node* head) {
    struct Node* odds[10005]; int oddsn = 0;
    struct Node* evens[10005]; int evensn = 0;
    struct Node* cur = head;
    int i = 1;
    while (cur) {
        if (i % 2 == 1) {
            odds[oddsn++] = cur;
        }
        else {
            evens[evensn++] = cur;
        }
        cur = cur->next;
        i++;
    }
    int nodes = concat(odds, evens);
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
// Recursive rewire: odd.next = even.next, even.next = that node's next, then recurse. Attach evenHead when even runs out. Stack O(n).

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

struct Node* oddEvenList_go(int odd, int even) {
    if (!even || !even->next) {
        odd->next = evenHead;
        return;
    }
    odd->next = even->next;
    even->next = odd->next.next;
    oddEvenList_go(odd->next, even->next);
}

struct Node* oddEvenList(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    struct Node* evenHead = head->next;
    oddEvenList_go(head, evenHead);
    return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// odd and even pointers. odd.next = odd.next.next, even.next = even.next.next, until even is exhausted. odd.next = evenHead. In-place, constant extra space.

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

struct Node* oddEvenList(struct Node* head) {
    if (!head || !head->next) {
        return head;
    }
    struct Node* odd = head;
    struct Node* even = head->next;
    struct Node* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
