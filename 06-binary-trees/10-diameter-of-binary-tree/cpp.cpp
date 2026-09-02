// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At every node, diameter candidate is height(left)+height(right). height itself walks the subtree, so nested walks are quadratic on a skewed tree.

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

int diameterOfBinaryTree_height(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return 1 + std::max(diameterOfBinaryTree_height(node->left), diameterOfBinaryTree_height(node->right));
}

int diameterOfBinaryTree_visit(TreeNode* node) {
    if (!node) {
        return;
    }
    TreeNode* through = height(node->left) + height(node->right);
    if (through > best) {
        best = through;
    }
    diameterOfBinaryTree_visit(node->left);
    diameterOfBinaryTree_visit(node->right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int best = 0;
    diameterOfBinaryTree_visit(root);
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS returns height. While returning, update best with leftHeight + rightHeight. Each node once.

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

int diameterOfBinaryTree_height(TreeNode* node) {
    if (!node) {
        return 0;
    }
    TreeNode* lh = diameterOfBinaryTree_height(node->left);
    TreeNode* rh = diameterOfBinaryTree_height(node->right);
    if (lh + rh > best) {
        best = lh + rh;
    }
    return 1 + std::max(lh, rh);
}

int diameterOfBinaryTree(TreeNode* root) {
    int best = 0;
    diameterOfBinaryTree_height(root);
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative postorder. A Map stores height after both children are done. Update diameter from those heights. No call stack; extra map of n heights.

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

int diameterOfBinaryTree(TreeNode* root) {
    if (!root) {
        return 0;
    }
    vector<TreeNode*> stack = {root};
    unordered_set<TreeNode*> seen;
    unordered_map<TreeNode*, int> height;
    height[nullptr] = 0;
    int best = 0;
    while (stack.size()) {
        TreeNode* node = stack.back();
        if (node->left && !height.count(node->left) && !seen.count(node->left)) {
            stack.push_back(node->left);
            continue;
        }
        if (node->right && !height.count(node->right) && !seen.count(node->right)) {
            stack.push_back(node->right);
            continue;
        }
        stack.back() /* then pop_back */;
        seen.insert(node);
        TreeNode* lh = height[node->left] || 0;
        TreeNode* rh = height[node->right] || 0;
        height[node] = 1 + std::max(lh, rh);
        if (lh + rh > best) {
            best = lh + rh;
        }
    }
    return best;
}
