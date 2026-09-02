// Method 1: Brute
// Time: O(n) | Space: O(n)
// Inorder dump, then return vals[n - k]. Extra array of every key.

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

int kthLargest(TreeNode* root, int k) {
    vector<int> vals;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        vals.push_back(node->val);
        go(node->right);
    };
    go(root);
    return vals[(int)vals.size() - k];
}


// Method 2: Optimal
// Time: O(h + k) | Space: O(h)
// Reverse inorder. Decrement k at each visit. When k hits 0, that value is the answer. Stop walking.

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

int kthLargest(TreeNode* root, int k) {
    int kLeft = k, ans = 0;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node || kLeft == 0) return;
        go(node->right);
        if (kLeft == 0) return;
        kLeft--;
        if (kLeft == 0) { ans = node->val; return; }
        go(node->left);
    };
    go(root);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris reverse inorder: thread the successor (leftmost of the right, via left pointers of the right spine). Visit without a stack, stop at k.

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

int kthLargest(TreeNode* root, int k) {
    TreeNode* cur = root;
    while (cur) {
        if (!cur->right) {
            if (--k == 0) return cur->val;
            cur = cur->left;
        } else {
            TreeNode* succ = cur->right;
            while (succ->left && succ->left != cur) succ = succ->left;
            if (!succ->left) { succ->left = cur; cur = cur->right; }
            else {
                succ->left = nullptr;
                if (--k == 0) return cur->val;
                cur = cur->left;
            }
        }
    }
    return 0;
}
