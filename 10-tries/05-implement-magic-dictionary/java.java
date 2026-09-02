// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// Store the list. For each stored word of the same length, count mismatches. Return true on a count of exactly 1.

class MagicDictionary {
  String[] words = new String[0];
  public void buildDict(String[] dictionary) { words = dictionary; }
  public boolean search(String searchWord) {
    int n = searchWord.length();
    for (String w : words) {
      if (w.length() != n) continue;
      int diff = 0;
      for (int j = 0; j < n; j++) if (w.charAt(j) != searchWord.charAt(j)) diff++;
      if (diff == 1) return true;
    }
    return false;
  }
}


// Method 2: Optimal
// Time: O(L * 26) | Space: O(n L^2)
// For each word, replace each position with '*' and map that pattern to the original letters. On search, look up each starred query and see if another letter is stored. Handles duplicates carefully.

import java.util.*;
class MagicDictionary {
  Map<String, List<Character>> map = new HashMap<String, List<Character>>();
  public void buildDict(String[] dictionary) {
    map.clear();
    for (String w : dictionary) {
      for (int j = 0; j < w.length(); j++) {
        String key = w.substring(0, j) + "*" + w.substring(j + 1);
        map.computeIfAbsent(key, k -> new ArrayList<Character>()).add(w.charAt(j));
      }
    }
  }
  public boolean search(String searchWord) {
    for (int j = 0; j < searchWord.length(); j++) {
      String key = searchWord.substring(0, j) + "*" + searchWord.substring(j + 1);
      for (char letter : map.getOrDefault(key, Collections.emptyList())) {
        if (letter != searchWord.charAt(j)) return true;
      }
    }
    return false;
  }
}


// Method 3: More optimal
// Time: O(26 L) | Space: O(n L)
// Trie DFS with a leftover mismatch budget of 1. At the end of the query the budget must be 0 (exactly one change). Compact and matches the 'magic' story.

class MagicDictionary {
  static class Node {
    Node[] ch = new Node[26];
    boolean end;
  }
  Node root = new Node();
  public void buildDict(String[] dictionary) {
    root = new Node();
    for (String w : dictionary) {
      Node cur = root;
      for (int j = 0; j < w.length(); j++) {
        int idx = w.charAt(j) - 'a';
        if (cur.ch[idx] == null) cur.ch[idx] = new Node();
        cur = cur.ch[idx];
      }
      cur.end = true;
    }
  }
  boolean dfs(Node node, String q, int i, int left) {
    if (node == null) return false;
    if (i == q.length()) return node.end && left == 0;
    int idx = q.charAt(i) - 'a';
    for (int k = 0; k < 26; k++) {
      int cost = k == idx ? 0 : 1;
      if (left - cost < 0) continue;
      if (dfs(node.ch[k], q, i + 1, left - cost)) return true;
    }
    return false;
  }
  public boolean search(String searchWord) { return dfs(root, searchWord, 0, 1); }
}
