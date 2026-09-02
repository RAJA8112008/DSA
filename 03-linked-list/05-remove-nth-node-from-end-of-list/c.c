// Method 1: Brute
// Time: O(n) | Space: O(n)
// Store every node in an array. Remove index length-n, then relink the remaining nodes in order. Extra array of pointers.

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

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node* nodes[10005]; int nodesn = 0;
    struct Node* cur = head;
    while (cur) {
        nodes[nodesn++] = cur;
        cur = cur->next;
    }
    nodes.splice(nodesn - n, 1);
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
// Recursive walk to the end, counting on the way back. When the counter hits n, skip that node from the parent. Stack is O(n).

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

struct Node* removeNthFromEnd_go(struct Node* node) {
    if (!node) {
        return 0;
    }
    struct Node* fromEnd = removeNthFromEnd_go(node->next) + 1;
    if (fromEnd == n + 1) {
        node->next = node->next.next;
    }
    return fromEnd;
}

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node* dummy = newNode(0, head);
    removeNthFromEnd_go(dummy);
    return dummy->next;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy head. Fast walks n+1 steps so the gap is n nodes. Then slow and fast move together. When fast is null, slow sits before the victim. Unlink and return dummy.next. One pass, constant extra space.

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

struct Node* removeNthFromEnd(struct Node* head, int n) {
    struct Node* dummy = newNode(0, head);
    struct Node* fast = dummy;
    struct Node* slow = dummy;
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next.next;
    return dummy->next;
}
