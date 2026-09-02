// Method 1: Brute
// Time: O(n · k) | Space: O(1)
// For each window start, scan k items for the max. Simple and too slow when k is n/2.

function maxSlidingWindow(nums, k) {
  const out = [];
  for (let i = 0; i + k - 1 < nums.length; i++) {
    let m = nums[i];
    for (let j = i + 1; j < i + k; j++) if (nums[j] > m) m = nums[j];
    out.push(m);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Max-heap of [value, index] (store negated value in a min-heap). Pop the top while its index left the window. Lazy delete keeps the heap honest. Better than n*k, worse than a deque.

function maxSlidingWindow(nums, k) {
  function MinHeap() {
    this.a = [];
  }
  MinHeap.prototype.key = function (x) { return x[0]; };
  MinHeap.prototype.push = function (x) {
    this.a.push(x);
    let i = this.a.length - 1;
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (this.a[i][0] >= this.a[p][0]) break;
      const t = this.a[i]; this.a[i] = this.a[p]; this.a[p] = t;
      i = p;
    }
  };
  MinHeap.prototype.pop = function () {
    const top = this.a[0];
    const last = this.a.pop();
    if (this.a.length) {
      this.a[0] = last;
      let i = 0;
      while (true) {
        let s = i;
        const l = i * 2 + 1, r = l + 1;
        if (l < this.a.length && this.a[l][0] < this.a[s][0]) s = l;
        if (r < this.a.length && this.a[r][0] < this.a[s][0]) s = r;
        if (s === i) break;
        const t = this.a[i]; this.a[i] = this.a[s]; this.a[s] = t;
        i = s;
      }
    }
    return top;
  };
  MinHeap.prototype.peek = function () { return this.a[0]; };

  const heap = new MinHeap();
  const out = [];
  for (let i = 0; i < nums.length; i++) {
    heap.push([-nums[i], i]);
    if (i < k - 1) continue;
    while (heap.peek()[1] <= i - k) heap.pop();
    out.push(-heap.peek()[0]);
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// Decreasing deque of indices. Pop back while nums[i] is larger. Pop front if it left the window. Front is the max. Each index enters and leaves once.

function maxSlidingWindow(nums, k) {
  const dq = [];
  const out = [];
  for (let i = 0; i < nums.length; i++) {
    while (dq.length && nums[dq[dq.length - 1]] <= nums[i]) dq.pop();
    dq.push(i);
    if (dq[0] <= i - k) dq.shift();
    if (i >= k - 1) out.push(nums[dq[0]]);
  }
  return out;
}
