// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS records the path to p and the path to q as arrays. Last common entry is the LCA. Extra path storage.

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

bool lowestCommonAncestor_find(TreeNode* node, TreeNode* target, vector<int>& path) {
    if (!node) {
        return false;
    }
    path.push_back(node);
    if (node == target) {
        return true;
    }
    if (lowestCommonAncestor_find(node->left, target, path) || lowestCommonAncestor_find(node->right, target, path)) {
        return true;
    }
    path.back() /* then pop_back */;
    return false;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> a;
    vector<TreeNode*> b;
    lowestCommonAncestor_find(root, p, a);
    lowestCommonAncestor_find(root, q, b);
    int i = 0;
    while (i < a.size() && i < b.size() && a[i] == b[i]) {
        i++;
    }
    return a[i - 1];
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// If node is null, p, or q, return node. Recurse left and right. If both sides return non-null, node is LCA. Else return the non-null side. One DFS.

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) {
        return root;
    }
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) {
        return root;
    }
    return (left != nullptr ? left : right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Iterative stack builds a parent map. Collect ancestors of p in a Set. Walk q's parent chain until a node is in the set. No recursion; extra map of n parents.

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_map<TreeNode*, TreeNode*> parent;
    parent[root] = nullptr;
    vector<TreeNode*> stack = {root};
    while (!parent.count(p) || !parent.count(q)) {
        TreeNode* node = stack.back() /* then pop_back */;
        if (node->left) {
            parent[node->left] = node;
            stack.push_back(node->left);
        }
        if (node->right) {
            parent[node->right] = node;
            stack.push_back(node->right);
        }
    }
    unordered_set<TreeNode*> seen;
    TreeNode* cur = p;
    while (cur) {
        seen.insert(cur);
        cur = parent[cur];
    }
    cur = q;
    while (!seen.count(cur)) {
        cur = parent[cur];
    }
    return cur;
}
