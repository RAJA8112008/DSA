// Method 1: Brute
// Time: O(n) | Space: O(h)
// Classic 1 + count(left) + count(right). Ignores the complete-tree promise. Fine for small n.

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

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Method 2: Optimal
// Time: O(log² n) | Space: O(log n)
// Measure leftmost and rightmost depths. If equal, subtree is perfect: (1 << h) - 1. Else 1 + count(left) + count(right). Each level does O(log n) height work.

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

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int lh = 0;
    int rh = 0;
    TreeNode* l = root;
    TreeNode* r = root;
    while (l) {
        lh++;
        l = l->left;
    }
    while (r) {
        rh++;
        r = r->right;
    }
    if (lh == rh) {
        return (1 << lh) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}


// Method 3: More optimal
// Time: O(log² n) | Space: O(1)
// Height of leftmost path, then binary search the last level: exists(index) walks h-1 bits from the root. Count = full upper levels + how many last-level nodes exist. Iterative, O(1) extra besides the tree.

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

int countNodes_leftHeight(TreeNode* node) {
    int h = 0;
    while (node) {
        h++;
        node = node->left;
    }
    return h;
}

bool countNodes_exists(int index, int h, TreeNode* node) {
    int lo = 0;
    int hi = (1 << (h - 1)) - 1;
    for (int i = 0; i < h - 1; i++) {
        TreeNode* mid = ((lo + hi) / 2);
        if (index <= mid) {
            node = node->left;
            hi = mid;
        }
        else {
            node = node->right;
            lo = mid + 1;
        }
    }
    return node;
}

int countNodes(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int h = countNodes_leftHeight(root);
    int lastCount = 1 << (h - 1);
    int lo = 0;
    int hi = lastCount - 1;
    while (lo <= hi) {
        TreeNode* mid = ((lo + hi) / 2);
        if (countNodes_exists(mid, h, root)) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return lastCount - 1 + lo;
}
