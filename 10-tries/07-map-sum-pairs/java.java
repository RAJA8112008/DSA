// Method 1: Brute
// Time: O(n L) sum | Space: O(n L)
// A plain key -> val map. sum walks every key and adds val when the key starts with the prefix.

import java.util.*;
class MapSum {
  Map<String, Integer> map = new HashMap<String, Integer>();
  public void insert(String key, int val) { map.put(key, val); }
  public int sum(String prefix) {
    int s = 0;
    for (Map.Entry<String, Integer> e : map.entrySet()) {
      if (e.getKey().startsWith(prefix)) s += e.getValue();
    }
    return s;
  }
}


// Method 2: Optimal
// Time: O(L) insert and sum | Space: O(n L)
// Keep the latest val per key. On insert, delta = newVal - oldVal. Add delta to every prefix string of the key in a second map. sum is then one lookup.

import java.util.*;
class MapSum {
  Map<String, Integer> val = new HashMap<String, Integer>();
  Map<String, Integer> pref = new HashMap<String, Integer>();
  public void insert(String key, int v) {
    int old = val.getOrDefault(key, 0);
    int delta = v - old;
    val.put(key, v);
    StringBuilder p = new StringBuilder();
    for (int i = 0; i < key.length(); i++) {
      p.append(key.charAt(i));
      String s = p.toString();
      pref.put(s, pref.getOrDefault(s, 0) + delta);
    }
  }
  public int sum(String prefix) { return pref.getOrDefault(prefix, 0); }
}


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Trie node holds a running sum of values that pass through it. insert adds the delta along the path. sum walks the prefix and returns that node's sum.

import java.util.*;
class MapSum {
  static class Node {
    Node[] ch = new Node[26];
    int sum;
  }
  Node root = new Node();
  Map<String, Integer> val = new HashMap<String, Integer>();
  public void insert(String key, int v) {
    int delta = v - val.getOrDefault(key, 0);
    val.put(key, v);
    Node cur = root;
    for (int i = 0; i < key.length(); i++) {
      int idx = key.charAt(i) - 'a';
      if (cur.ch[idx] == null) cur.ch[idx] = new Node();
      cur = cur.ch[idx];
      cur.sum += delta;
    }
  }
  public int sum(String prefix) {
    Node cur = root;
    for (int i = 0; i < prefix.length(); i++) {
      int idx = prefix.charAt(i) - 'a';
      if (cur.ch[idx] == null) return 0;
      cur = cur.ch[idx];
    }
    return cur.sum;
  }
}
