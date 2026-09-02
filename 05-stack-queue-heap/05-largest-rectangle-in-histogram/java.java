// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each bar, walk left and right while bars are at least this tall. Width times height. n starts, each can walk n.

class Solution {
  public int largestRectangleArea(int[] heights) {
    int best = 0, n = heights.length;
    for (int i = 0; i < n; i++) {
      int left = i, right = i;
      while (left > 0 && heights[left - 1] >= heights[i]) left--;
      while (right + 1 < n && heights[right + 1] >= heights[i]) right++;
      best = Math.max(best, heights[i] * (right - left + 1));
    }
    return best;
  }
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Two monotonic stacks: nearest smaller to the left, nearest smaller to the right. Then one pass of height * (right - left - 1). Each index processed a constant number of times.

import java.util.*;
class Solution {
  public int largestRectangleArea(int[] heights) {
    int n = heights.length;
    int[] left = new int[n], right = new int[n];
    Arrays.fill(left, -1);
    Arrays.fill(right, n);
    ArrayDeque<Integer> st = new ArrayDeque<Integer>();
    for (int i = 0; i < n; i++) {
      while (!st.isEmpty() && heights[st.peek()] >= heights[i]) st.pop();
      if (!st.isEmpty()) left[i] = st.peek();
      st.push(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.isEmpty() && heights[st.peek()] >= heights[i]) st.pop();
      if (!st.isEmpty()) right[i] = st.peek();
      st.push(i);
    }
    int best = 0;
    for (int i = 0; i < n; i++) best = Math.max(best, heights[i] * (right[i] - left[i] - 1));
    return best;
  }
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Append a 0 sentinel so every bar gets popped. One increasing stack of indices. When you pop height h at i, the width is i - newTop - 1. Same linear bound, one pass, less arrays.

import java.util.*;
class Solution {
  public int largestRectangleArea(int[] heights) {
    int n = heights.length;
    int[] h = Arrays.copyOf(heights, n + 1);
    ArrayDeque<Integer> st = new ArrayDeque<Integer>();
    st.push(-1);
    int best = 0;
    for (int i = 0; i < h.length; i++) {
      while (st.size() > 1 && h[st.peek()] > h[i]) {
        int height = h[st.pop()];
        int width = i - st.peek() - 1;
        best = Math.max(best, height * width);
      }
      st.push(i);
    }
    return best;
  }
}
