// Method 1: Brute
// Time: O(words * roots * L) | Space: O(1) extra
// For each sentence word, scan every root and keep the shortest one that is a prefix. Easy to write, quadratic in dictionary size.

void replaceWords(char dict[][48], int dn, char words[][48], int wn) {
  int i, j;
  for (i = 0; i < wn; i++) {
    char best[48];
    int blen;
    strcpy(best, words[i]);
    blen = (int)strlen(best);
    for (j = 0; j < dn; j++) {
      int rl = (int)strlen(dict[j]);
      if ((int)strlen(words[i]) >= rl && strncmp(words[i], dict[j], rl) == 0 && rl < blen) {
        strcpy(best, dict[j]);
        blen = rl;
      }
    }
    strcpy(words[i], best);
  }
}


// Method 2: Optimal
// Time: O(total chars) | Space: O(roots)
// Put roots in a set. For each word, try prefixes from length 1 up and take the first hit. That is the shortest root. Faster when few prefixes match.

int inDict(char dict[][48], int dn, const char* p) {
  int j; for (j = 0; j < dn; j++) if (strcmp(dict[j], p) == 0) return 1; return 0;
}
void replaceWordsSet(char dict[][48], int dn, char words[][48], int wn) {
  int i, L;
  for (i = 0; i < wn; i++) {
    int n = (int)strlen(words[i]);
    char p[48];
    for (L = 1; L <= n; L++) {
      memcpy(p, words[i], L); p[L] = 0;
      if (inDict(dict, dn, p)) { strcpy(words[i], p); break; }
    }
  }
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(roots)
// Trie of roots. Walk each sentence word until you hit an end flag, then stop. Shared prefixes make this the usual interview answer.

void replaceWordsTrie(char dict[][48], int dn, char words[][48], int wn) {
  Node* root = newNode();
  int i, j;
  for (i = 0; i < dn; i++) {
    Node* cur = root;
    for (j = 0; dict[i][j]; j++) {
      int idx = dict[i][j] - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = newNode();
      cur = cur->ch[idx];
    }
    cur->end = 1;
  }
  for (i = 0; i < wn; i++) {
    Node* cur = root;
    char built[48]; int k = 0;
    for (j = 0; words[i][j]; j++) {
      int idx = words[i][j] - 'a';
      if (!cur->ch[idx]) break;
      cur = cur->ch[idx];
      built[k++] = words[i][j]; built[k] = 0;
      if (cur->end) { strcpy(words[i], built); break; }
    }
  }
}
