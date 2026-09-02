// Method 1: Brute
// Time: O(n * 2^{2n}) | Space: O(n * 2^{2n})
// Every bit mask is a string of ( and ). You copy the string, then scan it with a balance counter. Most strings fail. Extra copies of every mask.

vector<string> generateParenthesis(int n) {
  vector<string> ans;
  int total = 1 << (2 * n);
  for (int mask = 0; mask < total; mask++) {
    string s;
    for (int b = 0; b < 2 * n; b++) s += (mask & (1 << b)) ? '(' : ')';
    int bal = 0; bool ok = true;
    for (char ch : s) {
      bal += ch == '(' ? 1 : -1;
      if (bal < 0) { ok = false; break; }
    }
    if (ok && bal == 0) ans.push_back(s);
  }
  return ans;
}


// Method 2: Optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Backtrack with a char buffer. Try '(' and ')' at every length. Still visits some invalid prefixes unless you add the count checks (see More optimal).

bool valid(const string& s) {
  int bal = 0;
  for (char ch : s) { bal += ch == '(' ? 1 : -1; if (bal < 0) return false; }
  return bal == 0;
}
void go(int n, string& path, vector<string>& ans) {
  if ((int)path.size() == 2 * n) { if (valid(path)) ans.push_back(path); return; }
  path.push_back('('); go(n, path, ans); path.pop_back();
  path.push_back(')'); go(n, path, ans); path.pop_back();
}


// Method 3: More optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Prune: add '(' only while open < n. Add ')' only while close < open. Leaves are exactly the Catalan number C_n. No invalid prefix is ever built.

void go(int n, int open, int close, string& path, vector<string>& ans) {
  if ((int)path.size() == 2 * n) { ans.push_back(path); return; }
  if (open < n) { path.push_back('('); go(n, open + 1, close, path, ans); path.pop_back(); }
  if (close < open) { path.push_back(')'); go(n, open, close + 1, path, ans); path.pop_back(); }
}
