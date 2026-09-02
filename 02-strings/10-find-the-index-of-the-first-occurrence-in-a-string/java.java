// Method 1: Brute
// Time: O((n-m)·m) | Space: O(1)
// Every start position compares up to m characters.
// How it works: for each i, check whether haystack[i..i+m) equals needle. First hit wins.

class Solution {
  public int strStr(String haystack, String needle) {
    int n = haystack.length();
    int m = needle.length();
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
      boolean ok = true;
      for (int j = 0; j < m; j++) {
        if (haystack.charAt(i + j) != needle.charAt(j)) { ok = false; break; }
      }
      if (ok) return i;
    }
    return -1;
  }
}


// Method 2: Optimal
// Time: O((n-m)·m) | Space: O(1)
// Same worst-case bound, fewer inner steps when the first character already mismatches (slice avoided).
// How it works: skip starts whose first character is wrong, then compare the rest. Empty needle returns 0.

class Solution {
  public int strStr(String haystack, String needle) {
    int n = haystack.length();
    int m = needle.length();
    if (m == 0) return 0;
    for (int i = 0; i + m <= n; i++) {
      if (haystack.charAt(i) != needle.charAt(0)) continue;
      int j = 1;
      while (j < m && haystack.charAt(i + j) == needle.charAt(j)) j++;
      if (j == m) return i;
    }
    return -1;
  }
}


// Method 3: More optimal
// Time: O(n + m) | Space: O(m)
// KMP: build lps of the needle in O(m), then scan haystack in O(n) without restarting from scratch on mismatch.
// How it works: lps[i] is the longest proper prefix of needle[0..i] that is also a suffix. On mismatch, j = lps[j-1] instead of j = 0 always.

class Solution {
  public int strStr(String haystack, String needle) {
    int n = haystack.length();
    int m = needle.length();
    if (m == 0) return 0;
    int[] lps = new int[m];
    int len = 0;
    int i = 1;
    while (i < m) {
      if (needle.charAt(i) == needle.charAt(len)) {
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
      if (haystack.charAt(hi) == needle.charAt(ni)) {
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
}
