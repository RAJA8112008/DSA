// Method 1: Brute
// Time: O(n) init, O(1) next | Space: O(n)
// Flatten inorder into an array at construction. next/hasNext are index moves. Simple, but you pay linear memory before the first call.

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

class BSTIterator {
    vector<int> vals;
    int i = 0;
    void go(TreeNode* node) {
        if (!node) return;
        go(node->left);
        vals.push_back(node->val);
        go(node->right);
    }
public:
    BSTIterator(TreeNode* root) { go(root); }
    int next() { return vals[i++]; }
    bool hasNext() { return i < (int)vals.size(); }
};


// Method 2: Optimal
// Time: O(h) init, amortized O(1) next | Space: O(h)
// Stack holds the path to the next node. Construction pushes the left spine. next() pops, then pushes the left spine of the right child.

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

class BSTIterator {
    vector<TreeNode*> stack;
    void pushLeft(TreeNode* node) {
        while (node) { stack.push_back(node); node = node->left; }
    }
public:
    BSTIterator(TreeNode* root) { pushLeft(root); }
    int next() {
        TreeNode* node = stack.back(); stack.pop_back();
        pushLeft(node->right);
        return node->val;
    }
    bool hasNext() { return !stack.empty(); }
};


// Method 3: More optimal
// Time: amortized O(1) next | Space: O(1)
// Morris: thread predecessor.right to the current node, walk without a stack. Unthread before yielding so the tree is restored. Extra memory is a handful of pointers.

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

class BSTIterator {
    TreeNode* cur;
public:
    BSTIterator(TreeNode* root) : cur(root) {}
    int next() {
        while (cur) {
            if (!cur->left) {
                int val = cur->val;
                cur = cur->right;
                return val;
            }
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) pred = pred->right;
            if (!pred->right) {
                pred->right = cur;
                cur = cur->left;
            } else {
                pred->right = nullptr;
                int val = cur->val;
                cur = cur->right;
                return val;
            }
        }
        return 0;
    }
    bool hasNext() { return cur != nullptr; }
};
