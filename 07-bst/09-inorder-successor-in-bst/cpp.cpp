// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder list of nodes, find p, return the next entry. Extra linear memory.

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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    vector<TreeNode*> nodes;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        nodes.push_back(node);
        go(node->right);
    };
    go(root);
    for (int i = 0; i < (int)nodes.size(); i++)
        if (nodes[i] == p) return i + 1 < (int)nodes.size() ? nodes[i + 1] : nullptr;
    return nullptr;
}


// Method 2: Optimal
// Time: O(h) | Space: O(1)
// Walk from the root. Whenever the current node is greater than p, it is a candidate successor — go left to hunt a closer one. Otherwise go right.

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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* succ = nullptr;
    TreeNode* cur = root;
    while (cur) {
        if (p->val < cur->val) { succ = cur; cur = cur->left; }
        else cur = cur->right;
    }
    return succ;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// If p has a right child, successor is leftmost there — O(h) on that spine only. Else fall back to the root walk. Same worst case, often shorter.

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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (p->right) {
        TreeNode* n = p->right;
        while (n->left) n = n->left;
        return n;
    }
    TreeNode* succ = nullptr;
    TreeNode* cur = root;
    while (cur) {
        if (p->val < cur->val) { succ = cur; cur = cur->left; }
        else cur = cur->right;
    }
    return succ;
}
