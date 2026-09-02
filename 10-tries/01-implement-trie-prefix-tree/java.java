// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep every inserted string in an array. search and startsWith scan the whole list. Correct, and fine for tiny dictionaries, but not the point of the problem.

import java.util.*;
class Trie {
  List<String> words = new ArrayList<String>();
  public void insert(String word) { words.add(word); }
  public boolean search(String word) {
    for (String w : words) if (w.equals(word)) return true;
    return false;
  }
  public boolean startsWith(String prefix) {
    for (String w : words) if (w.startsWith(prefix)) return true;
    return false;
  }
}


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// A set of full words plus a set of every prefix. Each call is a hash lookup. Extra memory stores every prefix string, which a trie shares instead.

import java.util.*;
class Trie {
  Set<String> words = new HashSet<String>();
  Set<String> prefs = new HashSet<String>();
  public void insert(String word) {
    words.add(word);
    StringBuilder p = new StringBuilder();
    for (int i = 0; i < word.length(); i++) {
      p.append(word.charAt(i));
      prefs.add(p.toString());
    }
  }
  public boolean search(String word) { return words.contains(word); }
  public boolean startsWith(String prefix) { return prefs.contains(prefix); }
}


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Real trie. Shared prefixes share nodes. insert, search, and startsWith each walk L children. This is the expected interview finish.

class Trie {
  static class Node {
    Node[] ch = new Node[26];
    boolean end;
  }
  Node root = new Node();
  public void insert(String word) {
    Node cur = root;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      if (cur.ch[idx] == null) cur.ch[idx] = new Node();
      cur = cur.ch[idx];
    }
    cur.end = true;
  }
  public boolean search(String word) {
    Node cur = root;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      if (cur.ch[idx] == null) return false;
      cur = cur.ch[idx];
    }
    return cur.end;
  }
  public boolean startsWith(String prefix) {
    Node cur = root;
    for (int i = 0; i < prefix.length(); i++) {
      int idx = prefix.charAt(i) - 'a';
      if (cur.ch[idx] == null) return false;
      cur = cur.ch[idx];
    }
    return true;
  }
}
