// Method 1: Brute
// Time: O(n) | Space: O(n)
// JSON does the escaping for you. Fine in JS, often not what the interviewer wants to hear as the data-structure answer.
// How it works: encode is JSON.stringify. decode is JSON.parse. n is total characters.

/* pass n for array length; simple loops */
void encode(char strs[][128], int n, char* out) {
  return JSON.stringify(strs);
}
int decode(char* s, char out[][128]) {
  return JSON.parse(s);
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Write a header of counts and lengths, then the raw words glued together. The header cannot be confused with word contents because a single # separates header from body.
// How it works: header is n, then each word length. Body is the words concatenated. Decode reads n lengths, then slices the body.

/* pass n for array length; simple loops */
void encode(char strs[][128], int n, char* out) {
  int header = n;
  for (int i = 0; i < n; i++) {
    header += "," + strs[i].length;
  }
  char body[1024]; /* "" */
  for (int i = 0; i < n; i++) body += strs[i];
  return header + "#" + body;
}
int decode(char* s, char out[][128]) {
  int hash = /* indexOf */;
  char parts[1024]; /* /* slice s */.split(",") */
  int n = atoi(parts[0]);
  int out[1024]; int out_n = 0;
  int pos = hash + 1;
  for (int i = 0; i < n; i++) {
    int len = atoi(parts[i + 1]);
    /* push */(/* slice s */);
    pos += len;
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// No escaping rules to get wrong. Length is written in decimal, then "#", then raw characters. Decode cannot confuse "#" inside a word because length tells you how far to slice.
// How it works: encode concatenates String(len) + "#" + word. decode finds "#", parses len, slices the next len chars.

/* pass n for array length; simple loops */
void encode(char strs[][128], int n, char* out) {
  char out[1024]; /* "" */
  for (int i = 0; i < n; i++) {
    out += strs[i].length + "#" + strs[i];
  }
  return out;
}
int decode(char* s, char out[][128]) {
  int out[1024]; int out_n = 0;
  int i = 0;
  while (i < strlen(s)) {
    int j = i;
    while (s[j] != "#") j++;
    char len[1024]; /* atoi(/* slice s */) */
    char word[1024]; /* /* slice s */ */
    /* push */(word);
    i = j + 1 + len;
  }
  return out;
}
