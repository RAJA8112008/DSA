// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Inorder keys, then insert in sorted order into a fresh BST. That rebuilds a stick. Shows why you must pick mids, not insert in order.

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

TreeNode* balanceBST(TreeNode* root) {
    vector<int> keys;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        keys.push_back(node->val);
        go(node->right);
    };
    go(root);
    function<TreeNode*(TreeNode*, int)> insert = [&](TreeNode* node, int val) -> TreeNode* {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    };
    TreeNode* out = nullptr;
    for (int val : keys) out = insert(out, val);
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Inorder into an array, then mid-as-root rebuild. Height is log n. Extra array of keys (or of nodes if you reuse them).

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

TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        nodes.push_back(node);
        go(node->right);
    };
    go(root);
    function<TreeNode*(int,int)> build = [&](int lo, int hi) -> TreeNode* {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = nodes[mid];
        node->left = build(lo, mid - 1);
        node->right = build(mid + 1, hi);
        return node;
    };
    return build(0, (int)nodes.size() - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// DSW: rotate every left child to the right to make a vine (linked list of right pointers). Then repeatedly rotate the vine to fold it into a balanced tree. In-place, O(1) extra besides recursion-free loops.

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

int vine(TreeNode* dummy) {
    TreeNode* tail = dummy;
    TreeNode* rest = dummy->right;
    int n = 0;
    while (rest) {
        if (rest->left) {
            TreeNode* old = rest;
            rest = rest->left;
            old->left = rest->right;
            rest->right = old;
            tail->right = rest;
        } else {
            tail = rest;
            rest = rest->right;
            n++;
        }
    }
    return n;
}
void compress(TreeNode* dummy, int count) {
    TreeNode* parent = dummy;
    for (int i = 0; i < count; i++) {
        TreeNode* child = parent->right;
        parent->right = child->right;
        child->right = parent->right->left;
        parent->right->left = child;
        parent = parent->right;
    }
}
TreeNode* balanceBST(TreeNode* root) {
    TreeNode dummy(0);
    dummy.right = root;
    int n = vine(&dummy);
    int m = 1;
    while (m * 2 + 1 <= n) m = m * 2 + 1;
    compress(&dummy, n - m);
    for (m /= 2; m >= 1; m /= 2) compress(&dummy, m);
    return dummy.right;
}
