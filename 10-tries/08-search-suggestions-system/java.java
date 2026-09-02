// Method 1: Brute
// Time: O(|s| n L) | Space: O(n)
// After each extra character, scan every product, keep those with the prefix, sort, take 3. Correct and slow.

import java.util.*;
class Solution {
  public List<List<String>> suggestedProducts(String[] products, String searchWord) {
    List<List<String>> out = new ArrayList<List<String>>();
    String pref = "";
    for (int i = 0; i < searchWord.length(); i++) {
      pref += searchWord.charAt(i);
      List<String> hit = new ArrayList<String>();
      for (String p : products) if (p.startsWith(pref)) hit.add(p);
      Collections.sort(hit);
      out.add(hit.subList(0, Math.min(3, hit.size())));
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(n L log n + |s| log n) | Space: O(n)
// Sort products once. For each growing prefix, lower-bound the first product >= prefix, then take the next three if they still share the prefix.

import java.util.*;
class Solution {
  public List<List<String>> suggestedProducts(String[] products, String searchWord) {
    Arrays.sort(products);
    List<List<String>> out = new ArrayList<List<String>>();
    String pref = "";
    for (int i = 0; i < searchWord.length(); i++) {
      pref += searchWord.charAt(i);
      int k = Arrays.binarySearch(products, pref);
      if (k < 0) k = -k - 1;
      List<String> row = new ArrayList<String>();
      for (int t = 0; t < 3 && k + t < products.length; t++) {
        if (products[k + t].startsWith(pref)) row.add(products[k + t]);
      }
      out.add(row);
    }
    return out;
  }
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Trie. At each node keep up to 3 lex-smallest words that pass through it (insert into a sorted short list). Typing searchWord is just walking children and reading that list.

import java.util.*;
class Solution {
  static class Node {
    Node[] ch = new Node[26];
    List<String> sug = new ArrayList<String>();
  }
  void addSug(List<String> list, String w) {
    list.add(w);
    Collections.sort(list);
    if (list.size() > 3) list.remove(list.size() - 1);
  }
  public List<List<String>> suggestedProducts(String[] products, String searchWord) {
    Node root = new Node();
    for (String w : products) {
      Node cur = root;
      for (int j = 0; j < w.length(); j++) {
        int idx = w.charAt(j) - 'a';
        if (cur.ch[idx] == null) cur.ch[idx] = new Node();
        cur = cur.ch[idx];
        addSug(cur.sug, w);
      }
    }
    List<List<String>> out = new ArrayList<List<String>>();
    Node cur = root;
    for (int i = 0; i < searchWord.length(); i++) {
      if (cur != null) cur = cur.ch[searchWord.charAt(i) - 'a'];
      out.add(cur == null ? new ArrayList<String>() : new ArrayList<String>(cur.sug));
    }
    return out;
  }
}
