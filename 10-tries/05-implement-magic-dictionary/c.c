// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// Store the list. For each stored word of the same length, count mismatches. Return true on a count of exactly 1.

typedef struct { char words[256][48]; int n; } MagicDictionary;
void buildDict(MagicDictionary* d, char dict[][48], int m) {
  int i; d->n = m; for (i = 0; i < m; i++) strcpy(d->words[i], dict[i]);
}
int search(MagicDictionary* d, const char* q) {
  int n = (int)strlen(q), i, j;
  for (i = 0; i < d->n; i++) {
    if ((int)strlen(d->words[i]) != n) continue;
    int diff = 0;
    for (j = 0; j < n; j++) if (d->words[i][j] != q[j]) diff++;
    if (diff == 1) return 1;
  }
  return 0;
}


// Method 2: Optimal
// Time: O(L * 26) | Space: O(n L^2)
// For each word, replace each position with '*' and map that pattern to the original letters. On search, look up each starred query and see if another letter is stored. Handles duplicates carefully.

/* pattern keys stored as original word with one '*' */
typedef struct { char key[48]; char letter; } Pair;
typedef struct { Pair p[4096]; int n; } MagicDictionary;
void buildDict(MagicDictionary* d, char dict[][48], int m) {
  int i, j; d->n = 0;
  for (i = 0; i < m; i++) {
    int L = (int)strlen(dict[i]);
    for (j = 0; j < L; j++) {
      strcpy(d->p[d->n].key, dict[i]);
      d->p[d->n].key[j] = '*';
      d->p[d->n].letter = dict[i][j];
      d->n++;
    }
  }
}
int search(MagicDictionary* d, const char* q) {
  char key[48]; int j, k, L = (int)strlen(q);
  for (j = 0; j < L; j++) {
    strcpy(key, q); key[j] = '*';
    for (k = 0; k < d->n; k++)
      if (strcmp(d->p[k].key, key) == 0 && d->p[k].letter != q[j]) return 1;
  }
  return 0;
}


// Method 3: More optimal
// Time: O(26 L) | Space: O(n L)
// Trie DFS with a leftover mismatch budget of 1. At the end of the query the budget must be 0 (exactly one change). Compact and matches the 'magic' story.

int magicDfs(Node* node, const char* q, int i, int left) {
  int k, idx;
  if (!node) return 0;
  if (!q[i]) return node->end && left == 0;
  idx = q[i] - 'a';
  for (k = 0; k < 26; k++) {
    int cost = k == idx ? 0 : 1;
    if (left - cost < 0) continue;
    if (magicDfs(node->ch[k], q, i + 1, left - cost)) return 1;
  }
  return 0;
}
