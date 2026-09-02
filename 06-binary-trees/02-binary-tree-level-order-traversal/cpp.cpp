// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS with a depth argument. Push val into levels[depth], creating the row if needed. Extra recursion stack plus the answer.

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

vector<vector<int>> levelOrder_dfs(TreeNode* node, int d) {
    if (!node) {
        return;
    }
    if (!levels[d]) {
        levels[d] = [];
    }
    levels[d].push(node->val);
    levelOrder_dfs(node->left, d + 1);
    levelOrder_dfs(node->right, d + 1);
}

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> levels;
    levelOrder_dfs(root, 0);
    return levels;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS queue. Each node is stored with its depth. Rows grow as depth increases. Extra pair objects on the queue.

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

vector<vector<int>> levelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> levels;
    vector<pair<TreeNode*, int>> queue;
    while (queue.size()) {
        auto __it = queue.front() /* erase begin */; TreeNode* node = __it.first; int d = __it.second;
        if (!levels[d]) {
            levels[d] = [];
        }
        levels[d].push(node->val);
        if (node->left) {
            queue.push_back({ node: node->left, d: d + 1 });
        }
        if (node->right) {
            queue.push_back({ node: node->right, d: d + 1 });
        }
    }
    return levels;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS without storing depth. n = queue.length is the current row size. Process exactly those n nodes, enqueue children for the next row. Cleaner constant factors; still O(width) queue.

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

vector<vector<int>> levelOrder(TreeNode* root) {
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
    return levels;
}
