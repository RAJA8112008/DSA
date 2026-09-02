// Method 1: Brute
// Time: O(n^2 L) | Space: O(n)
// Put words in a set. For each word, test that every prefix is in the set. Keep the longest, breaking ties lexicographically.

int hasWord(char words[][48], int n, const char* p) {
  int i; for (i = 0; i < n; i++) if (strcmp(words[i], p) == 0) return 1; return 0;
}
void longestWord(char words[][48], int n, char* best) {
  int i, L; best[0] = 0;
  for (i = 0; i < n; i++) {
    int ok = 1, len = (int)strlen(words[i]);
    char p[48];
    for (L = 1; L < len; L++) {
      memcpy(p, words[i], L); p[L] = 0;
      if (!hasWord(words, n, p)) { ok = 0; break; }
    }
    if (!ok) continue;
    if (len > (int)strlen(best) || (len == (int)strlen(best) && strcmp(words[i], best) < 0))
      strcpy(best, words[i]);
  }
}


// Method 2: Optimal
// Time: O(n L log n) | Space: O(n)
// Sort by length then lex. A word is valid if the set already holds word without its last letter (or the word has length 1). Insert only valid words. The last survivor is the answer if you also keep the lex-smallest of that length.

/* sort words by length then strcmp, then scan */
int cmpLen(const void* A, const void* B) {
  const char* a = (const char*)A;
  const char* b = (const char*)B;
  int da = (int)strlen(a), db = (int)strlen(b);
  if (da != db) return da - db;
  return strcmp(a, b);
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Insert every word into a trie with an end flag. DFS only through end nodes. The deepest (then lex-smallest) path is the answer.

void lwDfs(Node* cur, char* path, int len, char* best) {
  int i;
  if (!cur->end) return;
  path[len] = 0;
  if (len > (int)strlen(best) || (len == (int)strlen(best) && strcmp(path, best) < 0)) strcpy(best, path);
  for (i = 0; i < 26; i++) {
    if (!cur->ch[i]) continue;
    path[len] = (char)('a' + i);
    lwDfs(cur->ch[i], path, len + 1, best);
  }
}
