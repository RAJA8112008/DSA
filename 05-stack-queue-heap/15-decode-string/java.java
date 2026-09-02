// Method 1: Brute
// Time: O(n · out) | Space: O(n · out)
// Recursion: parse a chunk, and when you see k[...], slice the inner substring, decode it, repeat. Extra string copies of the remaining suffix. Correct, messy bounds.

class Solution {
  static class Pair { String text; int i; Pair(String t, int i) { text = t; this.i = i; } }
  Pair parse(String s, int i) {
    StringBuilder out = new StringBuilder();
    while (i < s.length() && s.charAt(i) != ']') {
      if (s.charAt(i) < '0' || s.charAt(i) > '9') {
        out.append(s.charAt(i)); i++; continue;
      }
      int k = 0;
      while (s.charAt(i) >= '0' && s.charAt(i) <= '9') { k = k * 10 + (s.charAt(i) - '0'); i++; }
      i++; // skip '['
      Pair inner = parse(s, i);
      for (int t = 0; t < k; t++) out.append(inner.text);
      i = inner.i + 1; // skip ']'
    }
    return new Pair(out.toString(), i);
  }
  public String decodeString(String s) { return parse(s, 0).text; }
}


// Method 2: Optimal
// Time: O(n + out) | Space: O(n + out)
// One stack. Digits build k. '[' pushes the current string and k, then resets. Letters append. ']' pops and repeats. Linear in input plus output size.

import java.util.*;
class Solution {
  public String decodeString(String s) {
    ArrayDeque<String> strs = new ArrayDeque<String>();
    ArrayDeque<Integer> ks = new ArrayDeque<Integer>();
    StringBuilder cur = new StringBuilder();
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i);
      if (ch >= '0' && ch <= '9') k = k * 10 + (ch - '0');
      else if (ch == '[') {
        strs.push(cur.toString()); ks.push(k);
        cur = new StringBuilder(); k = 0;
      } else if (ch == ']') {
        String prev = strs.pop(); int ck = ks.pop();
        StringBuilder next = new StringBuilder(prev);
        for (int t = 0; t < ck; t++) next.append(cur);
        cur = next;
      } else cur.append(ch);
    }
    return cur.toString();
  }
}


// Method 3: More optimal
// Time: O(n + out) | Space: O(n + out)
// Two stacks: counts and strings. Same linear bound. Some interviewers prefer two named stacks over pairs. Repeat still dominates the output cost.

import java.util.*;
class Solution {
  public String decodeString(String s) {
    ArrayDeque<Integer> counts = new ArrayDeque<Integer>();
    ArrayDeque<String> strs = new ArrayDeque<String>();
    StringBuilder cur = new StringBuilder();
    int k = 0;
    for (int i = 0; i < s.length(); i++) {
      char ch = s.charAt(i);
      if (ch >= '0' && ch <= '9') k = k * 10 + (ch - '0');
      else if (ch == '[') {
        counts.push(k); strs.push(cur.toString());
        cur = new StringBuilder(); k = 0;
      } else if (ch == ']') {
        StringBuilder next = new StringBuilder(strs.pop());
        int ck = counts.pop();
        for (int t = 0; t < ck; t++) next.append(cur);
        cur = next;
      } else cur.append(ch);
    }
    return cur.toString();
  }
}
