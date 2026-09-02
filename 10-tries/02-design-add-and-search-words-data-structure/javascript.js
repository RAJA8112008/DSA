// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep a list. For each stored word of the same length, compare char by char and treat '.' as a free pass. Simple and slow when the dictionary is large.

function WordDictionary() {
  this.words = [];
}
WordDictionary.prototype.addWord = function (word) {
  this.words.push(word);
};
WordDictionary.prototype.search = function (word) {
  const n = word.length;
  for (let i = 0; i < this.words.length; i++) {
    const w = this.words[i];
    if (w.length !== n) continue;
    let ok = true;
    for (let j = 0; j < n; j++) {
      if (word[j] !== "." && word[j] !== w[j]) { ok = false; break; }
    }
    if (ok) return true;
  }
  return false;
};


// Method 2: Optimal
// Time: O(k L) | Space: O(n L)
// Bucket words by length so a pattern of length L only scans that bucket. Still linear in the bucket size, but you skip obviously impossible words.

function WordDictionary() {
  this.byLen = {};
}
WordDictionary.prototype.addWord = function (word) {
  const n = word.length;
  if (!this.byLen[n]) this.byLen[n] = [];
  this.byLen[n].push(word);
};
WordDictionary.prototype.search = function (word) {
  const n = word.length;
  const list = this.byLen[n] || [];
  for (let i = 0; i < list.length; i++) {
    const w = list[i];
    let ok = true;
    for (let j = 0; j < n; j++) {
      if (word[j] !== "." && word[j] !== w[j]) { ok = false; break; }
    }
    if (ok) return true;
  }
  return false;
};


// Method 3: More optimal
// Time: O(26^d L) | Space: O(n L)
// Trie DFS. A letter follows one child. A '.' tries every living child. d is the number of dots. This is the expected design.

function WordDictionary() {
  this.root = { ch: Array(26).fill(null), end: false };
}
WordDictionary.prototype.addWord = function (word) {
  let cur = this.root;
  for (let i = 0; i < word.length; i++) {
    const idx = word.charCodeAt(i) - 97;
    if (!cur.ch[idx]) cur.ch[idx] = { ch: Array(26).fill(null), end: false };
    cur = cur.ch[idx];
  }
  cur.end = true;
};
WordDictionary.prototype.search = function (word) {
  const root = this.root;
  function dfs(node, i) {
    if (!node) return false;
    if (i === word.length) return node.end === true;
    const c = word[i];
    if (c === ".") {
      for (let k = 0; k < 26; k++) if (dfs(node.ch[k], i + 1)) return true;
      return false;
    }
    return dfs(node.ch[c.charCodeAt(0) - 97], i + 1);
  }
  return dfs(root, 0);
};
