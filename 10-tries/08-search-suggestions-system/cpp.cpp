// Method 1: Brute
// Time: O(|s| n L) | Space: O(n)
// After each extra character, scan every product, keep those with the prefix, sort, take 3. Correct and slow.

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
  vector<vector<string>> out;
  string pref;
  for (char c : searchWord) {
    pref += c;
    vector<string> hit;
    int n = (int)pref.size();
    for (auto& p : products)
      if ((int)p.size() >= n && p.compare(0, n, pref) == 0) hit.push_back(p);
    sort(hit.begin(), hit.end());
    if ((int)hit.size() > 3) hit.resize(3);
    out.push_back(hit);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n L log n + |s| log n) | Space: O(n)
// Sort products once. For each growing prefix, lower-bound the first product >= prefix, then take the next three if they still share the prefix.

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
  auto a = products;
  sort(a.begin(), a.end());
  vector<vector<string>> out;
  string pref;
  for (char c : searchWord) {
    pref += c;
    int k = (int)(lower_bound(a.begin(), a.end(), pref) - a.begin());
    vector<string> row;
    for (int t = 0; t < 3 && k + t < (int)a.size(); t++) {
      if (a[k + t].compare(0, pref.size(), pref) == 0) row.push_back(a[k + t]);
    }
    out.push_back(row);
  }
  return out;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Trie. At each node keep up to 3 lex-smallest words that pass through it (insert into a sorted short list). Typing searchWord is just walking children and reading that list.

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
  struct Node { Node* ch[26] = {}; vector<string> sug; };
  auto addSug = [](vector<string>& list, const string& w) {
    list.push_back(w);
    sort(list.begin(), list.end());
    if (list.size() > 3) list.pop_back();
  };
  Node* root = new Node();
  for (auto& w : products) {
    Node* cur = root;
    for (char c : w) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
      addSug(cur->sug, w);
    }
  }
  vector<vector<string>> out;
  Node* cur = root;
  for (char c : searchWord) {
    if (cur) cur = cur->ch[c - 'a'];
    out.push_back(cur ? cur->sug : vector<string>{});
  }
  return out;
}
