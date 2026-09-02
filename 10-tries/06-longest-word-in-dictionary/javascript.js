// Method 1: Brute
// Time: O(n^2 L) | Space: O(n)
// Put words in a set. For each word, test that every prefix is in the set. Keep the longest, breaking ties lexicographically.

function longestWord(words) {
  const set = Object.create(null);
  for (let i = 0; i < words.length; i++) set[words[i]] = true;
  let best = "";
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    let ok = true;
    for (let L = 1; L < w.length; L++) {
      if (!set[w.slice(0, L)]) { ok = false; break; }
    }
    if (!ok) continue;
    if (w.length > best.length || (w.length === best.length && w < best)) best = w;
  }
  return best;
}


// Method 2: Optimal
// Time: O(n L log n) | Space: O(n)
// Sort by length then lex. A word is valid if the set already holds word without its last letter (or the word has length 1). Insert only valid words. The last survivor is the answer if you also keep the lex-smallest of that length.

function longestWord(words) {
  words = words.slice().sort(function (a, b) {
    if (a.length !== b.length) return a.length - b.length;
    return a < b ? -1 : a > b ? 1 : 0;
  });
  const good = Object.create(null);
  good[""] = true;
  let best = "";
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    if (good[w.slice(0, w.length - 1)]) {
      good[w] = true;
      if (w.length > best.length) best = w;
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Insert every word into a trie with an end flag. DFS only through end nodes. The deepest (then lex-smallest) path is the answer.

function longestWord(words) {
  function node() { return { ch: Array(26).fill(null), end: false }; }
  const root = node();
  root.end = true;
  for (let i = 0; i < words.length; i++) {
    let cur = root;
    const w = words[i];
    for (let j = 0; j < w.length; j++) {
      const idx = w.charCodeAt(j) - 97;
      if (!cur.ch[idx]) cur.ch[idx] = node();
      cur = cur.ch[idx];
    }
    cur.end = true;
  }
  let best = "";
  function dfs(cur, path) {
    if (!cur.end) return;
    if (path.length > best.length || (path.length === best.length && path < best)) best = path;
    for (let i = 0; i < 26; i++) {
      if (!cur.ch[i]) continue;
      dfs(cur.ch[i], path + String.fromCharCode(97 + i));
    }
  }
  dfs(root, "");
  return best;
}
