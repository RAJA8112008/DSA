// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect every (hd, depth, val), sort, keep the first (smallest depth) per hd.

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

vector<int> topView(TreeNode* root) {
    vector<array<int,3>> items;
    function<void(TreeNode*,int,int)> go = [&](TreeNode* node, int hd, int d) {
        if (!node) return;
        items.push_back({hd, d, node->val});
        go(node->left, hd - 1, d + 1);
        go(node->right, hd + 1, d + 1);
    };
    go(root, 0, 0);
    sort(items.begin(), items.end());
    vector<int> out;
    int prev = INT_MIN, started = 0;
    for (auto& it : items) {
        if (!started || it[0] != prev) { out.push_back(it[2]); prev = it[0]; started = 1; }
    }
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS. The first time an hd appears, record it. Then emit from min hd to max hd.

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

vector<int> topView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    map<int, int> first;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        if (!first.count(hd)) first[hd] = node->val;
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    for (auto& kv : first) out.push_back(kv.second);
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS with depth. Keep a node for hd only if this depth is smaller. Then scan min..max hd. No queue.

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

void goTop(TreeNode* node, int hd, int d, unordered_map<int,int>& bestVal, unordered_map<int,int>& bestD, int& minH, int& maxH) {
    if (!node) return;
    if (!bestD.count(hd) || d < bestD[hd]) { bestD[hd] = d; bestVal[hd] = node->val; }
    minH = min(minH, hd);
    maxH = max(maxH, hd);
    goTop(node->left, hd - 1, d + 1, bestVal, bestD, minH, maxH);
    goTop(node->right, hd + 1, d + 1, bestVal, bestD, minH, maxH);
}
vector<int> topView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    unordered_map<int,int> bestVal, bestD;
    int minH = 0, maxH = 0;
    goTop(root, 0, 0, bestVal, bestD, minH, maxH);
    for (int h = minH; h <= maxH; h++) out.push_back(bestVal[h]);
    return out;
}
