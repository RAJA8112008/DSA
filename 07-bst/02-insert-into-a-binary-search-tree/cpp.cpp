// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every key, append val, sort, and rebuild a balanced tree from the middle. Extra arrays; you never use the existing shape.

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    vector<int> keys;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        keys.push_back(node->val);
        go(node->left);
        go(node->right);
    };
    go(root);
    keys.push_back(val);
    sort(keys.begin(), keys.end());
    function<TreeNode*(int,int)> build = [&](int lo, int hi) -> TreeNode* {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(keys[mid]);
        node->left = build(lo, mid - 1);
        node->right = build(mid + 1, hi);
        return node;
    };
    return build(0, (int)keys.size() - 1);
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse left or right and assign the returned child. When the child is null, allocate the new leaf. Root is returned unchanged unless the tree was empty.

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertIntoBST(root->left, val);
    else root->right = insertIntoBST(root->right, val);
    return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative: if the tree is empty, return a new root. Else walk until the next child is null and attach there. No recursion.

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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* fresh = new TreeNode(val);
    if (!root) return fresh;
    TreeNode* cur = root;
    while (true) {
        if (val < cur->val) {
            if (!cur->left) { cur->left = fresh; break; }
            cur = cur->left;
        } else {
            if (!cur->right) { cur->right = fresh; break; }
            cur = cur->right;
        }
    }
    return root;
}
