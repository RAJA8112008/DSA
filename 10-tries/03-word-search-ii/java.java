// Method 1: Brute
// Time: O(w m n 4^L) | Space: O(L)
// For each word, DFS from every cell. Mark the cell, try four neighbors, unmark. Correct, but you restart the whole board for every dictionary word.

import java.util.*;
class Solution {
  int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
  boolean dfs(char[][] board, int r, int c, int k, String word) {
    if (k == word.length()) return true;
    if (r < 0 || c < 0 || r >= board.length || c >= board[0].length) return false;
    if (board[r][c] != word.charAt(k)) return false;
    char saved = board[r][c];
    board[r][c] = '#';
    for (int[] d : dirs) {
      if (dfs(board, r + d[0], c + d[1], k + 1, word)) {
        board[r][c] = saved;
        return true;
      }
    }
    board[r][c] = saved;
    return false;
  }
  public List<String> findWords(char[][] board, String[] words) {
    List<String> out = new ArrayList<String>();
    for (String word : words) {
      boolean found = false;
      for (int r = 0; r < board.length && !found; r++)
        for (int c = 0; c < board[0].length && !found; c++)
          if (dfs(board, r, c, 0, word)) found = true;
      if (found) out.add(word);
    }
    return out;
  }
}


// Method 2: Optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Build a trie of all words, then DFS from every cell following only living children. One board walk instead of one walk per word.

import java.util.*;
class Solution {
  static class Node {
    Node[] ch = new Node[26];
    boolean end;
    String word = "";
  }
  int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
  void dfs(char[][] board, int r, int c, Node cur, Set<String> seen, List<String> out) {
    if (r < 0 || c < 0 || r >= board.length || c >= board[0].length) return;
    char ch = board[r][c];
    if (ch == '#') return;
    Node nxt = cur.ch[ch - 'a'];
    if (nxt == null) return;
    if (nxt.end && seen.add(nxt.word)) out.add(nxt.word);
    board[r][c] = '#';
    for (int[] d : dirs) dfs(board, r + d[0], c + d[1], nxt, seen, out);
    board[r][c] = ch;
  }
  public List<String> findWords(char[][] board, String[] words) {
    Node root = new Node();
    for (String s : words) {
      Node cur = root;
      for (int i = 0; i < s.length(); i++) {
        int idx = s.charAt(i) - 'a';
        if (cur.ch[idx] == null) cur.ch[idx] = new Node();
        cur = cur.ch[idx];
      }
      cur.end = true;
      cur.word = s;
    }
    Set<String> seen = new HashSet<String>();
    List<String> out = new ArrayList<String>();
    for (int r = 0; r < board.length; r++)
      for (int c = 0; c < board[0].length; c++)
        dfs(board, r, c, root, seen, out);
    return out;
  }
}


// Method 3: More optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Same trie DFS, but after you emit a word you clear that end mark (and optionally prune empty children). That stops duplicate work and extra copies of the same word.

import java.util.*;
class Solution {
  static class Node {
    Map<Character, Node> ch = new HashMap<Character, Node>();
    String word;
  }
  int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};
  void dfs(char[][] board, int r, int c, Node cur, List<String> out) {
    char ch = board[r][c];
    Node nxt = cur.ch.get(ch);
    if (nxt == null) return;
    if (nxt.word != null) { out.add(nxt.word); nxt.word = null; }
    board[r][c] = '#';
    for (int[] d : dirs) {
      int nr = r + d[0], nc = c + d[1];
      if (nr < 0 || nc < 0 || nr >= board.length || nc >= board[0].length) continue;
      if (board[nr][nc] == '#') continue;
      dfs(board, nr, nc, nxt, out);
    }
    board[r][c] = ch;
  }
  public List<String> findWords(char[][] board, String[] words) {
    Node root = new Node();
    for (String s : words) {
      Node cur = root;
      for (int i = 0; i < s.length(); i++) {
        char ch = s.charAt(i);
        cur.ch.putIfAbsent(ch, new Node());
        cur = cur.ch.get(ch);
      }
      cur.word = s;
    }
    List<String> out = new ArrayList<String>();
    for (int r = 0; r < board.length; r++)
      for (int c = 0; c < board[0].length; c++)
        dfs(board, r, c, root, out);
    return out;
  }
}
