// Method 1: Brute
// Time: O(2^n * n) | Space: O(2^n * n)
// At each index, cut or grow the last token, copying the token list. After the string ends, every token must sit in the dict. Catastrophic on repeated letters.

function wordBreak(s, wordDict) {
  const dict = {};
  for (let i = 0; i < wordDict.length; i++) dict[wordDict[i]] = 1;
  const ans = [];
  function go(i, parts, cur) {
    if (i === s.length) {
      const all = cur.length ? parts.concat([cur]) : parts.slice();
      for (let p = 0; p < all.length; p++) if (!dict[all[p]]) return;
      ans.push(all.join(" "));
      return;
    }
    go(i + 1, parts.slice(), cur + s[i]);
    if (cur.length) go(i, parts.concat([cur]), "");
  }
  go(0, [], "");
  return ans;
}


// Method 2: Optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// From i, try every dictionary word as a prefix of s[i..]. Push, recurse i+len, pop. Only legal words ever sit on the path. Still exponential in the number of sentences.

function wordBreak(s, wordDict) {
  const ans = [];
  function go(i, path) {
    if (i === s.length) { ans.push(path.join(" ")); return; }
    for (let w = 0; w < wordDict.length; w++) {
      const word = wordDict[w];
      if (s.slice(i, i + word.length) !== word) continue;
      path.push(word);
      go(i + word.length, path);
      path.pop();
    }
  }
  go(0, []);
  return ans;
}


// Method 3: More optimal
// Time: O(2^n * n) | Space: O(2^n * n)
// can[i] is true if s[i..] can be broken at all. If !can[i], skip that index (prune). Memo[i] stores the list of sentences from i so overlapping tails are not rebuilt.

function wordBreak(s, wordDict) {
  const n = s.length;
  const dict = {};
  for (let i = 0; i < wordDict.length; i++) dict[wordDict[i]] = 1;
  const can = Array(n + 1).fill(false);
  can[n] = true;
  for (let i = n - 1; i >= 0; i--) {
    for (let w = 0; w < wordDict.length; w++) {
      const word = wordDict[w];
      if (s.slice(i, i + word.length) === word && can[i + word.length]) { can[i] = true; break; }
    }
  }
  const memo = Array(n + 1);
  function go(i) {
    if (memo[i]) return memo[i];
    if (i === n) return [""];
    if (!can[i]) return memo[i] = [];
    const res = [];
    for (let w = 0; w < wordDict.length; w++) {
      const word = wordDict[w];
      if (s.slice(i, i + word.length) !== word) continue;
      const tails = go(i + word.length);
      for (let t = 0; t < tails.length; t++) res.push(tails[t] ? word + " " + tails[t] : word);
    }
    memo[i] = res;
    return res;
  }
  return can[0] ? go(0) : [];
}
