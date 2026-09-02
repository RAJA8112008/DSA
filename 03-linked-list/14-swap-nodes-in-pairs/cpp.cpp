// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect nodes, swap each pair of indexes, relink in that order. Extra array.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    vector<ListNode*> nodes;
    ListNode* cur = head;
    while (cur) {
        nodes.push_back(cur);
        cur = cur->next;
    }
    for (int i = 0; i + 1 < nodes.size(); i += 2) {
        int t = nodes[i];
        nodes[i] = nodes[i + 1];
        nodes[i + 1] = t;
    }
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (auto node : nodes) {
        tail->next = node;
        tail = tail->next;
    }
    tail->next = nullptr;
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// If fewer than two nodes, return head. Else first = head, second = head.next, first.next = swapPairs(second.next), second.next = first, return second. Stack O(n/2).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* first = head;
    ListNode* second = head->next;
    first->next = swapPairs(second->next);
    second->next = first;
    return second;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. prev, a, b: prev.next = b, a.next = b.next, b.next = a, then prev = a. Iterative, constant extra space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;
    while (prev->next && prev->next.next) {
        ListNode* a = prev->next;
        ListNode* b = a->next;
        prev->next = b;
        a->next = b->next;
        b->next = a;
        prev = a;
    }
    return dummy->next;
}
