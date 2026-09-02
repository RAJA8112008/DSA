// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump all values, then check each pair is strictly increasing. Extra array holds the whole walk.

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

bool isValidBST(TreeNode* root) {
    vector<int> vals;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        vals.push_back(node->val);
        go(node->right);
    };
    go(root);
    for (int i = 1; i < (int)vals.size(); i++) if (vals[i] <= vals[i - 1]) return false;
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (lo, hi). Left child inherits hi = node.val; right inherits lo = node.val. Use a type wider than int so INT_MIN / INT_MAX are legal node values.

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

bool isValidBST(TreeNode* root) {
    function<bool(TreeNode*, long long, long long)> ok = [&](TreeNode* node, long long lo, long long hi) {
        if (!node) return true;
        if (node->val <= lo || node->val >= hi) return false;
        return ok(node->left, lo, node->val) && ok(node->right, node->val, hi);
    };
    return ok(root, LLONG_MIN, LLONG_MAX);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. Track the previous value. If the current node is not greater, the tree is invalid. No extra value array.

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

bool isValidBST(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    TreeNode* prev = nullptr;
    while (cur || !stack.empty()) {
        while (cur) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back(); stack.pop_back();
        if (prev && cur->val <= prev->val) return false;
        prev = cur;
        cur = cur->right;
    }
    return true;
}
