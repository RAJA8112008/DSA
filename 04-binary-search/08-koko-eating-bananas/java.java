// Method 1: Brute
// Time: O(max(piles) * n) | Space: O(1)
// Try k = 1, 2, ... max pile. First k that finishes in h hours is the answer. Correct, but max pile can be 10^9 so this times out.

class Solution {
  long hours(int[] piles, int k) {
    long t = 0;
    for (int p : piles) t += (p + (long) k - 1) / k;
    return t;
  }
  public int minEatingSpeed(int[] piles, int h) {
    int cap = piles[0];
    for (int p : piles) if (p > cap) cap = p;
    for (int k = 1; k <= cap; k++) if (hours(piles, k) <= h) return k;
    return cap;
  }
}


// Method 2: Optimal
// Time: O(n log max(piles)) | Space: O(1)
// Binary search the first speed that finishes on time. If mid works, try slower (hi = mid). If not, need faster (lo = mid + 1). Each check walks all piles.

class Solution {
  long hours(int[] piles, int k) {
    long t = 0;
    for (int p : piles) t += (p + (long) k - 1) / k;
    return t;
  }
  public int minEatingSpeed(int[] piles, int h) {
    int lo = 1, hi = piles[0];
    for (int p : piles) if (p > hi) hi = p;
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (hours(piles, mid) <= h) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
}


// Method 3: More optimal
// Time: O(n log max(piles)) | Space: O(1)
// Overflow-safe mid. Integer ceil only (no float). Early exit in the hour count when the running total already exceeds h, so a failing speed can fail before the last pile.

class Solution {
  boolean ok(int[] piles, int k, int h) {
    long t = 0;
    for (int p : piles) {
      t += (p + (long) k - 1) / k;
      if (t > h) return false;
    }
    return true;
  }
  public int minEatingSpeed(int[] piles, int h) {
    int lo = 1, hi = piles[0];
    for (int p : piles) if (p > hi) hi = p;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (ok(piles, mid, h)) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
}
