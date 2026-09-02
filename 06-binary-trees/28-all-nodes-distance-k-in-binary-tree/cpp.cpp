// Method 1: Brute
// Time: O(n) | Space: O(n)
// Undirected graph of val->neighbors (vals are unique on LC). BFS from target.val for K steps.

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

void buildG(TreeNode* node, unordered_map<int, vector<int>>& g) {
    if (!node) return;
    if (node->left) {
        g[node->val].push_back(node->left->val);
        g[node->left->val].push_back(node->val);
        buildG(node->left, g);
    }
    if (node->right) {
        g[node->val].push_back(node->right->val);
        g[node->right->val].push_back(node->val);
        buildG(node->right, g);
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<int, vector<int>> g;
    buildG(root, g);
    unordered_set<int> seen;
    queue<pair<int,int>> q;
    q.push({target->val, 0});
    seen.insert(target->val);
    vector<int> out;
    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        if (d == k) { out.push_back(u); continue; }
        for (int v : g[u]) if (!seen.count(v)) { seen.insert(v); q.push({v, d + 1}); }
    }
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent map from nodes (not values). BFS from the target node with a visited set of pointers. Collect at distance k.

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

void markP(TreeNode* node, TreeNode* p, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!node) return;
    parent[node] = p;
    markP(node->left, node, parent);
    markP(node->right, node, parent);
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    markP(root, nullptr, parent);
    unordered_set<TreeNode*> seen;
    queue<pair<TreeNode*, int>> q;
    q.push({target, 0});
    seen.insert(target);
    vector<int> out;
    while (!q.empty()) {
        auto [node, d] = q.front(); q.pop();
        if (d == k) { out.push_back(node->val); continue; }
        TreeNode* nbr[3] = {node->left, node->right, parent[node]};
        for (int i = 0; i < 3; i++) {
            TreeNode* nx = nbr[i];
            if (!nx || seen.count(nx)) continue;
            seen.insert(nx);
            q.push({nx, d + 1});
        }
    }
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS returns distance from this subtree to target, or -1. When a child reports dist, walk the other child at k - dist - 2, and maybe record this node. Downward walk from target collects depth k.

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

void collect(TreeNode* node, int dist, vector<int>& out) {
    if (!node || dist < 0) return;
    if (dist == 0) { out.push_back(node->val); return; }
    collect(node->left, dist - 1, out);
    collect(node->right, dist - 1, out);
}
int dfsK(TreeNode* node, TreeNode* target, int k, vector<int>& out) {
    if (!node) return -1;
    if (node == target) { collect(node, k, out); return 0; }
    int L = dfsK(node->left, target, k, out);
    if (L >= 0) {
        if (L + 1 == k) out.push_back(node->val);
        else collect(node->right, k - L - 2, out);
        return L + 1;
    }
    int R = dfsK(node->right, target, k, out);
    if (R >= 0) {
        if (R + 1 == k) out.push_back(node->val);
        else collect(node->left, k - R - 2, out);
        return R + 1;
    }
    return -1;
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> out;
    dfsK(root, target, k, out);
    return out;
}
