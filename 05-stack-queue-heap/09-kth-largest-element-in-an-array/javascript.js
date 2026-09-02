// Method 1: Brute
// Time: O(n · k) | Space: O(n)
// Copy the array. k times, find and remove the current max. Fine for tiny k, slow for k near n.

function findKthLargest(nums, k) {
  const a = nums.slice();
  let ans = 0;
  for (let t = 0; t < k; t++) {
    let best = 0;
    for (let i = 1; i < a.length; i++) if (a[i] > a[best]) best = i;
    ans = a[best];
    a.splice(best, 1);
  }
  return ans;
}


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort descending (or ascending and index). Honest and short. Use this first in an interview, then offer a heap.

function findKthLargest(nums, k) {
  const a = nums.slice().sort(function (x, y) { return y - x; });
  return a[k - 1];
}


// Method 3: More optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of size k. If the heap is full and x is bigger than the peek, replace the peek. The peek is the k-th largest. Tiny binary heap inlined. Quickselect is expected O(n) if they want that next.

function findKthLargest(nums, k) {
  const h = [];
  function up(i) {
    while (i > 0) {
      const p = (i - 1) >> 1;
      if (h[i] >= h[p]) break;
      const t = h[i]; h[i] = h[p]; h[p] = t;
      i = p;
    }
  }
  function down(i) {
    while (true) {
      let s = i;
      const l = i * 2 + 1, r = l + 1;
      if (l < h.length && h[l] < h[s]) s = l;
      if (r < h.length && h[r] < h[s]) s = r;
      if (s === i) break;
      const t = h[i]; h[i] = h[s]; h[s] = t;
      i = s;
    }
  }
  function push(x) { h.push(x); up(h.length - 1); }
  function pop() {
    const top = h[0];
    const last = h.pop();
    if (h.length) { h[0] = last; down(0); }
    return top;
  }
  for (let i = 0; i < nums.length; i++) {
    if (h.length < k) push(nums[i]);
    else if (nums[i] > h[0]) { pop(); push(nums[i]); }
  }
  return h[0];
}
