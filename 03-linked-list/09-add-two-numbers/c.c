// Method 1: Brute
// Time: O(n+m) | Space: O(n+m)
// Turn each list into a BigInt (least-significant digit first), add, then emit digits into a new list. Easy in JavaScript, hides the carry logic interviewers want.

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

int addTwoNumbers_toBig(struct Node* node) {
    int n = 0;
    int place = 1;
    while (node) {
        n += node->val * place;
        place *= 10;
        node = node->next;
    }
    return n;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    int sum = addTwoNumbers_toBig(l1) + addTwoNumbers_toBig(l2);
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    if (sum == 0) {
        return dummy;
    }
    while (sum > 0) {
        tail->next = newNode(atoi(sum % 10));
        tail = tail->next;
        sum /= 10;
    }
    return dummy->next;
}


// Method 2: Optimal
// Time: O(max(n,m)) | Space: O(max(n,m))
// Recursive add of two nodes plus carry. Next call gets the rest of both lists. Stack depth follows the longer number.

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

struct Node* addTwoNumbers_add(struct Node* a, struct Node* b, int carry) {
    if (!a && !b && carry == 0) {
        return NULL;
    }
    int sum = (a ? a->val : 0) + (b ? b->val : 0) + carry;
    struct Node* node = newNode(sum % 10);
    node->next = addTwoNumbers_add(a ? a->next : NULL, b ? b->next : NULL, (sum / 10));
    return node;
}

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    return addTwoNumbers_add(l1, l2, 0);
}


// Method 3: More optimal
// Time: O(max(n,m)) | Space: O(1)
// Iterative dummy. Each step sums two digits and carry, writes sum % 10, carry becomes floor(sum/10). Extra node if carry remains. Output list is required; extra pointers are constant.

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

struct Node* addTwoNumbers(struct Node* l1, struct Node* l2) {
    struct Node* dummy = newNode(0);
    struct Node* tail = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
        tail->next = newNode(sum % 10);
        tail = tail->next;
        carry = (sum / 10);
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    return dummy->next;
}
