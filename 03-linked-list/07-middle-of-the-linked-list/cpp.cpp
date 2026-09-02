// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push every node into an array, then return the node at floor(length/2). Extra array of pointers.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    vector<ListNode*> nodes;
    ListNode* cur = head;
    while (cur) {
        nodes.push_back(cur);
        cur = cur->next;
    }
    return nodes[(nodes.size() / 2]];
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive slow/fast: if fast cannot take two steps, slow is the middle. Stack depth is O(n).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode_walk(int slow, int fast) {
    if (!fast || !fast->next) {
        return slow;
    }
    return middleNode_walk(slow->next, fast->next.next);
}

ListNode* middleNode(ListNode* head) {
    return middleNode_walk(head, head);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative tortoise and hare. When fast falls off, slow is the second middle on even length. Constant extra space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
    }
    return slow;
}
