// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep a list. For each stored word of the same length, compare char by char and treat '.' as a free pass. Simple and slow when the dictionary is large.

import java.util.*;
class WordDictionary {
  List<String> words = new ArrayList<String>();
  public void addWord(String word) { words.add(word); }
  public boolean search(String word) {
    int n = word.length();
    for (String w : words) {
      if (w.length() != n) continue;
      boolean ok = true;
      for (int j = 0; j < n; j++) {
        char c = word.charAt(j);
        if (c != '.' && c != w.charAt(j)) { ok = false; break; }
      }
      if (ok) return true;
    }
    return false;
  }
}


// Method 2: Optimal
// Time: O(k L) | Space: O(n L)
// Bucket words by length so a pattern of length L only scans that bucket. Still linear in the bucket size, but you skip obviously impossible words.

import java.util.*;
class WordDictionary {
  Map<Integer, List<String>> byLen = new HashMap<Integer, List<String>>();
  public void addWord(String word) {
    byLen.computeIfAbsent(word.length(), k -> new ArrayList<String>()).add(word);
  }
  public boolean search(String word) {
    List<String> list = byLen.getOrDefault(word.length(), Collections.emptyList());
    int n = word.length();
    for (String w : list) {
      boolean ok = true;
      for (int j = 0; j < n; j++) {
        char c = word.charAt(j);
        if (c != '.' && c != w.charAt(j)) { ok = false; break; }
      }
      if (ok) return true;
    }
    return false;
  }
}


// Method 3: More optimal
// Time: O(26^d L) | Space: O(n L)
// Trie DFS. A letter follows one child. A '.' tries every living child. d is the number of dots. This is the expected design.

class WordDictionary {
  static class Node {
    Node[] ch = new Node[26];
    boolean end;
  }
  Node root = new Node();
  public void addWord(String word) {
    Node cur = root;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      if (cur.ch[idx] == null) cur.ch[idx] = new Node();
      cur = cur.ch[idx];
    }
    cur.end = true;
  }
  boolean dfs(Node node, String word, int i) {
    if (node == null) return false;
    if (i == word.length()) return node.end;
    char c = word.charAt(i);
    if (c == '.') {
      for (int k = 0; k < 26; k++) if (dfs(node.ch[k], word, i + 1)) return true;
      return false;
    }
    return dfs(node.ch[c - 'a'], word, i + 1);
  }
  public boolean search(String word) { return dfs(root, word, 0); }
}
