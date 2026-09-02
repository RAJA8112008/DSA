// Method 1: Brute
// Time: O(n) | Space: O(n)
// Recursive inorder: walk left, push this value, walk right. Matches the definition. Extra memory is the output array plus O(h) call stack.

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

vector<int> inorderTraversal_go(TreeNode* node) {
    if (!node) {
        return;
    }
    inorderTraversal_go(node->left);
    out.push_back(node->val);
    inorderTraversal_go(node->right);
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<TreeNode*> out;
    inorderTraversal_go(root);
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Iterative stack: go left until null, pop, record val, go right. Same visit order as recursion without depending on engine stack limits as much; still O(h) extra.

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

vector<int> inorderTraversal(TreeNode* root) {
    vector<TreeNode*> out;
    vector<TreeNode*> stack;
    TreeNode* cur = root;
    while (cur || stack.size()) {
        while (cur) {
            stack.push_back(cur);
            cur = cur->left;
        }
        cur = stack.back() /* then pop_back */;
        out.push_back(cur->val);
        cur = cur->right;
    }
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris: if there is no left, visit and go right. Else find the predecessor (rightmost in left). If pred.right is null, thread it to cur and go left. If it already points at cur, unthread, visit, go right. Auxiliary space O(1) besides the output list.

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

vector<int> inorderTraversal(TreeNode* root) {
    vector<TreeNode*> out;
    TreeNode* cur = root;
    while (cur) {
        if (!cur->left) {
            out.push_back(cur->val);
            cur = cur->right;
        }
        else {
            TreeNode* pred = cur->left;
            while (pred->right && pred->right != cur) {
                pred = pred->right;
            }
            if (!pred->right) {
                pred->right = cur;
                cur = cur->left;
            }
            else {
                pred->right = nullptr;
                out.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return out;
}
