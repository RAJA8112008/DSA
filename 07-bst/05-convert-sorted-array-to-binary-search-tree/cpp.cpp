// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Insert 0..n-1 in order into an empty BST. Each insert walks a growing right spine, so you get a linked list of height n.

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

TreeNode* insertVal(TreeNode* node, int val) {
    if (!node) return new TreeNode(val);
    if (val < node->val) node->left = insertVal(node->left, val);
    else node->right = insertVal(node->right, val);
    return node;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = nullptr;
    for (int val : nums) root = insertVal(root, val);
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Slice the array around mid each call. Balanced, but each slice copies O(n) elements across the tree of calls.

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

TreeNode* sortedArrayToBST(vector<int>& nums) {
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


// Method 3: More optimal
// Time: O(n) | Space: O(log n)
// Pass inclusive indices. Each node is created once. Recursion depth is the height of the balanced tree.

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

TreeNode* sortedArrayToBST(vector<int>& nums) {
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
