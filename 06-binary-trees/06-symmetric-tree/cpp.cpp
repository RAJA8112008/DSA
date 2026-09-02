// Method 1: Brute
// Time: O(n) | Space: O(n)
// Encode the left subtree left-to-right with nulls, encode the right subtree right-to-left with nulls, compare. Extra arrays.

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

bool isSymmetric_enc(TreeNode* node, bool leftFirst, vector<string>& out) {
    if (!node) {
        out.push_back("N");
        return;
    }
    out.push_back(to_string(node->val));
    if (leftFirst) {
        isSymmetric_enc(node->left, true, out);
        isSymmetric_enc(node->right, true, out);
    }
    else {
        isSymmetric_enc(node->right, false, out);
        isSymmetric_enc(node->left, false, out);
    }
}

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    vector<TreeNode*> a;
    vector<TreeNode*> b;
    isSymmetric_enc(root->left, true, a);
    isSymmetric_enc(root->right, false, b);
    if (a.size() != b.size()) {
        return false;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// mirror(a,b): both null ok; one null fail; vals equal and mirror(a.left,b.right) and mirror(a.right,b.left). Recurse from root.left and root.right.

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

bool isSymmetric_mirror(TreeNode* a, TreeNode* b) {
    if (!a && !b) {
        return true;
    }
    if (!a || !b || a->val != b->val) {
        return false;
    }
    return isSymmetric_mirror(a->left, b->right) && isSymmetric_mirror(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return isSymmetric_mirror(root->left, root->right);
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// Queue of node pairs. Dequeue a and b, check, enqueue a.left with b.right and a.right with b.left. Iterative mirror test.

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

bool isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    vector<TreeNode*> queue = {root->left, root->right};
    while (queue.size()) {
        TreeNode* a = queue.front() /* erase begin */;
        TreeNode* b = queue.front() /* erase begin */;
        if (!a && !b) {
            continue;
        }
        if (!a || !b || a->val != b->val) {
            return false;
        }
        queue.push_back(a->left, b->right);
        queue.push_back(a->right, b->left);
    }
    return true;
}
