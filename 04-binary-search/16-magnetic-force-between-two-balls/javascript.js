// Method 1: Brute
// Time: O((max-min) * n) | Space: O(1)
// Sort, then try every distance from (max-min) down to 1. First distance that can place m balls is the answer. Distance range can be 10^9, so this times out.

function maxDistance(position, m) {
  position = position.slice().sort(function (a, b) { return a - b; });
  function can(dist) {
    let count = 1, last = position[0];
    for (let i = 1; i < position.length; i++) {
      if (position[i] - last >= dist) { count++; last = position[i]; }
    }
    return count >= m;
  }
  const span = position[position.length - 1] - position[0];
  for (let d = span; d >= 1; d--) if (can(d)) return d;
  return 0;
}


// Method 2: Optimal
// Time: O(n log(max-min)) | Space: O(1)
// Sort once. Binary search the gap. Greedy: place the next ball at the first basket that is at least mid away from the last placed ball. If you place m, try a larger gap (lo = mid + 1).

function maxDistance(position, m) {
  position = position.slice().sort(function (a, b) { return a - b; });
  function can(dist) {
    let count = 1, last = position[0];
    for (let i = 1; i < position.length; i++) {
      if (position[i] - last >= dist) { count++; last = position[i]; if (count >= m) return true; }
    }
    return false;
  }
  let lo = 1, hi = position[position.length - 1] - position[0], ans = 0;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (can(mid)) { ans = mid; lo = mid + 1; }
    else hi = mid - 1;
  }
  return ans;
}


// Method 3: More optimal
// Time: O(n log(max-min)) | Space: O(1)
// Overflow-safe mid. Half-open last-true: if mid works, lo = mid + 1, else hi = mid, then return lo - 1. No separate ans. Early stop once m balls are placed.

function maxDistance(position, m) {
  position = position.slice().sort(function (a, b) { return a - b; });
  function can(dist) {
    let count = 1, last = position[0];
    for (let i = 1; i < position.length; i++) {
      if (position[i] - last >= dist) {
        count++;
        last = position[i];
        if (count >= m) return true;
      }
    }
    return false;
  }
  let lo = 1, hi = position[position.length - 1] - position[0] + 1;
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (can(mid)) lo = mid + 1;
    else hi = mid;
  }
  return lo - 1;
}
