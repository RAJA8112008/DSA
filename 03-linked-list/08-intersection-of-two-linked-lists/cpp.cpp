// Method 1: Brute
// Time: O(n·m) | Space: O(1)
// For each node in A, walk all of B looking for the same object. No extra set. Quadratic time.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    while (a) {
        ListNode* b = headB;
        while (b) {
            if (a == b) {
                return a;
            }
            b = b->next;
        }
        a = a->next;
    }
    return nullptr;
}


// Method 2: Optimal
// Time: O(n+m) | Space: O(n)
// Put every node of A in a Set. Walk B; the first node in the set is the intersection. Linear time, extra memory for A.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    unordered_set<ListNode*> seen;
    ListNode* a = headA;
    while (a) {
        seen.insert(a);
        a = a->next;
    }
    ListNode* b = headB;
    while (b) {
        if (seen.count(b)) {
            return b;
        }
        b = b->next;
    }
    return nullptr;
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Pointer a walks A then B. Pointer b walks B then A. They travel the same total length and meet at the first shared node, or both hit null. No set.

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* a = headA;
    ListNode* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}
