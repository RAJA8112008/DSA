// Method 1: Brute
// Time: O(S) | Space: O(m)
// S is the total number of characters. Each word is compared to the current prefix from scratch.
// How it works: prefix starts as strs[0]. For each next word, cut prefix while it is not a prefix of that word.

/* pass n for array length; simple loops */
void longestCommonPrefix(char strs[][64], int n, char* out) {
  if (!n) return "";
  char prefix[1024]; /* strs[0] */
  for (int i = 1; i < n; i++) {
    while (strs[i].indexOf(prefix) != 0) {
      prefix = /* slice prefix */;
      if (prefix == "") return "";
    }
  }
  return prefix;
}


// Method 2: Optimal
// Time: O(n log n + m) | Space: O(m)
// Sort the n words, then only the first and last can disagree. m is the shorter of those two.
// How it works: after sort, walk columns of first vs last until they differ. That slice is the prefix of the whole set.

/* pass n for array length; simple loops */
void longestCommonPrefix(char strs[][64], int n, char* out) {
  if (!n) return "";
  char list[1024]; /* strs.sort() */
  int first = list[0];
  int last = list[strlen(list) - 1];
  int i = 0;
  while (i < first_len && i < last_len && first[i] == last[i]) i++;
  return /* slice first */;
}


// Method 3: More optimal
// Time: O(S) | Space: O(1)
// No sort copy. Extra memory is a few indexes. Worst case still reads every character of every word until a mismatch.
// How it works: for column i of strs[0], every other word must have the same character. Return the slice before the first failure.

/* pass n for array length; simple loops */
void longestCommonPrefix(char strs[][64], int n, char* out) {
  if (!n) return "";
  char first[1024]; /* strs[0] */
  for (int i = 0; i < strlen(first); i++) {
    int ch = first[i];
    for (int j = 1; j < n; j++) {
      if (i >= strs[j].length || strs[j][i] != ch) return /* slice first */;
    }
  }
  return first;
}
