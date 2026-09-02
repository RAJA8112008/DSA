// Method 1: Brute
// Time: O(n log n) find | Space: O(n)
// Keep every number. findMedian copies and sorts. addNum is O(1). Queries get slower as the stream grows.

import java.util.*;
class MedianFinder {
  ArrayList<Integer> a = new ArrayList<Integer>();
  public MedianFinder() {}
  public void addNum(int num) { a.add(num); }
  public double findMedian() {
    ArrayList<Integer> b = new ArrayList<Integer>(a);
    Collections.sort(b);
    int n = b.size();
    if (n % 2 != 0) return b.get((n - 1) / 2);
    return (b.get(n / 2 - 1) + b.get(n / 2)) / 2.0;
  }
}
class Solution {}


// Method 2: Optimal
// Time: O(n) add, O(1) find | Space: O(n)
// Keep a sorted array. Binary search the insert index, then splice. findMedian is O(1). Better than sorting everything on each query.

import java.util.*;
class MedianFinder {
  ArrayList<Integer> a = new ArrayList<Integer>();
  public MedianFinder() {}
  public void addNum(int num) {
    int lo = 0, hi = a.size();
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (a.get(mid) < num) lo = mid + 1;
      else hi = mid;
    }
    a.add(lo, num);
  }
  public double findMedian() {
    int n = a.size();
    if (n % 2 != 0) return a.get((n - 1) / 2);
    return (a.get(n / 2 - 1) + a.get(n / 2)) / 2.0;
  }
}
class Solution {}


// Method 3: More optimal
// Time: O(log n) add, O(1) find | Space: O(n)
// low is a max-heap (negated in a min-heap). high is a min-heap. Balance sizes. Median is low's top, or the average of both tops. True stream solution.

class MedianFinder {
  int[] low = new int[8], high = new int[8];
  int ln = 0, hn = 0;
  void grow() {
    if (ln == low.length) low = java.util.Arrays.copyOf(low, ln * 2);
    if (hn == high.length) high = java.util.Arrays.copyOf(high, hn * 2);
  }
  void up(int[] h, int n, int i) {
    while (i > 0) { int p=(i-1)>>1; if (h[i]>=h[p]) break; int t=h[i]; h[i]=h[p]; h[p]=t; i=p; }
  }
  void down(int[] h, int n, int i) {
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<n && h[l]<h[s]) s=l; if (r<n && h[r]<h[s]) s=r;
      if (s==i) break; int t=h[i]; h[i]=h[s]; h[s]=t; i=s; }
  }
  void pushLow(int x) { grow(); low[ln++]=x; up(low, ln, ln-1); }
  void pushHigh(int x) { grow(); high[hn++]=x; up(high, hn, hn-1); }
  int popLow() { int t=low[0]; low[0]=low[--ln]; if (ln>0) down(low, ln, 0); return t; }
  int popHigh() { int t=high[0]; high[0]=high[--hn]; if (hn>0) down(high, hn, 0); return t; }
  public MedianFinder() {}
  public void addNum(int num) {
    pushLow(-num);
    pushHigh(-popLow());
    if (hn > ln) pushLow(-popHigh());
  }
  public double findMedian() {
    if (ln > hn) return -low[0];
    return (-low[0] + high[0]) / 2.0;
  }
}
class Solution {}
