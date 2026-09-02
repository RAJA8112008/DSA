// Method 1: Brute
// Time: O(n) | Space: O(n)
// Build undirected graph on values (unique). BFS from start. Answer is the max distance.

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

int amountOfTime(TreeNode* root, int start) {
    unordered_map<int, vector<int>> g;
    function<void(TreeNode*)> build = [&](TreeNode* node) {
        if (!node) return;
        if (node->left) {
            g[node->val].push_back(node->left->val);
            g[node->left->val].push_back(node->val);
            build(node->left);
        }
        if (node->right) {
            g[node->val].push_back(node->right->val);
            g[node->right->val].push_back(node->val);
            build(node->right);
        }
    };
    build(root);
    unordered_set<int> seen;
    queue<pair<int,int>> q;
    q.push({start, 0});
    seen.insert(start);
    int best = 0;
    while (!q.empty()) {
        auto [u, d] = q.front(); q.pop();
        best = max(best, d);
        for (int v : g[u]) if (!seen.count(v)) { seen.insert(v); q.push({v, d + 1}); }
    }
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Parent pointers, BFS from the start node (find it first). Minutes = max distance.

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

int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* src = nullptr;
    function<void(TreeNode*, TreeNode*)> mark = [&](TreeNode* node, TreeNode* p) {
        if (!node) return;
        parent[node] = p;
        if (node->val == start) src = node;
        mark(node->left, node);
        mark(node->right, node);
    };
    mark(root, nullptr);
    unordered_set<TreeNode*> seen;
    queue<pair<TreeNode*, int>> q;
    q.push({src, 0});
    seen.insert(src);
    int best = 0;
    while (!q.empty()) {
        auto [node, d] = q.front(); q.pop();
        best = max(best, d);
        TreeNode* nbr[3] = {node->left, node->right, parent[node]};
        for (int i = 0; i < 3; i++) {
            if (!nbr[i] || seen.count(nbr[i])) continue;
            seen.insert(nbr[i]);
            q.push({nbr[i], d + 1});
        }
    }
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS returns height of the subtree. When the start node is found, ans is max(height below, distance going up through the parent). One traversal, no graph.

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

int amountOfTime(TreeNode* root, int start) {
    int ans = 0;
    function<int(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return 0;
        int L = dfs(node->left);
        int R = dfs(node->right);
        if (node->val == start) {
            ans = max(ans, max(L, R));
            return -1;
        }
        if (L < 0) { ans = max(ans, R - L); return L - 1; }
        if (R < 0) { ans = max(ans, L - R); return R - 1; }
        return 1 + max(L, R);
    };
    dfs(root);
    return ans;
}
