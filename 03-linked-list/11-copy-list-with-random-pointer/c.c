// Method 1: Brute
// Time: O(n) | Space: O(n)
// First pass: clone every node into a Map, next and random left null. Second pass: wire next and random through the map. Two walks, extra map of n nodes.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    n->random = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* copyRandomList(struct Node* head) {
    struct Node* mapK[10005]; struct Node* mapV[10005]; int mapn = 0;
    struct Node* cur = head;
    while (cur) {
        mapK[mapn] = cur; mapV[mapn++] = newNode(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        struct Node* copy = map[cur];
        copy->next = cur->next ? map[cur->next] : NULL;
        copy->random = cur->random ? map[cur->random] : NULL;
        cur = cur->next;
    }
    return head ? map[head] : NULL;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One recursive walk with a Map. If the node is already cloned, return it (handles random cycles). Otherwise clone, then fill next and random. Still O(n) extra map plus stack.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    n->random = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* copyRandomList_copy(struct Node* node) {
    if (!node) {
        return NULL;
    }
    if (containsPtr(map, mapn, node)) {
        return map[node];
    }
    struct Node* cloned = newNode(node->val);
    mapK[mapn] = node; mapV[mapn++] = cloned;
    cloned->next = copyRandomList_copy(node->next);
    cloned->random = copyRandomList_copy(node->random);
    return cloned;
}

struct Node* copyRandomList(struct Node* head) {
    struct Node* mapK[10005]; struct Node* mapV[10005]; int mapn = 0;
    return copyRandomList_copy(head);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Weave: original -> copy -> original.next. Set copy.random from original.random.next. Unweave into two lists. Extra space is the copies themselves, no hash map. (O(1) auxiliary.)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->next = NULL;
    n->random = NULL;
    return n;
}

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

int containsPtr(struct Node** a, int n, struct Node* x) {
    for (int i = 0; i < n; i++) if (a[i] == x) return 1;
    return 0;
}

struct Node* copyRandomList(struct Node* head) {
    if (!head) {
        return NULL;
    }
    struct Node* cur = head;
    while (cur) {
        struct Node* copy = newNode(cur->val, cur->next, NULL);
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while (cur) {
        if (cur->random) {
            cur->next.random = cur->random.next;
        }
        cur = cur->next.next;
    }
    struct Node* newHead = head->next;
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        cur->next = copy->next;
        copy->next = copy->next ? copy->next.next : NULL;
        cur = cur->next;
    }
    return newHead;
}
