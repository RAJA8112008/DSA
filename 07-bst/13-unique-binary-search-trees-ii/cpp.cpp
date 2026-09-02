// Method 1: Brute
// Time: O(n · n!) | Space: O(n · n!)
// Generate every permutation of 1..n, insert into a BST, serialize the shape, keep one copy per unique serialization. Correct but factorial.

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

TreeNode* insertVal(TreeNode* node, int val) {
    if (!node) return new TreeNode(val);
    if (val < node->val) node->left = insertVal(node->left, val);
    else node->right = insertVal(node->right, val);
    return node;
}
TreeNode* cloneT(TreeNode* node) {
    if (!node) return nullptr;
    return new TreeNode(node->val, cloneT(node->left), cloneT(node->right));
}
string serial(TreeNode* node) {
    if (!node) return "#";
    return to_string(node->val) + "," + serial(node->left) + "," + serial(node->right);
}
void permGen(vector<int>& nums, int i, unordered_set<string>& seen, vector<TreeNode*>& out) {
    if (i == (int)nums.size()) {
        TreeNode* root = nullptr;
        for (int v : nums) root = insertVal(root, v);
        string s = serial(root);
        if (!seen.count(s)) { seen.insert(s); out.push_back(cloneT(root)); }
        return;
    }
    for (int j = i; j < (int)nums.size(); j++) {
        swap(nums[i], nums[j]);
        permGen(nums, i + 1, seen, out);
        swap(nums[i], nums[j]);
    }
}
vector<TreeNode*> generateTrees(int n) {
    vector<int> nums(n);
    iota(nums.begin(), nums.end(), 1);
    unordered_set<string> seen;
    vector<TreeNode*> out;
    permGen(nums, 0, seen, out);
    return out;
}


// Method 2: Optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// For each root i in [lo, hi], cartesian product of left trees and right trees. Empty range yields a single null tree so a missing child is represented once.

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

vector<TreeNode*> build(int lo, int hi) {
    vector<TreeNode*> out;
    if (lo > hi) { out.push_back(nullptr); return out; }
    for (int i = lo; i <= hi; i++) {
        auto lefts = build(lo, i - 1);
        auto rights = build(i + 1, hi);
        for (auto* L : lefts) for (auto* R : rights) {
            TreeNode* node = new TreeNode(i);
            node->left = L;
            node->right = R;
            out.push_back(node);
        }
    }
    return out;
}
vector<TreeNode*> generateTrees(int n) {
    if (!n) return {};
    return build(1, n);
}


// Method 3: More optimal
// Time: O(C(n) · n) | Space: O(C(n) · n)
// Memoize [lo, hi]. Shared ranges (for example all trees on 3,4,5) are built once. Catalan many trees still must be allocated.

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

map<pair<int,int>, vector<TreeNode*>> memo;
vector<TreeNode*> build(int lo, int hi) {
    auto key = make_pair(lo, hi);
    if (memo.count(key)) return memo[key];
    vector<TreeNode*> out;
    if (lo > hi) { out.push_back(nullptr); return memo[key] = out; }
    for (int i = lo; i <= hi; i++) {
        auto lefts = build(lo, i - 1);
        auto rights = build(i + 1, hi);
        for (auto* L : lefts) for (auto* R : rights) {
            TreeNode* node = new TreeNode(i);
            node->left = L; node->right = R;
            out.push_back(node);
        }
    }
    return memo[key] = out;
}
vector<TreeNode*> generateTrees(int n) {
    memo.clear();
    if (!n) return {};
    return build(1, n);
}
