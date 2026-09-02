// Method 1: Brute
// Time: O(n) | Space: O(n)
// BFS into an array of every node, then swap left/right on each. Extra list of n pointers.

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

TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return root;
    }
    vector<TreeNode*> nodes;
    vector<TreeNode*> queue = {root};
    while (queue.size()) {
        TreeNode* node = queue.front() /* erase begin */;
        nodes.push_back(node);
        if (node->left) {
            queue.push_back(node->left);
        }
        if (node->right) {
            queue.push_back(node->right);
        }
    }
    for (auto node : nodes) {
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse: invert children, then swap this node's left and right (order of swap vs recurse both work). Stack O(h).

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

TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    invertTree(root->left);
    invertTree(root->right);
    TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack. Pop a node, swap children, push non-null children. Same work, no recursion. Queue instead of stack is also fine.

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

TreeNode* invertTree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    vector<TreeNode*> stack = {root};
    while (stack.size()) {
        TreeNode* node = stack.back() /* then pop_back */;
        TreeNode* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
        if (node->left) {
            stack.push_back(node->left);
        }
        if (node->right) {
            stack.push_back(node->right);
        }
    }
    return root;
}
