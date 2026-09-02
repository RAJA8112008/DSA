// Method 1: Brute
// Time: O(|s| n L) | Space: O(n)
// After each extra character, scan every product, keep those with the prefix, sort, take 3. Correct and slow.

function suggestedProducts(products, searchWord) {
  const out = [];
  let pref = "";
  for (let i = 0; i < searchWord.length; i++) {
    pref += searchWord[i];
    const hit = [];
    for (let j = 0; j < products.length; j++) {
      const p = products[j];
      if (p.length >= pref.length && p.slice(0, pref.length) === pref) hit.push(p);
    }
    hit.sort();
    out.push(hit.slice(0, 3));
  }
  return out;
}


// Method 2: Optimal
// Time: O(n L log n + |s| log n) | Space: O(n)
// Sort products once. For each growing prefix, lower-bound the first product >= prefix, then take the next three if they still share the prefix.

function suggestedProducts(products, searchWord) {
  const a = products.slice().sort();
  const out = [];
  let pref = "";
  function lowerBound(s) {
    let lo = 0, hi = a.length;
    while (lo < hi) {
      const mid = (lo + hi) >> 1;
      if (a[mid] < s) lo = mid + 1;
      else hi = mid;
    }
    return lo;
  }
  for (let i = 0; i < searchWord.length; i++) {
    pref += searchWord[i];
    const k = lowerBound(pref);
    const row = [];
    for (let t = 0; t < 3 && k + t < a.length; t++) {
      const p = a[k + t];
      if (p.length >= pref.length && p.slice(0, pref.length) === pref) row.push(p);
    }
    out.push(row);
  }
  return out;
}


// Method 3: More optimal
// Time: O(total chars) | Space: O(total chars)
// Trie. At each node keep up to 3 lex-smallest words that pass through it (insert into a sorted short list). Typing searchWord is just walking children and reading that list.

function suggestedProducts(products, searchWord) {
  function node() { return { ch: Array(26).fill(null), sug: [] }; }
  const root = node();
  function addSug(list, w) {
    list.push(w);
    list.sort();
    if (list.length > 3) list.pop();
  }
  for (let i = 0; i < products.length; i++) {
    const w = products[i];
    let cur = root;
    for (let j = 0; j < w.length; j++) {
      const idx = w.charCodeAt(j) - 97;
      if (!cur.ch[idx]) cur.ch[idx] = node();
      cur = cur.ch[idx];
      addSug(cur.sug, w);
    }
  }
  const out = [];
  let cur = root;
  for (let i = 0; i < searchWord.length; i++) {
    if (cur) cur = cur.ch[searchWord.charCodeAt(i) - 97];
    out.push(cur ? cur.sug.slice() : []);
  }
  return out;
}
