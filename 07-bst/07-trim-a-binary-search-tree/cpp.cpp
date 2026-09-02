// Method 1: Brute
// Time: O(n) | Space: O(n)
// Gather every in-range key, sort, rebuild a balanced tree. Correct values, but new nodes and a different shape.

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

TreeNode* trimBST(TreeNode* root, int low, int high) {
    vector<int> keys;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        if (node->val >= low && node->val <= high) keys.push_back(node->val);
        go(node->left);
        go(node->right);
    };
    go(root);
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
// Time: O(n) | Space: O(h)
// Postorder prune using the BST property. Reuse the original nodes. If the root is outside the window, drop it and return one trimmed child.

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

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (!root) return nullptr;
    if (root->val < low) return trimBST(root->right, low, high);
    if (root->val > high) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Move the root iteratively until it sits inside [low, high], then recursively trim the two sides. Fewer frames when the original root is far outside the window.

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

TreeNode* trimSide(TreeNode* node, int low, int high) {
    if (!node) return nullptr;
    if (node->val < low) return trimSide(node->right, low, high);
    if (node->val > high) return trimSide(node->left, low, high);
    node->left = trimSide(node->left, low, high);
    node->right = trimSide(node->right, low, high);
    return node;
}
TreeNode* trimBST(TreeNode* root, int low, int high) {
    while (root && (root->val < low || root->val > high))
        root = root->val < low ? root->right : root->left;
    if (!root) return nullptr;
    root->left = trimSide(root->left, low, high);
    root->right = trimSide(root->right, low, high);
    return root;
}
