// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, rotate the array with splice/concat or new indexes, rebuild. Extra array.

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

struct Node* rotateRight(struct Node* head, int k) {
    if (!head) {
        return head;
    }
    int vals[10005]; int valsn = 0;
    struct Node* p = head;
    for (; p; p = p->next) {
        vals[valsn++] = p->val;
    }
    k = k % valsn;
    int rotated = vals);
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    for (int _i = 0; _i < rotatedn; _i++) { struct Node* v = rotated[_i];
        tail->next = newNode(v);
        tail = tail->next;
    }
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive helper finds length and the tail, then a second walk cuts at n-k. Stack for the first walk is O(n). Same idea as counting, with recursion instead of a loop for length.

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

int rotateRight_count(struct Node* node) {
    if (!node) {
        return;
    }
    box_n++;
    box_tail = node;
    rotateRight_count(node->next);
}

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next) {
        return head;
    }
    int box_n = 0;
    struct Node* box_tail = NULL;
    rotateRight_count(head);
    k = k % box_n;
    if (k == 0) {
        return head;
    }
    int steps = box.n - k;
    struct Node* cur = head;
    for (int i = 1; i < steps; i++) {
        cur = cur->next;
    }
    struct Node* newHead = cur->next;
    cur->next = NULL;
    box_tail->next = head;
    return newHead;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Find tail and n in one walk, close the ring, walk n - k % n steps from head, cut. Constant extra space, one extra pass after the count.

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

struct Node* rotateRight(struct Node* head, int k) {
    if (!head || !head->next) {
        return head;
    }
    int n = 1;
    struct Node* tail = head;
    while (tail->next) {
        tail = tail->next;
        n++;
    }
    k = k % n;
    if (k == 0) {
        return head;
    }
    tail->next = head;
    int steps = n - k;
    struct Node* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    struct Node* newHead = newTail->next;
    newTail->next = NULL;
    return newHead;
}
