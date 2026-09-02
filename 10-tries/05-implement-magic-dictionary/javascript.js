// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// Store the list. For each stored word of the same length, count mismatches. Return true on a count of exactly 1.

function MagicDictionary() {
  this.words = [];
}
MagicDictionary.prototype.buildDict = function (dictionary) {
  this.words = dictionary.slice();
};
MagicDictionary.prototype.search = function (searchWord) {
  const n = searchWord.length;
  for (let i = 0; i < this.words.length; i++) {
    const w = this.words[i];
    if (w.length !== n) continue;
    let diff = 0;
    for (let j = 0; j < n; j++) if (w[j] !== searchWord[j]) diff++;
    if (diff === 1) return true;
  }
  return false;
};


// Method 2: Optimal
// Time: O(L * 26) | Space: O(n L^2)
// For each word, replace each position with '*' and map that pattern to the original letters. On search, look up each starred query and see if another letter is stored. Handles duplicates carefully.

function MagicDictionary() {
  this.map = Object.create(null);
}
MagicDictionary.prototype.buildDict = function (dictionary) {
  this.map = Object.create(null);
  for (let i = 0; i < dictionary.length; i++) {
    const w = dictionary[i];
    for (let j = 0; j < w.length; j++) {
      const key = w.slice(0, j) + "*" + w.slice(j + 1);
      if (!this.map[key]) this.map[key] = [];
      this.map[key].push(w[j]);
    }
  }
};
MagicDictionary.prototype.search = function (searchWord) {
  for (let j = 0; j < searchWord.length; j++) {
    const key = searchWord.slice(0, j) + "*" + searchWord.slice(j + 1);
    const letters = this.map[key] || [];
    for (let k = 0; k < letters.length; k++) {
      if (letters[k] !== searchWord[j]) return true;
    }
  }
  return false;
};


// Method 3: More optimal
// Time: O(26 L) | Space: O(n L)
// Trie DFS with a leftover mismatch budget of 1. At the end of the query the budget must be 0 (exactly one change). Compact and matches the 'magic' story.

function MagicDictionary() {
  this.root = { ch: Array(26).fill(null), end: false };
}
MagicDictionary.prototype.buildDict = function (dictionary) {
  this.root = { ch: Array(26).fill(null), end: false };
  for (let i = 0; i < dictionary.length; i++) {
    let cur = this.root;
    const w = dictionary[i];
    for (let j = 0; j < w.length; j++) {
      const idx = w.charCodeAt(j) - 97;
      if (!cur.ch[idx]) cur.ch[idx] = { ch: Array(26).fill(null), end: false };
      cur = cur.ch[idx];
    }
    cur.end = true;
  }
};
MagicDictionary.prototype.search = function (searchWord) {
  const root = this.root;
  function dfs(node, i, left) {
    if (!node) return false;
    if (i === searchWord.length) return node.end === true && left === 0;
    const idx = searchWord.charCodeAt(i) - 97;
    for (let k = 0; k < 26; k++) {
      const cost = k === idx ? 0 : 1;
      if (left - cost < 0) continue;
      if (dfs(node.ch[k], i + 1, left - cost)) return true;
    }
    return false;
  }
  return dfs(root, 0, 1);
};
