// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Push values, sort the array, write them back onto the existing nodes. Extra array. Does not show list merge sort.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head) {
    vector<int> vals;
    ListNode* cur = head;
    while (cur) {
        vals.push_back(cur->val);
        cur = cur->next;
    }
    sort(vals.begin(), vals.end());
    cur = head;
    int i = 0;
    while (cur) {
        cur->val = vals[i++];
        cur = cur->next;
    }
    return head;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Top-down merge sort. Slow/fast splits the list, recurse both halves, merge sorted chains. Stack is O(log n) for balanced splits.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
    }
    ListNode* mid = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(mid));
}

ListNode* merge(ListNode* a, ListNode* b) {
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        }
        else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a || b;
    return dummy->next;
}


// Method 3: More optimal
// Time: O(n log n) | Space: O(1)
// Bottom-up merge sort. Count n, then merge adjacent runs of size step, doubling step. split cuts a run. merge hangs the merged pair after prev. No recursion stack.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* sortList_split(ListNode* start, int len) {
    ListNode* p = start;
    for (int i = 1; p && i < len; i++) {
        p = p->next;
    }
    if (!p) {
        return nullptr;
    }
    ListNode* rest = p->next;
    p->next = nullptr;
    return rest;
}

ListNode* sortList_merge(ListNode* prev, ListNode* a, ListNode* b) {
    ListNode* tail = prev;
    while (a && b) {
        if (a->val < b->val) {
            tail->next = a;
            a = a->next;
        }
        else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    tail->next = a || b;
    while (tail->next) {
        tail = tail->next;
    }
    return tail;
}

ListNode* sortList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    int n = 0;
    ListNode* p = head;
    for (; p; p = p->next) {
        n++;
    }
    ListNode* dummy = new ListNode(0, head);
    for (int step = 1; step < n; step *= 2) {
        ListNode* prev = dummy;
        ListNode* cur = dummy->next;
        while (cur) {
            ListNode* left = cur;
            ListNode* right = sortList_split(left, step);
            cur = sortList_split(right, step);
            prev = sortList_merge(prev, left, right);
        }
    }
    return dummy->next;
}
