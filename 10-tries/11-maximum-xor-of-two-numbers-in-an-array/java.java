// Method 1: Brute
// Time: O(n^2) | Space: O(1)
// XOR every pair, keep the max. Correct, too slow for n = 2e5.

class Solution {
  public int findMaximumXOR(int[] nums) {
    int best = 0, n = nums.length;
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        best = Math.max(best, nums[i] ^ nums[j]);
    return best;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build the answer from bit 31 down. Assume the next bit can be 1. If some prefix ^ candidate exists in the set of current prefixes, keep that bit. Hash set of prefixes is the usual O(n) per bit trick.

import java.util.*;
class Solution {
  public int findMaximumXOR(int[] nums) {
    int best = 0, mask = 0;
    for (int b = 31; b >= 0; b--) {
      mask |= (1 << b);
      Set<Integer> seen = new HashSet<Integer>();
      for (int x : nums) seen.add(x & mask);
      int cand = best | (1 << b);
      for (int p : seen) {
        if (seen.contains(p ^ cand)) { best = cand; break; }
      }
    }
    return best;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Insert every number into a binary trie (high bit first). For each number, walk the opposite bit when it exists. That walk is the max XOR against the set. Same O(32 n), clearer as a trie.

class Solution {
  static class Node {
    Node[] ch = new Node[2];
  }
  void insert(Node root, int x) {
    Node cur = root;
    for (int b = 31; b >= 0; b--) {
      int bit = (x >> b) & 1;
      if (cur.ch[bit] == null) cur.ch[bit] = new Node();
      cur = cur.ch[bit];
    }
  }
  int best(Node root, int x) {
    Node cur = root;
    int ans = 0;
    for (int b = 31; b >= 0; b--) {
      int bit = (x >> b) & 1, want = 1 - bit;
      if (cur.ch[want] != null) { ans |= (1 << b); cur = cur.ch[want]; }
      else cur = cur.ch[bit];
    }
    return ans;
  }
  public int findMaximumXOR(int[] nums) {
    Node root = new Node();
    for (int x : nums) insert(root, x);
    int out = 0;
    for (int x : nums) out = Math.max(out, best(root, x));
    return out;
  }
}
