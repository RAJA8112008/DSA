// Method 1: Brute
// Time: O(m + n) | Space: O(m + n)
// Merge the two sorted lists into one, then pick the middle one or two values. Easy to code, extra memory, and not the log bound they asked for.

#include <stdlib.h>
double findMedianSortedArrays(int* a, int m, int* b, int n) {
  int* merged = (int*)malloc(sizeof(int) * (m + n));
  int i = 0, j = 0, k = 0;
  while (i < m && j < n) merged[k++] = a[i] <= b[j] ? a[i++] : b[j++];
  while (i < m) merged[k++] = a[i++];
  while (j < n) merged[k++] = b[j++];
  int mid = (m + n) / 2;
  double ans;
  if ((m + n) % 2) ans = merged[mid];
  else ans = (merged[mid - 1] + merged[mid]) / 2.0;
  free(merged);
  return ans;
}


// Method 2: Optimal
// Time: O(m + n) | Space: O(1)
// Walk two pointers until you have seen the median index (and the one before it for even length). No merged array. Linear time, constant extra memory. Still not log.

double findMedianSortedArrays(int* a, int m, int* b, int n) {
  int last = (m + n) / 2, i = 0, j = 0, prev = 0, cur = 0;
  for (int t = 0; t <= last; t++) {
    prev = cur;
    if (i < m && (j >= n || a[i] <= b[j])) cur = a[i++];
    else cur = b[j++];
  }
  if ((m + n) % 2) return cur;
  return (prev + cur) / 2.0;
}


// Method 3: More optimal
// Time: O(log(min(m, n))) | Space: O(1)
// Binary search a cut on the shorter array. Left parts together hold half the items. If aLeft > bRight, cut is too far right. If bLeft > aRight, cut is too far left. When both sides cross correctly, the median is max(lefts) or the average with min(rights).

double findMedianSortedArrays(int* a, int m, int* b, int n) {
  if (m > n) return findMedianSortedArrays(b, n, a, m);
  int lo = 0, hi = m, half = (m + n + 1) / 2;
  const long long INF = 1000000000000000LL;
  while (lo <= hi) {
    int i = lo + ((hi - lo) >> 1);
    int j = half - i;
    long long aL = i == 0 ? -INF : a[i - 1];
    long long aR = i == m ? INF : a[i];
    long long bL = j == 0 ? -INF : b[j - 1];
    long long bR = j == n ? INF : b[j];
    if (aL <= bR && bL <= aR) {
      if ((m + n) % 2) return (double)(aL > bL ? aL : bL);
      long long left = aL > bL ? aL : bL;
      long long right = aR < bR ? aR : bR;
      return (left + right) / 2.0;
    }
    if (aL > bR) hi = i - 1;
    else lo = i + 1;
  }
  return 0;
}
