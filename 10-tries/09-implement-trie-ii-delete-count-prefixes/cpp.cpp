// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// An array of words. equalTo counts exact matches. startingWith counts prefix matches. erase removes the first copy.

struct Trie {
  vector<string> words;
  void insert(string word) { words.push_back(word); }
  int countWordsEqualTo(string word) {
    int c = 0;
    for (auto& w : words) if (w == word) c++;
    return c;
  }
  int countWordsStartingWith(string prefix) {
    int c = 0, n = (int)prefix.size();
    for (auto& w : words)
      if ((int)w.size() >= n && w.compare(0, n, prefix) == 0) c++;
    return c;
  }
  void erase(string word) {
    auto it = find(words.begin(), words.end(), word);
    if (it != words.end()) words.erase(it);
  }
};


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// wordCount map and prefixCount map. insert / erase add or subtract 1 along every prefix. Queries are hash lookups. Watch erase: never go below zero.

struct Trie {
  unordered_map<string, int> wordCount, prefCount;
  void insert(string word) {
    wordCount[word]++;
    string p;
    for (char c : word) { p += c; prefCount[p]++; }
  }
  int countWordsEqualTo(string word) { return wordCount[word]; }
  int countWordsStartingWith(string prefix) { return prefCount[prefix]; }
  void erase(string word) {
    if (!wordCount[word]) return;
    wordCount[word]--;
    string p;
    for (char c : word) { p += c; prefCount[p]--; }
  }
};


// Method 3: More optimal
// Time: O(L) | Space: O(total chars) shared
// Trie node has words (how many end here) and pref (how many pass through). insert increments. erase decrements and unlinks a child whose pref hits 0.

struct Trie {
  struct Node { Node* ch[26] = {}; int words = 0, pref = 0; };
  Node* root = new Node();
  void insert(string word) {
    Node* cur = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
      cur->pref++;
    }
    cur->words++;
  }
  int countWordsEqualTo(string word) {
    Node* cur = root;
    for (char c : word) {
      int idx = c - 'a';
      if (!cur->ch[idx]) return 0;
      cur = cur->ch[idx];
    }
    return cur->words;
  }
  int countWordsStartingWith(string prefix) {
    Node* cur = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!cur->ch[idx]) return 0;
      cur = cur->ch[idx];
    }
    return cur->pref;
  }
  void erase(string word) {
    if (!countWordsEqualTo(word)) return;
    Node* cur = root;
    for (char c : word) {
      int idx = c - 'a';
      Node* nxt = cur->ch[idx];
      nxt->pref--;
      if (nxt->pref == 0) { cur->ch[idx] = nullptr; return; }
      cur = nxt;
    }
    cur->words--;
  }
};
