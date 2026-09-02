// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// Store the list. For each stored word of the same length, count mismatches. Return true on a count of exactly 1.

struct MagicDictionary {
  vector<string> words;
  void buildDict(vector<string> dictionary) { words = dictionary; }
  bool search(string searchWord) {
    int n = (int)searchWord.size();
    for (auto& w : words) {
      if ((int)w.size() != n) continue;
      int diff = 0;
      for (int j = 0; j < n; j++) if (w[j] != searchWord[j]) diff++;
      if (diff == 1) return true;
    }
    return false;
  }
};


// Method 2: Optimal
// Time: O(L * 26) | Space: O(n L^2)
// For each word, replace each position with '*' and map that pattern to the original letters. On search, look up each starred query and see if another letter is stored. Handles duplicates carefully.

struct MagicDictionary {
  unordered_map<string, vector<char>> mp;
  void buildDict(vector<string> dictionary) {
    mp.clear();
    for (auto& w : dictionary) {
      for (int j = 0; j < (int)w.size(); j++) {
        string key = w.substr(0, j) + "*" + w.substr(j + 1);
        mp[key].push_back(w[j]);
      }
    }
  }
  bool search(string searchWord) {
    for (int j = 0; j < (int)searchWord.size(); j++) {
      string key = searchWord.substr(0, j) + "*" + searchWord.substr(j + 1);
      for (char letter : mp[key]) if (letter != searchWord[j]) return true;
    }
    return false;
  }
};


// Method 3: More optimal
// Time: O(26 L) | Space: O(n L)
// Trie DFS with a leftover mismatch budget of 1. At the end of the query the budget must be 0 (exactly one change). Compact and matches the 'magic' story.

struct MagicDictionary {
  struct Node { Node* ch[26] = {}; bool end = false; };
  Node* root = new Node();
  void buildDict(vector<string> dictionary) {
    root = new Node();
    for (auto& w : dictionary) {
      Node* cur = root;
      for (char c : w) {
        int idx = c - 'a';
        if (!cur->ch[idx]) cur->ch[idx] = new Node();
        cur = cur->ch[idx];
      }
      cur->end = true;
    }
  }
  bool dfs(Node* node, const string& q, int i, int left) {
    if (!node) return false;
    if (i == (int)q.size()) return node->end && left == 0;
    int idx = q[i] - 'a';
    for (int k = 0; k < 26; k++) {
      int cost = k == idx ? 0 : 1;
      if (left - cost < 0) continue;
      if (dfs(node->ch[k], q, i + 1, left - cost)) return true;
    }
    return false;
  }
  bool search(string searchWord) { return dfs(root, searchWord, 0, 1); }
};
