// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep a list. For each stored word of the same length, compare char by char and treat '.' as a free pass. Simple and slow when the dictionary is large.

typedef struct { char words[256][48]; int n; } WordDictionary;
void addWord(WordDictionary* d, const char* word) {
  strcpy(d->words[d->n++], word);
}
int search(WordDictionary* d, const char* word) {
  int n = (int)strlen(word), i, j;
  for (i = 0; i < d->n; i++) {
    if ((int)strlen(d->words[i]) != n) continue;
    int ok = 1;
    for (j = 0; j < n; j++) {
      if (word[j] != '.' && word[j] != d->words[i][j]) { ok = 0; break; }
    }
    if (ok) return 1;
  }
  return 0;
}


// Method 2: Optimal
// Time: O(k L) | Space: O(n L)
// Bucket words by length so a pattern of length L only scans that bucket. Still linear in the bucket size, but you skip obviously impossible words.

/* byLen[len][0..cnt[len]-1] */
typedef struct {
  char byLen[40][128][48];
  int cnt[40];
} WordDictionary;
void addWord(WordDictionary* d, const char* word) {
  int n = (int)strlen(word);
  strcpy(d->byLen[n][d->cnt[n]++], word);
}
int search(WordDictionary* d, const char* word) {
  int n = (int)strlen(word), i, j;
  for (i = 0; i < d->cnt[n]; i++) {
    int ok = 1;
    for (j = 0; j < n; j++) {
      if (word[j] != '.' && word[j] != d->byLen[n][i][j]) { ok = 0; break; }
    }
    if (ok) return 1;
  }
  return 0;
}


// Method 3: More optimal
// Time: O(26^d L) | Space: O(n L)
// Trie DFS. A letter follows one child. A '.' tries every living child. d is the number of dots. This is the expected design.

typedef struct Node { struct Node* ch[26]; int end; } Node;
typedef struct { Node* root; } WordDictionary;
Node* newNode(void) { return (Node*)calloc(1, sizeof(Node)); }
void wdInit(WordDictionary* d) { d->root = newNode(); }
void addWord(WordDictionary* d, const char* word) {
  Node* cur = d->root;
  int i;
  for (i = 0; word[i]; i++) {
    int idx = word[i] - 'a';
    if (!cur->ch[idx]) cur->ch[idx] = newNode();
    cur = cur->ch[idx];
  }
  cur->end = 1;
}
int dfs(Node* node, const char* word, int i) {
  int k;
  if (!node) return 0;
  if (!word[i]) return node->end;
  if (word[i] == '.') {
    for (k = 0; k < 26; k++) if (dfs(node->ch[k], word, i + 1)) return 1;
    return 0;
  }
  return dfs(node->ch[word[i] - 'a'], word, i + 1);
}
int search(WordDictionary* d, const char* word) { return dfs(d->root, word, 0); }
