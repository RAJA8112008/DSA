// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy every value into an array, reverse the array, then build a brand new list. Easy to see, but it allocates n extra nodes and ignores that you can flip next in place.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    vector<int> vals;
    ListNode* cur = head;
    while (cur) {
        vals.push_back(cur->val);
        cur = cur->next;
    }
    reverse(vals.begin(), vals.end());
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (auto v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse to the end, then set head.next.next = head and cut head.next. The call stack holds every node, so space is O(n). Clear picture of 'suffix first'.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    head->next.next = head;
    head->next = nullptr;
    return newHead;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative three-pointer reverse. Each node is visited once. Extra memory is a few names, not the stack and not a new list. This is the usual interview target.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}
