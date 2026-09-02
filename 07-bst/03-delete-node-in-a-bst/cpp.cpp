// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump every key except key, then rebuild a balanced BST from the sorted list. Simple, but you throw away the original shape.

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

TreeNode* deleteNode(TreeNode* root, int key) {
    vector<int> keys;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        if (node->val != key) keys.push_back(node->val);
        go(node->left);
        go(node->right);
    };
    go(root);
    sort(keys.begin(), keys.end());
    function<TreeNode*(int,int)> build = [&](int lo, int hi) -> TreeNode* {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(keys[mid]);
        node->left = build(lo, mid - 1);
        node->right = build(mid + 1, hi);
        return node;
    };
    return build(0, (int)keys.size() - 1);
}


// Method 2: Optimal
// Time: O(h) | Space: O(h)
// Recurse to the node. Leaf or one child: return the other child. Two children: copy leftmost of right into node.val, then delete that successor from the right subtree.

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

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteNode(root->left, key);
    else if (key > root->val) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        TreeNode* succ = root->right;
        while (succ->left) succ = succ->left;
        root->val = succ->val;
        root->right = deleteNode(root->right, succ->val);
    }
    return root;
}


// Method 3: More optimal
// Time: O(h) | Space: O(1)
// Iterative search with a parent pointer. Splice zero/one-child nodes directly. For two children, copy the successor value then unlink the successor (it has no left child).

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

TreeNode* spliceNode(TreeNode* root, TreeNode* parent, TreeNode* node, TreeNode* child) {
    if (!parent) return child;
    if (parent->left == node) parent->left = child;
    else parent->right = child;
    return root;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    TreeNode* parent = nullptr;
    TreeNode* cur = root;
    while (cur && cur->val != key) {
        parent = cur;
        cur = key < cur->val ? cur->left : cur->right;
    }
    if (!cur) return root;
    if (!cur->left) return spliceNode(root, parent, cur, cur->right);
    if (!cur->right) return spliceNode(root, parent, cur, cur->left);
    TreeNode* sp = cur;
    TreeNode* succ = cur->right;
    while (succ->left) { sp = succ; succ = succ->left; }
    cur->val = succ->val;
    if (sp->left == succ) sp->left = succ->right;
    else sp->right = succ->right;
    return root;
}
