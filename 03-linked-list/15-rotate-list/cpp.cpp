// Method 1: Brute
// Time: O(n) | Space: O(n)
// Copy values, rotate the array with splice/concat or new indexes, rebuild. Extra array.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head) {
        return head;
    }
    vector<int> vals;
    ListNode* p = head;
    for (; p; p = p->next) {
        vals.push_back(p->val);
    }
    k = k % vals.size();
    int rotated = vector<int>(vals.begin()+vals.size() - k).concat(vector<int>(vals.begin()+0, vals.begin(, vals.end())+vals.size() - k));
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    for (auto v : rotated) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy->next;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recursive helper finds length and the tail, then a second walk cuts at n-k. Stack for the first walk is O(n). Same idea as counting, with recursion instead of a loop for length.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int rotateRight_count(ListNode* node) {
    if (!node) {
        return;
    }
    box_n++;
    box_tail = node;
    rotateRight_count(node->next);
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
        return head;
    }
    int box_n = 0;
    ListNode* box_tail = nullptr;
    rotateRight_count(head);
    k = k % box_n;
    if (k == 0) {
        return head;
    }
    int steps = box.n - k;
    ListNode* cur = head;
    for (int i = 1; i < steps; i++) {
        cur = cur->next;
    }
    ListNode* newHead = cur->next;
    cur->next = nullptr;
    box_tail->next = head;
    return newHead;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Find tail and n in one walk, close the ring, walk n - k % n steps from head, cut. Constant extra space, one extra pass after the count.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
        return head;
    }
    int n = 1;
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
        n++;
    }
    k = k % n;
    if (k == 0) {
        return head;
    }
    tail->next = head;
    int steps = n - k;
    ListNode* newTail = head;
    for (int i = 1; i < steps; i++) {
        newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;
    newTail->next = nullptr;
    return newHead;
}
