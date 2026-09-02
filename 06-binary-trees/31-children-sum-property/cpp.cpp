// Method 1: Brute
// Time: O(n) | Space: O(n)
// For every node, sum the two children (0 if null) and compare. Recurse both sides. Extra list of all nodes first.

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

bool isSumTree(TreeNode* root) {
    vector<TreeNode*> nodes;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        nodes.push_back(node);
        go(node->left);
        go(node->right);
    };
    go(root);
    for (TreeNode* n : nodes) {
        if (!n->left && !n->right) continue;
        int L = n->left ? n->left->val : 0;
        int R = n->right ? n->right->val : 0;
        if (n->val != L + R) return false;
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder boolean. Null and leaves are true. Then check val == left+right and both subtrees hold.

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

bool isSumTree(TreeNode* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;
    int L = root->left ? root->left->val : 0;
    int R = root->right ? root->right->val : 0;
    return root->val == L + R && isSumTree(root->left) && isSumTree(root->right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Return a pair (ok, val) so a failed subtree aborts. Same checks, one value returned upward.

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

pair<bool,int> goSum(TreeNode* node) {
    if (!node) return {true, 0};
    if (!node->left && !node->right) return {true, node->val};
    auto L = goSum(node->left);
    auto R = goSum(node->right);
    bool ok = L.first && R.first && node->val == L.second + R.second;
    return {ok, node->val};
}
bool isSumTree(TreeNode* root) { return goSum(root).first; }
