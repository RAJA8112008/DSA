// Method 1: Brute
// Time: O(n^2 L) | Space: O(1)
// For every ordered pair, concatenate and test palindrome. Fine for tiny n, not for n = 5000.

import java.util.*;
class Solution {
  boolean isPal(String s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
      if (s.charAt(i) != s.charAt(j)) return false;
      i++; j--;
    }
    return true;
  }
  public List<List<Integer>> palindromePairs(String[] words) {
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    int n = words.length;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (i != j && isPal(words[i] + words[j]))
          out.add(Arrays.asList(i, j));
    return out;
  }
}


// Method 2: Optimal
// Time: O(n L^2) | Space: O(n L)
// Map word -> index. For each word, try every split. If the left half is a palindrome, look up reverse(right). If the right half is a palindrome, look up reverse(left). Handles the empty-word case.

import java.util.*;
class Solution {
  boolean isPal(String s, int a, int b) {
    while (a < b) {
      if (s.charAt(a) != s.charAt(b)) return false;
      a++; b--;
    }
    return true;
  }
  public List<List<Integer>> palindromePairs(String[] words) {
    Map<String, Integer> idx = new HashMap<String, Integer>();
    for (int i = 0; i < words.length; i++) idx.put(words[i], i);
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    Set<String> seen = new HashSet<String>();
    for (int i = 0; i < words.length; i++) {
      String w = words[i];
      int n = w.length();
      for (int cut = 0; cut <= n; cut++) {
        if (isPal(w, cut, n - 1)) {
          String rev = new StringBuilder(w.substring(0, cut)).reverse().toString();
          if (idx.containsKey(rev)) {
            int j = idx.get(rev);
            String key = i + "," + j;
            if (i != j && seen.add(key)) out.add(Arrays.asList(i, j));
          }
        }
        if (cut > 0 && isPal(w, 0, cut - 1)) {
          String rev = new StringBuilder(w.substring(cut)).reverse().toString();
          if (idx.containsKey(rev)) {
            int j = idx.get(rev);
            String key = j + "," + i;
            if (i != j && seen.add(key)) out.add(Arrays.asList(j, i));
          }
        }
      }
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(n L^2) | Space: O(n L)
// Insert the reverse of every word into a trie, storing the index at the end. While walking a word, if the remaining suffix is a palindrome and the node is an end, you have a pair. Also collect end indexes whose leftover reverse is a palindrome. Same complexity, trie picture.

import java.util.*;
class Solution {
  static class Node {
    Map<Character, Node> ch = new HashMap<Character, Node>();
    int idx = -1;
    List<Integer> palBelow = new ArrayList<Integer>();
  }
  boolean isPal(String s, int a, int b) {
    while (a < b) {
      if (s.charAt(a) != s.charAt(b)) return false;
      a++; b--;
    }
    return true;
  }
  public List<List<Integer>> palindromePairs(String[] words) {
    Node root = new Node();
    for (int i = 0; i < words.length; i++) {
      String w = words[i];
      Node cur = root;
      for (int j = w.length() - 1; j >= 0; j--) {
        if (isPal(w, 0, j)) cur.palBelow.add(i);
        char c = w.charAt(j);
        cur.ch.putIfAbsent(c, new Node());
        cur = cur.ch.get(c);
      }
      cur.idx = i;
      cur.palBelow.add(i);
    }
    List<List<Integer>> out = new ArrayList<List<Integer>>();
    Set<String> seen = new HashSet<String>();
    for (int i = 0; i < words.length; i++) {
      String w = words[i];
      Node cur = root;
      boolean fell = false;
      for (int k = 0; k < w.length(); k++) {
        if (cur.idx >= 0 && isPal(w, k, w.length() - 1)) {
          String key = i + "," + cur.idx;
          if (i != cur.idx && seen.add(key)) out.add(Arrays.asList(i, cur.idx));
        }
        if (!cur.ch.containsKey(w.charAt(k))) { fell = true; break; }
        cur = cur.ch.get(w.charAt(k));
      }
      if (!fell) {
        for (int j : cur.palBelow) {
          String key = i + "," + j;
          if (i != j && seen.add(key)) out.add(Arrays.asList(i, j));
        }
      }
    }
    return out;
  }
}
