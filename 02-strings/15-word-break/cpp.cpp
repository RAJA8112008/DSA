// Method 1: Brute
// Time: O(2ⁿ) | Space: O(n)
// Each position may start many words. Overlapping failures are recomputed. Stack depth is O(n).
// How it works: dfs(i) is true if i is the end, or some wordDict entry matches s starting at i and dfs continues after it.

// vector, unordered_map, string
bool wordBreak(string s, vector<string>& wordDict) {
  auto dfs = [&](i) {
    if (i == (int)s.size()) return true;
    for (int w = 0; w < (int)wordDict.size(); w++) {
      string word = wordDict[w];
      if (s.substr(i, (i + (int)word.size())-(i)) == word && dfs(i + (int)word.size())) return true;
    }
    return false;
  }
  return dfs(0);
}


// Method 2: Optimal
// Time: O(n² · k) | Space: O(n)
// ok[i] loops previous starts and slices. k is cost of string compare / slice.
// How it works: ok[0] = true. ok[j] is true if some i < j has ok[i] and s.slice(i,j) is in the dictionary Set.

// vector, unordered_map, string
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<int> words;
  int n = (int)s.size();
  vector<int> ok = vector<int>(n + 1).fill(false);
  ok[0] = true;
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < j; i++) {
      if (ok[i] && words.count(s.substr(i, (j)-(i)))) {
        ok[j] = true;
        break;
      }
    }
  }
  return ok[n];
}


// Method 3: More optimal
// Time: O(n · L) | Space: O(n)
// From each true index i, only try lengths 1..longest word, not every j. L is that max length times slice cost, still typically much less than n for each i.
// How it works: same ok array. If ok[i], try each length up to longest. If the slice is a word, mark ok[i+len].

// vector, unordered_map, string
bool wordBreak(string s, vector<string>& wordDict) {
  unordered_set<int> words;
  int longest = 0;
  for (int w = 0; w < (int)wordDict.size(); w++) {
    if (wordDict[w].length > longest) longest = wordDict[w].length;
  }
  int n = (int)s.size();
  vector<int> ok = vector<int>(n + 1).fill(false);
  ok[0] = true;
  for (int i = 0; i < n; i++) {
    if (!ok[i]) continue;
    for (int len = 1; len <= longest && i + len <= n; len++) {
      if (words.count(s.substr(i, (i + len)-(i)))) ok[i + len] = true;
    }
  }
  return ok[n];
}
