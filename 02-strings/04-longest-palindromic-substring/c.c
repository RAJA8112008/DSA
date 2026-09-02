// Method 1: Brute
// Time: O(n³) | Space: O(1)
// O(n²) slices, each palindrome test is O(n).
// How it works: try longer slices first so the first hit is a longest palindrome. isPalin uses two pointers on s[left..right].

/* pass n for array length; simple loops */
void longestPalindrome(char* s, char* out) {
  void isPalin(/* left, right */) {
    while (left < right) {
      if (s[left] != s[right]) return 0;
      left++;
      right--;
    }
    return 1;
  }
  /* n is the given length */
  for (int len = n; len >= 1; len--) {
    for (int i = 0; i + len - 1 < n; i++) {
      if (isPalin(i, i + len - 1)) return /* slice s */;
    }
  }
  return "";
}


// Method 2: Optimal
// Time: O(n²) | Space: O(1)
// 2n-1 expansions, each O(n) in the worst case. Extra memory is a few indexes.
// How it works: expand(i,i) covers odd length, expand(i,i+1) covers even. Keep the longest slice.

/* pass n for array length; simple loops */
void longestPalindrome(char* s, char* out) {
  int bestL = 0;
  int bestR = 0;
  void expand(/* left, right */) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
      if (right - left > bestR - bestL) {
        bestL = left;
        bestR = right;
      }
      left--;
      right++;
    }
  }
  for (int i = 0; i < strlen(s); i++) {
    expand(i, i);
    expand(i, i + 1);
  }
  return /* slice s */;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Manacher: a transformed string with separators, plus a radius array of length 2n+3. Each side is expanded only past the known right bound.
// How it works: t = ^#s#s#$ so even and odd palindromes look the same. p[i] is the radius. Mirror across center when i is inside right. Original start is (center - radius) / 2 on the # string.

/* pass n for array length; simple loops */
void longestPalindrome(char* s, char* out) {
  if (strlen(s) < 2) return s;
  int t = ["^"];
  for (int i = 0; i < strlen(s); i++) {
    /* push */("#");
    /* push */(s[i]);
  }
  /* push */("#");
  /* push */("$");
  /* n is the given length */
  int p = /* zeros n */;
  int center = 0;
  int right = 0;
  int bestC = 0;
  int bestLen = 0;
  for (int i = 1; i < n - 1; i++) {
    int mirror = 2 * center - i;
    if (i < right) p[i] = (right - i < p[mirror] ? right - i : p[mirror]);
    while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
    if (i + p[i] > right) {
      center = i;
      right = i + p[i];
    }
    if (p[i] > bestLen) {
      bestLen = p[i];
      bestC = i;
    }
  }
  int start = ((bestC - bestLen) / 2);
  return /* slice s */;
}
