// Method 1: Brute
// Time: O(n²) | Space: O(h)
// For each node, DFS the rest of the tree looking for k - val. Nested walks. No extra set.

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

bool existsSkip(TreeNode* node, TreeNode* skip, int val) {
    if (!node) return false;
    if (node != skip && node->val == val) return true;
    return existsSkip(node->left, skip, val) || existsSkip(node->right, skip, val);
}
bool goFind(TreeNode* root, TreeNode* node, int k) {
    if (!node) return false;
    if (existsSkip(root, node, k - node->val)) return true;
    return goFind(root, node->left, k) || goFind(root, node->right, k);
}
bool findTarget(TreeNode* root, int k) { return goFind(root, root, k); }


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Hash set of visited values. DFS: if k - val is in the set, done; else add val and continue. Works on any binary tree.

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

bool findTarget(TreeNode* root, int k) {
    unordered_set<int> seen;
    function<bool(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return false;
        if (seen.count(k - node->val)) return true;
        seen.insert(node->val);
        return go(node->left) || go(node->right);
    };
    return go(root);
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Inorder array is sorted. Two pointers from both ends. Uses the BST. Space is still linear for the array; two iterators would drop it to O(h).

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

bool findTarget(TreeNode* root, int k) {
    vector<int> vals;
    function<void(TreeNode*)> go = [&](TreeNode* node) {
        if (!node) return;
        go(node->left);
        vals.push_back(node->val);
        go(node->right);
    };
    go(root);
    int i = 0, j = (int)vals.size() - 1;
    while (i < j) {
        int s = vals[i] + vals[j];
        if (s == k) return true;
        if (s < k) i++;
        else j--;
    }
    return false;
}
