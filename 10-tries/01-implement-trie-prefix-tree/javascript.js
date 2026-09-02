// Method 1: Brute
// Time: O(n L) search | Space: O(n L)
// Keep every inserted string in an array. search and startsWith scan the whole list. Correct, and fine for tiny dictionaries, but not the point of the problem.

function Trie() {
  this.words = [];
}
Trie.prototype.insert = function (word) {
  this.words.push(word);
};
Trie.prototype.search = function (word) {
  for (let i = 0; i < this.words.length; i++) {
    if (this.words[i] === word) return true;
  }
  return false;
};
Trie.prototype.startsWith = function (prefix) {
  const n = prefix.length;
  for (let i = 0; i < this.words.length; i++) {
    const w = this.words[i];
    if (w.length >= n && w.slice(0, n) === prefix) return true;
  }
  return false;
};


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// A set of full words plus a set of every prefix. Each call is a hash lookup. Extra memory stores every prefix string, which a trie shares instead.

function Trie() {
  this.words = Object.create(null);
  this.prefs = Object.create(null);
}
Trie.prototype.insert = function (word) {
  this.words[word] = true;
  let p = "";
  for (let i = 0; i < word.length; i++) {
    p += word[i];
    this.prefs[p] = true;
  }
};
Trie.prototype.search = function (word) {
  return this.words[word] === true;
};
Trie.prototype.startsWith = function (prefix) {
  return this.prefs[prefix] === true;
};


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Real trie. Shared prefixes share nodes. insert, search, and startsWith each walk L children. This is the expected interview finish.

function Trie() {
  this.root = { ch: Array(26).fill(null), end: false };
}
Trie.prototype.insert = function (word) {
  let cur = this.root;
  for (let i = 0; i < word.length; i++) {
    const idx = word.charCodeAt(i) - 97;
    if (!cur.ch[idx]) cur.ch[idx] = { ch: Array(26).fill(null), end: false };
    cur = cur.ch[idx];
  }
  cur.end = true;
};
Trie.prototype.search = function (word) {
  let cur = this.root;
  for (let i = 0; i < word.length; i++) {
    const idx = word.charCodeAt(i) - 97;
    if (!cur.ch[idx]) return false;
    cur = cur.ch[idx];
  }
  return cur.end === true;
};
Trie.prototype.startsWith = function (prefix) {
  let cur = this.root;
  for (let i = 0; i < prefix.length; i++) {
    const idx = prefix.charCodeAt(i) - 97;
    if (!cur.ch[idx]) return false;
    cur = cur.ch[idx];
  }
  return true;
};
