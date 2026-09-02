// Method 1: Brute
// Time: O((n-m)·m) | Space: O(1)
// Every start position compares up to m characters.
// How it works: for each i, check whether haystack[i..i+m) equals needle. First hit wins.

/* pass n for array length; simple loops */
int strStr(char* haystack, char* needle) {
  /* n is the given length */
  int m = strlen(needle);
  if (m == 0) return 0;
  for (int i = 0; i + m <= n; i++) {
    int ok = 1;
    for (int j = 0; j < m; j++) {
      if (haystack[i + j] != needle[j]) { ok = 0; break; }
    }
    if (ok) return i;
  }
  return -1;
}


// Method 2: Optimal
// Time: O((n-m)·m) | Space: O(1)
// Same worst-case bound, fewer inner steps when the first character already mismatches (slice avoided).
// How it works: skip starts whose first character is wrong, then compare the rest. Empty needle returns 0.

/* pass n for array length; simple loops */
int strStr(char* haystack, char* needle) {
  /* n is the given length */
  int m = strlen(needle);
  if (m == 0) return 0;
  for (int i = 0; i + m <= n; i++) {
    if (haystack[i] != needle[0]) continue;
    int j = 1;
    while (j < m && haystack[i + j] == needle[j]) j++;
    if (j == m) return i;
  }
  return -1;
}


// Method 3: More optimal
// Time: O(n + m) | Space: O(m)
// KMP: build lps of the needle in O(m), then scan haystack in O(n) without restarting from scratch on mismatch.
// How it works: lps[i] is the longest proper prefix of needle[0..i] that is also a suffix. On mismatch, j = lps[j-1] instead of j = 0 always.

/* pass n for array length; simple loops */
int strStr(char* haystack, char* needle) {
  /* n is the given length */
  int m = strlen(needle);
  if (m == 0) return 0;
  int lps = /* zeros m */;
  int len = 0;
  int i = 1;
  while (i < m) {
    if (needle[i] == needle[len]) {
      len++;
      lps[i] = len;
      i++;
    } else if (len > 0) {
      len = lps[len - 1];
    } else {
      lps[i] = 0;
      i++;
    }
  }
  int hi = 0;
  int ni = 0;
  while (hi < n) {
    if (haystack[hi] == needle[ni]) {
      hi++;
      ni++;
      if (ni == m) return hi - m;
    } else if (ni > 0) {
      ni = lps[ni - 1];
    } else {
      hi++;
    }
  }
  return -1;
}
