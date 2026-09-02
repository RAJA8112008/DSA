// Method 1: Brute
// Time: O(n²) | Space: O(n²)
// Collect every root-to-leaf path, then keep those whose sum equals target. Path copies dominate memory.

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

void goPaths(TreeNode* node, vector<int>& path, vector<vector<int>>& paths) {
    if (!node) return;
    path.push_back(node->val);
    if (!node->left && !node->right) paths.push_back(path);
    goPaths(node->left, path, paths);
    goPaths(node->right, path, paths);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> paths, out;
    vector<int> path;
    goPaths(root, path, paths);
    for (auto& p : paths) {
        int s = 0;
        for (int v : p) s += v;
        if (s == targetSum) out.push_back(p);
    }
    return out;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(h)
// Backtracking. remain starts at targetSum. At a leaf, if remain == node.val, snapshot the path. Copying a path is O(h); total output can be O(n²).

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

void goSum(TreeNode* node, int remain, vector<int>& path, vector<vector<int>>& out) {
    if (!node) return;
    path.push_back(node->val);
    if (!node->left && !node->right && remain == node->val) out.push_back(path);
    goSum(node->left, remain - node->val, path, out);
    goSum(node->right, remain - node->val, path, out);
    path.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> out;
    vector<int> path;
    goSum(root, targetSum, path, out);
    return out;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(n²)
// Iterative stack of {node, remain, path}. Same snapshots at leaves. Avoids call-stack overflow on a stick, still copies paths.

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

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> out;
    if (!root) return out;
    struct Frame { TreeNode* node; int remain; vector<int> path; };
    vector<Frame> stack;
    stack.push_back({root, targetSum, {root->val}});
    while (!stack.empty()) {
        Frame cur = stack.back(); stack.pop_back();
        if (!cur.node->left && !cur.node->right && cur.remain == cur.node->val) out.push_back(cur.path);
        if (cur.node->right) {
            vector<int> np = cur.path;
            np.push_back(cur.node->right->val);
            stack.push_back({cur.node->right, cur.remain - cur.node->val, np});
        }
        if (cur.node->left) {
            vector<int> np = cur.path;
            np.push_back(cur.node->left->val);
            stack.push_back({cur.node->left, cur.remain - cur.node->val, np});
        }
    }
    return out;
}
