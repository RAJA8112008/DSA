// Method 1: Brute
// Time: O(n log n) find | Space: O(n)
// Keep every number. findMedian copies and sorts. addNum is O(1). Queries get slower as the stream grows.

class MedianFinder {
  vector<int> a;
public:
  void addNum(int num) { a.push_back(num); }
  double findMedian() {
    vector<int> b = a;
    sort(b.begin(), b.end());
    int n = (int)b.size();
    if (n % 2) return b[(n - 1) / 2];
    return (b[n / 2 - 1] + b[n / 2]) / 2.0;
  }
};


// Method 2: Optimal
// Time: O(n) add, O(1) find | Space: O(n)
// Keep a sorted array. Binary search the insert index, then splice. findMedian is O(1). Better than sorting everything on each query.

class MedianFinder {
  vector<int> a;
public:
  void addNum(int num) {
    int lo = 0, hi = (int)a.size();
    while (lo < hi) {
      int mid = (lo + hi) >> 1;
      if (a[mid] < num) lo = mid + 1;
      else hi = mid;
    }
    a.insert(a.begin() + lo, num);
  }
  double findMedian() {
    int n = (int)a.size();
    if (n % 2) return a[(n - 1) / 2];
    return (a[n / 2 - 1] + a[n / 2]) / 2.0;
  }
};


// Method 3: More optimal
// Time: O(log n) add, O(1) find | Space: O(n)
// low is a max-heap (negated in a min-heap). high is a min-heap. Balance sizes. Median is low's top, or the average of both tops. True stream solution.

class MedianFinder {
  vector<int> low, high; // low stores negated max-heap; high min-heap
  void up(vector<int>& h, int i) {
    while (i > 0) { int p=(i-1)>>1; if (h[i]>=h[p]) break; swap(h[i], h[p]); i=p; }
  }
  void down(vector<int>& h, int i) {
    int n=(int)h.size();
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<n && h[l]<h[s]) s=l; if (r<n && h[r]<h[s]) s=r;
      if (s==i) break; swap(h[i], h[s]); i=s; }
  }
  void push(vector<int>& h, int x) { h.push_back(x); up(h, (int)h.size()-1); }
  int pop(vector<int>& h) {
    int top = h[0]; h[0]=h.back(); h.pop_back(); if (!h.empty()) down(h, 0); return top;
  }
public:
  void addNum(int num) {
    push(low, -num);
    push(high, -pop(low));
    if (high.size() > low.size()) push(low, -pop(high));
  }
  double findMedian() {
    if (low.size() > high.size()) return -low[0];
    return (-low[0] + high[0]) / 2.0;
  }
};
