// Method 1: Brute
// Time: O(n) | Space: O(n)
// Ignore the BST. DFS every node into a list, then scan for val. Correct on any binary tree, but you throw away the ordering.

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

TreeNode* searchBST(TreeNode* root, int val) {
    vector<TreeNode*> nodes;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        nodes.push_back(node);
        go(node->left);
        go(node->right);
    };
    go(root);
    for (TreeNode* node : nodes) if (node->val == val) return node;
    return nullptr;
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse on one child. Each call compares val with the node and drops a whole subtree. Stack depth is the height.

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

TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Same comparisons in a while loop. No call stack. Returns the node or null when the walk falls off.

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

TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* cur = root;
    while (cur && cur->val != val) cur = val < cur->val ? cur->left : cur->right;
    return cur;
}
