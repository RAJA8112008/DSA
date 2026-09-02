// Method 1: Brute
// Time: O(n·m) | Space: O(n)
// Push every node of root into an array, then isSameTree against subRoot for each. Extra array plus O(n*m) compares.

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

bool isSubtree_same(TreeNode* a, TreeNode* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b || a->val != b->val) {
        return false;
    }
    return isSubtree_same(a->left, b->left) && isSubtree_same(a->right, b->right);
}

bool isSubtree_collect(TreeNode* node) {
    if (!node) {
        return;
    }
    nodes.push_back(node);
    isSubtree_collect(node->left);
    isSubtree_collect(node->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    vector<TreeNode*> nodes;
    isSubtree_collect(root);
    for (auto node : nodes) {
        if (isSubtree_same(node, subRoot)) {
            return true;
        }
    }
    return false;
}


// Method 2: Optimal
// Time: O(n·m) | Space: O(h)
// No extra node list. If this node matches as a tree, true. Else try left or right. Worst case still O(n*m), typical interview code.

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

bool isSubtree_same(TreeNode* a, TreeNode* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b || a->val != b->val) {
        return false;
    }
    return isSubtree_same(a->left, b->left) && isSubtree_same(a->right, b->right);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (!root) {
        return false;
    }
    if (isSubtree_same(root, subRoot)) {
        return true;
    }
    return (isSubtree(root->left, subRoot) != nullptr ? isSubtree(root->left, subRoot) : isSubtree(root->right, subRoot));
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(n+m)
// Serialize with parentheses so each subtree is a unique string. Check whether ser(subRoot) is a substring of ser(root). Linear in the size of the strings (and typical includes).

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

bool isSubtree_ser(TreeNode* node) {
    if (!node) {
        return "N";
    }
    return "(" + node->val + "," + isSubtree_ser(node->left) + "," + isSubtree_ser(node->right) + ")";
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    return isSubtree_ser(root).indexOf(isSubtree_ser(subRoot)) != -1;
}
