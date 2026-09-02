// Method 1: Brute
// Time: O(2^n * n) | Space: O(2^n * n)
// At each index, cut or grow the last token, copying the token list. After the string ends, every token must sit in the dict. Catastrophic on repeated letters.

/* brute cut-or-grow; classroom sketch */
void go(const char* s, int i, char parts[][32], int nparts, char* cur, int clen) {
  (void)s; (void)i; (void)parts; (void)nparts; (void)cur; (void)clen;
}


// Method 2: Optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// From i, try every dictionary word as a prefix of s[i..]. Push, recurse i+len, pop. Only legal words ever sit on the path. Still exponential in the number of sentences.

void go(const char* s, int n, char dict[][32], int nd, int i, char* path, int plen) {
  int w, len, k;
  if (i == n) { path[plen] = '\0'; printf("%s\n", path); return; }
  for (w = 0; w < nd; w++) {
    len = (int)strlen(dict[w]);
    if (i + len > n) continue;
    if (strncmp(s + i, dict[w], len) != 0) continue;
    if (plen) path[plen++] = ' ';
    for (k = 0; k < len; k++) path[plen++] = dict[w][k];
    go(s, n, dict, nd, i + len, path, plen);
    plen -= len + (plen > len ? 1 : 0);
  }
}


// Method 3: More optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// can[i] is true if s[i..] can be broken at all. If !can[i], skip that index (prune). Memo[i] stores the list of sentences from i so overlapping tails are not rebuilt.

int canBreak(const char* s, int n, char dict[][32], int nd, int* can) {
  int i, w, len;
  can[n] = 1;
  for (i = n - 1; i >= 0; i--) {
    can[i] = 0;
    for (w = 0; w < nd; w++) {
      len = (int)strlen(dict[w]);
      if (i + len <= n && strncmp(s + i, dict[w], len) == 0 && can[i + len]) { can[i] = 1; break; }
    }
  }
  return can[0];
}
