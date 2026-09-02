// Method 1: Brute
// Time: O(n) | Space: O(n)
// Collect all nodes with (isLeft, isRight, isLeaf). Then emit left bound, leaves, reverse right bound, skipping duplicates via a seen set.

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

bool isLeaf(TreeNode* n) { return n && !n->left && !n->right; }
void goBound(TreeNode* node, bool onLeft, bool onRight, vector<int>& leftB, vector<int>& rightB, vector<int>& leaves) {
    if (!node) return;
    if (isLeaf(node)) { leaves.push_back(node->val); return; }
    if (onLeft) leftB.push_back(node->val);
    else if (onRight) rightB.push_back(node->val);
    goBound(node->left, onLeft, onRight && !node->right, leftB, rightB, leaves);
    goBound(node->right, onLeft && !node->left, onRight, leftB, rightB, leaves);
}
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> leftB, rightB, leaves;
    if (!root) return leftB;
    if (!isLeaf(root)) leftB.push_back(root->val);
    goBound(root->left, true, false, leftB, rightB, leaves);
    goBound(root->right, false, true, leftB, rightB, leaves);
    if (isLeaf(root)) leaves.push_back(root->val);
    reverse(rightB.begin(), rightB.end());
    leftB.insert(leftB.end(), leaves.begin(), leaves.end());
    leftB.insert(leftB.end(), rightB.begin(), rightB.end());
    return leftB;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Three passes: left edge (stop before a leaf), all leaves, right edge into a stack then pop. Clear and classic interview split.

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

bool isLeafN(TreeNode* n) { return !n->left && !n->right; }
void leaves(TreeNode* node, vector<int>& out) {
    if (!node) return;
    if (isLeafN(node)) { out.push_back(node->val); return; }
    leaves(node->left, out);
    leaves(node->right, out);
}
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    if (!isLeafN(root)) out.push_back(root->val);
    TreeNode* cur = root->left;
    while (cur) {
        if (!isLeafN(cur)) out.push_back(cur->val);
        cur = cur->left ? cur->left : cur->right;
    }
    leaves(root, out);
    vector<int> right;
    cur = root->right;
    while (cur) {
        if (!isLeafN(cur)) right.push_back(cur->val);
        cur = cur->right ? cur->right : cur->left;
    }
    while (!right.empty()) { out.push_back(right.back()); right.pop_back(); }
    return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// One DFS. Pass whether this node is on the left bound, right bound, or a leaf. Append left-bound before children, leaves in the middle, right-bound after children (so they reverse themselves).

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

bool isLeafN(TreeNode* n) { return !n->left && !n->right; }
void goBound2(TreeNode* node, bool leftB, bool rightB, vector<int>& out) {
    if (!node) return;
    if (isLeafN(node) || leftB) out.push_back(node->val);
    goBound2(node->left, leftB, rightB && !node->right, out);
    goBound2(node->right, leftB && !node->left, rightB, out);
    if (rightB && !isLeafN(node) && !leftB) out.push_back(node->val);
}
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> out;
    if (!root) return out;
    if (isLeafN(root)) { out.push_back(root->val); return out; }
    out.push_back(root->val);
    goBound2(root->left, true, false, out);
    goBound2(root->right, false, true, out);
    return out;
}
