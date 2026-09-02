// Method 1: Brute
// Time: O(max(piles) * n) | Space: O(1)
// Try k = 1, 2, ... max pile. First k that finishes in h hours is the answer. Correct, but max pile can be 10^9 so this times out.

long long hoursK(int* piles, int n, int k) {
  long long t = 0;
  for (int i = 0; i < n; i++) t += (piles[i] + (long long)k - 1) / k;
  return t;
}
int minEatingSpeed(int* piles, int n, int h) {
  int cap = piles[0];
  for (int i = 1; i < n; i++) if (piles[i] > cap) cap = piles[i];
  for (int k = 1; k <= cap; k++) if (hoursK(piles, n, k) <= h) return k;
  return cap;
}


// Method 2: Optimal
// Time: O(n log max(piles)) | Space: O(1)
// Binary search the first speed that finishes on time. If mid works, try slower (hi = mid). If not, need faster (lo = mid + 1). Each check walks all piles.

long long hoursK(int* piles, int n, int k) {
  long long t = 0;
  for (int i = 0; i < n; i++) t += (piles[i] + (long long)k - 1) / k;
  return t;
}
int minEatingSpeed(int* piles, int n, int h) {
  int lo = 1, hi = piles[0];
  for (int i = 1; i < n; i++) if (piles[i] > hi) hi = piles[i];
  while (lo < hi) {
    int mid = (lo + hi) >> 1;
    if (hoursK(piles, n, mid) <= h) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}


// Method 3: More optimal
// Time: O(n log max(piles)) | Space: O(1)
// Overflow-safe mid. Integer ceil only (no float). Early exit in the hour count when the running total already exceeds h, so a failing speed can fail before the last pile.

int okSpeed(int* piles, int n, int k, int h) {
  long long t = 0;
  for (int i = 0; i < n; i++) {
    t += (piles[i] + (long long)k - 1) / k;
    if (t > h) return 0;
  }
  return 1;
}
int minEatingSpeed(int* piles, int n, int h) {
  int lo = 1, hi = piles[0];
  for (int i = 1; i < n; i++) if (piles[i] > hi) hi = piles[i];
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (okSpeed(piles, n, mid, h)) hi = mid;
    else lo = mid + 1;
  }
  return lo;
}
