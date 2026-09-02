// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node recompute both heights and recurse isBalanced on children. Height work repeats on the same nodes.

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

bool isBalanced_height(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return 1 + std::max(isBalanced_height(node->left), isBalanced_height(node->right));
}

bool isBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }
    if (abs(isBalanced_height(root->left) - isBalanced_height(root->right)) > 1) {
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Postorder returns height. If a child is already unbalanced or |lh-rh|>1, return -1 and bubble up. One visit per node.

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

bool isBalanced_walk(TreeNode* node) {
    if (!node) {
        return 0;
    }
    TreeNode* lh = isBalanced_walk(node->left);
    if (lh < 0) {
        return -1;
    }
    TreeNode* rh = isBalanced_walk(node->right);
    if (rh < 0) {
        return -1;
    }
    if (abs(lh - rh) > 1) {
        return -1;
    }
    return 1 + std::max(lh, rh);
}

bool isBalanced(TreeNode* root) {
    return isBalanced_walk(root) >= 0;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder with a height map. After both children, check |lh-rh| and store height. No recursion.

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

bool isBalanced(TreeNode* root) {
    if (!root) {
        return true;
    }
    vector<TreeNode*> stack = {root};
    unordered_map<TreeNode*, int> height;
    height[nullptr] = 0;
    while (stack.size()) {
        TreeNode* node = stack.back();
        if (node->left && !height.count(node->left)) {
            stack.push_back(node->left);
            continue;
        }
        if (node->right && !height.count(node->right)) {
            stack.push_back(node->right);
            continue;
        }
        stack.back() /* then pop_back */;
        TreeNode* lh = height[node->left] || 0;
        TreeNode* rh = height[node->right] || 0;
        if (abs(lh - rh) > 1) {
            return false;
        }
        height[node] = 1 + std::max(lh, rh);
    }
    return true;
}
