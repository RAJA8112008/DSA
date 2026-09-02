// Method 1: Brute
// Time: O(sum * n) | Space: O(1)
// Try every capacity from the heaviest box up to the total sum. First success is the answer. Sum can be huge, so this is only the idea sketch.

function shipWithinDays(weights, days) {
  function need(cap) {
    let d = 1, load = 0;
    for (let i = 0; i < weights.length; i++) {
      if (load + weights[i] > cap) { d++; load = 0; }
      load += weights[i];
    }
    return d;
  }
  let lo = 0, hi = 0;
  for (let i = 0; i < weights.length; i++) {
    if (weights[i] > lo) lo = weights[i];
    hi += weights[i];
  }
  for (let cap = lo; cap <= hi; cap++) if (need(cap) <= days) return cap;
  return hi;
}


// Method 2: Optimal
// Time: O(n log sum) | Space: O(1)
// Binary search capacity. Greedy load until the next package would overflow, then start a new day. If that day count is <= D, try a smaller cap.

function shipWithinDays(weights, days) {
  function need(cap) {
    let d = 1, load = 0;
    for (let i = 0; i < weights.length; i++) {
      if (load + weights[i] > cap) { d++; load = 0; }
      load += weights[i];
    }
    return d;
  }
  let lo = 0, hi = 0;
  for (let i = 0; i < weights.length; i++) {
    if (weights[i] > lo) lo = weights[i];
    hi += weights[i];
  }
  while (lo < hi) {
    const mid = (lo + hi) >> 1;
    if (need(mid) <= days) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Overflow-safe mid. Stop counting days as soon as d exceeds the limit. Same answer, fewer wasted additions on a capacity that is clearly too small.

function shipWithinDays(weights, days) {
  function ok(cap) {
    let d = 1, load = 0;
    for (let i = 0; i < weights.length; i++) {
      if (weights[i] > cap) return false;
      if (load + weights[i] > cap) {
        d++;
        load = 0;
        if (d > days) return false;
      }
      load += weights[i];
    }
    return true;
  }
  let lo = 0, hi = 0;
  for (let i = 0; i < weights.length; i++) {
    if (weights[i] > lo) lo = weights[i];
    hi += weights[i];
  }
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
