// Method 1: Brute
// Time: O(2^n) | Space: O(n)
// Every start tries every word. Failed prefixes are retried from overlapping indexes. Worst case is exponential in n. Stack is O(n).

function wordBreak(s, wordDict) {
  function go(i) {
    if (i === s.length) return true;
    for (let w = 0; w < wordDict.length; w++) {
      const word = wordDict[w];
      if (s.startsWith(word, i) && go(i + word.length)) return true;
    }
    return false;
  }
  return go(0);
}


// Method 2: Optimal
// Time: O(n * m * L) | Space: O(n)
// Each start index i is solved once. Per index you try m words, each startsWith costs up to L. Memo of n booleans. n is s.length, m is dict size, L is max word length.

function wordBreak(s, wordDict) {
  const memo = [];
  function go(i) {
    if (i === s.length) return true;
    if (memo[i] !== undefined) return memo[i];
    for (let w = 0; w < wordDict.length; w++) {
      const word = wordDict[w];
      if (s.startsWith(word, i) && go(i + word.length)) {
        memo[i] = true;
        return true;
      }
    }
    memo[i] = false;
    return false;
  }
  return go(0);
}


// Method 3: More optimal
// Time: O(n * m * L) | Space: O(n + m)
// Bottom-up: can[0] is true. From every true cut, stamp every word that matches. A Set makes membership obvious if you later scan splits by length. No recursion; same polynomial bound.

function wordBreak(s, wordDict) {
  const words = new Set(wordDict);
  const n = s.length;
  const can = Array(n + 1).fill(false);
  can[0] = true;
  for (let i = 0; i < n; i++) {
    if (!can[i]) continue;
    words.forEach(function (word) {
      if (s.startsWith(word, i)) can[i + word.length] = true;
    });
  }
  return can[n];
}
