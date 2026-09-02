// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Keep an array of visited nodes. For each new node, scan the array for the same object. Correct, but the scan makes it quadratic.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
    vector<ListNode*> seen;
    ListNode* cur = head;
    while (cur) {
        for (int i = 0; i < seen.size(); i++) {
            if (seen[i] == cur) {
                return true;
            }
        }
        seen.push_back(cur);
        cur = cur->next;
    }
    return false;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A Set stores nodes you already walked. Add is O(1) on average. First repeat means a cycle. Extra memory equals the number of distinct nodes before a repeat.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
    unordered_set<ListNode*> seen;
    ListNode* cur = head;
    while (cur) {
        if (seen.count(cur)) {
            return true;
        }
        seen.insert(cur);
        cur = cur->next;
    }
    return false;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Floyd: slow +1, fast +2. No set. If they meet, there is a cycle. If fast hits null, there is not. Constant extra pointers.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

bool hasCycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next.next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}
