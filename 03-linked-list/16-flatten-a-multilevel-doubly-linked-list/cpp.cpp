// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS preorder into an array (node, child, next). Then walk the array and set next/prev, clear child. Extra array of every node.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x, Node* prev, Node* next, Node* child) : val(x), prev(prev), next(next), child(child) {}
};

Node* flatten_dfs(Node* node) {
    while (node) {
        nodes.push_back(node);
        if (node->child) {
            flatten_dfs(node->child);
        }
        node = node->next;
    }
}

Node* flatten(Node* head) {
    vector<Node*> nodes;
    flatten_dfs(head);
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i].prev = i == 0 ? nullptr : nodes[i - 1];
        nodes[i].next = i == nodes.size() - 1 ? nullptr : nodes[i + 1];
        nodes[i].child = nullptr;
    }
    return nodes[0] || nullptr;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse: if a node has a child, flatten the child, hang it after the node, find the child's tail, attach the old next. Stack depth follows nesting.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x, Node* prev, Node* next, Node* child) : val(x), prev(prev), next(next), child(child) {}
};

Node* flatten_go(Node* node) {
    Node* cur = node;
    Node* last = node;
    while (cur) {
        Node* next = cur->next;
        if (cur->child) {
            Node* childLast = flatten_go(cur->child);
            cur->next = cur->child;
            cur->child.prev = cur;
            cur->child = nullptr;
            if (childLast) {
                childLast->next = next;
                if (next) {
                    next->prev = childLast;
                }
                last = childLast;
            }
        }
        else {
            last = cur;
        }
        cur = next;
    }
    return last;
}

Node* flatten(Node* head) {
    flatten_go(head);
    return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Walk with one pointer. On a child, find that child's current tail (no recurse), splice the whole child between cur and cur.next, clear child. Then continue. Auxiliary space O(1).

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node* child;
    Node(int x, Node* prev, Node* next, Node* child) : val(x), prev(prev), next(next), child(child) {}
};

Node* flatten(Node* head) {
    Node* cur = head;
    while (cur) {
        if (cur->child) {
            Node* tail = cur->child;
            while (tail->next) {
                tail = tail->next;
            }
            tail->next = cur->next;
            if (cur->next) {
                cur->next.prev = tail;
            }
            cur->next = cur->child;
            cur->child.prev = cur;
            cur->child = nullptr;
        }
        cur = cur->next;
    }
    return head;
}
