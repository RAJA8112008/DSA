// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk the list into an array, then build from mid indices. Extra O(n) memory for the copy.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newListNode(int val) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

struct Node* buildArr(int* nums, int lo, int hi) {
    if (lo > hi) return NULL;
    int mid = lo + (hi - lo) / 2;
    struct Node* node = newNode(nums[mid]);
    node->left = buildArr(nums, lo, mid - 1);
    node->right = buildArr(nums, mid + 1, hi);
    return node;
}
struct Node* sortedListToBST(struct ListNode* head) {
    int nums[20005], n = 0;
    while (head) { nums[n++] = head->val; head = head->next; }
    return buildArr(nums, 0, n - 1);
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Slow/fast finds the mid. Cut prev.next so the left half is a shorter list. Recurse on left half, mid node, and right half. No array, but each level rescans the list.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newListNode(int val) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

struct Node* sortedListToBST(struct ListNode* head) {
    if (!head) return NULL;
    if (!head->next) return newNode(head->val);
    struct ListNode* prev = NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    struct Node* node = newNode(slow->val);
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return node;
}


// Method 3: More optimal
// Time: O(n) | Space: O(log n)
// Count n. Inorder-build: recurse left of size n/2, consume the current list node as the root, then recurse right. The list pointer only moves forward. Each node is visited once.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = NULL;
    n->right = NULL;
    return n;
}

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* newListNode(int val) {
    struct ListNode* n = (struct ListNode*)malloc(sizeof(struct ListNode));
    n->val = val;
    n->next = NULL;
    return n;
}

struct Node* buildInorder(struct ListNode** cur, int count) {
    if (count <= 0) return NULL;
    struct Node* left = buildInorder(cur, (count - 1) / 2);
    struct Node* node = newNode((*cur)->val);
    *cur = (*cur)->next;
    node->left = left;
    node->right = buildInorder(cur, count / 2);
    return node;
}
struct Node* sortedListToBST(struct ListNode* head) {
    int n = 0;
    for (struct ListNode* p = head; p; p = p->next) n++;
    return buildInorder(&head, n);
}
