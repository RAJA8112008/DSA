// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// An array of words. equalTo counts exact matches. startingWith counts prefix matches. erase removes the first copy.

import java.util.*;
class Trie {
  List<String> words = new ArrayList<String>();
  public void insert(String word) { words.add(word); }
  public int countWordsEqualTo(String word) {
    int c = 0;
    for (String w : words) if (w.equals(word)) c++;
    return c;
  }
  public int countWordsStartingWith(String prefix) {
    int c = 0;
    for (String w : words) if (w.startsWith(prefix)) c++;
    return c;
  }
  public void erase(String word) { words.remove(word); }
}


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// wordCount map and prefixCount map. insert / erase add or subtract 1 along every prefix. Queries are hash lookups. Watch erase: never go below zero.

import java.util.*;
class Trie {
  Map<String, Integer> wordCount = new HashMap<String, Integer>();
  Map<String, Integer> prefCount = new HashMap<String, Integer>();
  public void insert(String word) {
    wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
    StringBuilder p = new StringBuilder();
    for (int i = 0; i < word.length(); i++) {
      p.append(word.charAt(i));
      String s = p.toString();
      prefCount.put(s, prefCount.getOrDefault(s, 0) + 1);
    }
  }
  public int countWordsEqualTo(String word) { return wordCount.getOrDefault(word, 0); }
  public int countWordsStartingWith(String prefix) { return prefCount.getOrDefault(prefix, 0); }
  public void erase(String word) {
    if (wordCount.getOrDefault(word, 0) == 0) return;
    wordCount.put(word, wordCount.get(word) - 1);
    StringBuilder p = new StringBuilder();
    for (int i = 0; i < word.length(); i++) {
      p.append(word.charAt(i));
      String s = p.toString();
      prefCount.put(s, prefCount.get(s) - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(L) | Space: O(total chars) shared
// Trie node has words (how many end here) and pref (how many pass through). insert increments. erase decrements and unlinks a child whose pref hits 0.

class Trie {
  static class Node {
    Node[] ch = new Node[26];
    int words, pref;
  }
  Node root = new Node();
  public void insert(String word) {
    Node cur = root;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      if (cur.ch[idx] == null) cur.ch[idx] = new Node();
      cur = cur.ch[idx];
      cur.pref++;
    }
    cur.words++;
  }
  public int countWordsEqualTo(String word) {
    Node cur = root;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      if (cur.ch[idx] == null) return 0;
      cur = cur.ch[idx];
    }
    return cur.words;
  }
  public int countWordsStartingWith(String prefix) {
    Node cur = root;
    for (int i = 0; i < prefix.length(); i++) {
      int idx = prefix.charAt(i) - 'a';
      if (cur.ch[idx] == null) return 0;
      cur = cur.ch[idx];
    }
    return cur.pref;
  }
  public void erase(String word) {
    if (countWordsEqualTo(word) == 0) return;
    Node cur = root;
    for (int i = 0; i < word.length(); i++) {
      int idx = word.charAt(i) - 'a';
      Node nxt = cur.ch[idx];
      nxt.pref--;
      if (nxt.pref == 0) { cur.ch[idx] = null; return; }
      cur = nxt;
    }
    cur.words--;
  }
}
