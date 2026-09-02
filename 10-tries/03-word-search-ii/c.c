// Method 1: Brute
// Time: O(w m n 4^L) | Space: O(L)
// For each word, DFS from every cell. Mark the cell, try four neighbors, unmark. Correct, but you restart the whole board for every dictionary word.

int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int dfs(char** board, int rows, int cols, int r, int c, int k, const char* word) {
  int i;
  if (!word[k]) return 1;
  if (r < 0 || c < 0 || r >= rows || c >= cols) return 0;
  if (board[r][c] != word[k]) return 0;
  char saved = board[r][c];
  board[r][c] = '#';
  for (i = 0; i < 4; i++) {
    if (dfs(board, rows, cols, r + dirs[i][0], c + dirs[i][1], k + 1, word)) {
      board[r][c] = saved;
      return 1;
    }
  }
  board[r][c] = saved;
  return 0;
}


// Method 2: Optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Build a trie of all words, then DFS from every cell following only living children. One board walk instead of one walk per word.

typedef struct TNode { struct TNode* ch[26]; int end; char word[48]; } TNode;
TNode* tnode(void) { return (TNode*)calloc(1, sizeof(TNode)); }
int dirs4[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
void dfs2(char** board, int rows, int cols, int r, int c, TNode* cur,
          char out[][48], int* on) {
  int i;
  if (r < 0 || c < 0 || r >= rows || c >= cols) return;
  char ch = board[r][c];
  TNode* nxt;
  if (ch == '#') return;
  nxt = cur->ch[ch - 'a'];
  if (!nxt) return;
  if (nxt->end) {
    int dup = 0, k;
    for (k = 0; k < *on; k++) if (strcmp(out[k], nxt->word) == 0) dup = 1;
    if (!dup) strcpy(out[(*on)++], nxt->word);
  }
  board[r][c] = '#';
  for (i = 0; i < 4; i++) dfs2(board, rows, cols, r + dirs4[i][0], c + dirs4[i][1], nxt, out, on);
  board[r][c] = ch;
}


// Method 3: More optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Same trie DFS, but after you emit a word you clear that end mark (and optionally prune empty children). That stops duplicate work and extra copies of the same word.

/* After a hit, clear tnode->end so the same word is not pushed twice.
   Map children: linear scan of 26 slots is enough in C. */
typedef struct TNode2 { struct TNode2* ch[26]; char word[48]; } TNode2;
void dfs3(char** board, int rows, int cols, int r, int c, TNode2* cur,
          char out[][48], int* on) {
  char ch = board[r][c];
  TNode2* nxt;
  int i;
  if (ch == '#' || ch < 'a' || ch > 'z') return;
  nxt = cur->ch[ch - 'a'];
  if (!nxt) return;
  if (nxt->word[0]) {
    strcpy(out[(*on)++], nxt->word);
    nxt->word[0] = 0;
  }
  board[r][c] = '#';
  for (i = 0; i < 4; i++) {
    int nr = r + dirs4[i][0], nc = c + dirs4[i][1];
    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols) continue;
    if (board[nr][nc] == '#') continue;
    dfs3(board, rows, cols, nr, nc, nxt, out, on);
  }
  board[r][c] = ch;
}
