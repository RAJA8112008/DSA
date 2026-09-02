// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each bar, walk left and right while bars are at least this tall. Width times height. n starts, each can walk n.

function largestRectangleArea(heights) {
  let best = 0;
  const n = heights.length;
  for (let i = 0; i < n; i++) {
    let left = i, right = i;
    while (left > 0 && heights[left - 1] >= heights[i]) left--;
    while (right + 1 < n && heights[right + 1] >= heights[i]) right++;
    best = Math.max(best, heights[i] * (right - left + 1));
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Two monotonic stacks: nearest smaller to the left, nearest smaller to the right. Then one pass of height * (right - left - 1). Each index processed a constant number of times.

function largestRectangleArea(heights) {
  const n = heights.length;
  const left = Array(n).fill(-1);
  const right = Array(n).fill(n);
  const st = [];
  for (let i = 0; i < n; i++) {
    while (st.length && heights[st[st.length - 1]] >= heights[i]) st.pop();
    if (st.length) left[i] = st[st.length - 1];
    st.push(i);
  }
  st.length = 0;
  for (let i = n - 1; i >= 0; i--) {
    while (st.length && heights[st[st.length - 1]] >= heights[i]) st.pop();
    if (st.length) right[i] = st[st.length - 1];
    st.push(i);
  }
  let best = 0;
  for (let i = 0; i < n; i++) {
    best = Math.max(best, heights[i] * (right[i] - left[i] - 1));
  }
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Append a 0 sentinel so every bar gets popped. One increasing stack of indices. When you pop height h at i, the width is i - newTop - 1. Same linear bound, one pass, less arrays.

function largestRectangleArea(heights) {
  const h = heights.concat([0]);
  const st = [-1];
  let best = 0;
  for (let i = 0; i < h.length; i++) {
    while (st.length > 1 && h[st[st.length - 1]] > h[i]) {
      const height = h[st.pop()];
      const width = i - st[st.length - 1] - 1;
      best = Math.max(best, height * width);
    }
    st.push(i);
  }
  return best;
}
