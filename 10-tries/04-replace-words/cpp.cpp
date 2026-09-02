// Method 1: Brute
// Time: O(words * roots * L) | Space: O(1) extra
// For each sentence word, scan every root and keep the shortest one that is a prefix. Easy to write, quadratic in dictionary size.

string replaceWords(vector<string>& dictionary, string sentence) {
  stringstream ss(sentence);
  string w, out;
  while (ss >> w) {
    string best = w;
    for (auto& r : dictionary)
      if (w.size() >= r.size() && w.compare(0, r.size(), r) == 0 && r.size() < best.size()) best = r;
    if (!out.empty()) out += ' ';
    out += best;
  }
  return out;
}


// Method 2: Optimal
// Time: O(total chars) | Space: O(roots)
// Put roots in a set. For each word, try prefixes from length 1 up and take the first hit. That is the shortest root. Faster when few prefixes match.

string replaceWords(vector<string>& dictionary, string sentence) {
  unordered_set<string> set(dictionary.begin(), dictionary.end());
  stringstream ss(sentence);
  string w, out;
  while (ss >> w) {
    string pick = w;
    for (int L = 1; L <= (int)w.size(); L++) {
      string p = w.substr(0, L);
      if (set.count(p)) { pick = p; break; }
    }
    if (!out.empty()) out += ' ';
    out += pick;
  }
  return out;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(roots)
// Trie of roots. Walk each sentence word until you hit an end flag, then stop. Shared prefixes make this the usual interview answer.

string replaceWords(vector<string>& dictionary, string sentence) {
  struct Node { Node* ch[26] = {}; bool end = false; };
  Node* root = new Node();
  for (auto& r : dictionary) {
    Node* cur = root;
    for (char c : r) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
    }
    cur->end = true;
  }
  stringstream ss(sentence);
  string w, out;
  while (ss >> w) {
    Node* cur = root;
    string built, pick = w;
    for (char c : w) {
      int idx = c - 'a';
      if (!cur->ch[idx]) break;
      cur = cur->ch[idx];
      built += c;
      if (cur->end) { pick = built; break; }
    }
    if (!out.empty()) out += ' ';
    out += pick;
  }
  return out;
}
