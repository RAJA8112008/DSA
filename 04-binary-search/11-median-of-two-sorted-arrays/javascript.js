// Method 1: Brute
// Time: O(m + n) | Space: O(m + n)
// Merge the two sorted lists into one, then pick the middle one or two values. Easy to code, extra memory, and not the log bound they asked for.

function findMedianSortedArrays(a, b) {
  const m = a.length, n = b.length, merged = [];
  let i = 0, j = 0;
  while (i < m && j < n) {
    if (a[i] <= b[j]) merged.push(a[i++]);
    else merged.push(b[j++]);
  }
  while (i < m) merged.push(a[i++]);
  while (j < n) merged.push(b[j++]);
  const mid = Math.floor((m + n) / 2);
  if ((m + n) % 2 === 1) return merged[mid];
  return (merged[mid - 1] + merged[mid]) / 2;
}


// Method 2: Optimal
// Time: O(m + n) | Space: O(1)
// Walk two pointers until you have seen the median index (and the one before it for even length). No merged array. Linear time, constant extra memory. Still not log.

function findMedianSortedArrays(a, b) {
  const m = a.length, n = b.length, last = Math.floor((m + n) / 2);
  let i = 0, j = 0, prev = 0, cur = 0;
  for (let t = 0; t <= last; t++) {
    prev = cur;
    if (i < m && (j >= n || a[i] <= b[j])) cur = a[i++];
    else cur = b[j++];
  }
  if ((m + n) % 2 === 1) return cur;
  return (prev + cur) / 2;
}


// Method 3: More optimal
// Time: O(log(min(m, n))) | Space: O(1)
// Binary search a cut on the shorter array. Left parts together hold half the items. If aLeft > bRight, cut is too far right. If bLeft > aRight, cut is too far left. When both sides cross correctly, the median is max(lefts) or the average with min(rights).

function findMedianSortedArrays(a, b) {
  if (a.length > b.length) return findMedianSortedArrays(b, a);
  const m = a.length, n = b.length;
  let lo = 0, hi = m;
  const half = Math.floor((m + n + 1) / 2);
  while (lo <= hi) {
    const i = lo + ((hi - lo) >> 1);
    const j = half - i;
    const aL = i === 0 ? -1e15 : a[i - 1];
    const aR = i === m ? 1e15 : a[i];
    const bL = j === 0 ? -1e15 : b[j - 1];
    const bR = j === n ? 1e15 : b[j];
    if (aL <= bR && bL <= aR) {
      if ((m + n) % 2 === 1) return aL > bL ? aL : bL;
      const left = aL > bL ? aL : bL;
      const right = aR < bR ? aR : bR;
      return (left + right) / 2;
    }
    if (aL > bR) hi = i - 1;
    else lo = i + 1;
  }
  return 0;
}
