// Method 1: Brute
// Time: O(n^2 L) | Space: O(1)
// For every ordered pair, concatenate and test palindrome. Fine for tiny n, not for n = 5000.

bool isPal(const string& s) {
  int i = 0, j = (int)s.size() - 1;
  while (i < j) { if (s[i] != s[j]) return false; i++; j--; }
  return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
  vector<vector<int>> out;
  int n = (int)words.size();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (i != j && isPal(words[i] + words[j])) out.push_back({i, j});
  return out;
}


// Method 2: Optimal
// Time: O(n L^2) | Space: O(n L)
// Map word -> index. For each word, try every split. If the left half is a palindrome, look up reverse(right). If the right half is a palindrome, look up reverse(left). Handles the empty-word case.

bool isPal(const string& s, int a, int b) {
  while (a < b) { if (s[a] != s[b]) return false; a++; b--; }
  return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
  unordered_map<string, int> idx;
  for (int i = 0; i < (int)words.size(); i++) idx[words[i]] = i;
  vector<vector<int>> out;
  unordered_set<string> seen;
  auto add = [&](int i, int j) {
    if (i == j) return;
    string key = to_string(i) + "," + to_string(j);
    if (seen.count(key)) return;
    seen.insert(key);
    out.push_back({i, j});
  };
  for (int i = 0; i < (int)words.size(); i++) {
    string w = words[i];
    int n = (int)w.size();
    for (int cut = 0; cut <= n; cut++) {
      if (isPal(w, cut, n - 1)) {
        string rev = w.substr(0, cut);
        reverse(rev.begin(), rev.end());
        if (idx.count(rev)) add(i, idx[rev]);
      }
      if (cut > 0 && isPal(w, 0, cut - 1)) {
        string rev = w.substr(cut);
        reverse(rev.begin(), rev.end());
        if (idx.count(rev)) add(idx[rev], i);
      }
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(n L^2) | Space: O(n L)
// Insert the reverse of every word into a trie, storing the index at the end. While walking a word, if the remaining suffix is a palindrome and the node is an end, you have a pair. Also collect end indexes whose leftover reverse is a palindrome. Same complexity, trie picture.

struct Node {
  unordered_map<char, Node*> ch;
  int idx = -1;
  vector<int> palBelow;
};
bool isPal(const string& s, int a, int b) {
  while (a < b) { if (s[a] != s[b]) return false; a++; b--; }
  return true;
}
vector<vector<int>> palindromePairs(vector<string>& words) {
  Node* root = new Node();
  for (int i = 0; i < (int)words.size(); i++) {
    const string& w = words[i];
    Node* cur = root;
    for (int j = (int)w.size() - 1; j >= 0; j--) {
      if (isPal(w, 0, j)) cur->palBelow.push_back(i);
      char c = w[j];
      if (!cur->ch.count(c)) cur->ch[c] = new Node();
      cur = cur->ch[c];
    }
    cur->idx = i;
    cur->palBelow.push_back(i);
  }
  vector<vector<int>> out;
  unordered_set<string> seen;
  auto add = [&](int i, int j) {
    if (i == j) return;
    string key = to_string(i) + "," + to_string(j);
    if (seen.count(key)) return;
    seen.insert(key);
    out.push_back({i, j});
  };
  for (int i = 0; i < (int)words.size(); i++) {
    const string& w = words[i];
    Node* cur = root;
    bool fell = false;
    for (int k = 0; k < (int)w.size(); k++) {
      if (cur->idx >= 0 && isPal(w, k, (int)w.size() - 1)) add(i, cur->idx);
      if (!cur->ch.count(w[k])) { fell = true; break; }
      cur = cur->ch[w[k]];
    }
    if (!fell) for (int j : cur->palBelow) add(i, j);
  }
  return out;
}
