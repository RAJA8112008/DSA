// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep every inserted string in an array. search and startsWith scan the whole list. Correct, and fine for tiny dictionaries, but not the point of the problem.

typedef struct {
  char words[256][48];
  int n;
} Trie;
void insert(Trie* t, const char* word) {
  strcpy(t->words[t->n++], word);
}
int search(Trie* t, const char* word) {
  int i;
  for (i = 0; i < t->n; i++) if (strcmp(t->words[i], word) == 0) return 1;
  return 0;
}
int startsWith(Trie* t, const char* prefix) {
  int i, n = (int)strlen(prefix);
  for (i = 0; i < t->n; i++)
    if ((int)strlen(t->words[i]) >= n && strncmp(t->words[i], prefix, n) == 0) return 1;
  return 0;
}


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// A set of full words plus a set of every prefix. Each call is a hash lookup. Extra memory stores every prefix string, which a trie shares instead.

/* two parallel string tables stand in for hash sets */
typedef struct {
  char words[256][48]; int wn;
  char prefs[2048][48]; int pn;
} Trie;
static int has(char a[][48], int n, const char* s) {
  int i; for (i = 0; i < n; i++) if (strcmp(a[i], s) == 0) return 1; return 0;
}
void insert(Trie* t, const char* word) {
  char p[48]; int i, k = 0;
  strcpy(t->words[t->wn++], word);
  p[0] = 0;
  for (i = 0; word[i]; i++) {
    p[k++] = word[i]; p[k] = 0;
    if (!has(t->prefs, t->pn, p)) strcpy(t->prefs[t->pn++], p);
  }
}
int search(Trie* t, const char* word) { return has(t->words, t->wn, word); }
int startsWith(Trie* t, const char* prefix) { return has(t->prefs, t->pn, prefix); }


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Real trie. Shared prefixes share nodes. insert, search, and startsWith each walk L children. This is the expected interview finish.

typedef struct Node { struct Node* ch[26]; int end; } Node;
typedef struct { Node* root; } Trie;
Node* newNode(void) { return (Node*)calloc(1, sizeof(Node)); }
void trieInit(Trie* t) { t->root = newNode(); }
void insert(Trie* t, const char* word) {
  Node* cur = t->root;
  int i;
  for (i = 0; word[i]; i++) {
    int idx = word[i] - 'a';
    if (!cur->ch[idx]) cur->ch[idx] = newNode();
    cur = cur->ch[idx];
  }
  cur->end = 1;
}
int search(Trie* t, const char* word) {
  Node* cur = t->root;
  int i;
  for (i = 0; word[i]; i++) {
    int idx = word[i] - 'a';
    if (!cur->ch[idx]) return 0;
    cur = cur->ch[idx];
  }
  return cur->end;
}
int startsWith(Trie* t, const char* prefix) {
  Node* cur = t->root;
  int i;
  for (i = 0; prefix[i]; i++) {
    int idx = prefix[i] - 'a';
    if (!cur->ch[idx]) return 0;
    cur = cur->ch[idx];
  }
  return 1;
}
