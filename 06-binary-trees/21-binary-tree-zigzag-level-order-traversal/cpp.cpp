// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order into lists. Reverse rows whose index is odd. Extra reverse pass per odd level.

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = (int)q.size();
        vector<int> row;
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); q.pop();
            row.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        if ((int)out.size() % 2 == 1) reverse(row.begin(), row.end());
        out.push_back(row);
    }
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Deque of nodes. Even levels poll from the front and offer children left-then-right at the back. Odd levels poll from the back and offer children right-then-left at the front.

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

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    deque<TreeNode*> dq;
    dq.push_back(root);
    bool leftToRight = true;
    while (!dq.empty()) {
        int n = (int)dq.size();
        vector<int> row;
        for (int i = 0; i < n; i++) {
            if (leftToRight) {
                TreeNode* node = dq.front(); dq.pop_front();
                row.push_back(node->val);
                if (node->left) dq.push_back(node->left);
                if (node->right) dq.push_back(node->right);
            } else {
                TreeNode* node = dq.back(); dq.pop_back();
                row.push_back(node->val);
                if (node->right) dq.push_front(node->right);
                if (node->left) dq.push_front(node->left);
            }
        }
        out.push_back(row);
        leftToRight = !leftToRight;
    }
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with depth. Append a new list when you first reach a depth. Push on even depths, unshift on odd depths. Recursion stack only.

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

void goZig(TreeNode* node, int d, vector<vector<int>>& out) {
    if (!node) return;
    if (d == (int)out.size()) out.push_back({});
    if (d % 2 == 0) out[d].push_back(node->val);
    else out[d].insert(out[d].begin(), node->val);
    goZig(node->left, d + 1, out);
    goZig(node->right, d + 1, out);
}
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> out;
    goZig(root, 0, out);
    return out;
}
