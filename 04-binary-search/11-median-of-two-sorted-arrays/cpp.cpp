// Method 1: Brute
// Time: O(m + n) | Space: O(m + n)
// Merge the two sorted lists into one, then pick the middle one or two values. Easy to code, extra memory, and not the log bound they asked for.

class Solution {
public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int m = (int)a.size(), n = (int)b.size();
    vector<int> merged; merged.reserve(m + n);
    int i = 0, j = 0;
    while (i < m && j < n) merged.push_back(a[i] <= b[j] ? a[i++] : b[j++]);
    while (i < m) merged.push_back(a[i++]);
    while (j < n) merged.push_back(b[j++]);
    int mid = (m + n) / 2;
    if ((m + n) % 2) return merged[mid];
    return (merged[mid - 1] + merged[mid]) / 2.0;
  }
};


// Method 2: Optimal
// Time: O(m + n) | Space: O(1)
// Walk two pointers until you have seen the median index (and the one before it for even length). No merged array. Linear time, constant extra memory. Still not log.

class Solution {
public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    int m = (int)a.size(), n = (int)b.size(), last = (m + n) / 2;
    int i = 0, j = 0, prev = 0, cur = 0;
    for (int t = 0; t <= last; t++) {
      prev = cur;
      if (i < m && (j >= n || a[i] <= b[j])) cur = a[i++];
      else cur = b[j++];
    }
    if ((m + n) % 2) return cur;
    return (prev + cur) / 2.0;
  }
};


// Method 3: More optimal
// Time: O(log(min(m, n))) | Space: O(1)
// Binary search a cut on the shorter array. Left parts together hold half the items. If aLeft > bRight, cut is too far right. If bLeft > aRight, cut is too far left. When both sides cross correctly, the median is max(lefts) or the average with min(rights).

class Solution {
public:
  double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
    if (a.size() > b.size()) return findMedianSortedArrays(b, a);
    int m = (int)a.size(), n = (int)b.size();
    int lo = 0, hi = m, half = (m + n + 1) / 2;
    const long long INF = (1LL << 60);
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
};
