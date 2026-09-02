// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk from head. The first node already in the Set is the start of the cycle. If you reach null, there is no cycle.

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

struct Node* detectCycle(struct Node* head) {
    struct Node* seen[10005]; int seenn = 0;
    struct Node* cur = head;
    while (cur) {
        if (containsPtr(seen, seenn, cur)) {
            return cur;
        }
        seen[seenn++] = cur;
        cur = cur->next;
    }
    return NULL;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Floyd finds a node inside the cycle. Walk that loop once into a Set. Then walk from head until you hit a node in the set. Extra memory is the cycle length.

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

struct Node* detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    struct Node* meet = NULL;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
        if (slow == fast) {
            meet = slow;
            break;
        }
    }
    if (!meet) {
        return NULL;
    }
    struct Node* inCycle[10005]; int inCyclen = 0;
    struct Node* p = meet;
    do {
        inCycle[inCyclen++] = p;
        p = p->next;
    } while (p != meet);
    struct Node* q = head;
    while (!containsPtr(inCycle, inCyclen, q)) {
        q = q->next;
    }
    return q;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// After slow and fast meet, put one pointer at head. Walk both one step at a time. They meet at the cycle start. Proof: distance from head to start equals distance from meet to start around the loop. No extra set.

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

struct Node* detectCycle(struct Node* head) {
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
        if (slow == fast) {
            struct Node* p = head;
            while (p != slow) {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}
