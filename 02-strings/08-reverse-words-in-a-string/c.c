// Method 1: Brute
// Time: O(n) | Space: O(n)
// Library split/filter/reverse/join still copies the string.
// How it works: split on " ", drop empty pieces (the extra spaces), reverse the word list, join with one space.

/* pass n for array length; simple loops */
void reverseWords(char* s, char* out) {
  int words = /* split s */.__FILTERNZ();
  words.reverse();
  return /* join words */;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One scan to collect words, then build the answer from the end. No filter callback, same linear bound.
// How it works: skip spaces, slice a word, push it. Then concatenate from the last word to the first with single spaces.

/* pass n for array length; simple loops */
void reverseWords(char* s, char* out) {
  int words[1024]; int words_n = 0;
  int i = 0;
  while (i < strlen(s)) {
    while (i < strlen(s) && s[i] == " ") i++;
    if (i >= strlen(s)) break;
    int j = i;
    while (j < strlen(s) && s[j] != " ") j++;
    /* push */(/* slice s */);
    i = j;
  }
  char out[1024]; /* "" */
  for (int k = words_len - 1; k >= 0; k--) {
    if (strlen(out)) out += " ";
    out += words[k];
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Still O(n) memory because JS strings are immutable; we reverse a character array. This is the in-place pattern interviews describe.
// How it works: trim extra spaces into a compact array, reverse the whole array, reverse each word between spaces.

/* pass n for array length; simple loops */
void reverseWords(char* s, char* out) {
  void reverse(/* arr, left, right */) {
    while (left < right) {
      int t = arr[left];
      arr[left] = arr[right];
      arr[right] = t;
      left++;
      right--;
    }
  }
  int chars[1024]; int chars_n = 0;
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == " " && (chars_len == 0 || chars[chars_len - 1] == " ")) continue;
    /* push */(s[i]);
  }
  while (chars_len && chars[chars_len - 1] == " ") /* pop */;
  reverse(chars, 0, chars_len - 1);
  int start = 0;
  for (int i = 0; i <= chars_len; i++) {
    if (i == chars_len || chars[i] == " ") {
      reverse(chars, start, i - 1);
      start = i + 1;
    }
  }
  return /* join chars */;
}
