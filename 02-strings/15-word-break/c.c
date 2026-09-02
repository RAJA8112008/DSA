// Method 1: Brute
// Time: O(2ⁿ) | Space: O(n)
// Each position may start many words. Overlapping failures are recomputed. Stack depth is O(n).
// How it works: dfs(i) is true if i is the end, or some wordDict entry matches s starting at i and dfs continues after it.

/* pass n for array length; simple loops */
int wordBreak(char* s, char wordDict[][64], int wn) {
  void dfs(/* i */) {
    if (i == strlen(s)) return 1;
    for (int w = 0; w < n; w++) {
      char word[1024]; /* wordDict[w] */
      if (/* slice s */ == word && dfs(i + strlen(word))) return 1;
    }
    return 0;
  }
  return dfs(0);
}


// Method 2: Optimal
// Time: O(n² · k) | Space: O(n)
// ok[i] loops previous starts and slices. k is cost of string compare / slice.
// How it works: ok[0] = true. ok[j] is true if some i < j has ok[i] and s.slice(i,j) is in the dictionary Set.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int wordBreak(char* s, char wordDict[][64], int wn) {
  int words_keys[1024]; int words_n = 0;
  /* n is the given length */
  int ok = /* array n + 1 */.fill(0);
  ok[0] = 1;
  for (int j = 1; j <= n; j++) {
    for (int i = 0; i < j; i++) {
      if (ok[i] && map_find(words_keys, words_n, /* slice s */) >= 0) {
        ok[j] = 1;
        break;
      }
    }
  }
  return ok[n];
}


// Method 3: More optimal
// Time: O(n · L) | Space: O(n)
// From each true index i, only try lengths 1..longest word, not every j. L is that max length times slice cost, still typically much less than n for each i.
// How it works: same ok array. If ok[i], try each length up to longest. If the slice is a word, mark ok[i+len].

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int wordBreak(char* s, char wordDict[][64], int wn) {
  int words_keys[1024]; int words_n = 0;
  int longest = 0;
  for (int w = 0; w < n; w++) {
    if (wordDict[w].length > longest) longest = wordDict[w].length;
  }
  /* n is the given length */
  int ok = /* array n + 1 */.fill(0);
  ok[0] = 1;
  for (int i = 0; i < n; i++) {
    if (!ok[i]) continue;
    for (int len = 1; len <= longest && i + len <= n; len++) {
      if (map_find(words_keys, words_n, /* slice s */) >= 0) ok[i + len] = 1;
    }
  }
  return ok[n];
}
