// Method 1: Brute
// Time: O(n log n) find | Space: O(n)
// Keep every number. findMedian copies and sorts. addNum is O(1). Queries get slower as the stream grows.

function MedianFinder() {
  this.a = [];
}
MedianFinder.prototype.addNum = function (num) { this.a.push(num); };
MedianFinder.prototype.findMedian = function () {
  const b = this.a.slice().sort(function (x, y) { return x - y; });
  const n = b.length;
  if (n % 2) return b[(n - 1) / 2];
  return (b[n / 2 - 1] + b[n / 2]) / 2;
};


// Method 2: Optimal
// Time: O(n) add, O(1) find | Space: O(n)
// Keep a sorted array. Binary search the insert index, then splice. findMedian is O(1). Better than sorting everything on each query.

function MedianFinder() {
  this.a = [];
}
MedianFinder.prototype.addNum = function (num) {
  let lo = 0, hi = this.a.length;
  while (lo < hi) {
    const mid = (lo + hi) >> 1;
    if (this.a[mid] < num) lo = mid + 1;
    else hi = mid;
  }
  this.a.splice(lo, 0, num);
};
MedianFinder.prototype.findMedian = function () {
  const n = this.a.length;
  if (n % 2) return this.a[(n - 1) / 2];
  return (this.a[n / 2 - 1] + this.a[n / 2]) / 2;
};


// Method 3: More optimal
// Time: O(log n) add, O(1) find | Space: O(n)
// low is a max-heap (negated in a min-heap). high is a min-heap. Balance sizes. Median is low's top, or the average of both tops. True stream solution.

function MedianFinder() {
  this.low = [];  // max-heap via negated values
  this.high = []; // min-heap of the upper half
}
MedianFinder.prototype._up = function (h, i, key) {
  while (i > 0) {
    const p = (i - 1) >> 1;
    if (key(h[i]) >= key(h[p])) break;
    const t = h[i]; h[i] = h[p]; h[p] = t;
    i = p;
  }
};
MedianFinder.prototype._down = function (h, i, key) {
  while (true) {
    let s = i;
    const l = i * 2 + 1, r = l + 1;
    if (l < h.length && key(h[l]) < key(h[s])) s = l;
    if (r < h.length && key(h[r]) < key(h[s])) s = r;
    if (s === i) break;
    const t = h[i]; h[i] = h[s]; h[s] = t;
    i = s;
  }
};
MedianFinder.prototype._push = function (h, x, key) {
  h.push(x); this._up(h, h.length - 1, key);
};
MedianFinder.prototype._pop = function (h, key) {
  const top = h[0];
  const last = h.pop();
  if (h.length) { h[0] = last; this._down(h, 0, key); }
  return top;
};
MedianFinder.prototype.addNum = function (num) {
  const id = function (x) { return x; };
  this._push(this.low, -num, id);
  this._push(this.high, -this._pop(this.low, id), id);
  if (this.high.length > this.low.length) {
    this._push(this.low, -this._pop(this.high, id), id);
  }
};
MedianFinder.prototype.findMedian = function () {
  if (this.low.length > this.high.length) return -this.low[0];
  return (-this.low[0] + this.high[0]) / 2;
};
