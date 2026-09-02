// Method 1: Brute
// Time: O(sum * n) | Space: O(1)
// Try every capacity from the heaviest box up to the total sum. First success is the answer. Sum can be huge, so this is only the idea sketch.

class Solution {
  int need(int[] weights, int cap) {
    int d = 1, load = 0;
    for (int w : weights) {
      if (load + w > cap) { d++; load = 0; }
      load += w;
    }
    return d;
  }
  public int shipWithinDays(int[] weights, int days) {
    int lo = 0, hi = 0;
    for (int w : weights) { if (w > lo) lo = w; hi += w; }
    for (int cap = lo; cap <= hi; cap++) if (need(weights, cap) <= days) return cap;
    return hi;
  }
}


// Method 2: Optimal
// Time: O(n log sum) | Space: O(1)
// Binary search capacity. Greedy load until the next package would overflow, then start a new day. If that day count is <= D, try a smaller cap.

class Solution {
  int need(int[] weights, int cap) {
    int d = 1, load = 0;
    for (int w : weights) {
      if (load + w > cap) { d++; load = 0; }
      load += w;
    }
    return d;
  }
  public int shipWithinDays(int[] weights, int days) {
    int lo = 0, hi = 0;
    for (int w : weights) { if (w > lo) lo = w; hi += w; }
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (need(weights, mid) <= days) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
}


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Overflow-safe mid. Stop counting days as soon as d exceeds the limit. Same answer, fewer wasted additions on a capacity that is clearly too small.

class Solution {
  boolean ok(int[] weights, int cap, int days) {
    int d = 1, load = 0;
    for (int w : weights) {
      if (w > cap) return false;
      if (load + w > cap) {
        d++;
        load = 0;
        if (d > days) return false;
      }
      load += w;
    }
    return true;
  }
  public int shipWithinDays(int[] weights, int days) {
    int lo = 0, hi = 0;
    for (int w : weights) { if (w > lo) lo = w; hi += w; }
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (ok(weights, mid, days)) hi = mid;
      else lo = mid + 1;
    }
    return lo;
  }
}
