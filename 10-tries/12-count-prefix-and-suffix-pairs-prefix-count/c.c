// Method 1: Brute
// Time: O(n L) | Space: O(1)
// For each word, compare pref character by character. Count a hit when the whole pref matches.

int prefixCount(char words[][48], int n, const char* pref) {
  int i, c = 0, L = (int)strlen(pref);
  for (i = 0; i < n; i++)
    if ((int)strlen(words[i]) >= L && strncmp(words[i], pref, L) == 0) c++;
  return c;
}


// Method 2: Optimal
// Time: O(n^2 L) | Space: O(1)
// For the related prefix-and-suffix-pairs problem: try every i < j and test both prefix and suffix. Still brute pairs, but the check is the right idea before a trie of (char, char) pairs.

int isPrefixAndSuffix(const char* a, const char* b) {
  int n = (int)strlen(a), m = (int)strlen(b);
  if (n > m) return 0;
  if (strncmp(b, a, n) != 0) return 0;
  if (strncmp(b + m - n, a, n) != 0) return 0;
  return 1;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Prefix count: insert every word into a trie, increment pref on each node, then walk pref once. For prefix-and-suffix pairs, a twin trie on (first char, last char) pairs is the upgrade when n is large.

int prefixCountTrie(char words[][48], int n, const char* pref) {
  Node* root = newNode();
  int i, j;
  for (i = 0; i < n; i++) {
    Node* cur = root;
    for (j = 0; words[i][j]; j++) {
      int idx = words[i][j] - 'a';
      if (!cur->ch[idx]) cur->ch[idx] = newNode();
      cur = cur->ch[idx];
      cur->end++; /* reuse end as pref count */
    }
  }
  {
    Node* cur = root;
    for (j = 0; pref[j]; j++) {
      int idx = pref[j] - 'a';
      if (!cur->ch[idx]) return 0;
      cur = cur->ch[idx];
    }
    return cur->end;
  }
}
