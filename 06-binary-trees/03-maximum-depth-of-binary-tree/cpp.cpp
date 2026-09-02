// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect every root-to-leaf path into arrays, return the longest length. Extra memory for all paths.

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

int maxDepth_go(TreeNode* node, vector<int>& path) {
    if (!node) {
        return;
    }
    path.push_back(node->val);
    if (!node->left && !node->right) {
        paths.push_back(path.size());
    }
    maxDepth_go(node->left, path);
    maxDepth_go(node->right, path);
    path.back() /* then pop_back */;
}

int maxDepth(TreeNode* root) {
    vector<int> paths;
    maxDepth_go(root, []);
    return paths.size() ? *max_element(paths.begin(), paths.end()) : 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Recursive height: null is 0, else 1 + max of children. One visit per node. Stack O(h).

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

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Iterative stack of {node, depth}. Track the max depth seen. Same complexity, no engine recursion. BFS would use O(width) instead of O(h).

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

int maxDepth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int best = 0;
    vector<pair<TreeNode*, int>> stack;
    while (stack.size()) {
        auto __it = stack.back() /* then pop_back */; TreeNode* node = __it.first; int d = __it.second;
        if (d > best) {
            best = d;
        }
        if (node->left) {
            stack.push_back({ node: node->left, d: d + 1 });
        }
        if (node->right) {
            stack.push_back({ node: node->right, d: d + 1 });
        }
    }
    return best;
}
