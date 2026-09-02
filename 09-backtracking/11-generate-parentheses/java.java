// Method 1: Brute
// Time: O(n * 2^{2n}) | Space: O(n * 2^{2n})
// Every bit mask is a string of ( and ). You copy the string, then scan it with a balance counter. Most strings fail. Extra copies of every mask.

import java.util.*;
class Solution {
  public List<String> generateParenthesis(int n) {
    List<String> ans = new ArrayList<String>();
    int total = 1 << (2 * n);
    for (int mask = 0; mask < total; mask++) {
      StringBuilder sb = new StringBuilder();
      for (int b = 0; b < 2 * n; b++) sb.append((mask & (1 << b)) != 0 ? '(' : ')');
      String s = sb.toString();
      int bal = 0;
      boolean ok = true;
      for (int i = 0; i < s.length(); i++) {
        bal += s.charAt(i) == '(' ? 1 : -1;
        if (bal < 0) { ok = false; break; }
      }
      if (ok && bal == 0) ans.add(s);
    }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Backtrack with a char buffer. Try '(' and ')' at every length. Still visits some invalid prefixes unless you add the count checks (see More optimal).

import java.util.*;
class Solution {
  public List<String> generateParenthesis(int n) {
    List<String> ans = new ArrayList<String>();
    go(n, new StringBuilder(), ans);
    return ans;
  }
  boolean valid(String s) {
    int bal = 0;
    for (int i = 0; i < s.length(); i++) {
      bal += s.charAt(i) == '(' ? 1 : -1;
      if (bal < 0) return false;
    }
    return bal == 0;
  }
  void go(int n, StringBuilder path, List<String> ans) {
    if (path.length() == 2 * n) {
      String s = path.toString();
      if (valid(s)) ans.add(s);
      return;
    }
    path.append('('); go(n, path, ans); path.deleteCharAt(path.length() - 1);
    path.append(')'); go(n, path, ans); path.deleteCharAt(path.length() - 1);
  }
}


// Method 3: More optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Prune: add '(' only while open < n. Add ')' only while close < open. Leaves are exactly the Catalan number C_n. No invalid prefix is ever built.

import java.util.*;
class Solution {
  public List<String> generateParenthesis(int n) {
    List<String> ans = new ArrayList<String>();
    go(n, 0, 0, new StringBuilder(), ans);
    return ans;
  }
  void go(int n, int open, int close, StringBuilder path, List<String> ans) {
    if (path.length() == 2 * n) { ans.add(path.toString()); return; }
    if (open < n) {
      path.append('(');
      go(n, open + 1, close, path, ans);
      path.deleteCharAt(path.length() - 1);
    }
    if (close < open) {
      path.append(')');
      go(n, open, close + 1, path, ans);
      path.deleteCharAt(path.length() - 1);
    }
  }
}
