// Method 1: Brute
// Time: O(n * 2^{2n}) | Space: O(n * 2^{2n})
// Every bit mask is a string of ( and ). You copy the string, then scan it with a balance counter. Most strings fail. Extra copies of every mask.

void generateParenthesis(int n) {
  int total = 1 << (2 * n), mask, b, bal, ok;
  char s[32];
  for (mask = 0; mask < total; mask++) {
    for (b = 0; b < 2 * n; b++) s[b] = (mask & (1 << b)) ? '(' : ')';
    s[2 * n] = '\0';
    bal = 0; ok = 1;
    for (b = 0; b < 2 * n; b++) {
      bal += s[b] == '(' ? 1 : -1;
      if (bal < 0) { ok = 0; break; }
    }
    if (ok && bal == 0) printf("%s\n", s);
  }
}


// Method 2: Optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Backtrack with a char buffer. Try '(' and ')' at every length. Still visits some invalid prefixes unless you add the count checks (see More optimal).

int valid(const char* s) {
  int bal = 0, i;
  for (i = 0; s[i]; i++) {
    bal += s[i] == '(' ? 1 : -1;
    if (bal < 0) return 0;
  }
  return bal == 0;
}
void go(int n, char* path, int len) {
  if (len == 2 * n) {
    path[len] = '\0';
    if (valid(path)) printf("%s\n", path);
    return;
  }
  path[len] = '('; go(n, path, len + 1);
  path[len] = ')'; go(n, path, len + 1);
}


// Method 3: More optimal
// Time: O(4^n / sqrt(n)) | Space: O(n)
// Prune: add '(' only while open < n. Add ')' only while close < open. Leaves are exactly the Catalan number C_n. No invalid prefix is ever built.

void go(int n, int open, int close, char* path, int len) {
  if (len == 2 * n) { path[len] = '\0'; printf("%s\n", path); return; }
  if (open < n) { path[len] = '('; go(n, open + 1, close, path, len + 1); }
  if (close < open) { path[len] = ')'; go(n, open, close + 1, path, len + 1); }
}
