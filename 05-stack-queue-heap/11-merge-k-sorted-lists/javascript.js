// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Walk every node into an array, sort, then wire a new list. Ignores that each list is already sorted. Easy to code under pressure.

function mergeKLists(lists) {
  const vals = [];
  for (let i = 0; i < lists.length; i++) {
    let p = lists[i];
    while (p) { vals.push(p.val); p = p.next; }
  }
  vals.sort(function (a, b) { return a - b; });
  const dummy = { val: 0, next: null };
  let cur = dummy;
  for (let i = 0; i < vals.length; i++) {
    cur.next = { val: vals[i], next: null };
    cur = cur.next;
  }
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of list heads keyed by val. Pop the smallest, push its next. n pops, heap size k. Uses the sorted property.

function mergeKLists(lists) {
  const h = [];
  function key(x) { return x.val; }
  function up(i) {
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (key(h[i]) >= key(h[p])) break;
      const t = h[i]; h[i] = h[p]; h[p] = t;
      i = p;
    }
  }
  function down(i) {
    while (true) {
      let s = i;
      const l = i * 2 + 1, r = l + 1;
      if (l < h.length && key(h[l]) < key(h[s])) s = l;
      if (r < h.length && key(h[r]) < key(h[s])) s = r;
      if (s === i) break;
      const t = h[i]; h[i] = h[s]; h[s] = t;
      i = s;
    }
  }
  function push(node) { h.push(node); up(h.length - 1); }
  function pop() {
    const top = h[0];
    const last = h.pop();
    if (h.length) { h[0] = last; down(0); }
    return top;
  }
  for (let i = 0; i < lists.length; i++) if (lists[i]) push(lists[i]);
  const dummy = { val: 0, next: null };
  let cur = dummy;
  while (h.length) {
    const node = pop();
    cur.next = node;
    cur = node;
    if (node.next) push(node.next);
  }
  return dummy.next;
}


// Method 3: More optimal
// Time: O(n log k) | Space: O(log k)
// Pairwise merge like merge sort. Recursion depth log k. No heap to implement. Same n log k, often faster constants in JS, and O(1) extra besides the call stack.

function mergeKLists(lists) {
  if (!lists.length) return null;
  function mergeTwo(a, b) {
    const dummy = { val: 0, next: null };
    let cur = dummy;
    while (a && b) {
      if (a.val <= b.val) { cur.next = a; a = a.next; }
      else { cur.next = b; b = b.next; }
      cur = cur.next;
    }
    cur.next = a || b;
    return dummy.next;
  }
  function split(lo, hi) {
    if (lo === hi) return lists[lo];
    const mid = (lo + hi) >> 1;
    return mergeTwo(split(lo, mid), split(mid + 1, hi));
  }
  return split(0, lists.length - 1);
}
