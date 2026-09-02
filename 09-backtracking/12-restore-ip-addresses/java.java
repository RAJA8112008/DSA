// Method 1: Brute
// Time: O(n^4) | Space: O(n)
// Three nested cuts copy substring pieces, then a validator checks leading zeros and 0..255. n is at most 12, so this still finishes, but you build illegal IPs first.

import java.util.*;
class Solution {
  boolean ok(String part) {
    if (part.length() == 0 || part.length() > 3) return false;
    if (part.length() > 1 && part.charAt(0) == '0') return false;
    int v = Integer.parseInt(part);
    return v >= 0 && v <= 255;
  }
  public List<String> restoreIpAddresses(String s) {
    List<String> ans = new ArrayList<String>();
    int n = s.length();
    for (int i = 1; i < n; i++)
      for (int j = i + 1; j < n; j++)
        for (int k = j + 1; k < n; k++) {
          String a = s.substring(0, i), b = s.substring(i, j), c = s.substring(j, k), d = s.substring(k);
          if (ok(a) && ok(b) && ok(c) && ok(d)) ans.add(a + "." + b + "." + c + "." + d);
        }
    return ans;
  }
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// s length is at most 12, so the search is constant. Backtrack parts 0..3. From i, try length 1, 2, 3. Push the piece, recurse, pop. Copy the joined string at 4 parts.

import java.util.*;
class Solution {
  boolean ok(String part) {
    if (part.length() == 0 || part.length() > 3) return false;
    if (part.length() > 1 && part.charAt(0) == '0') return false;
    return Integer.parseInt(part) <= 255;
  }
  public List<String> restoreIpAddresses(String s) {
    List<String> ans = new ArrayList<String>();
    go(s, 0, new ArrayList<String>(), ans);
    return ans;
  }
  void go(String s, int i, List<String> parts, List<String> ans) {
    if (parts.size() == 4) {
      if (i == s.length()) ans.add(String.join(".", parts));
      return;
    }
    for (int len = 1; len <= 3 && i + len <= s.length(); len++) {
      String piece = s.substring(i, i + len);
      if (!ok(piece)) continue;
      parts.add(piece);
      go(s, i + len, parts, ans);
      parts.remove(parts.size() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Before trying a length, prune: leftover chars must sit in [4-parts, 3*(4-parts)]. Drop leading-zero parts immediately. Cuts the tiny tree even further.

import java.util.*;
class Solution {
  public List<String> restoreIpAddresses(String s) {
    List<String> ans = new ArrayList<String>();
    go(s, 0, new ArrayList<String>(), ans);
    return ans;
  }
  void go(String s, int i, List<String> parts, List<String> ans) {
    int leftParts = 4 - parts.size();
    int leftChars = s.length() - i;
    if (leftChars < leftParts || leftChars > 3 * leftParts) return;
    if (parts.size() == 4) { ans.add(String.join(".", parts)); return; }
    for (int len = 1; len <= 3 && i + len <= s.length(); len++) {
      if (len > 1 && s.charAt(i) == '0') break;
      String piece = s.substring(i, i + len);
      if (Integer.parseInt(piece) > 255) continue;
      parts.add(piece);
      go(s, i + len, parts, ans);
      parts.remove(parts.size() - 1);
    }
  }
}
