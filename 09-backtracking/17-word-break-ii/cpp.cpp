// Method 1: Brute
// Time: O(2^n * n) | Space: O(2^n * n)
// At each index, cut or grow the last token, copying the token list. After the string ends, every token must sit in the dict. Catastrophic on repeated letters.

void go(string& s, int i, vector<string> parts, string cur, unordered_set<string>& dict, vector<string>& ans) {
  if (i == (int)s.size()) {
    if (cur.size()) parts.push_back(cur);
    for (auto& w : parts) if (!dict.count(w)) return;
    string sent = parts[0];
    for (int p = 1; p < (int)parts.size(); p++) sent += " " + parts[p];
    ans.push_back(sent);
    return;
  }
  go(s, i + 1, parts, cur + s[i], dict, ans);
  if (cur.size()) { parts.push_back(cur); go(s, i, parts, "", dict, ans); }
}


// Method 2: Optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// From i, try every dictionary word as a prefix of s[i..]. Push, recurse i+len, pop. Only legal words ever sit on the path. Still exponential in the number of sentences.

void go(string& s, int i, vector<string>& wordDict, vector<string>& path, vector<string>& ans) {
  if (i == (int)s.size()) {
    string sent = path[0];
    for (int p = 1; p < (int)path.size(); p++) sent += " " + path[p];
    ans.push_back(sent);
    return;
  }
  for (auto& word : wordDict) {
    if (s.compare(i, word.size(), word) != 0) continue;
    path.push_back(word);
    go(s, i + (int)word.size(), wordDict, path, ans);
    path.pop_back();
  }
}


// Method 3: More optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// can[i] is true if s[i..] can be broken at all. If !can[i], skip that index (prune). Memo[i] stores the list of sentences from i so overlapping tails are not rebuilt.

vector<string> go(string& s, int i, vector<string>& wordDict, vector<int>& can, vector<vector<string>>& memo, vector<int>& seen) {
  if (seen[i]) return memo[i];
  seen[i] = 1;
  if (i == (int)s.size()) return memo[i] = {""};
  if (!can[i]) return memo[i];
  for (auto& word : wordDict) {
    if (s.compare(i, word.size(), word) != 0) continue;
    for (auto& tail : go(s, i + (int)word.size(), wordDict, can, memo, seen))
      memo[i].push_back(tail.empty() ? word : word + " " + tail);
  }
  return memo[i];
}
