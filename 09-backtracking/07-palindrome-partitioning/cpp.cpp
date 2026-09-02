// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// At each index you either cut or keep growing the last piece, copying the piece list every time. After a full partition you test every piece. Many illegal cuttings are built first and thrown away.

bool isPalParts(vector<string>& parts) {
  for (auto& w : parts) {
    int l = 0, r = (int)w.size() - 1;
    while (l < r) { if (w[l] != w[r]) return false; l++; r--; }
  }
  return true;
}
void go(string& s, int i, vector<string> parts, string cur, vector<vector<string>>& ans) {
  if (i == (int)s.size()) {
    if (cur.size()) parts.push_back(cur);
    if (isPalParts(parts)) ans.push_back(parts);
    return;
  }
  go(s, i + 1, parts, cur + s[i], ans);
  if (cur.size()) {
    parts.push_back(cur);
    go(s, i, parts, "", ans);
  }
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// From start, try every end. If s[start..end] is a palindrome, push it, recurse end+1, pop. Illegal prefixes never grow. Copy only at the end of s.

bool isPal(const string& s, int l, int r) {
  while (l < r) { if (s[l] != s[r]) return false; l++; r--; }
  return true;
}
void go(const string& s, int start, vector<string>& path, vector<vector<string>>& ans) {
  if (start == (int)s.size()) { ans.push_back(path); return; }
  for (int end = start; end < (int)s.size(); end++) {
    if (!isPal(s, start, end)) continue;
    path.push_back(s.substr(start, end - start + 1));
    go(s, end + 1, path, ans);
    path.pop_back();
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n^2)
// pal[l][r] is true if s[l..r] is a palindrome. Fill in O(n^2). Each cut check is then O(1). Same 2^n cuttings, cheaper work per node.

vector<vector<string>> partition(string s) {
  int n = (int)s.size();
  vector<vector<int>> pal(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) pal[i][i] = 1;
  for (int i = 0; i < n - 1; i++) pal[i][i + 1] = s[i] == s[i + 1];
  for (int len = 3; len <= n; len++)
    for (int l = 0; l + len - 1 < n; l++) {
      int r = l + len - 1;
      pal[l][r] = s[l] == s[r] && pal[l + 1][r - 1];
    }
  vector<vector<string>> ans;
  vector<string> path;
  function<void(int)> go = [&](int start) {
    if (start == n) { ans.push_back(path); return; }
    for (int end = start; end < n; end++) {
      if (!pal[start][end]) continue;
      path.push_back(s.substr(start, end - start + 1));
      go(end + 1);
      path.pop_back();
    }
  };
  go(0);
  return ans;
}
