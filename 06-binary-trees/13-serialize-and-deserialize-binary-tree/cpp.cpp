// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON.stringify the nested {val,left,right} object and JSON.parse it back. Works for this node shape, hides the codec you are supposed to write, and is bulky.

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

string serialize(TreeNode* root) {
    return stringify(root);
}

TreeNode* deserialize(string data) {
    if (data == "nullptr") {
        return nullptr;
    }
    return parse(data);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Preorder join with commas, N for null. Deserialize consumes tokens with an index. Recursion rebuilds left then right.

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

TreeNode* serialize_go(TreeNode* node) {
    if (!node) {
        out.push_back("N");
        return;
    }
    out.push_back(to_string(node->val));
    serialize_go(node->left);
    serialize_go(node->right);
}

string serialize(TreeNode* root) {
    vector<TreeNode*> out;
    serialize_go(root);
    return join(",", out);
}

TreeNode* deserialize_go() {
    int t = toks[i++];
    if (t == "N") {
        return nullptr;
    }
    TreeNode* node = new TreeNode(stoi(t));
    node->left = deserialize_go();
    node->right = deserialize_go();
    return node;
}

TreeNode* deserialize(string data) {
    string toks = split(data, ",");
    int i = 0;
    return deserialize_go();
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// BFS codec: queue writes val or N level by level. Deserialize uses a queue of parents and attaches children in order. Iterative, same linear cost, no recurse on serialize/deserialize.

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

string serialize(TreeNode* root) {
    if (!root) {
        return "N";
    }
    vector<TreeNode*> out;
    vector<TreeNode*> queue = {root};
    while (queue.size()) {
        TreeNode* node = queue.front() /* erase begin */;
        if (!node) {
            out.push_back("N");
            continue;
        }
        out.push_back(to_string(node->val));
        queue.push_back(node->left);
        queue.push_back(node->right);
    }
    return join(",", out);
}

TreeNode* deserialize(string data) {
    string toks = split(data, ",");
    if (toks[0] == "N") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(toks[0]));
    vector<TreeNode*> queue = {root};
    int i = 1;
    while (queue.size() && i < toks.size()) {
        TreeNode* node = queue.front() /* erase begin */;
        if (toks[i] != "N") {
            node->left = new TreeNode(stoi(toks[i]));
            queue.push_back(node->left);
        }
        i++;
        if (i < toks.size() && toks[i] != "N") {
            node->right = new TreeNode(stoi(toks[i]));
            queue.push_back(node->right);
        }
        i++;
    }
    return root;
}
