// Method 1: Brute
// Time: O(max(piles) * n) | Space: O(1)
// Try k = 1, 2, ... max pile. First k that finishes in h hours is the answer. Correct, but max pile can be 10^9 so this times out.

function minEatingSpeed(piles, h) {
  function hours(k) {
    let t = 0;
    for (let i = 0; i < piles.length; i++) t += Math.ceil(piles[i] / k);
    return t;
  }
  const cap = Math.max.apply(null, piles);
  for (let k = 1; k <= cap; k++) if (hours(k) <= h) return k;
  return cap;
}


// Method 2: Optimal
// Time: O(n log max(piles)) | Space: O(1)
// Binary search the first speed that finishes on time. If mid works, try slower (hi = mid). If not, need faster (lo = mid + 1). Each check walks all piles.

function minEatingSpeed(piles, h) {
  function hours(k) {
    let t = 0;
    for (let i = 0; i < piles.length; i++) t += Math.floor((piles[i] + k - 1) / k);
    return t;
  }
  let lo = 1, hi = piles[0];
  for (let i = 1; i < piles.length; i++) if (piles[i] > hi) hi = piles[i];
  while (lo < hi) {
    const mid = (lo + hi) >> 1;
    if (hours(mid) <= h) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(n log max(piles)) | Space: O(1)
// Overflow-safe mid. Integer ceil only (no float). Early exit in the hour count when the running total already exceeds h, so a failing speed can fail before the last pile.

function minEatingSpeed(piles, h) {
  function ok(k) {
    let t = 0;
    for (let i = 0; i < piles.length; i++) {
      t += Math.floor((piles[i] + k - 1) / k);
      if (t > h) return false;
    }
    return true;
  }
  let lo = 1, hi = piles[0];
  for (let i = 1; i < piles.length; i++) if (piles[i] > hi) hi = piles[i];
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
