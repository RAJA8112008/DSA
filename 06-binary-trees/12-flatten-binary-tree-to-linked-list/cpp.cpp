// Method 1: Brute
// Time: O(n) | Space: O(n)
// Preorder collect nodes into an array. Then set each left to null and next.right to the following node. Extra array.

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

TreeNode* flatten_pre(TreeNode* node) {
    if (!node) {
        return;
    }
    nodes.push_back(node);
    flatten_pre(node->left);
    flatten_pre(node->right);
}

void flatten(TreeNode* root) {
    vector<TreeNode*> nodes;
    flatten_pre(root);
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].left = nullptr;
        nodes[i].right = i + 1 < nodes.size() ? nodes[i + 1] : nullptr;
    }
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recurse right, then left, keep a tail pointer of the already flattened suffix. Hang this node in front. Stack O(h).

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

TreeNode* flatten_go(TreeNode* node) {
    if (!node) {
        return;
    }
    flatten_go(node->right);
    flatten_go(node->left);
    node->right = box_tail;
    node->left = nullptr;
    box_tail = node;
}

void flatten(TreeNode* root) {
    TreeNode* box_tail = nullptr;
    flatten_go(root);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// While cur exists: if it has a left, find rightmost of left, attach cur.right there, move left to right, clear left. Then cur = cur.right. No extra stack.

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

void flatten(TreeNode* root) {
    TreeNode* cur = root;
    while (cur) {
        if (cur->left) {
            TreeNode* pred = cur->left;
            while (pred->right) {
                pred = pred->right;
            }
            pred->right = cur->right;
            cur->right = cur->left;
            cur->left = nullptr;
        }
        cur = cur->right;
    }
}
