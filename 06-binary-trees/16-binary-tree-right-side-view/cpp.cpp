// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order into rows, then map each row to its last value. Extra storage for every node value.

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

vector<int> rightSideView(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> levels;
    vector<TreeNode*> queue = {root};
    while (queue.size()) {
        int n = queue.size();
        vector<int> row;
        for (int i = 0; i < n; i++) {
            TreeNode* node = queue.front() /* erase begin */;
            row.push_back(node->val);
            if (node->left) {
                queue.push_back(node->left);
            }
            if (node->right) {
                queue.push_back(node->right);
            }
        }
        levels.push_back(row);
    }
    return /* last of each row */ lastOfRows(levels);
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// DFS visit right child first. If depth === ans.length, this is the first node seen at that depth from the right. Recursion O(h).

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

vector<int> rightSideView_dfs(TreeNode* node, int d) {
    if (!node) {
        return;
    }
    if (d == ans.size()) {
        ans.push_back(node->val);
    }
    rightSideView_dfs(node->right, d + 1);
    rightSideView_dfs(node->left, d + 1);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    rightSideView_dfs(root, 0);
    return ans;
}


// Method 3: More optimal
// Time: O(n) | Space: O(w)
// BFS. For each level of size n, the last shifted node is the right-side value. Only the answer plus the queue, no full row arrays.

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

vector<int> rightSideView(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<int> ans;
    vector<TreeNode*> queue = {root};
    while (queue.size()) {
        int n = queue.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = queue.front() /* erase begin */;
            if (i == n - 1) {
                ans.push_back(node->val);
            }
            if (node->left) {
                queue.push_back(node->left);
            }
            if (node->right) {
                queue.push_back(node->right);
            }
        }
    }
    return ans;
}
