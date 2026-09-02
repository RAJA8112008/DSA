// Method 1: Brute
// Time: O(4^n * n) | Space: O(n)
// Between digits you copy four choices: nothing (concat), +, -, *. At the end you parse and evaluate, respecting * first. Extra strings everywhere. Leading-zero expressions are built then thrown away.

import java.util.*;
class Solution {
  public List<String> addOperators(String num, int target) {
    List<String> ans = new ArrayList<String>();
    if (num.length() == 0) return ans;
    go(num, target, 0, "", ans);
    return ans;
  }
  boolean ok(String expr) {
    int i = 0;
    while (i < expr.length()) {
      char ch = expr.charAt(i);
      if (ch == '+' || ch == '-' || ch == '*') { i++; continue; }
      int j = i;
      while (j < expr.length() && Character.isDigit(expr.charAt(j))) j++;
      if (j - i > 1 && expr.charAt(i) == '0') return false;
      i = j;
    }
    return true;
  }
  long evalExpr(String expr) {
    java.util.ArrayList<Long> tokens = new java.util.ArrayList<Long>();
    java.util.ArrayList<Character> signs = new java.util.ArrayList<Character>();
    int i = 0;
    Character lastOp = null;
    while (i < expr.length()) {
      char ch = expr.charAt(i);
      if (ch == '+' || ch == '-') { signs.add(ch); lastOp = ch; i++; continue; }
      if (ch == '*') { lastOp = '*'; i++; continue; }
      int j = i; long v = 0;
      while (j < expr.length() && Character.isDigit(expr.charAt(j))) { v = v * 10 + (expr.charAt(j) - '0'); j++; }
      if (lastOp != null && lastOp == '*') tokens.set(tokens.size() - 1, tokens.get(tokens.size() - 1) * v);
      else tokens.add(v);
      lastOp = null;
      i = j;
    }
    long sum = 0; int si = 0;
    sum = tokens.get(0);
    for (int t = 1; t < tokens.size(); t++) {
      char op = signs.get(si++);
      if (op == '+') sum += tokens.get(t); else sum -= tokens.get(t);
    }
    return sum;
  }
  void go(String num, int target, int i, String expr, List<String> ans) {
    if (i == num.length()) {
      if (ok(expr) && evalExpr(expr) == target) ans.add(expr);
      return;
    }
    if (i == 0) { go(num, target, 1, "" + num.charAt(0), ans); return; }
    String[] ops = {"", "+", "-", "*"};
    for (String op : ops) go(num, target, i + 1, expr + op + num.charAt(i), ans);
  }
}


// Method 2: Optimal
// Time: O(4^n) | Space: O(n)
// From index i, take the next operand as a long (concat digits). For the first number, just place it. Later, branch +, -, * onto one path buffer and undo. A running cur and last let you accept a leaf without a separate eval. Leading zeros are skipped.

import java.util.*;
class Solution {
  public List<String> addOperators(String num, int target) {
    List<String> ans = new ArrayList<String>();
    go(num, target, 0, new StringBuilder(), 0L, 0L, ans);
    return ans;
  }
  void go(String num, int target, int i, StringBuilder expr, long cur, long last, List<String> ans) {
    if (i == num.length()) {
      if (cur == target) ans.add(expr.toString());
      return;
    }
    long val = 0;
    int len = expr.length();
    for (int j = i; j < num.length(); j++) {
      if (j > i && num.charAt(i) == '0') break;
      val = val * 10 + (num.charAt(j) - '0');
      String piece = num.substring(i, j + 1);
      if (i == 0) {
        expr.append(piece);
        go(num, target, j + 1, expr, val, val, ans);
        expr.setLength(len);
      } else {
        expr.append('+').append(piece);
        go(num, target, j + 1, expr, cur + val, val, ans);
        expr.setLength(len);
        expr.append('-').append(piece);
        go(num, target, j + 1, expr, cur - val, -val, ans);
        expr.setLength(len);
        expr.append('*').append(piece);
        go(num, target, j + 1, expr, cur - last + last * val, last * val, ans);
        expr.setLength(len);
      }
    }
  }
}


// Method 3: More optimal
// Time: O(4^n) | Space: O(n)
// Track cur (value of the expression so far) and last (the last operand, signed). Concat: last = last*10+d, cur = cur - oldLast + last. Plus: cur+val, last=val. Minus: cur-val, last=-val. Times: cur-last+last*val, last=last*val. No eval. Leading zeros break. Use 64-bit to avoid overflow.

import java.util.*;
class Solution {
  public List<String> addOperators(String num, int target) {
    List<String> ans = new ArrayList<String>();
    go(num, target, 0, new StringBuilder(), 0L, 0L, ans);
    return ans;
  }
  void go(String num, int target, int i, StringBuilder expr, long cur, long last, List<String> ans) {
    if (i == num.length()) {
      if (cur == target) ans.add(expr.toString());
      return;
    }
    long val = 0;
    int len = expr.length();
    for (int j = i; j < num.length(); j++) {
      if (j > i && num.charAt(i) == '0') break;
      val = val * 10 + (num.charAt(j) - '0');
      String piece = num.substring(i, j + 1);
      if (i == 0) {
        expr.append(piece);
        go(num, target, j + 1, expr, val, val, ans);
        expr.setLength(len);
      } else {
        expr.append('+').append(piece);
        go(num, target, j + 1, expr, cur + val, val, ans);
        expr.setLength(len);
        expr.append('-').append(piece);
        go(num, target, j + 1, expr, cur - val, -val, ans);
        expr.setLength(len);
        expr.append('*').append(piece);
        go(num, target, j + 1, expr, cur - last + last * val, last * val, ans);
        expr.setLength(len);
      }
    }
  }
}
