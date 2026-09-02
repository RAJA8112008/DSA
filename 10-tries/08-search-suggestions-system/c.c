// Method 1: Brute
// Time: O(|s| n L) | Space: O(n)
// After each extra character, scan every product, keep those with the prefix, sort, take 3. Correct and slow.

/* after each prefix, collect matches, qsort, take 3 */
int cmpStr(const void* a, const void* b) {
  return strcmp((const char*)a, (const char*)b);
}


// Method 2: Optimal
// Time: O(n L log n + |s| log n) | Space: O(n)
// Sort products once. For each growing prefix, lower-bound the first product >= prefix, then take the next three if they still share the prefix.

int lowerBound(char a[][48], int n, const char* s) {
  int lo = 0, hi = n;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (strcmp(a[mid], s) < 0) lo = mid + 1;
    else hi = mid;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Trie. At each node keep up to 3 lex-smallest words that pass through it (insert into a sorted short list). Typing searchWord is just walking children and reading that list.

typedef struct SugNode {
  struct SugNode* ch[26];
  char sug[3][48];
  int sn;
} SugNode;
void addSug(SugNode* n, const char* w) {
  int i, j;
  if (n->sn < 3) { strcpy(n->sug[n->sn++], w); }
  else if (strcmp(w, n->sug[2]) < 0) strcpy(n->sug[2], w);
  for (i = 0; i < n->sn; i++)
    for (j = i + 1; j < n->sn; j++)
      if (strcmp(n->sug[j], n->sug[i]) < 0) {
        char t[48]; strcpy(t, n->sug[i]); strcpy(n->sug[i], n->sug[j]); strcpy(n->sug[j], t);
      }
}
