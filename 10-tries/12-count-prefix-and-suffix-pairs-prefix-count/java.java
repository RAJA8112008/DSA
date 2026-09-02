// Method 1: Brute
// Time: O(n L) | Space: O(1)
// For each word, compare pref character by character. Count a hit when the whole pref matches.

class Solution {
  public int prefixCount(String[] words, String pref) {
    int c = 0;
    for (String w : words) if (w.startsWith(pref)) c++;
    return c;
  }
}


// Method 2: Optimal
// Time: O(n^2 L) | Space: O(1)
// For the related prefix-and-suffix-pairs problem: try every i < j and test both prefix and suffix. Still brute pairs, but the check is the right idea before a trie of (char, char) pairs.

class Solution {
  boolean isPrefixAndSuffix(String a, String b) {
    return b.startsWith(a) && b.endsWith(a);
  }
  public int countPrefixSuffixPairs(String[] words) {
    int c = 0;
    for (int i = 0; i < words.length; i++)
      for (int j = i + 1; j < words.length; j++)
        if (isPrefixAndSuffix(words[i], words[j])) c++;
    return c;
  }
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Prefix count: insert every word into a trie, increment pref on each node, then walk pref once. For prefix-and-suffix pairs, a twin trie on (first char, last char) pairs is the upgrade when n is large.

class Solution {
  static class Node {
    Node[] ch = new Node[26];
    int pref;
  }
  public int prefixCount(String[] words, String pref) {
    Node root = new Node();
    for (String w : words) {
      Node cur = root;
      for (int j = 0; j < w.length(); j++) {
        int idx = w.charAt(j) - 'a';
        if (cur.ch[idx] == null) cur.ch[idx] = new Node();
        cur = cur.ch[idx];
        cur.pref++;
      }
    }
    Node cur = root;
    for (int j = 0; j < pref.length(); j++) {
      int idx = pref.charAt(j) - 'a';
      if (cur.ch[idx] == null) return 0;
      cur = cur.ch[idx];
    }
    return cur.pref;
  }
}
