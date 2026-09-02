// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Keep an array of visited nodes. For each new node, scan the array for the same object. Correct, but the scan makes it quadratic.

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

bool hasCycle(struct Node* head) {
    struct Node* seen[10005]; int seenn = 0;
    struct Node* cur = head;
    while (cur) {
        for (int i = 0; i < seenn; i++) {
            if (seen[i] == cur) {
                return true;
            }
        }
        seen[seenn++] = cur;
        cur = cur->next;
    }
    return false;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A Set stores nodes you already walked. Add is O(1) on average. First repeat means a cycle. Extra memory equals the number of distinct nodes before a repeat.

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

bool hasCycle(struct Node* head) {
    struct Node* seen[10005]; int seenn = 0;
    struct Node* cur = head;
    while (cur) {
        if (containsPtr(seen, seenn, cur)) {
            return true;
        }
        seen[seenn++] = cur;
        cur = cur->next;
    }
    return false;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Floyd: slow +1, fast +2. No set. If they meet, there is a cycle. If fast hits null, there is not. Constant extra pointers.

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

bool hasCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
