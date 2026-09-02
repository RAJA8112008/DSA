// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// DFS push [col, row, val]. Sort by col, then row, then val. Group into lists. Matches LeetCode 987.

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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<array<int,3>> items;
    function<void(TreeNode*,int,int)> go = [&](TreeNode* node, int row, int col) {
        if (!node) return;
        items.push_back({col, row, node->val});
        go(node->left, row + 1, col - 1);
        go(node->right, row + 1, col + 1);
    };
    go(root, 0, 0);
    sort(items.begin(), items.end());
    vector<vector<int>> out;
    int prev = INT_MIN, started = 0;
    for (auto& it : items) {
        if (!started || it[0] != prev) { out.push_back({}); prev = it[0]; started = 1; }
        out.back().push_back(it[2]);
    }
    return out;
}


// Method 2: Optimal
// Time: O(n log w) | Space: O(n)
// BFS so row order is natural. TreeMap / sorted map of columns. GFG order (no value sort). w is the number of columns.

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

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    map<int, vector<int>> cols;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        cols[hd].push_back(node->val);
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    for (auto& kv : cols) out.push_back(kv.second);
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Same BFS. Record min and max hd, then emit columns in a plain loop. No log w map.

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

vector<vector<int>> verticalOrder(TreeNode* root) {
    vector<vector<int>> out;
    if (!root) return out;
    vector<TreeNode*> nodes = {root};
    vector<int> hds = {0};
    int minH = 0, maxH = 0;
    for (int i = 0; i < (int)nodes.size(); i++) {
        int hd = hds[i];
        minH = min(minH, hd);
        maxH = max(maxH, hd);
        if (nodes[i]->left) { nodes.push_back(nodes[i]->left); hds.push_back(hd - 1); }
        if (nodes[i]->right) { nodes.push_back(nodes[i]->right); hds.push_back(hd + 1); }
    }
    out.assign(maxH - minH + 1, {});
    for (int i = 0; i < (int)nodes.size(); i++) out[hds[i] - minH].push_back(nodes[i]->val);
    return out;
}
