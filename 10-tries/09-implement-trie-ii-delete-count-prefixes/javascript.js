// Method 1: Brute
// Time: O(n L) | Space: O(n L)
// An array of words. equalTo counts exact matches. startingWith counts prefix matches. erase removes the first copy.

function Trie() {
  this.words = [];
}
Trie.prototype.insert = function (word) {
  this.words.push(word);
};
Trie.prototype.countWordsEqualTo = function (word) {
  let c = 0;
  for (let i = 0; i < this.words.length; i++) if (this.words[i] === word) c++;
  return c;
};
Trie.prototype.countWordsStartingWith = function (prefix) {
  let c = 0;
  const n = prefix.length;
  for (let i = 0; i < this.words.length; i++) {
    const w = this.words[i];
    if (w.length >= n && w.slice(0, n) === prefix) c++;
  }
  return c;
};
Trie.prototype.erase = function (word) {
  const i = this.words.indexOf(word);
  if (i >= 0) this.words.splice(i, 1);
};


// Method 2: Optimal
// Time: O(L) | Space: O(n L)
// wordCount map and prefixCount map. insert / erase add or subtract 1 along every prefix. Queries are hash lookups. Watch erase: never go below zero.

function Trie() {
  this.wordCount = Object.create(null);
  this.prefCount = Object.create(null);
}
Trie.prototype.insert = function (word) {
  this.wordCount[word] = (this.wordCount[word] || 0) + 1;
  let p = "";
  for (let i = 0; i < word.length; i++) {
    p += word[i];
    this.prefCount[p] = (this.prefCount[p] || 0) + 1;
  }
};
Trie.prototype.countWordsEqualTo = function (word) {
  return this.wordCount[word] || 0;
};
Trie.prototype.countWordsStartingWith = function (prefix) {
  return this.prefCount[prefix] || 0;
};
Trie.prototype.erase = function (word) {
  if (!this.wordCount[word]) return;
  this.wordCount[word]--;
  let p = "";
  for (let i = 0; i < word.length; i++) {
    p += word[i];
    this.prefCount[p]--;
  }
};


// Method 3: More optimal
// Time: O(L) | Space: O(total chars) shared
// Trie node has words (how many end here) and pref (how many pass through). insert increments. erase decrements and unlinks a child whose pref hits 0.

function Trie() {
  this.root = { ch: Array(26).fill(null), words: 0, pref: 0 };
}
Trie.prototype.insert = function (word) {
  let cur = this.root;
  for (let i = 0; i < word.length; i++) {
    const idx = word.charCodeAt(i) - 97;
    if (!cur.ch[idx]) cur.ch[idx] = { ch: Array(26).fill(null), words: 0, pref: 0 };
    cur = cur.ch[idx];
    cur.pref++;
  }
  cur.words++;
};
Trie.prototype.countWordsEqualTo = function (word) {
  let cur = this.root;
  for (let i = 0; i < word.length; i++) {
    const idx = word.charCodeAt(i) - 97;
    if (!cur.ch[idx]) return 0;
    cur = cur.ch[idx];
  }
  return cur.words;
};
Trie.prototype.countWordsStartingWith = function (prefix) {
  let cur = this.root;
  for (let i = 0; i < prefix.length; i++) {
    const idx = prefix.charCodeAt(i) - 97;
    if (!cur.ch[idx]) return 0;
    cur = cur.ch[idx];
  }
  return cur.pref;
};
Trie.prototype.erase = function (word) {
  if (this.countWordsEqualTo(word) === 0) return;
  let cur = this.root;
  for (let i = 0; i < word.length; i++) {
    const idx = word.charCodeAt(i) - 97;
    const nxt = cur.ch[idx];
    nxt.pref--;
    if (nxt.pref === 0) { cur.ch[idx] = null; return; }
    cur = nxt;
  }
  cur.words--;
};
