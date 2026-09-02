// Method 1: Brute
// Time: O(n L) sum | Space: O(n L)
// A plain key -> val map. sum walks every key and adds val when the key starts with the prefix.

struct MapSum {
  unordered_map<string, int> mp;
  void insert(string key, int val) { mp[key] = val; }
  int sum(string prefix) {
    int s = 0, n = (int)prefix.size();
    for (auto& e : mp)
      if ((int)e.first.size() >= n && e.first.compare(0, n, prefix) == 0) s += e.second;
    return s;
  }
};


// Method 2: Optimal
// Time: O(L) insert and sum | Space: O(n L)
// Keep the latest val per key. On insert, delta = newVal - oldVal. Add delta to every prefix string of the key in a second map. sum is then one lookup.

struct MapSum {
  unordered_map<string, int> val, pref;
  void insert(string key, int v) {
    int old = val.count(key) ? val[key] : 0;
    int delta = v - old;
    val[key] = v;
    string p;
    for (char c : key) { p += c; pref[p] += delta; }
  }
  int sum(string prefix) { return pref[prefix]; }
};


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Trie node holds a running sum of values that pass through it. insert adds the delta along the path. sum walks the prefix and returns that node's sum.

struct MapSum {
  struct Node { Node* ch[26] = {}; int sum = 0; };
  Node* root = new Node();
  unordered_map<string, int> val;
  void insert(string key, int v) {
    int delta = v - (val.count(key) ? val[key] : 0);
    val[key] = v;
    Node* cur = root;
    for (char c : key) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
      cur->sum += delta;
    }
  }
  int sum(string prefix) {
    Node* cur = root;
    for (char c : prefix) {
      int idx = c - 'a';
      if (!cur->ch[idx]) return 0;
      cur = cur->ch[idx];
    }
    return cur->sum;
  }
};
