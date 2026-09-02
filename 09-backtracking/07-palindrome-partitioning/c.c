// Method 1: Brute
// Time: O(n * 2^n) | Space: O(n * 2^n)
// At each index you either cut or keep growing the last piece, copying the piece list every time. After a full partition you test every piece. Many illegal cuttings are built first and thrown away.

int isPal(const char* s, int l, int r) {
  while (l < r) { if (s[l] != s[r]) return 0; l++; r--; }
  return 1;
}
/* brute: try every cut mask after building the string; classroom print */
void partitionBrute(const char* s) {
  int n = (int)strlen(s), mask, i, ok, start;
  int maxMask = 1 << (n > 0 ? n - 1 : 0);
  for (mask = 0; mask < maxMask; mask++) {
    ok = 1; start = 0;
    for (i = 0; i < n - 1; i++) if (mask & (1 << i)) {
      if (!isPal(s, start, i)) { ok = 0; break; }
      start = i + 1;
    }
    if (ok && isPal(s, start, n - 1)) printf("ok mask %d\n", mask);
  }
}


// Method 2: Optimal
// Time: O(n * 2^n) | Space: O(n)
// From start, try every end. If s[start..end] is a palindrome, push it, recurse end+1, pop. Illegal prefixes never grow. Copy only at the end of s.

int isPal(const char* s, int l, int r) {
  while (l < r) { if (s[l] != s[r]) return 0; l++; r--; }
  return 1;
}
void go(const char* s, int n, int start, int* cuts, int ncuts) {
  int end, k;
  if (start == n) {
    printf("partition\n");
    return;
  }
  for (end = start; end < n; end++) {
    if (!isPal(s, start, end)) continue;
    cuts[ncuts] = end;
    go(s, n, end + 1, cuts, ncuts + 1);
  }
}


// Method 3: More optimal
// Time: O(n * 2^n) | Space: O(n^2)
// pal[l][r] is true if s[l..r] is a palindrome. Fill in O(n^2). Each cut check is then O(1). Same 2^n cuttings, cheaper work per node.

void fillPal(const char* s, int n, int pal[][32]) {
  int i, l, r, len;
  for (i = 0; i < n; i++) pal[i][i] = 1;
  for (i = 0; i < n - 1; i++) pal[i][i + 1] = s[i] == s[i + 1];
  for (len = 3; len <= n; len++)
    for (l = 0; l + len - 1 < n; l++) {
      r = l + len - 1;
      pal[l][r] = (s[l] == s[r] && pal[l + 1][r - 1]);
    }
}
