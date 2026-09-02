// Method 1: Brute
// Time: O(n^2) | Space: O(1)
// XOR every pair, keep the max. Correct, too slow for n = 2e5.

int findMaximumXOR(vector<int>& nums) {
  int best = 0, n = (int)nums.size();
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) best = max(best, nums[i] ^ nums[j]);
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build the answer from bit 31 down. Assume the next bit can be 1. If some prefix ^ candidate exists in the set of current prefixes, keep that bit. Hash set of prefixes is the usual O(n) per bit trick.

int findMaximumXOR(vector<int>& nums) {
  int best = 0, mask = 0;
  for (int b = 31; b >= 0; b--) {
    mask |= (1 << b);
    unordered_set<int> seen;
    for (int x : nums) seen.insert(x & mask);
    int cand = best | (1 << b);
    for (int p : seen) {
      if (seen.count(p ^ cand)) { best = cand; break; }
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Insert every number into a binary trie (high bit first). For each number, walk the opposite bit when it exists. That walk is the max XOR against the set. Same O(32 n), clearer as a trie.

int findMaximumXOR(vector<int>& nums) {
  struct Node { Node* ch[2] = {}; };
  Node* root = new Node();
  auto insert = [&](int x) {
    Node* cur = root;
    for (int b = 31; b >= 0; b--) {
      int bit = (x >> b) & 1;
      if (!cur->ch[bit]) cur->ch[bit] = new Node();
      cur = cur->ch[bit];
    }
  };
  auto best = [&](int x) {
    Node* cur = root;
    int ans = 0;
    for (int b = 31; b >= 0; b--) {
      int bit = (x >> b) & 1, want = 1 - bit;
      if (cur->ch[want]) { ans |= (1 << b); cur = cur->ch[want]; }
      else cur = cur->ch[bit];
    }
    return ans;
  };
  for (int x : nums) insert(x);
  int out = 0;
  for (int x : nums) out = max(out, best(x));
  return out;
}
