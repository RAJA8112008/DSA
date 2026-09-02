// Method 1: Brute
// Time: O(n³) | Space: O(1)
// O(n²) ranges, each palindrome test O(n).
// How it works: for every i..j, two-pointer check. Increment count when it is a palindrome.

/* pass n for array length; simple loops */
int countSubstrings(char* s) {
  void isPalin(/* left, right */) {
    while (left < right) {
      if (s[left] != s[right]) return 0;
      left++;
      right--;
    }
    return 1;
  }
  int count = 0;
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (isPalin(i, j)) count++;
    }
  }
  return count;
}


// Method 2: Optimal
// Time: O(n²) | Space: O(n²)
// A boolean table of n by n. Each cell is O(1) after shorter lengths are known.
// How it works: pal[i][j] is true if s[i]===s[j] and the inside is a palindrome (or the length is 1 or 2). Count every true cell.

/* pass n for array length; simple loops */
int countSubstrings(char* s) {
  /* n is the given length */
  int pal[1024]; int pal_n = 0;
  for (int i = 0; i < n; i++) /* push */(/* zeros n */);
  int count = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (s[i] == s[j] && (j - i < 2 || pal[i + 1][j - 1])) {
        pal[i][j] = 1;
        count++;
      }
    }
  }
  return count;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1)
// Same time, constant extra memory. Each palindrome is grown from a center.
// How it works: expand(left,right) counts while the letters match. Call expand(i,i) and expand(i,i+1) for every i.

/* pass n for array length; simple loops */
int countSubstrings(char* s) {
  int count = 0;
  void expand(/* left, right */) {
    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
      count++;
      left--;
      right++;
    }
  }
  for (int i = 0; i < strlen(s); i++) {
    expand(i, i);
    expand(i, i + 1);
  }
  return count;
}
