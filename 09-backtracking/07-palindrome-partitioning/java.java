// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// At each index you either cut or keep growing the last piece, copying the piece list every time. After a full partition you test every piece. Many illegal cuttings are built first and thrown away.

import java.util.*;
class Solution {
  public List<List<String>> partition(String s) {
    List<List<String>> ans = new ArrayList<List<String>>();
    go(s, 0, new ArrayList<String>(), "", ans);
    return ans;
  }
  boolean isPal(List<String> parts) {
    for (String w : parts) {
      int l = 0, r = w.length() - 1;
      while (l < r) { if (w.charAt(l) != w.charAt(r)) return false; l++; r--; }
    }
    return true;
  }
  void go(String s, int i, List<String> parts, String cur, List<List<String>> ans) {
    if (i == s.length()) {
      List<String> all = new ArrayList<String>(parts);
      if (cur.length() > 0) all.add(cur);
      if (isPal(all)) ans.add(all);
      return;
    }
    go(s, i + 1, new ArrayList<String>(parts), cur + s.charAt(i), ans);
    if (cur.length() > 0) {
      List<String> cut = new ArrayList<String>(parts);
      cut.add(cur);
      go(s, i, cut, "", ans);
    }
  }
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// From start, try every end. If s[start..end] is a palindrome, push it, recurse end+1, pop. Illegal prefixes never grow. Copy only at the end of s.

import java.util.*;
class Solution {
  public List<List<String>> partition(String s) {
    List<List<String>> ans = new ArrayList<List<String>>();
    go(s, 0, new ArrayList<String>(), ans);
    return ans;
  }
  boolean isPal(String s, int l, int r) {
    while (l < r) { if (s.charAt(l) != s.charAt(r)) return false; l++; r--; }
    return true;
  }
  void go(String s, int start, List<String> path, List<List<String>> ans) {
    if (start == s.length()) { ans.add(new ArrayList<String>(path)); return; }
    for (int end = start; end < s.length(); end++) {
      if (!isPal(s, start, end)) continue;
      path.add(s.substring(start, end + 1));
      go(s, end + 1, path, ans);
      path.remove(path.size() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n^2)
// pal[l][r] is true if s[l..r] is a palindrome. Fill in O(n^2). Each cut check is then O(1). Same 2^n cuttings, cheaper work per node.

import java.util.*;
class Solution {
  public List<List<String>> partition(String s) {
    int n = s.length();
    boolean[][] pal = new boolean[n][n];
    for (int i = 0; i < n; i++) pal[i][i] = true;
    for (int i = 0; i < n - 1; i++) pal[i][i + 1] = s.charAt(i) == s.charAt(i + 1);
    for (int len = 3; len <= n; len++) {
      for (int l = 0; l + len - 1 < n; l++) {
        int r = l + len - 1;
        pal[l][r] = s.charAt(l) == s.charAt(r) && pal[l + 1][r - 1];
      }
    }
    List<List<String>> ans = new ArrayList<List<String>>();
    go(s, 0, pal, new ArrayList<String>(), ans);
    return ans;
  }
  void go(String s, int start, boolean[][] pal, List<String> path, List<List<String>> ans) {
    if (start == s.length()) { ans.add(new ArrayList<String>(path)); return; }
    for (int end = start; end < s.length(); end++) {
      if (!pal[start][end]) continue;
      path.add(s.substring(start, end + 1));
      go(s, end + 1, pal, path, ans);
      path.remove(path.size() - 1);
    }
  }
}
