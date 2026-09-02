// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk and push a value only when it differs from the last kept one, then rebuild. Extra array of uniques.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    vector<int> vals;
    ListNode* cur = head;
    while (cur) {
        if (vals.size() == 0 || vals.back() != cur->val) {
            vals.push_back(cur->val);
        }
        cur = cur->next;
    }
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
// Recurse on head.next first. If the next node has the same val, skip it. Stack is O(n).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    head->next = deleteDuplicates(head->next);
    if (head->next && head->next.val == head->val) {
        return head->next;
    }
    return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pointer. While the next node duplicates, skip it. Then advance. In-place, constant extra space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* cur = head;
    while (cur && cur->next) {
        if (cur->val == cur->next.val) {
            cur->next = cur->next.next;
        }
        else {
            cur = cur->next;
        }
    }
    return head;
}
