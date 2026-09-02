// Method 1: Brute
// Time: O(n L) | Space: O(1)
// For each word, compare pref character by character. Count a hit when the whole pref matches.

int prefixCount(vector<string>& words, string pref) {
  int c = 0, n = (int)pref.size();
  for (auto& w : words)
    if ((int)w.size() >= n && w.compare(0, n, pref) == 0) c++;
  return c;
}


// Method 2: Optimal
// Time: O(n^2 L) | Space: O(1)
// For the related prefix-and-suffix-pairs problem: try every i < j and test both prefix and suffix. Still brute pairs, but the check is the right idea before a trie of (char, char) pairs.

bool isPrefixAndSuffix(const string& a, const string& b) {
  int n = (int)a.size(), m = (int)b.size();
  if (n > m) return false;
  return b.compare(0, n, a) == 0 && b.compare(m - n, n, a) == 0;
}
int countPrefixSuffixPairs(vector<string>& words) {
  int c = 0, n = (int)words.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (isPrefixAndSuffix(words[i], words[j])) c++;
  return c;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Prefix count: insert every word into a trie, increment pref on each node, then walk pref once. For prefix-and-suffix pairs, a twin trie on (first char, last char) pairs is the upgrade when n is large.

int prefixCount(vector<string>& words, string pref) {
  struct Node { Node* ch[26] = {}; int pref = 0; };
  Node* root = new Node();
  for (auto& w : words) {
    Node* cur = root;
    for (char c : w) {
      int idx = c - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = new Node();
      cur = cur->ch[idx];
      cur->pref++;
    }
  }
  Node* cur = root;
  for (char c : pref) {
    int idx = c - 'a';
    if (!cur->ch[idx]) return 0;
    cur = cur->ch[idx];
  }
  return cur->pref;
}
