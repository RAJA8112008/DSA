// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order queue. For each level, node.next = the next polled node, last.next = null.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int n = (int)q.size();
        for (int i = 0; i < n; i++) {
            Node* node = q.front(); q.pop();
            if (i + 1 < n) node->next = q.front();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return root;
}


// Method 2: Optimal
// Time: O(n) | Space: O(1)
// On a perfect tree, left.next = right, and right.next = node.next.left. Recurse both children. Uses the next links already set on this level.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root || !root->left) return root;
    root->left->next = root->right;
    if (root->next) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Iterative: leftmost starts at root. Walk the level via next. Wire children, then leftmost = leftmost.left. No recursion, no queue.

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

Node* connect(Node* root) {
    if (!root) return nullptr;
    Node* leftmost = root;
    while (leftmost->left) {
        Node* cur = leftmost;
        while (cur) {
            cur->left->next = cur->right;
            if (cur->next) cur->right->next = cur->next->left;
            cur = cur->next;
        }
        leftmost = leftmost->left;
    }
    return root;
}
