// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Collect (hd, depth, index, val), sort, keep the last per hd.

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

vector<int> bottomView(TreeNode* root) {
    vector<array<int,4>> items;
    int idx = 0;
    function<void(TreeNode*,int,int)> go = [&](TreeNode* node, int hd, int d) {
        if (!node) return;
        items.push_back({hd, d, idx++, node->val});
        go(node->left, hd - 1, d + 1);
        go(node->right, hd + 1, d + 1);
    };
    go(root, 0, 0);
    sort(items.begin(), items.end());
    vector<int> out;
    for (int i = 0; i < (int)items.size(); i++)
        if (i + 1 == (int)items.size() || items[i][0] != items[i + 1][0]) out.push_back(items[i][3]);
    return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// BFS overwrite per hd. Last write is the deepest (or the right one on a tie). Emit min..max.

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

vector<int> bottomView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    map<int, int> last;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto [node, hd] = q.front(); q.pop();
        last[hd] = node->val;
        if (node->left) q.push({node->left, hd - 1});
        if (node->right) q.push({node->right, hd + 1});
    }
    for (auto& kv : last) out.push_back(kv.second);
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// DFS: keep val for hd when depth >= stored depth (overwrite on tie so right-later wins if you visit right after left).

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

void goBot(TreeNode* node, int hd, int d, unordered_map<int,int>& val, unordered_map<int,int>& dep, int& minH, int& maxH) {
    if (!node) return;
    if (!dep.count(hd) || d >= dep[hd]) { dep[hd] = d; val[hd] = node->val; }
    minH = min(minH, hd);
    maxH = max(maxH, hd);
    goBot(node->left, hd - 1, d + 1, val, dep, minH, maxH);
    goBot(node->right, hd + 1, d + 1, val, dep, minH, maxH);
}
vector<int> bottomView(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    unordered_map<int,int> val, dep;
    int minH = 0, maxH = 0;
    goBot(root, 0, 0, val, dep, minH, maxH);
    for (int h = minH; h <= maxH; h++) out.push_back(val[h]);
    return out;
}
