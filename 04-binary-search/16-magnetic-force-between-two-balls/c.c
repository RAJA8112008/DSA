// Method 1: Brute
// Time: O((max-min) * n) | Space: O(1)
// Sort, then try every distance from (max-min) down to 1. First distance that can place m balls is the answer. Distance range can be 10^9, so this times out.

#include <stdlib.h>
int cmpInt(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
int canPlace(int* p, int n, int m, int dist) {
  int count = 1, last = p[0];
  for (int i = 1; i < n; i++) if (p[i] - last >= dist) { count++; last = p[i]; }
  return count >= m;
}
int maxDistance(int* position, int n, int m) {
  qsort(position, n, sizeof(int), cmpInt);
  int span = position[n - 1] - position[0];
  for (int d = span; d >= 1; d--) if (canPlace(position, n, m, d)) return d;
  return 0;
}


// Method 2: Optimal
// Time: O(n log(max-min)) | Space: O(1)
// Sort once. Binary search the gap. Greedy: place the next ball at the first basket that is at least mid away from the last placed ball. If you place m, try a larger gap (lo = mid + 1).

#include <stdlib.h>
int cmpInt(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
int canPlace(int* p, int n, int m, int dist) {
  int count = 1, last = p[0];
  for (int i = 1; i < n; i++) {
    if (p[i] - last >= dist) { count++; last = p[i]; if (count >= m) return 1; }
  }
  return 0;
}
int maxDistance(int* position, int n, int m) {
  qsort(position, n, sizeof(int), cmpInt);
  int lo = 1, hi = position[n - 1] - position[0], ans = 0;
  while (lo <= hi) {
    int mid = (lo + hi) >> 1;
    if (canPlace(position, n, m, mid)) { ans = mid; lo = mid + 1; }
    else hi = mid - 1;
  }
  return ans;
}


// Method 3: More optimal
// Time: O(n log(max-min)) | Space: O(1)
// Overflow-safe mid. Half-open last-true: if mid works, lo = mid + 1, else hi = mid, then return lo - 1. No separate ans. Early stop once m balls are placed.

#include <stdlib.h>
int cmpInt(const void* a, const void* b) { return *(const int*)a - *(const int*)b; }
int canPlace(int* p, int n, int m, int dist) {
  int count = 1, last = p[0];
  for (int i = 1; i < n; i++) {
    if (p[i] - last >= dist) { count++; last = p[i]; if (count >= m) return 1; }
  }
  return 0;
}
int maxDistance(int* position, int n, int m) {
  qsort(position, n, sizeof(int), cmpInt);
  int lo = 1, hi = position[n - 1] - position[0] + 1;
  while (lo < hi) {
    int mid = lo + ((hi - lo) >> 1);
    if (canPlace(position, n, m, mid)) lo = mid + 1;
    else hi = mid;
  }
  return lo - 1;
}
