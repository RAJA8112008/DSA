// Method 1: Brute
// Time: O(n) calls | Space: O(1)
// Ask isBadVersion from 1 upward. First true is the answer. Correct, burns the API on large n.

function firstBadVersion(n, isBadVersion) {
  for (let i = 1; i <= n; i++) if (isBadVersion(i)) return i;
  return n;
}


// Method 2: Optimal
// Time: O(log n) calls | Space: O(1)
// Classic first-true. When mid is bad, store it and search left. When mid is good, search right. About log2(n) API calls.

function firstBadVersion(n, isBadVersion) {
  let lo = 1, hi = n, ans = n;
  while (lo <= hi) {
    const mid = (lo + hi) >> 1;
    if (isBadVersion(mid)) {
      ans = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }
  return ans;
}


// Method 3: More optimal
// Time: O(log n) calls | Space: O(1)
// Overflow-safe mid is required in Java: (lo+hi)/2 wraps when n is 2^31-1. Half-open while (lo < hi): bad means hi = mid, good means lo = mid + 1. Return lo. Same call count, no extra ans, no overflow.

function firstBadVersion(n, isBadVersion) {
  let lo = 1, hi = n;
  while (lo < hi) {
    const mid = lo + ((hi - lo) >> 1);
    if (isBadVersion(mid)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
