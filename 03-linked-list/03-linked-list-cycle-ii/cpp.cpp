// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk from head. The first node already in the Set is the start of the cycle. If you reach null, there is no cycle.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {
    unordered_set<ListNode*> seen;
    ListNode* cur = head;
    while (cur) {
        if (seen.count(cur)) {
            return cur;
        }
        seen.insert(cur);
        cur = cur->next;
    }
    return nullptr;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Floyd finds a node inside the cycle. Walk that loop once into a Set. Then walk from head until you hit a node in the set. Extra memory is the cycle length.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* meet = nullptr;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
        if (slow == fast) {
            meet = slow;
            break;
        }
    }
    if (!meet) {
        return nullptr;
    }
    unordered_set<ListNode*> inCycle;
    ListNode* p = meet;
    do {
        inCycle.insert(p);
        p = p->next;
    } while (p != meet);
    ListNode* q = head;
    while (!inCycle.count(q)) {
        q = q->next;
    }
    return q;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// After slow and fast meet, put one pointer at head. Walk both one step at a time. They meet at the cycle start. Proof: distance from head to start equals distance from meet to start around the loop. No extra set.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
        if (slow == fast) {
            ListNode* p = head;
            while (p != slow) {
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return nullptr;
}
