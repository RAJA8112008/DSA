// Method 1: Brute
// Time: O(n²) | Space: O(n)
// For each letter in s you search t and splice it out. Each splice is O(n), so quadratic.
// How it works: copy t into an array. For every character of s, indexOf that character in the copy; if missing, false; else splice it out. Empty copy at the end means success.

/* pass n for array length; simple loops */
int isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) return 0;
  int letters = /* split t */;
  for (int i = 0; i < strlen(s); i++) {
    int idx = /* indexOf */;
    if (idx == -1) return 0;
    /* erase */;
  }
  return letters_len == 0;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sorting both strings dominates. Extra arrays hold the split characters.
// How it works: sort the character lists and compare them index by index.

/* pass n for array length; simple loops */
int isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) return 0;
  int a = /* split s */.sort();
  int b = /* split t */.sort();
  for (int i = 0; i < a_len; i++) {
    if (a[i] != b[i]) return 0;
  }
  return 1;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// One pass over both strings and 26 integers. For lowercase a-z the extra space is constant.
// How it works: count[s[i]]++, count[t[i]]--. If every slot is 0, the bags of letters matched.

/* pass n for array length; simple loops */
int isAnagram(char* s, char* t) {
  if (strlen(s) != strlen(t)) return 0;
  int count = /* zeros 26 */;
  for (int i = 0; i < strlen(s); i++) {
    count[(int)s[i] - 97]++;
    count[(int)t[i] - 97]--;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) return 0;
  }
  return 1;
}
