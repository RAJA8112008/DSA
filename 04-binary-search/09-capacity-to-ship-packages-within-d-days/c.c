// Method 1: Brute
// Time: O(sum * n) | Space: O(1)
// Try every capacity from the heaviest box up to the total sum. First success is the answer. Sum can be huge, so this is only the idea sketch.

int needCap(int* w, int n, int cap) {
  int d = 1, load = 0;
  for (int i = 0; i < n; i++) {
    if (load + w[i] > cap) { d++; load = 0; }
    load += w[i];
  }
  return d;
}
int shipWithinDays(int* weights, int n, int days) {
  int lo = 0, hi = 0;
  for (int i = 0; i < n; i++) { if (weights[i] > lo) lo = weights[i]; hi += weights[i]; }
  for (int cap = lo; cap <= hi; cap++) if (needCap(weights, n, cap) <= days) return cap;
  return hi;
}


// Method 2: Optimal
// Time: O(n log sum) | Space: O(1)
// Binary search capacity. Greedy load until the next package would overflow, then start a new day. If that day count is <= D, try a smaller cap.

int needCap(int* w, int n, int cap) {
  int d = 1, load = 0;
  for (int i = 0; i < n; i++) {
    if (load + w[i] > cap) { d++; load = 0; }
    load += w[i];
  }
  return d;
}
int shipWithinDays(int* weights, int n, int days) {
  int lo = 0, hi = 0;
  for (int i = 0; i < n; i++) { if (weights[i] > lo) lo = weights[i]; hi += weights[i]; }
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (needCap(weights, n, mid) <= days) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(n log sum) | Space: O(1)
// Overflow-safe mid. Stop counting days as soon as d exceeds the limit. Same answer, fewer wasted additions on a capacity that is clearly too small.

int okCap(int* w, int n, int cap, int days) {
  int d = 1, load = 0;
  for (int i = 0; i < n; i++) {
    if (w[i] > cap) return 0;
    if (load + w[i] > cap) {
      d++; load = 0;
      if (d > days) return 0;
    }
    load += w[i];
  }
  return 1;
}
int shipWithinDays(int* weights, int n, int days) {
  int lo = 0, hi = 0;
  for (int i = 0; i < n; i++) { if (weights[i] > lo) lo = weights[i]; hi += weights[i]; }
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (okCap(weights, n, mid, days)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
