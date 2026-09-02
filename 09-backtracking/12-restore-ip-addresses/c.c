// Method 1: Brute
// Time: O(n^4) | Space: O(n)
// Three nested cuts copy substring pieces, then a validator checks leading zeros and 0..255. n is at most 12, so this still finishes, but you build illegal IPs first.

int ok(const char* s, int l, int r) {
  int len = r - l + 1, v = 0, i;
  if (len <= 0 || len > 3) return 0;
  if (len > 1 && s[l] == '0') return 0;
  for (i = l; i <= r; i++) v = v * 10 + (s[i] - '0');
  return v >= 0 && v <= 255;
}


// Method 2: Optimal
// Time: O(1) | Space: O(1)
// s length is at most 12, so the search is constant. Backtrack parts 0..3. From i, try length 1, 2, 3. Push the piece, recurse, pop. Copy the joined string at 4 parts.

int ok(const char* s, int l, int r) {
  int len = r - l + 1, v = 0, i;
  if (len <= 0 || len > 3) return 0;
  if (len > 1 && s[l] == '0') return 0;
  for (i = l; i <= r; i++) v = v * 10 + (s[i] - '0');
  return v <= 255;
}
void go(const char* s, int n, int i, int* cuts, int nparts) {
  int len;
  if (nparts == 4) { if (i == n) printf("ip\n"); return; }
  for (len = 1; len <= 3 && i + len <= n; len++) {
    if (!ok(s, i, i + len - 1)) continue;
    cuts[nparts] = i + len;
    go(s, n, i + len, cuts, nparts + 1);
  }
}


// Method 3: More optimal
// Time: O(1) | Space: O(1)
// Before trying a length, prune: leftover chars must sit in [4-parts, 3*(4-parts)]. Drop leading-zero parts immediately. Cuts the tiny tree even further.

void go(const char* s, int n, int i, int nparts, char* path, int plen) {
  int leftParts = 4 - nparts, leftChars = n - i, len, v, t;
  if (leftChars < leftParts || leftChars > 3 * leftParts) return;
  if (nparts == 4) { path[plen] = '\0'; printf("%s\n", path); return; }
  for (len = 1; len <= 3 && i + len <= n; len++) {
    if (len > 1 && s[i] == '0') break;
    v = 0;
    for (t = 0; t < len; t++) v = v * 10 + (s[i + t] - '0');
    if (v > 255) continue;
    if (nparts) path[plen++] = '.';
    for (t = 0; t < len; t++) path[plen++] = s[i + t];
    go(s, n, i + len, nparts + 1, path, plen);
    plen -= len + (nparts ? 1 : 0);
  }
}
