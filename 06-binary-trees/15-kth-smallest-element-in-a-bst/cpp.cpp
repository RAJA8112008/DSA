// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full inorder into an array, return vals[k-1]. Always walks the whole tree.

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

int kthSmallest_inorder(TreeNode* node) {
    if (!node) {
        return;
    }
    kthSmallest_inorder(node->left);
    vals.push_back(node->val);
    kthSmallest_inorder(node->right);
}

int kthSmallest(TreeNode* root, int k) {
    vector<int> vals;
    kthSmallest_inorder(root);
    return vals[k - 1];
}


// Method 2: Optimal
// Time: O(h+k) | Space: O(h)
// Recursive inorder with a counter. When count hits k, record val and stop expanding. Better when k is small.

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

int kthSmallest_go(TreeNode* node) {
    if (!node || box.count >= k) {
        return;
    }
    kthSmallest_go(node->left);
    box_count++;
    if (box.count == k) {
        box_ans = node->val;
        return;
    }
    kthSmallest_go(node->right);
}

int kthSmallest(TreeNode* root, int k) {
    int box_count = 0;
    int box_ans = 0;
    kthSmallest_go(root);
    return box.ans;
}


// Method 3: More optimal
// Time: O(h+k) | Space: O(h)
// Iterative inorder. Each pop is the next smallest. After k pops, return that val. Easy to stop early; no extra values array.

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

int kthSmallest(TreeNode* root, int k) {
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    while (true) {
        while (cur) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back() /* then pop_back */;
        k--;
        if (k == 0) {
            return cur->val;
        }
        cur = cur->right;
    }
}
