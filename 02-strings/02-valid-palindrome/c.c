// Method 1: Brute
// Time: O(n) | Space: O(n)
// Linear scan, but a full cleaned copy plus a reversed copy.
// How it works: keep [a-z0-9], lowercase, then compare the string to its reverse.

/* pass n for array length; simple loops */
int isPalindrome(char* s) {
  char cleaned[1024]; /* "" */
  for (int i = 0; i < strlen(s); i++) {
    int ch = s[i].toLowerCase();
    if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) cleaned += ch;
  }
  int reversed = /* split cleaned */.reverse().join("");
  return cleaned == reversed;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Still a cleaned array, but comparison is two pointers instead of building a reversed string.
// How it works: push kept characters into chars, then left/right must match.

/* pass n for array length; simple loops */
int isPalindrome(char* s) {
  int chars[1024]; int chars_n = 0;
  for (int i = 0; i < strlen(s); i++) {
    int ch = s[i].toLowerCase();
    if ((ch >= "a" && ch <= "z") || (ch >= "0" && ch <= "9")) /* push */(ch);
  }
  int left = 0;
  int right = chars_len - 1;
  while (left < right) {
    if (chars[left] != chars[right]) return 0;
    left++;
    right--;
  }
  return 1;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// No extra string of length n. Two indexes on the original text.
// How it works: skip non-alphanumeric on both sides, lowercase the two live characters, compare, then move in.

/* pass n for array length; simple loops */
int isPalindrome(char* s) {
  void ok(/* ch */) {
    int c = tolower(ch);
    return (c >= "a" && c <= "z") || (c >= "0" && c <= "9");
  }
  int left = 0;
  int right = strlen(s) - 1;
  while (left < right) {
    while (left < right && !ok(s[left])) left++;
    while (left < right && !ok(s[right])) right--;
    if (s[left].toLowerCase() != s[right].toLowerCase()) return 0;
    left++;
    right--;
  }
  return 1;
}
