// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump into an array, then check each pair is strictly increasing. Extra O(n) array.

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

bool isValidBST_inorder(TreeNode* node) {
    if (!node) {
        return;
    }
    isValidBST_inorder(node->left);
    vals.push_back(node->val);
    isValidBST_inorder(node->right);
}

bool isValidBST(TreeNode* root) {
    vector<int> vals;
    isValidBST_inorder(root);
    for (int i = 1; i < vals.size(); i++) {
        if (vals[i] <= vals[i - 1]) {
            return false;
        }
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Each node must lie in (low, high). Left child gets high = node.val. Right child gets low = node.val. Use -Infinity / Infinity at the root. Recursion O(h).

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

bool isValidBST_ok(TreeNode* node, int low, int high) {
    if (!node) {
        return true;
    }
    if (node->val <= low || node->val >= high) {
        return false;
    }
    return isValidBST_ok(node->left, low, node->val) && isValidBST_ok(node->right, node->val, high);
}

bool isValidBST(TreeNode* root) {
    return isValidBST_ok(root, INT_MIN, INT_MAX);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative inorder. prev holds the last visited value. If node.val <= prev, fail. No extra values array.

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

bool isValidBST(TreeNode* root) {
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    TreeNode* prev = INT_MIN;
    bool hasPrev = false;
    while (cur || stack.size()) {
        while (cur) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back() /* then pop_back */;
        if (hasPrev && cur->val <= prev) {
            return false;
        }
        prev = cur->val;
        hasPrev = true;
        cur = cur->right;
    }
    return true;
}
