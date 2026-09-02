// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, reverse each complete window of k in the array, rebuild a new list. Extra array and new nodes.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    vector<int> vals;
    ListNode* p = head;
    for (; p; p = p->next) {
        vals.push_back(p->val);
    }
    for (int i = 0; i + k <= vals.size(); i += k) {
        int l = i;
        int r = i + k - 1;
        while (l < r) {
            int t = vals[l];
            vals[l] = vals[r];
            vals[r] = t;
            l++;
            r--;
        }
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
// Time: O(n) | Space: O(n/k)
// If fewer than k nodes remain, return head. Else reverse the first k, then set the old head's next to reverseKGroup of the leftover. Recursion depth is number of groups.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    int n = 0;
    ListNode* p = head;
    while (p && n < k) {
        p = p->next;
        n++;
    }
    if (n < k) {
        return head;
    }
    ListNode* prev = nullptr;
    ListNode* cur = head;
    for (int i = 0; i < k; i++) {
        ListNode* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    head->next = reverseKGroup(cur, k);
    return prev;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy before head. For each group, reverse k nodes between groupPrev and groupNext, then slide groupPrev. No recursion. Constant extra pointers.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseKGroup_kth(ListNode* start, int k) {
    ListNode* n = start;
    for (int i = 0; i < k; i++) {
        if (!n) {
            return nullptr;
        }
        n = n->next;
    }
    return n;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* groupPrev = dummy;
    while (true) {
        ListNode* groupLast = reverseKGroup_kth(groupPrev, k);
        if (!groupLast) {
            break;
        }
        ListNode* groupNext = groupLast->next;
        ListNode* prev = groupNext;
        ListNode* cur = groupPrev->next;
        while (cur != groupNext) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        ListNode* newGroupStart = groupPrev->next;
        groupPrev->next = groupLast;
        groupPrev = newGroupStart;
    }
    return dummy->next;
}
