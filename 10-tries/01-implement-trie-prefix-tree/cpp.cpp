// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep every inserted string in an array. search and startsWith scan the whole list. Correct, and fine for tiny dictionaries, but not the point of the problem.

struct Trie {
  vector<string> words;
  void insert(string word) { words.push_back(word); }
  bool search(string word) {
    for (auto& w : words) if (w == word) return true;
    return false;
  }
  bool startsWith(string prefix) {
    int n = (int)prefix.size();
    for (auto& w : words)
      if ((int)w.size() >= n && w.compare(0, n, prefix) == 0) return true;
    return false;
  }
};


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// A set of full words plus a set of every prefix. Each call is a hash lookup. Extra memory stores every prefix string, which a trie shares instead.

struct Trie {
  unordered_set<string> words, prefs;
  void insert(string word) {
    words.insert(word);
    string p;
    for (char c : word) { p += c; prefs.insert(p); }
  }
  bool search(string word) { return words.count(word); }
  bool startsWith(string prefix) { return prefs.count(prefix); }
};


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Real trie. Shared prefixes share nodes. insert, search, and startsWith each walk L children. This is the expected interview finish.

struct Trie {
  struct Node { Node* ch[26] = {}; bool end = false; };
  Node* root = new Node();
  void insert(string word) {
    Node* cur = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
    }
    cur->end = true;
  }
  bool search(string word) {
    Node* cur = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!cur->ch[idx]) return false;
      cur = cur->ch[idx];
    }
    return cur->end;
  }
  bool startsWith(string prefix) {
    Node* cur = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!cur->ch[idx]) return false;
      cur = cur->ch[idx];
    }
    return true;
  }
};
