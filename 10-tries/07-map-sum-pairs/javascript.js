// Method 1: Brute
// Time: O(n L) sum | Space: O(n L)
// A plain key -> val map. sum walks every key and adds val when the key starts with the prefix.

function MapSum() {
  this.map = Object.create(null);
}
MapSum.prototype.insert = function (key, val) {
  this.map[key] = val;
};
MapSum.prototype.sum = function (prefix) {
  let s = 0;
  const keys = Object.keys(this.map);
  for (let i = 0; i < keys.length; i++) {
    const k = keys[i];
    if (k.length >= prefix.length && k.slice(0, prefix.length) === prefix) s += this.map[k];
  }
  return s;
};


// Method 2: Optimal
// Time: O(L) insert and sum | Space: O(n L)
// Keep the latest val per key. On insert, delta = newVal - oldVal. Add delta to every prefix string of the key in a second map. sum is then one lookup.

function MapSum() {
  this.val = Object.create(null);
  this.pref = Object.create(null);
}
MapSum.prototype.insert = function (key, v) {
  const old = this.val[key] || 0;
  const delta = v - old;
  this.val[key] = v;
  let p = "";
  for (let i = 0; i < key.length; i++) {
    p += key[i];
    this.pref[p] = (this.pref[p] || 0) + delta;
  }
};
MapSum.prototype.sum = function (prefix) {
  return this.pref[prefix] || 0;
};


// Method 3: More optimal
// Time: O(L) | Space: O(n L) shared
// Trie node holds a running sum of values that pass through it. insert adds the delta along the path. sum walks the prefix and returns that node's sum.

function MapSum() {
  this.root = { ch: Array(26).fill(null), sum: 0 };
  this.val = Object.create(null);
}
MapSum.prototype.insert = function (key, v) {
  const delta = v - (this.val[key] || 0);
  this.val[key] = v;
  let cur = this.root;
  for (let i = 0; i < key.length; i++) {
    const idx = key.charCodeAt(i) - 97;
    if (!cur.ch[idx]) cur.ch[idx] = { ch: Array(26).fill(null), sum: 0 };
    cur = cur.ch[idx];
    cur.sum += delta;
  }
};
MapSum.prototype.sum = function (prefix) {
  let cur = this.root;
  for (let i = 0; i < prefix.length; i++) {
    const idx = prefix.charCodeAt(i) - 97;
    if (!cur.ch[idx]) return 0;
    cur = cur.ch[idx];
  }
  return cur.sum;
};
