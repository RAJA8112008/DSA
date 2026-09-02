// Method 1: Brute
// Time: O(w m n 4^L) | Space: O(L)
// For each word, DFS from every cell. Mark the cell, try four neighbors, unmark. Correct, but you restart the whole board for every dictionary word.

class Solution {
  int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  bool dfs(vector<vector<char>>& board, int r, int c, int k, const string& word) {
    if (k == (int)word.size()) return true;
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return false;
    if (board[r][c] != word[k]) return false;
    char saved = board[r][c];
    board[r][c] = '#';
    for (int i = 0; i < 4; i++) {
      if (dfs(board, r + dirs[i][0], c + dirs[i][1], k + 1, word)) {
        board[r][c] = saved;
        return true;
      }
    }
    board[r][c] = saved;
    return false;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<string> out;
    for (auto& word : words) {
      bool found = false;
      for (int r = 0; r < (int)board.size() && !found; r++)
        for (int c = 0; c < (int)board[0].size() && !found; c++)
          if (dfs(board, r, c, 0, word)) found = true;
      if (found) out.push_back(word);
    }
    return out;
  }
};


// Method 2: Optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Build a trie of all words, then DFS from every cell following only living children. One board walk instead of one walk per word.

class Solution {
  struct Node { Node* ch[26] = {}; bool end = false; string word; };
  int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  void dfs(vector<vector<char>>& board, int r, int c, Node* cur,
           unordered_set<string>& seen, vector<string>& out) {
    if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size()) return;
    char ch = board[r][c];
    if (ch == '#') return;
    Node* nxt = cur->ch[ch - 'a'];
    if (!nxt) return;
    if (nxt->end && !seen.count(nxt->word)) { seen.insert(nxt->word); out.push_back(nxt->word); }
    board[r][c] = '#';
    for (int i = 0; i < 4; i++) dfs(board, r + dirs[i][0], c + dirs[i][1], nxt, seen, out);
    board[r][c] = ch;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Node* root = new Node();
    for (auto& s : words) {
      Node* cur = root;
      for (char ch : s) {
        int idx = ch - 'a';
        if (!cur->ch[idx]) cur->ch[idx] = new Node();
        cur = cur->ch[idx];
      }
      cur->end = true; cur->word = s;
    }
    unordered_set<string> seen;
    vector<string> out;
    for (int r = 0; r < (int)board.size(); r++)
      for (int c = 0; c < (int)board[0].size(); c++)
        dfs(board, r, c, root, seen, out);
    return out;
  }
};


// Method 3: More optimal
// Time: O(m n 4^L) | Space: O(total chars)
// Same trie DFS, but after you emit a word you clear that end mark (and optionally prune empty children). That stops duplicate work and extra copies of the same word.

class Solution {
  struct Node {
    unordered_map<char, Node*> ch;
    string word;
  };
  int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  void dfs(vector<vector<char>>& board, int r, int c, Node* cur, vector<string>& out) {
    char ch = board[r][c];
    auto it = cur->ch.find(ch);
    if (it == cur->ch.end()) return;
    Node* nxt = it->second;
    if (!nxt->word.empty()) { out.push_back(nxt->word); nxt->word.clear(); }
    board[r][c] = '#';
    for (int i = 0; i < 4; i++) {
      int nr = r + dirs[i][0], nc = c + dirs[i][1];
      if (nr < 0 || nc < 0 || nr >= (int)board.size() || nc >= (int)board[0].size()) continue;
      if (board[nr][nc] == '#') continue;
      dfs(board, nr, nc, nxt, out);
    }
    board[r][c] = ch;
  }
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    Node* root = new Node();
    for (auto& s : words) {
      Node* cur = root;
      for (char ch : s) {
        if (!cur->ch.count(ch)) cur->ch[ch] = new Node();
        cur = cur->ch[ch];
      }
      cur->word = s;
    }
    vector<string> out;
    for (int r = 0; r < (int)board.size(); r++)
      for (int c = 0; c < (int)board[0].size(); c++)
        dfs(board, r, c, root, out);
    return out;
  }
};
