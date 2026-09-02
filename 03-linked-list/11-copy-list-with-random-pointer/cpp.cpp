// Method 1: Brute
// Time: O(n) | Space: O(n)
// First pass: clone every node into a Map, next and random left null. Second pass: wire next and random through the map. Two walks, extra map of n nodes.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node* next, Node* random) : val(x), next(next), random(random) {}
};

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> map;
    Node* cur = head;
    while (cur) {
        map[cur] = new Node(cur->val);
        cur = cur->next;
    }
    cur = head;
    while (cur) {
        Node* copy = map[cur];
        copy->next = cur->next ? map[cur->next] : nullptr;
        copy->random = cur->random ? map[cur->random] : nullptr;
        cur = cur->next;
    }
    return head ? map[head] : nullptr;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One recursive walk with a Map. If the node is already cloned, return it (handles random cycles). Otherwise clone, then fill next and random. Still O(n) extra map plus stack.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node* next, Node* random) : val(x), next(next), random(random) {}
};

Node* copyRandomList_copy(Node* node) {
    if (!node) {
        return nullptr;
    }
    if (map.count(node)) {
        return map[node];
    }
    Node* cloned = new Node(node->val);
    map[node] = cloned;
    cloned->next = copyRandomList_copy(node->next);
    cloned->random = copyRandomList_copy(node->random);
    return cloned;
}

Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> map;
    return copyRandomList_copy(head);
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Weave: original -> copy -> original.next. Set copy.random from original.random.next. Unweave into two lists. Extra space is the copies themselves, no hash map. (O(1) auxiliary.)

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(nullptr), random(nullptr) {}
    Node(int x, Node* next, Node* random) : val(x), next(next), random(random) {}
};

Node* copyRandomList(Node* head) {
    if (!head) {
        return nullptr;
    }
    Node* cur = head;
    while (cur) {
        Node* copy = new Node(cur->val, cur->next, nullptr);
        cur->next = copy;
        cur = copy->next;
    }
    cur = head;
    while (cur) {
        if (cur->random) {
            cur->next.random = cur->random.next;
        }
        cur = cur->next.next;
    }
    Node* newHead = head->next;
    cur = head;
    while (cur) {
        Node* copy = cur->next;
        cur->next = copy->next;
        copy->next = copy->next ? copy->next.next : nullptr;
        cur = cur->next;
    }
    return newHead;
}
