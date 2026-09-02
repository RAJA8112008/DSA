// Method 1: Brute
// Time: O(n^2 L) | Space: O(1)
// For every ordered pair, concatenate and test palindrome. Fine for tiny n, not for n = 5000.

function palindromePairs(words) {
  function isPal(s) {
    let i = 0, j = s.length - 1;
    while (i < j) {
      if (s[i] !== s[j]) return false;
      i++;
      j--;
    }
    return true;
  }
  const out = [];
  const n = words.length;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      if (i === j) continue;
      if (isPal(words[i] + words[j])) out.push([i, j]);
    }
  }
  return out;
}


// Method 2: Optimal
// Time: O(n L^2) | Space: O(n L)
// Map word -> index. For each word, try every split. If the left half is a palindrome, look up reverse(right). If the right half is a palindrome, look up reverse(left). Handles the empty-word case.

function palindromePairs(words) {
  function isPal(s, a, b) {
    while (a < b) {
      if (s[a] !== s[b]) return false;
      a++;
      b--;
    }
    return true;
  }
  const idx = Object.create(null);
  for (let i = 0; i < words.length; i++) idx[words[i]] = i;
  const out = [];
  const seen = Object.create(null);
  function add(i, j) {
    const key = i + "," + j;
    if (i === j || seen[key]) return;
    seen[key] = true;
    out.push([i, j]);
  }
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    const n = w.length;
    for (let cut = 0; cut <= n; cut++) {
      if (isPal(w, cut, n - 1)) {
        const rev = w.slice(0, cut).split("").reverse().join("");
        if (idx[rev] !== undefined) add(i, idx[rev]);
      }
      if (cut > 0 && isPal(w, 0, cut - 1)) {
        const rev = w.slice(cut).split("").reverse().join("");
        if (idx[rev] !== undefined) add(idx[rev], i);
      }
    }
  }
  return out;
}


// Method 3: More optimal
// Time: O(n L^2) | Space: O(n L)
// Insert the reverse of every word into a trie, storing the index at the end. While walking a word, if the remaining suffix is a palindrome and the node is an end, you have a pair. Also collect end indexes whose leftover reverse is a palindrome. Same complexity, trie picture.

function palindromePairs(words) {
  function isPal(s, a, b) {
    while (a < b) {
      if (s[a] !== s[b]) return false;
      a++;
      b--;
    }
    return true;
  }
  function node() { return { ch: {}, idx: -1, palBelow: [] }; }
  const root = node();
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    let cur = root;
    for (let j = w.length - 1; j >= 0; j--) {
      if (isPal(w, 0, j)) cur.palBelow.push(i);
      const c = w[j];
      if (!cur.ch[c]) cur.ch[c] = node();
      cur = cur.ch[c];
    }
    cur.idx = i;
    cur.palBelow.push(i);
  }
  const out = [];
  const seen = Object.create(null);
  function add(i, j) {
    const key = i + "," + j;
    if (i === j || seen[key]) return;
    seen[key] = true;
    out.push([i, j]);
  }
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    let cur = root;
    let k = 0;
    for (; k < w.length; k++) {
      if (cur.idx >= 0 && isPal(w, k, w.length - 1)) add(i, cur.idx);
      if (!cur.ch[w[k]]) { cur = null; break; }
      cur = cur.ch[w[k]];
    }
    if (cur) {
      for (let t = 0; t < cur.palBelow.length; t++) add(i, cur.palBelow[t]);
    }
  }
  return out;
}
