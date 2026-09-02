// Method 1: Brute
// Time: O(n^2) | Space: O(1)
// XOR every pair, keep the max. Correct, too slow for n = 2e5.

int findMaximumXOR(int* nums, int n) {
  int best = 0, i, j;
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++) {
      int x = nums[i] ^ nums[j];
      if (x > best) best = x;
    }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build the answer from bit 31 down. Assume the next bit can be 1. If some prefix ^ candidate exists in the set of current prefixes, keep that bit. Hash set of prefixes is the usual O(n) per bit trick.

int findMaximumXORPref(int* nums, int n) {
  int best = 0, mask = 0, b, i, k;
  int seen[4096];
  for (b = 31; b >= 0; b--) {
    mask |= (1 << b);
    int sn = 0;
    for (i = 0; i < n; i++) {
      int p = nums[i] & mask;
      int found = 0;
      for (k = 0; k < sn; k++) if (seen[k] == p) found = 1;
      if (!found && sn < 4096) seen[sn++] = p;
    }
    int cand = best | (1 << b), ok = 0;
    for (i = 0; i < sn && !ok; i++)
      for (k = 0; k < sn; k++) if (seen[k] == (seen[i] ^ cand)) ok = 1;
    if (ok) best = cand;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Insert every number into a binary trie (high bit first). For each number, walk the opposite bit when it exists. That walk is the max XOR against the set. Same O(32 n), clearer as a trie.

typedef struct BNode { struct BNode* ch[2]; } BNode;
BNode* bnew(void) { return (BNode*)calloc(1, sizeof(BNode)); }
void binsert(BNode* root, int x) {
  BNode* cur = root;
  int b;
  for (b = 31; b >= 0; b--) {
    int bit = (x >> b) & 1;
    if (!cur->ch[bit]) cur->ch[bit] = bnew();
    cur = cur->ch[bit];
  }
}
int bbest(BNode* root, int x) {
  BNode* cur = root;
  int ans = 0, b;
  for (b = 31; b >= 0; b--) {
    int bit = (x >> b) & 1, want = 1 - bit;
    if (cur->ch[want]) { ans |= (1 << b); cur = cur->ch[want]; }
    else cur = cur->ch[bit];
  }
  return ans;
}
