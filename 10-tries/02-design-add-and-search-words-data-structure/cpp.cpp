// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep a list. For each stored word of the same length, compare char by char and treat '.' as a free pass. Simple and slow when the dictionary is large.

struct WordDictionary {
  vector<string> words;
  void addWord(string word) { words.push_back(word); }
  bool search(string word) {
    int n = (int)word.size();
    for (auto& w : words) {
      if ((int)w.size() != n) continue;
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (word[j] != '.' && word[j] != w[j]) { ok = false; break; }
      }
      if (ok) return true;
    }
    return false;
  }
};


// Method 2: Optimal
// Time: O(k L) | Space: O(n L)
// Bucket words by length so a pattern of length L only scans that bucket. Still linear in the bucket size, but you skip obviously impossible words.

struct WordDictionary {
  unordered_map<int, vector<string>> byLen;
  void addWord(string word) { byLen[(int)word.size()].push_back(word); }
  bool search(string word) {
    int n = (int)word.size();
    auto it = byLen.find(n);
    if (it == byLen.end()) return false;
    for (auto& w : it->second) {
      bool ok = true;
      for (int j = 0; j < n; j++) {
        if (word[j] != '.' && word[j] != w[j]) { ok = false; break; }
      }
      if (ok) return true;
    }
    return false;
  }
};


// Method 3: More optimal
// Time: O(26^d L) | Space: O(n L)
// Trie DFS. A letter follows one child. A '.' tries every living child. d is the number of dots. This is the expected design.

struct WordDictionary {
  struct Node { Node* ch[26] = {}; bool end = false; };
  Node* root = new Node();
  void addWord(string word) {
    Node* cur = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
    }
    cur->end = true;
  }
  bool dfs(Node* node, const string& word, int i) {
    if (!node) return false;
    if (i == (int)word.size()) return node->end;
    char c = word[i];
    if (c == '.') {
      for (int k = 0; k < 26; k++) if (dfs(node->ch[k], word, i + 1)) return true;
      return false;
    }
    return dfs(node->ch[c - 'a'], word, i + 1);
  }
  bool search(string word) { return dfs(root, word, 0); }
};
