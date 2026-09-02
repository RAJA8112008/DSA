// Method 1: Brute
// Time: O(2^n * n) | Space: O(2^n * n)
// At each index, cut or grow the last token, copying the token list. After the string ends, every token must sit in the dict. Catastrophic on repeated letters.

import java.util.*;
class Solution {
  public List<String> wordBreak(String s, List<String> wordDict) {
    Set<String> dict = new HashSet<String>(wordDict);
    List<String> ans = new ArrayList<String>();
    go(s, 0, new ArrayList<String>(), "", dict, ans);
    return ans;
  }
  void go(String s, int i, List<String> parts, String cur, Set<String> dict, List<String> ans) {
    if (i == s.length()) {
      List<String> all = new ArrayList<String>(parts);
      if (cur.length() > 0) all.add(cur);
      for (String w : all) if (!dict.contains(w)) return;
      ans.add(String.join(" ", all));
      return;
    }
    go(s, i + 1, new ArrayList<String>(parts), cur + s.charAt(i), dict, ans);
    if (cur.length() > 0) {
      List<String> cut = new ArrayList<String>(parts);
      cut.add(cur);
      go(s, i, cut, "", dict, ans);
    }
  }
}


// Method 2: Optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// From i, try every dictionary word as a prefix of s[i..]. Push, recurse i+len, pop. Only legal words ever sit on the path. Still exponential in the number of sentences.

import java.util.*;
class Solution {
  public List<String> wordBreak(String s, List<String> wordDict) {
    List<String> ans = new ArrayList<String>();
    go(s, 0, wordDict, new ArrayList<String>(), ans);
    return ans;
  }
  void go(String s, int i, List<String> wordDict, List<String> path, List<String> ans) {
    if (i == s.length()) { ans.add(String.join(" ", path)); return; }
    for (String word : wordDict) {
      if (i + word.length() > s.length()) continue;
      if (!s.startsWith(word, i)) continue;
      path.add(word);
      go(s, i + word.length(), wordDict, path, ans);
      path.remove(path.size() - 1);
    }
  }
}


// Method 3: More optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// can[i] is true if s[i..] can be broken at all. If !can[i], skip that index (prune). Memo[i] stores the list of sentences from i so overlapping tails are not rebuilt.

import java.util.*;
class Solution {
  public List<String> wordBreak(String s, List<String> wordDict) {
    int n = s.length();
    boolean[] can = new boolean[n + 1];
    can[n] = true;
    for (int i = n - 1; i >= 0; i--)
      for (String word : wordDict)
        if (i + word.length() <= n && s.startsWith(word, i) && can[i + word.length()]) { can[i] = true; break; }
    Map<Integer, List<String>> memo = new HashMap<Integer, List<String>>();
    return can[0] ? go(s, 0, wordDict, can, memo) : new ArrayList<String>();
  }
  List<String> go(String s, int i, List<String> wordDict, boolean[] can, Map<Integer, List<String>> memo) {
    if (memo.containsKey(i)) return memo.get(i);
    List<String> res = new ArrayList<String>();
    if (i == s.length()) { res.add(""); return res; }
    if (!can[i]) { memo.put(i, res); return res; }
    for (String word : wordDict) {
      if (!s.startsWith(word, i)) continue;
      for (String tail : go(s, i + word.length(), wordDict, can, memo))
        res.add(tail.isEmpty() ? word : word + " " + tail);
    }
    memo.put(i, res);
    return res;
  }
}
