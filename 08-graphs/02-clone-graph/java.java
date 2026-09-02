// Method 1: Brute
// Time: O(n + e) | Space: O(n)
// One shared old-to-new map is required so a node is cloned once. The extra Set copy on every call is wasted; it does not change correctness. Drop the copies and you get Optimal.

import java.util.*;
class Node {
  public int val;
  public List<Node> neighbors;
  public Node(int _val) { val = _val; neighbors = new ArrayList<Node>(); }
}
class Solution {
  Map<Node, Node> map = new HashMap<Node, Node>();
  Node dfs(Node cur, Set<Node> seenCopy) {
    if (map.containsKey(cur)) return map.get(cur);
    Node copy = new Node(cur.val);
    map.put(cur, copy);
    Set<Node> nextSeen = new HashSet<Node>(seenCopy);
    nextSeen.add(cur);
    for (Node nei : cur.neighbors) copy.neighbors.add(dfs(nei, nextSeen));
    return copy;
  }
  public Node cloneGraph(Node node) {
    if (node == null) return null;
    return dfs(node, new HashSet<Node>());
  }
}


// Method 2: Optimal
// Time: O(n + e) | Space: O(n)
// One Map from old node to new node. DFS creates the clone, then fills neighbors. Each node and edge is processed once.

import java.util.*;
class Node {
  public int val; public List<Node> neighbors;
  public Node(int _val) { val = _val; neighbors = new ArrayList<Node>(); }
}
class Solution {
  Map<Node, Node> map = new HashMap<Node, Node>();
  Node dfs(Node cur) {
    if (map.containsKey(cur)) return map.get(cur);
    Node copy = new Node(cur.val);
    map.put(cur, copy);
    for (Node nei : cur.neighbors) copy.neighbors.add(dfs(nei));
    return copy;
  }
  public Node cloneGraph(Node node) {
    if (node == null) return null;
    return dfs(node);
  }
}


// Method 3: More optimal
// Time: O(n + e) | Space: O(n)
// BFS with the same map avoids deep recursion on a long chain. Complexity matches DFS. Prefer this when the graph can be a long path.

import java.util.*;
class Node {
  public int val; public List<Node> neighbors;
  public Node(int _val) { val = _val; neighbors = new ArrayList<Node>(); }
}
class Solution {
  public Node cloneGraph(Node node) {
    if (node == null) return null;
    Map<Node, Node> map = new HashMap<Node, Node>();
    map.put(node, new Node(node.val));
    ArrayDeque<Node> q = new ArrayDeque<Node>();
    q.addLast(node);
    while (!q.isEmpty()) {
      Node cur = q.pollFirst();
      Node copy = map.get(cur);
      for (Node nei : cur.neighbors) {
        if (!map.containsKey(nei)) {
          map.put(nei, new Node(nei.val));
          q.addLast(nei);
        }
        copy.neighbors.add(map.get(nei));
      }
    }
    return map.get(node);
  }
}
