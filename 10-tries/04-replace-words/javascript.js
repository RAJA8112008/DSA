// Method 1: Brute
// Time: O(words * roots * L) | Space: O(1) extra
// For each sentence word, scan every root and keep the shortest one that is a prefix. Easy to write, quadratic in dictionary size.

function replaceWords(dictionary, sentence) {
  const words = sentence.split(" ");
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    let best = w;
    for (let j = 0; j < dictionary.length; j++) {
      const r = dictionary[j];
      if (w.length >= r.length && w.slice(0, r.length) === r && r.length < best.length) best = r;
    }
    words[i] = best;
  }
  return words.join(" ");
}


// Method 2: Optimal
// Time: O(total chars) | Space: O(roots)
// Put roots in a set. For each word, try prefixes from length 1 up and take the first hit. That is the shortest root. Faster when few prefixes match.

function replaceWords(dictionary, sentence) {
  const set = Object.create(null);
  for (let i = 0; i < dictionary.length; i++) set[dictionary[i]] = true;
  const words = sentence.split(" ");
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    for (let L = 1; L <= w.length; L++) {
      const p = w.slice(0, L);
      if (set[p]) { words[i] = p; break; }
    }
  }
  return words.join(" ");
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(roots)
// Trie of roots. Walk each sentence word until you hit an end flag, then stop. Shared prefixes make this the usual interview answer.

function replaceWords(dictionary, sentence) {
  function node() { return { ch: Array(26).fill(null), end: false }; }
  const root = node();
  for (let i = 0; i < dictionary.length; i++) {
    let cur = root;
    const r = dictionary[i];
    for (let j = 0; j < r.length; j++) {
      const idx = r.charCodeAt(j) - 97;
      if (!cur.ch[idx]) cur.ch[idx] = node();
      cur = cur.ch[idx];
    }
    cur.end = true;
  }
  const words = sentence.split(" ");
  for (let i = 0; i < words.length; i++) {
    const w = words[i];
    let cur = root;
    let built = "";
    for (let j = 0; j < w.length; j++) {
      const idx = w.charCodeAt(j) - 97;
      if (!cur.ch[idx]) break;
      cur = cur.ch[idx];
      built += w[j];
      if (cur.end) { words[i] = built; break; }
    }
  }
  return words.join(" ");
}
