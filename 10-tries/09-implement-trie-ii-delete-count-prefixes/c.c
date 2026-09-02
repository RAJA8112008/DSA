// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// An array of words. equalTo counts exact matches. startingWith counts prefix matches. erase removes the first copy.

typedef struct { char words[512][48]; int n; } Trie;
void insert(Trie* t, const char* word) { strcpy(t->words[t->n++], word); }
int countWordsEqualTo(Trie* t, const char* word) {
  int i, c = 0; for (i = 0; i < t->n; i++) if (strcmp(t->words[i], word) == 0) c++; return c;
}
int countWordsStartingWith(Trie* t, const char* prefix) {
  int i, c = 0, n = (int)strlen(prefix);
  for (i = 0; i < t->n; i++)
    if ((int)strlen(t->words[i]) >= n && strncmp(t->words[i], prefix, n) == 0) c++;
  return c;
}
void erase(Trie* t, const char* word) {
  int i, j;
  for (i = 0; i < t->n; i++) if (strcmp(t->words[i], word) == 0) {
    for (j = i + 1; j < t->n; j++) strcpy(t->words[j - 1], t->words[j]);
    t->n--;
    return;
  }
}


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// wordCount map and prefixCount map. insert / erase add or subtract 1 along every prefix. Queries are hash lookups. Watch erase: never go below zero.

typedef struct { char k[48]; int v; } KV;
typedef struct { KV word[512]; int wn; KV pref[4096]; int pn; } Trie;
static int findKV(KV* a, int n, const char* k) {
  int i; for (i = 0; i < n; i++) if (strcmp(a[i].k, k) == 0) return i; return -1;
}
static void addKV(KV* a, int* n, const char* k, int d) {
  int i = findKV(a, *n, k);
  if (i >= 0) a[i].v += d;
  else { strcpy(a[*n].k, k); a[*n].v = d; (*n)++; }
}
void insert(Trie* t, const char* word) {
  char p[48]; int i, k = 0;
  addKV(t->word, &t->wn, word, 1);
  p[0] = 0;
  for (i = 0; word[i]; i++) { p[k++] = word[i]; p[k] = 0; addKV(t->pref, &t->pn, p, 1); }
}
int countWordsEqualTo(Trie* t, const char* word) {
  int i = findKV(t->word, t->wn, word); return i >= 0 ? t->word[i].v : 0;
}
int countWordsStartingWith(Trie* t, const char* prefix) {
  int i = findKV(t->pref, t->pn, prefix); return i >= 0 ? t->pref[i].v : 0;
}


// Method 3: More optimal
// Time: O(L) | Space: O(total chars) shared
// Trie node has words (how many end here) and pref (how many pass through). insert increments. erase decrements and unlinks a child whose pref hits 0.

typedef struct T2 { struct T2* ch[26]; int words, pref; } T2;
typedef struct { T2* root; } TrieII;
T2* t2new(void) { return (T2*)calloc(1, sizeof(T2)); }
void t2insert(TrieII* t, const char* word) {
  T2* cur = t->root;
  int i;
  for (i = 0; word[i]; i++) {
    int idx = word[i] - 'a';
    if (!cur->ch[idx]) cur->ch[idx] = t2new();
    cur = cur->ch[idx];
    cur->pref++;
  }
  cur->words++;
}
