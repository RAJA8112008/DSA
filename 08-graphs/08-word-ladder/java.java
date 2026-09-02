// Method 1: Brute
// Time: O(26^L · n) | Space: O(n·L)
// DFS with a copied remaining-word set at every step. It can walk long dead paths before it finds the short ladder. Exponential in ladder length.

import java.util.*;
class Solution {
  int best;
  void dfs(String word, int dist, Set<String> left, String endWord) {
    if (dist >= best) return;
    if (word.equals(endWord)) { best = dist; return; }
    char[] arr = word.toCharArray();
    for (int i = 0; i < arr.length; i++) {
      char old = arr[i];
      for (char c = 'a'; c <= 'z'; c++) {
        arr[i] = c;
        String next = new String(arr);
        if (!left.contains(next)) continue;
        Set<String> copy = new HashSet<String>(left);
        copy.remove(next);
        dfs(next, dist+1, copy, endWord);
      }
      arr[i] = old;
    }
  }
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> words = new HashSet<String>(wordList);
    if (!words.contains(endWord)) return 0;
    best = Integer.MAX_VALUE;
    dfs(beginWord, 1, words, endWord);
    return best == Integer.MAX_VALUE ? 0 : best;
  }
}


// Method 2: Optimal
// Time: O(n·L·26) | Space: O(n·L)
// BFS from beginWord. Each word is enqueued once. Trying 26 letters at each index is the usual neighbor generator. First time you hit endWord is the shortest length.

import java.util.*;
class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> words = new HashSet<String>(wordList);
    if (!words.contains(endWord)) return 0;
    ArrayDeque<String> q = new ArrayDeque<String>();
    ArrayDeque<Integer> d = new ArrayDeque<Integer>();
    q.addLast(beginWord); d.addLast(1);
    words.remove(beginWord);
    while (!q.isEmpty()) {
      String word = q.pollFirst(); int dist = d.pollFirst();
      if (word.equals(endWord)) return dist;
      char[] arr = word.toCharArray();
      for (int i = 0; i < arr.length; i++) {
        char old = arr[i];
        for (char c = 'a'; c <= 'z'; c++) {
          arr[i] = c;
          String next = new String(arr);
          if (!words.contains(next)) continue;
          words.remove(next);
          q.addLast(next); d.addLast(dist+1);
        }
        arr[i] = old;
      }
    }
    return 0;
  }
}


// Method 3: More optimal
// Time: O(n·L·26) | Space: O(n·L)
// Bidirectional BFS. Expand the smaller frontier each round. When a candidate sits in the other set, the two searches met. Branching is cut roughly in half on typical dictionaries.

import java.util.*;
class Solution {
  public int ladderLength(String beginWord, String endWord, List<String> wordList) {
    Set<String> words = new HashSet<String>(wordList);
    if (!words.contains(endWord)) return 0;
    Set<String> begin = new HashSet<String>(), end = new HashSet<String>(), seen = new HashSet<String>();
    begin.add(beginWord); end.add(endWord); seen.add(beginWord); seen.add(endWord);
    int steps = 1;
    while (!begin.isEmpty() && !end.isEmpty()) {
      if (begin.size() > end.size()) { Set<String> tmp=begin; begin=end; end=tmp; }
      Set<String> next = new HashSet<String>();
      for (String word : begin) {
        char[] arr = word.toCharArray();
        for (int i = 0; i < arr.length; i++) {
          char old = arr[i];
          for (char c = 'a'; c <= 'z'; c++) {
            arr[i] = c;
            String cand = new String(arr);
            if (end.contains(cand)) return steps + 1;
            if (!words.contains(cand) || seen.contains(cand)) continue;
            seen.add(cand); next.add(cand);
          }
          arr[i] = old;
        }
      }
      begin = next; steps++;
    }
    return 0;
  }
}
