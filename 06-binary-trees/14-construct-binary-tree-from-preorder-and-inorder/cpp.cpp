// Method 1: Brute
// Time: O(n²) | Space: O(n)
// Root is preorder[0]. Scan inorder for it, slice left/right arrays, recurse. Slicing and scanning are O(n) per node.

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

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (!preorder.size()) {
        return nullptr;
    }
    int rootVal = preorder[0];
    TreeNode* root = new TreeNode(rootVal);
    TreeNode* mid = find(inorder.begin(), inorder.end(), rootVal);
    root->left = buildTree(vector<int>(preorder.begin()+1, preorder.begin()+mid + 1), vector<int>(inorder.begin()+0, inorder.begin()+mid));
    root->right = buildTree(vector<int>(preorder.begin()+mid + 1), preorder.begin()+vector<int>(inorder.begin()+mid + 1, inorder.end()));
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// HashMap of inorder indexes. Recurse with (preL, preR, inL, inR) bounds. Each node created once; map lookup O(1).

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

TreeNode* buildTree_build(int preL, int preR, int inL, int inR) {
    if (preL > preR) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[preL]);
    TreeNode* mid = idx[root->val];
    int leftSize = mid - inL;
    root->left = buildTree_build(preL + 1, preL + leftSize, inL, mid - 1);
    root->right = buildTree_build(preL + leftSize + 1, preR, mid + 1, inR);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int,int> idx;
    for (int i = 0; i < inorder.size(); i++) {
        idx[inorder[i]] = i;
    }
    return buildTree_build(0, preorder.size() - 1, 0, inorder.size() - 1);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Advance a preorder index and an inorder index. build(stop) creates a node, builds left until inorder hits this val, then right until stop. No hashmap; O(h) stack only besides the tree.

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

TreeNode* buildTree_build(int stop) {
    if (p >= preorder.size()) {
        return nullptr;
    }
    if (inorder[i] == stop) {
        i++;
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[p++]);
    root->left = buildTree_build(root->val);
    root->right = buildTree_build(stop);
    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* p = 0;
    int i = 0;
    return buildTree_build();
}
