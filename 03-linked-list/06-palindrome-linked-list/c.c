// Method 1: Brute
// Time: O(n) | Space: O(n)
// Dump values into an array. Check index i against length-1-i. Extra memory is the array.

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

bool isPalindrome(struct Node* head) {
    int vals[10005]; int valsn = 0;
    struct Node* cur = head;
    while (cur) {
        vals[valsn++] = cur->val;
        cur = cur->next;
    }
    int i = 0;
    int j = valsn - 1;
    while (i < j) {
        if (vals[i] != vals[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse to the tail. A shared front pointer walks forward as the stack walks back. First mismatch fails. Stack is O(n).

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

bool isPalindrome_go(struct Node* node) {
    if (!node) {
        return;
    }
    isPalindrome_go(node->next);
    if (node->val != box.front->val) {
        box_ok = false;
    }
    box_front = box_front->next;
}

bool isPalindrome(struct Node* head) {
    struct Node* box_front = head;
    bool box_ok = true;
    isPalindrome_go(head);
    return box.ok;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Slow/fast to the mid, reverse the second half, compare first half with reversed half. Only a few pointers. Mutates the list; reverse again if you must restore.

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

bool isPalindrome(struct Node* head) {
    if (!head || !head->next) {
        return true;
    }
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
    }
    struct Node* prev = NULL;
    struct Node* cur = slow;
    while (cur) {
        struct Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    struct Node* a = head;
    struct Node* b = prev;
    while (b) {
        if (a->val != b->val) {
            return false;
        }
        a = a->next;
        b = b->next;
    }
    return true;
}
