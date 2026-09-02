// Method 1: Brute
// Time: O(n) | Space: O(n)
// Store every node in an array. Remove index length-n, then relink the remaining nodes in order. Extra array of pointers.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<ListNode*> nodes;
    ListNode* cur = head;
    while (cur) {
        nodes.push_back(cur);
        cur = cur->next;
    }
    nodes.splice(nodes.size() - n, 1);
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
// Recursive walk to the end, counting on the way back. When the counter hits n, skip that node from the parent. Stack is O(n).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd_go(ListNode* node) {
    if (!node) {
        return 0;
    }
    ListNode* fromEnd = removeNthFromEnd_go(node->next) + 1;
    if (fromEnd == n + 1) {
        node->next = node->next.next;
    }
    return fromEnd;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    removeNthFromEnd_go(dummy);
    return dummy->next;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Dummy head. Fast walks n+1 steps so the gap is n nodes. Then slow and fast move together. When fast is null, slow sits before the victim. Unlink and return dummy.next. One pass, constant extra space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy;
    ListNode* slow = dummy;
    for (int i = 0; i < n + 1; i++) {
        fast = fast->next;
    }
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next.next;
    return dummy->next;
}
