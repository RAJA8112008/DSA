// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records every root-to-leaf path as an array, sums each, compares to target. Extra storage for all paths.

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

bool hasPathSum_go(TreeNode* node, vector<int>& path) {
    if (!node) {
        return;
    }
    path.push_back(node->val);
    if (!node->left && !node->right) {
        int s = 0;
        for (auto v : path) {
            s += v;
        }
        sums.push_back(s);
    }
    hasPathSum_go(node->left, path);
    hasPathSum_go(node->right, path);
    path.back() /* then pop_back */;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    vector<int> sums;
    hasPathSum_go(root, []);
    return find(sums.begin(), sums.end(), targetSum) != -1;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse with remaining. At a leaf, remaining === node.val. Else try left or right with remaining - val.

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

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }
    TreeNode* rest = targetSum - root->val;
    return (hasPathSum(root->left, rest) != nullptr ? hasPathSum(root->left, rest) : hasPathSum(root->right, rest));
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of node plus remaining sum. Same check at leaves. No recursion.

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

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return false;
    }
    vector<pair<TreeNode*, int>> stack;
    while (stack.size()) {
        auto __it = stack.back() /* then pop_back */; TreeNode* node = __it.first; int left = __it.second;
        if (!node->left && !node->right && node->val == left) {
            return true;
        }
        if (node->left) {
            stack.push_back({ node: node->left, left: left - node->val });
        }
        if (node->right) {
            stack.push_back({ node: node->right, left: left - node->val });
        }
    }
    return false;
}
