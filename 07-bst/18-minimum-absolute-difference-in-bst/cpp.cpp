// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Dump all values, then compare every pair. Extra array and quadratic checks.

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

int getMinimumDifference(TreeNode* root) {
    vector<int> vals;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        vals.push_back(node->val);
        go(node->left);
        go(node->right);
    };
    go(root);
    int best = INT_MAX;
    for (int i = 0; i < (int)vals.size(); i++)
        for (int j = i + 1; j < (int)vals.size(); j++)
            best = min(best, abs(vals[i] - vals[j]));
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Inorder. Compare each node with the previous inorder value. The min of those adjacent gaps is the global min.

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

int getMinimumDifference(TreeNode* root) {
    TreeNode* prev = nullptr;
    int best = INT_MAX;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        if (prev) best = min(best, node->val - prev->val);
        prev = node;
        go(node->right);
    };
    go(root);
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris inorder with a previous pointer. Same adjacent-gap logic, no stack.

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

int getMinimumDifference(TreeNode* root) {
    TreeNode* prev = nullptr;
    int best = INT_MAX;
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            if (prev) best = min(best, cur->val - prev->val);
            prev = cur;
            cur = cur->right;
        } else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) { pred->right = cur; cur = cur->left; }
            else {
                pred->right = nullptr;
                if (prev) best = min(best, cur->val - prev->val);
                prev = cur;
                cur = cur->right;
            }
        }
    }
    return best;
}
