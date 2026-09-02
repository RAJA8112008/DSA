// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk the list into an array, then build from mid indices. Extra O(n) memory for the copy.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    vector<int> nums;
    while (head) { nums.push_back(head->val); head = head->next; }
    function<TreeNode*(int,int)> build = [&](int lo, int hi) -> TreeNode* {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(lo, mid - 1);
        node->right = build(mid + 1, hi);
        return node;
    };
    return build(0, (int)nums.size() - 1);
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(log n)
// Slow/fast finds the mid. Cut prev.next so the left half is a shorter list. Recurse on left half, mid node, and right half. No array, but each level rescans the list.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    ListNode* prev = nullptr;
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = nullptr;
    TreeNode* node = new TreeNode(slow->val);
    node->left = sortedListToBST(head);
    node->right = sortedListToBST(slow->next);
    return node;
}


// Method 3: More optimal
// Time: O(n) | Space: O(log n)
// Count n. Inorder-build: recurse left of size n/2, consume the current list node as the root, then recurse right. The list pointer only moves forward. Each node is visited once.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

TreeNode* sortedListToBST(ListNode* head) {
    int n = 0;
    for (ListNode* p = head; p; p = p->next) n++;
    ListNode* cur = head;
    function<TreeNode*(int)> build = [&](int count) -> TreeNode* {
        if (count <= 0) return nullptr;
        TreeNode* left = build((count - 1) / 2);
        TreeNode* node = new TreeNode(cur->val);
        cur = cur->next;
        node->left = left;
        node->right = build(count / 2);
        return node;
    };
    return build(n);
}
