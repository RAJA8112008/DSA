// Method 1: Brute
// Time: O(n) | Space: O(n)
// Push odd-position nodes, then even-position nodes, into arrays. Relink in that order. Extra arrays.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    vector<ListNode*> odds;
    vector<ListNode*> evens;
    ListNode* cur = head;
    int i = 1;
    while (cur) {
        if (i % 2 == 1) {
            odds.push_back(cur);
        }
        else {
            evens.push_back(cur);
        }
        cur = cur->next;
        i++;
    }
    int nodes = concat(odds, evens);
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
// Recursive rewire: odd.next = even.next, even.next = that node's next, then recurse. Attach evenHead when even runs out. Stack O(n).

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList_go(int odd, int even) {
    if (!even || !even->next) {
        odd->next = evenHead;
        return;
    }
    odd->next = even->next;
    even->next = odd->next.next;
    oddEvenList_go(odd->next, even->next);
}

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* evenHead = head->next;
    oddEvenList_go(head, evenHead);
    return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// odd and even pointers. odd.next = odd.next.next, even.next = even.next.next, until even is exhausted. odd.next = evenHead. In-place, constant extra space.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }
    ListNode* odd = head;
    ListNode* even = head->next;
    ListNode* evenHead = even;
    while (even && even->next) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}
