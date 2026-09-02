// Method 1: Brute
// Time: O(2ⁿ) | Space: O(n)
// Each position may start many words. Overlapping failures are recomputed. Stack depth is O(n).
// How it works: dfs(i) is true if i is the end, or some wordDict entry matches s starting at i and dfs continues after it.

class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    public void dfs(i) {
      if (i == s.length()) return true;
      for (int w = 0; w < wordDict.length; w++) {
        String word = wordDict[w];
        if (s.substring(i, i + word.length()) == word && dfs(i + word.length())) return true;
      }
      return false;
    }
    return dfs(0);
  }
}


// Method 2: Optimal
// Time: O(n² · k) | Space: O(n)
// ok[i] loops previous starts and slices. k is cost of string compare / slice.
// How it works: ok[0] = true. ok[j] is true if some i < j has ok[i] and s.slice(i,j) is in the dictionary Set.

class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    Set<Integer> words = new HashSet<>();
    int n = s.length();
    boolean[] ok = new int[n + 1].fill(false);
    ok[0] = true;
    for (int j = 1; j <= n; j++) {
      for (int i = 0; i < j; i++) {
        if (ok[i] && words.contains(s.substring(i, j))) {
          ok[j] = true;
          break;
        }
      }
    }
    return ok[n];
  }
}


// Method 3: More optimal
// Time: O(n · L) | Space: O(n)
// From each true index i, only try lengths 1..longest word, not every j. L is that max length times slice cost, still typically much less than n for each i.
// How it works: same ok array. If ok[i], try each length up to longest. If the slice is a word, mark ok[i+len].

class Solution {
  public boolean wordBreak(String s, List<String> wordDict) {
    Set<Integer> words = new HashSet<>();
    int longest = 0;
    for (int w = 0; w < wordDict.length; w++) {
      if (wordDict[w].length > longest) longest = wordDict[w].length;
    }
    int n = s.length();
    boolean[] ok = new int[n + 1].fill(false);
    ok[0] = true;
    for (int i = 0; i < n; i++) {
      if (!ok[i]) continue;
      for (int len = 1; len <= longest && i + len <= n; len++) {
        if (words.contains(s.substring(i, i + len))) ok[i + len] = true;
      }
    }
    return ok[n];
  }
}
