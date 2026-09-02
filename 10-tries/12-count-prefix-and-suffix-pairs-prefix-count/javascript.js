// Method 1: Brute
// Time: O(n L) | Space: O(1)
// For each word, compare pref character by character. Count a hit when the whole pref matches.

function prefixCount(words, pref) {
  let c = 0;
  const n = pref.length;
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    if (w.length < n) continue;
    let ok = true;
    for (let j = 0; j < n; j++) if (w[j] !== pref[j]) { ok = false; break; }
    if (ok) c++;
  }
  return c;
}


// Method 2: Optimal
// Time: O(n^2 L) | Space: O(1)
// For the related prefix-and-suffix-pairs problem: try every i < j and test both prefix and suffix. Still brute pairs, but the check is the right idea before a trie of (char, char) pairs.

function countPrefixSuffixPairs(words) {
  function isPrefixAndSuffix(a, b) {
    const n = a.length, m = b.length;
    if (n > m) return false;
    for (let i = 0; i < n; i++) if (a[i] !== b[i]) return false;
    for (let i = 0; i < n; i++) if (a[i] !== b[m - n + i]) return false;
    return true;
  }
  let c = 0;
  for (let i = 0; i < words.length; i++) {
    for (let j = i + 1; j < words.length; j++) {
      if (isPrefixAndSuffix(words[i], words[j])) c++;
    }
  }
  return c;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Prefix count: insert every word into a trie, increment pref on each node, then walk pref once. For prefix-and-suffix pairs, a twin trie on (first char, last char) pairs is the upgrade when n is large.

function prefixCount(words, pref) {
  function node() { return { ch: Array(26).fill(null), pref: 0 }; }
  const root = node();
  for (let i = 0; i < words.length; i++) {
    let cur = root;
    const w = words[i];
    for (let j = 0; j < w.length; j++) {
      const idx = w.charCodeAt(j) - 97;
      if (!cur.ch[idx]) cur.ch[idx] = node();
      cur = cur.ch[idx];
      cur.pref++;
    }
  }
  let cur = root;
  for (let j = 0; j < pref.length; j++) {
    const idx = pref.charCodeAt(j) - 97;
    if (!cur.ch[idx]) return 0;
    cur = cur.ch[idx];
  }
  return cur.pref;
}
