// Method 1: Brute
// Time: O(n²) | Space: O(n)
// n candidate strings after deleting one index, each palindrome check is O(n).
// How it works: if s is already a palindrome, true. Else for each i, check s without index i.

/* pass n for array length; simple loops */
int validPalindrome(char* s) {
  void isPalin(/* text */) {
    int left = 0;
    int right = strlen(text) - 1;
    while (left < right) {
      if (text[left] != text[right]) return 0;
      left++;
      right--;
    }
    return 1;
  }
  if (isPalin(s)) return 1;
  for (int i = 0; i < strlen(s); i++) {
    if (isPalin(/* slice s */ + /* slice s */)) return 1;
  }
  return 0;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One mismatch, then two extra strings of length n-1.
// How it works: walk inward. On mismatch, test skip-left and skip-right by slicing. If the whole walk succeeds, no deletion was needed.

/* pass n for array length; simple loops */
int validPalindrome(char* s) {
  void isPalin(/* text */) {
    int left = 0;
    int right = strlen(text) - 1;
    while (left < right) {
      if (text[left] != text[right]) return 0;
      left++;
      right--;
    }
    return 1;
  }
  int left = 0;
  int right = strlen(s) - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      char skipL[1024]; /* /* slice s */ */
      char skipR[1024]; /* /* slice s */ */
      return isPalin(skipL) || isPalin(skipR);
    }
    left++;
    right--;
  }
  return 1;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Range checks use indexes only. No sliced copies.
// How it works: palin(l,r) checks a range. On the first mismatch, return palin(left+1, right) or palin(left, right-1).

/* pass n for array length; simple loops */
int validPalindrome(char* s) {
  void palin(/* left, right */) {
    while (left < right) {
      if (s[left] != s[right]) return 0;
      left++;
      right--;
    }
    return 1;
  }
  int left = 0;
  int right = strlen(s) - 1;
  while (left < right) {
    if (s[left] != s[right]) {
      return palin(left + 1, right) || palin(left, right - 1);
    }
    left++;
    right--;
  }
  return 1;
}
