// Method 1: Brute
// Time: O(n) | Space: O(w)
// BFS. Width of a level is the queue size (actual nodes). Max over levels. Matches GFG's non-null count.

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

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int best = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = (int)q.size();
        best = max(best, n);
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front(); q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(w)
// LeetCode width: BFS with heap indices. Subtract the first index of the level so numbers stay small. Width = last - first + 1.

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

int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    int best = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    while (!q.empty()) {
        int n = (int)q.size();
        unsigned long long first = q.front().second, last = first;
        for (int i = 0; i < n; i++) {
            auto [node, idx] = q.front(); q.pop();
            idx -= first;
            last = idx;
            if (node->left) q.push({node->left, idx * 2 + 1});
            if (node->right) q.push({node->right, idx * 2 + 2});
        }
        best = max(best, (int)last + 1);
    }
    return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with (depth, normalized index). Store the first index seen at each depth. Width = idx - first[depth] + 1. Recursion only.

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

void goW(TreeNode* node, int d, unsigned long long idx, vector<unsigned long long>& first, int& best) {
    if (!node) return;
    if (d == (int)first.size()) first.push_back(idx);
    unsigned long long pos = idx - first[d];
    best = max(best, (int)pos + 1);
    goW(node->left, d + 1, pos * 2 + 1, first, best);
    goW(node->right, d + 1, pos * 2 + 2, first, best);
}
int widthOfBinaryTree(TreeNode* root) {
    vector<unsigned long long> first;
    int best = 0;
    goW(root, 0, 0, first, best);
    return best;
}
