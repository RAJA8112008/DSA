// Method 1: Brute
// Time: O(4^n * n) | Space: O(4^n * n)
// Each digit branches up to 4 ways. path + letter allocates a new string every time. n is the number of digits. Fine for n <= 4, wasteful copies.

import java.util.*;
class Solution {
  static final String[] MAP = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  public List<String> letterCombinations(String digits) {
    List<String> ans = new ArrayList<String>();
    if (digits.length() == 0) return ans;
    go(digits, 0, "", ans);
    return ans;
  }
  void go(String digits, int i, String path, List<String> ans) {
    if (i == digits.length()) { ans.add(path); return; }
    String letters = MAP[digits.charAt(i) - '0'];
    for (int j = 0; j < letters.length(); j++) go(digits, i + 1, path + letters.charAt(j), ans);
  }
}


// Method 2: Optimal
// Time: O(4^n * n) | Space: O(n)
// One char buffer. Push a letter, recurse, pop. Copy to the answer only at the last digit. Extra space is O(n) besides the output.

import java.util.*;
class Solution {
  static final String[] MAP = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  public List<String> letterCombinations(String digits) {
    List<String> ans = new ArrayList<String>();
    if (digits.length() == 0) return ans;
    go(digits, 0, new StringBuilder(), ans);
    return ans;
  }
  void go(String digits, int i, StringBuilder path, List<String> ans) {
    if (i == digits.length()) { ans.add(path.toString()); return; }
    String letters = MAP[digits.charAt(i) - '0'];
    for (int j = 0; j < letters.length(); j++) {
      path.append(letters.charAt(j));
      go(digits, i + 1, path, ans);
      path.deleteCharAt(path.length() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(4^n * n) | Space: O(4^n * n)
// Iterative: start with [""]. For each digit, replace every prefix with prefix+letter. No recursion. Empty digits return [] immediately (early stop).

import java.util.*;
class Solution {
  static final String[] MAP = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  public List<String> letterCombinations(String digits) {
    List<String> cur = new ArrayList<String>();
    if (digits.length() == 0) return cur;
    cur.add("");
    for (int i = 0; i < digits.length(); i++) {
      String letters = MAP[digits.charAt(i) - '0'];
      List<String> next = new ArrayList<String>();
      for (String prefix : cur)
        for (int j = 0; j < letters.length(); j++) next.add(prefix + letters.charAt(j));
      cur = next;
    }
    return cur;
  }
}
