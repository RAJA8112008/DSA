// Method 1: Brute
// Time: O(n^2 L) | Space: O(n)
// Put words in a set. For each word, test that every prefix is in the set. Keep the longest, breaking ties lexicographically.

import java.util.*;
class Solution {
  public String longestWord(String[] words) {
    Set<String> set = new HashSet<String>(Arrays.asList(words));
    String best = "";
    for (String w : words) {
      boolean ok = true;
      for (int L = 1; L < w.length(); L++) {
        if (!set.contains(w.substring(0, L))) { ok = false; break; }
      }
      if (!ok) continue;
      if (w.length() > best.length() || (w.length() == best.length() && w.compareTo(best) < 0)) best = w;
    }
    return best;
  }
}


// Method 2: Optimal
// Time: O(n L log n) | Space: O(n)
// Sort by length then lex. A word is valid if the set already holds word without its last letter (or the word has length 1). Insert only valid words. The last survivor is the answer if you also keep the lex-smallest of that length.

import java.util.*;
class Solution {
  public String longestWord(String[] words) {
    Arrays.sort(words, (a, b) -> a.length() != b.length() ? a.length() - b.length() : a.compareTo(b));
    Set<String> good = new HashSet<String>();
    good.add("");
    String best = "";
    for (String w : words) {
      if (good.contains(w.substring(0, w.length() - 1))) {
        good.add(w);
        if (w.length() > best.length()) best = w;
      }
    }
    return best;
  }
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Insert every word into a trie with an end flag. DFS only through end nodes. The deepest (then lex-smallest) path is the answer.

class Solution {
  static class Node {
    Node[] ch = new Node[26];
    boolean end;
  }
  String best = "";
  void dfs(Node cur, String path) {
    if (!cur.end) return;
    if (path.length() > best.length() || (path.length() == best.length() && path.compareTo(best) < 0)) best = path;
    for (int i = 0; i < 26; i++) if (cur.ch[i] != null) dfs(cur.ch[i], path + (char) ('a' + i));
  }
  public String longestWord(String[] words) {
    Node root = new Node();
    root.end = true;
    for (String w : words) {
      Node cur = root;
      for (int j = 0; j < w.length(); j++) {
        int idx = w.charAt(j) - 'a';
        if (cur.ch[idx] == null) cur.ch[idx] = new Node();
        cur = cur.ch[idx];
      }
      cur.end = true;
    }
    best = "";
    dfs(root, "");
    return best;
  }
}
