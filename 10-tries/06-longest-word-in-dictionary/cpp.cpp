// Method 1: Brute
// Time: O(n^2 L) | Space: O(n)
// Put words in a set. For each word, test that every prefix is in the set. Keep the longest, breaking ties lexicographically.

string longestWord(vector<string>& words) {
  unordered_set<string> st(words.begin(), words.end());
  string best;
  for (auto& w : words) {
    bool ok = true;
    for (int L = 1; L < (int)w.size(); L++) {
      if (!st.count(w.substr(0, L))) { ok = false; break; }
    }
    if (!ok) continue;
    if (w.size() > best.size() || (w.size() == best.size() && w < best)) best = w;
  }
  return best;
}


// Method 2: Optimal
// Time: O(n L log n) | Space: O(n)
// Sort by length then lex. A word is valid if the set already holds word without its last letter (or the word has length 1). Insert only valid words. The last survivor is the answer if you also keep the lex-smallest of that length.

string longestWord(vector<string>& words) {
  auto a = words;
  sort(a.begin(), a.end(), [](const string& x, const string& y) {
    if (x.size() != y.size()) return x.size() < y.size();
    return x < y;
  });
  unordered_set<string> good;
  good.insert("");
  string best;
  for (auto& w : a) {
    if (good.count(w.substr(0, w.size() - 1))) {
      good.insert(w);
      if (w.size() > best.size()) best = w;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Insert every word into a trie with an end flag. DFS only through end nodes. The deepest (then lex-smallest) path is the answer.

string longestWord(vector<string>& words) {
  struct Node { Node* ch[26] = {}; bool end = false; };
  Node* root = new Node();
  root->end = true;
  for (auto& w : words) {
    Node* cur = root;
    for (char c : w) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
    }
    cur->end = true;
  }
  string best;
  function<void(Node*, string)> dfs = [&](Node* cur, string path) {
    if (!cur->end) return;
    if (path.size() > best.size() || (path.size() == best.size() && path < best)) best = path;
    for (int i = 0; i < 26; i++) if (cur->ch[i]) dfs(cur->ch[i], path + char('a' + i));
  };
  dfs(root, "");
  return best;
}
