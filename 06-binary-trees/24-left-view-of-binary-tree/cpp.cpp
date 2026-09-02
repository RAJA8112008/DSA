// Method 1: Brute
// Time: O(n) | Space: O(n)
// Full level-order lists, then pick the first value of each list.

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

vector<int> leftView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = (int)q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) out.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// BFS. When i == 0 in the level loop, that node is the left view. w is the widest level.

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

vector<int> leftView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = (int)q.size();
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); q.pop();
            if (i == 0) out.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS left-first. If depth == out.length this is the first node at that depth. Recursion stack only.

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

void goLeft(TreeNode* node, int d, vector<int>& out) {
    if (!node) return;
    if (d == (int)out.size()) out.push_back(node->val);
    goLeft(node->left, d + 1, out);
    goLeft(node->right, d + 1, out);
}
vector<int> leftView(TreeNode* root) {
    vector<int> out;
    goLeft(root, 0, out);
    return out;
}
