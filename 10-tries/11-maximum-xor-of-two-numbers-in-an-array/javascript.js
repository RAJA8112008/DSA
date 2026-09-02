// Method 1: Brute
// Time: O(n^2) | Space: O(1)
// XOR every pair, keep the max. Correct, too slow for n = 2e5.

function findMaximumXOR(nums) {
  let best = 0;
  const n = nums.length;
  for (let i = 0; i < n; i++) {
    for (let j = i + 1; j < n; j++) {
      const x = nums[i] ^ nums[j];
      if (x > best) best = x;
    }
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Build the answer from bit 31 down. Assume the next bit can be 1. If some prefix ^ candidate exists in the set of current prefixes, keep that bit. Hash set of prefixes is the usual O(n) per bit trick.

function findMaximumXOR(nums) {
  let best = 0;
  let mask = 0;
  for (let b = 31; b >= 0; b--) {
    mask |= (1 << b);
    const seen = Object.create(null);
    for (let i = 0; i < nums.length; i++) seen[nums[i] & mask] = true;
    const cand = best | (1 << b);
    let ok = false;
    const keys = Object.keys(seen);
    for (let i = 0; i < keys.length; i++) {
      const p = keys[i] | 0;
      if (seen[(p ^ cand) >>> 0] || seen[p ^ cand]) { ok = true; break; }
    }
    if (ok) best = cand;
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Insert every number into a binary trie (high bit first). For each number, walk the opposite bit when it exists. That walk is the max XOR against the set. Same O(32 n), clearer as a trie.

function findMaximumXOR(nums) {
  function bitNode() { return { ch: [null, null] }; }
  const root = bitNode();
  function insert(x) {
    let cur = root;
    for (let b = 31; b >= 0; b--) {
      const bit = (x >> b) & 1;
      if (!cur.ch[bit]) cur.ch[bit] = bitNode();
      cur = cur.ch[bit];
    }
  }
  function best(x) {
    let cur = root;
    let ans = 0;
    for (let b = 31; b >= 0; b--) {
      const bit = (x >> b) & 1;
      const want = 1 - bit;
      if (cur.ch[want]) {
        ans |= (1 << b);
        cur = cur.ch[want];
      } else cur = cur.ch[bit];
    }
    return ans;
  }
  for (let i = 0; i < nums.length; i++) insert(nums[i]);
  let out = 0;
  for (let i = 0; i < nums.length; i++) {
    const v = best(nums[i]);
    if (v > out) out = v;
  }
  return out;
}
