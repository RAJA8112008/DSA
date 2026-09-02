// Method 1: Brute
// Time: O(words * roots * L) | Space: O(1) extra
// For each sentence word, scan every root and keep the shortest one that is a prefix. Easy to write, quadratic in dictionary size.

class Solution {
  public String replaceWords(List<String> dictionary, String sentence) {
    String[] words = sentence.split(" ");
    for (int i = 0; i < words.length; i++) {
      String w = words[i], best = w;
      for (String r : dictionary) {
        if (w.startsWith(r) && r.length() < best.length()) best = r;
      }
      words[i] = best;
    }
    return String.join(" ", words);
  }
}


// Method 2: Optimal
// Time: O(total chars) | Space: O(roots)
// Put roots in a set. For each word, try prefixes from length 1 up and take the first hit. That is the shortest root. Faster when few prefixes match.

import java.util.*;
class Solution {
  public String replaceWords(List<String> dictionary, String sentence) {
    Set<String> set = new HashSet<String>(dictionary);
    String[] words = sentence.split(" ");
    for (int i = 0; i < words.length; i++) {
      String w = words[i];
      for (int L = 1; L <= w.length(); L++) {
        String p = w.substring(0, L);
        if (set.contains(p)) { words[i] = p; break; }
      }
    }
    return String.join(" ", words);
  }
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(roots)
// Trie of roots. Walk each sentence word until you hit an end flag, then stop. Shared prefixes make this the usual interview answer.

class Solution {
  static class Node {
    Node[] ch = new Node[26];
    boolean end;
  }
  public String replaceWords(List<String> dictionary, String sentence) {
    Node root = new Node();
    for (String r : dictionary) {
      Node cur = root;
      for (int j = 0; j < r.length(); j++) {
        int idx = r.charAt(j) - 'a';
        if (cur.ch[idx] == null) cur.ch[idx] = new Node();
        cur = cur.ch[idx];
      }
      cur.end = true;
    }
    String[] words = sentence.split(" ");
    for (int i = 0; i < words.length; i++) {
      String w = words[i];
      Node cur = root;
      StringBuilder built = new StringBuilder();
      for (int j = 0; j < w.length(); j++) {
        int idx = w.charAt(j) - 'a';
        if (cur.ch[idx] == null) break;
        cur = cur.ch[idx];
        built.append(w.charAt(j));
        if (cur.end) { words[i] = built.toString(); break; }
      }
    }
    return String.join(" ", words);
  }
}
