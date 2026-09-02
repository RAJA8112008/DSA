// Method 1: Brute
// Time: O(n²) | Space: O(h)
// At each node, maxDown on left and right is computed from scratch, then visit children. Nested tree walks.

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

int maxPathSum_maxDown(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return node->val + std::max(0, maxPathSum_maxDown(node->left), maxPathSum_maxDown(node->right));
}

int maxPathSum_visit(TreeNode* node) {
    if (!node) {
        return;
    }
    TreeNode* left = std::max(0, maxDown(node->left));
    TreeNode* right = std::max(0, maxDown(node->right));
    int through = node->val + left + right;
    if (through > best) {
        best = through;
    }
    maxPathSum_visit(node->left);
    maxPathSum_visit(node->right);
}

int maxPathSum(TreeNode* root) {
    int best = INT_MIN;
    maxPathSum_visit(root);
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// gain(node) = val + max(0, gain(left), gain(right)) for continuing up. Through-node sum updates a boxed best. One DFS.

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

int maxPathSum_gain(TreeNode* node) {
    if (!node) {
        return 0;
    }
    TreeNode* left = std::max(0, maxPathSum_gain(node->left));
    TreeNode* right = std::max(0, maxPathSum_gain(node->right));
    int through = node->val + left + right;
    if (through > best) {
        best = through;
    }
    return node->val + std::max(left, right);
}

int maxPathSum(TreeNode* root) {
    int best = INT_MIN;
    maxPathSum_gain(root);
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Same linear DFS, but dfs returns {gain, best} so there is no outer mutable. Parent combines through, left.best, and right.best. Cleaner to reason about.

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

int maxPathSum_dfs(TreeNode* node) {
    if (!node) {
        return {0, INT_MIN};
    }
    TreeNode* L = maxPathSum_dfs(node->left);
    TreeNode* R = maxPathSum_dfs(node->right);
    TreeNode* left = std::max(0, L.gain);
    TreeNode* right = std::max(0, R.gain);
    int through = node->val + left + right;
    int gain = node->val + std::max(left, right);
    int best = std::max(through, L.best, R.best);
    return {gain, best};
}

int maxPathSum(TreeNode* root) {
    return maxPathSum_dfs(root).best;
}
