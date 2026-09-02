// Method 1: Brute
// Time: O(m + n) | Space: O(m + n)
// Merge the two sorted lists into one, then pick the middle one or two values. Easy to code, extra memory, and not the log bound they asked for.

class Solution {
  public double findMedianSortedArrays(int[] a, int[] b) {
    int m = a.length, n = b.length;
    int[] merged = new int[m + n];
    int i = 0, j = 0, k = 0;
    while (i < m && j < n) merged[k++] = a[i] <= b[j] ? a[i++] : b[j++];
    while (i < m) merged[k++] = a[i++];
    while (j < n) merged[k++] = b[j++];
    int mid = (m + n) / 2;
    if (((m + n) & 1) == 1) return merged[mid];
    return (merged[mid - 1] + merged[mid]) / 2.0;
  }
}


// Method 2: Optimal
// Time: O(m + n) | Space: O(1)
// Walk two pointers until you have seen the median index (and the one before it for even length). No merged array. Linear time, constant extra memory. Still not log.

class Solution {
  public double findMedianSortedArrays(int[] a, int[] b) {
    int m = a.length, n = b.length, last = (m + n) / 2;
    int i = 0, j = 0, prev = 0, cur = 0;
    for (int t = 0; t <= last; t++) {
      prev = cur;
      if (i < m && (j >= n || a[i] <= b[j])) cur = a[i++];
      else cur = b[j++];
    }
    if (((m + n) & 1) == 1) return cur;
    return (prev + cur) / 2.0;
  }
}


// Method 3: More optimal
// Time: O(log(min(m, n))) | Space: O(1)
// Binary search a cut on the shorter array. Left parts together hold half the items. If aLeft > bRight, cut is too far right. If bLeft > aRight, cut is too far left. When both sides cross correctly, the median is max(lefts) or the average with min(rights).

class Solution {
  public double findMedianSortedArrays(int[] a, int[] b) {
    if (a.length > b.length) return findMedianSortedArrays(b, a);
    int m = a.length, n = b.length;
    int lo = 0, hi = m, half = (m + n + 1) / 2;
    while (lo <= hi) {
      int i = lo + ((hi - lo) >> 1);
      int j = half - i;
      long aL = i == 0 ? Long.MIN_VALUE / 4 : a[i - 1];
      long aR = i == m ? Long.MAX_VALUE / 4 : a[i];
      long bL = j == 0 ? Long.MIN_VALUE / 4 : b[j - 1];
      long bR = j == n ? Long.MAX_VALUE / 4 : b[j];
      if (aL <= bR && bL <= aR) {
        if (((m + n) & 1) == 1) return Math.max(aL, bL);
        return (Math.max(aL, bL) + Math.min(aR, bR)) / 2.0;
      }
      if (aL > bR) hi = i - 1;
      else lo = i + 1;
    }
    return 0;
  }
}
