// Method 1: Brute
// Time: O(n + e) | Space: O(n)
// One shared old-to-new map is required so a node is cloned once. The extra Set copy on every call is wasted; it does not change correctness. Drop the copies and you get Optimal.

class Node {
public:
  int val;
  vector<Node*> neighbors;
  Node(int _val) { val = _val; }
};
class Solution {
  unordered_map<Node*, Node*> mp;
  Node* dfs(Node* cur, unordered_set<Node*> seenCopy) {
    if (mp.count(cur)) return mp[cur];
    Node* copy = new Node(cur->val);
    mp[cur] = copy;
    seenCopy.insert(cur);
    for (Node* nei : cur->neighbors) copy->neighbors.push_back(dfs(nei, seenCopy));
    return copy;
  }
public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    return dfs(node, {});
  }
};


// Method 2: Optimal
// Time: O(n + e) | Space: O(n)
// One Map from old node to new node. DFS creates the clone, then fills neighbors. Each node and edge is processed once.

class Node {
public:
  int val; vector<Node*> neighbors;
  Node(int _val) { val = _val; }
};
class Solution {
  unordered_map<Node*, Node*> mp;
  Node* dfs(Node* cur) {
    if (mp.count(cur)) return mp[cur];
    Node* copy = new Node(cur->val);
    mp[cur] = copy;
    for (Node* nei : cur->neighbors) copy->neighbors.push_back(dfs(nei));
    return copy;
  }
public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    return dfs(node);
  }
};


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// BFS with the same map avoids deep recursion on a long chain. Complexity matches DFS. Prefer this when the graph can be a long path.

class Node {
public:
  int val; vector<Node*> neighbors;
  Node(int _val) { val = _val; }
};
class Solution {
public:
  Node* cloneGraph(Node* node) {
    if (!node) return NULL;
    unordered_map<Node*, Node*> mp;
    mp[node] = new Node(node->val);
    queue<Node*> q; q.push(node);
    while (!q.empty()) {
      Node* cur = q.front(); q.pop();
      Node* copy = mp[cur];
      for (Node* nei : cur->neighbors) {
        if (!mp.count(nei)) { mp[nei] = new Node(nei->val); q.push(nei); }
        copy->neighbors.push_back(mp[nei]);
      }
    }
    return mp[node];
  }
};
