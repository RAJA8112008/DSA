// Method 1: Brute
// Time: O(4^n * n) | Space: O(4^n * n)
// Each digit branches up to 4 ways. path + letter allocates a new string every time. n is the number of digits. Fine for n <= 4, wasteful copies.

void go(const char* digits, int i, char* path, int len, const char** mp) {
  int j;
  if (digits[i] == '\0') { path[len] = '\0'; printf("%s\n", path); return; }
  const char* letters = mp[digits[i] - '0'];
  for (j = 0; letters[j]; j++) {
    path[len] = letters[j];
    go(digits, i + 1, path, len + 1, mp);
  }
}


// Method 2: Optimal
// Time: O(4^n * n) | Space: O(n)
// One char buffer. Push a letter, recurse, pop. Copy to the answer only at the last digit. Extra space is O(n) besides the output.

void go(const char* digits, int i, char* path, int len, const char** mp) {
  int j;
  if (digits[i] == '\0') { path[len] = '\0'; printf("%s\n", path); return; }
  const char* letters = mp[digits[i] - '0'];
  for (j = 0; letters[j]; j++) {
    path[len] = letters[j];
    go(digits, i + 1, path, len + 1, mp);
  }
}


// Method 3: More optimal
// Time: O(4^n * n) | Space: O(4^n * n)
// Iterative: start with [""]. For each digit, replace every prefix with prefix+letter. No recursion. Empty digits return [] immediately (early stop).

/* cur holds prefixes; ncur is count. Early stop if digits empty. */
int letterCombinations(const char* digits, char out[][16]) {
  const char* mp[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  int ncur = 1, i, p, j, nnext;
  char cur[256][16], next[256][16];
  if (digits[0] == '\0') return 0;
  cur[0][0] = '\0';
  for (i = 0; digits[i]; i++) {
    const char* letters = mp[digits[i] - '0'];
    nnext = 0;
    for (p = 0; p < ncur; p++) for (j = 0; letters[j]; j++) {
      sprintf(next[nnext], "%s%c", cur[p], letters[j]);
      nnext++;
    }
    ncur = nnext;
    for (p = 0; p < ncur; p++) strcpy(cur[p], next[p]);
  }
  for (p = 0; p < ncur; p++) strcpy(out[p], cur[p]);
  return ncur;
}
