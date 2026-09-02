// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode each tree as a preorder array with N for null, then compare the arrays. Extra strings/arrays for both trees.

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

bool isSameTree_enc(TreeNode* node, vector<string>& out) {
    if (!node) {
        out.push_back("N");
        return;
    }
    out.push_back(to_string(node->val));
    isSameTree_enc(node->left, out);
    isSameTree_enc(node->right, out);
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<TreeNode*> a;
    vector<TreeNode*> b;
    isSameTree_enc(p, a);
    isSameTree_enc(q, b);
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If both null, true. If one null or vals differ, false. Else both lefts and both rights. Stack O(h).

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

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) {
        return true;
    }
    if (!p || !q || p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative: stack of pairs. Pop two nodes, check null/val, push children pairs. Same complexity, no recursion.

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

bool isSameTree(TreeNode* p, TreeNode* q) {
    vector<TreeNode*> stack = {[p, q]};
    while (stack.size()) {
        int pair = stack.back() /* then pop_back */;
        TreeNode* a = pair[0];
        TreeNode* b = pair[1];
        if (!a && !b) {
            continue;
        }
        if (!a || !b || a->val != b->val) {
            return false;
        }
        stack.push_back([a->left, b->left]);
        stack.push_back([a->right, b->right]);
    }
    return true;
}
