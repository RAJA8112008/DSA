// Method 1: Brute
// Time: O(n) | Space: O(h)
// DFS every node. Add val when it is inside the interval. Correct on a plain binary tree too.

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

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    int add = (root->val >= low && root->val <= high) ? root->val : 0;
    return add + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Prune: skip left when node is below low, skip right when node is above high. Best case you only walk the in-range corridor.

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

int rangeSumBST(TreeNode* root, int low, int high) {
    if (!root) return 0;
    if (root->val < low) return rangeSumBST(root->right, low, high);
    if (root->val > high) return rangeSumBST(root->left, low, high);
    return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Explicit stack, same prune. No recursion. Push only children that can still hold in-range keys.

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

int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    vector<TreeNode*> stack;
    if (root) stack.push_back(root);
    while (!stack.empty()) {
        TreeNode* node = stack.back(); stack.pop_back();
        if (node->val >= low && node->val <= high) sum += node->val;
        if (node->left && node->val > low) stack.push_back(node->left);
        if (node->right && node->val < high) stack.push_back(node->right);
    }
    return sum;
}
