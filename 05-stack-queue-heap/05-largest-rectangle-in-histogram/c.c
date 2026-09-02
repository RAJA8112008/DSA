// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each bar, walk left and right while bars are at least this tall. Width times height. n starts, each can walk n.

int largestRectangleArea(int* heights, int n) {
  int best = 0;
  for (int i = 0; i < n; i++) {
    int left = i, right = i;
    while (left > 0 && heights[left - 1] >= heights[i]) left--;
    while (right + 1 < n && heights[right + 1] >= heights[i]) right++;
    int area = heights[i] * (right - left + 1);
    if (area > best) best = area;
  }
  return best;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Two monotonic stacks: nearest smaller to the left, nearest smaller to the right. Then one pass of height * (right - left - 1). Each index processed a constant number of times.

#include <stdlib.h>
int largestRectangleArea(int* heights, int n) {
  int* left = (int*)malloc(sizeof(int) * n);
  int* right = (int*)malloc(sizeof(int) * n);
  int* st = (int*)malloc(sizeof(int) * n);
  int sn = 0;
  for (int i = 0; i < n; i++) { left[i] = -1; right[i] = n; }
  for (int i = 0; i < n; i++) {
    while (sn && heights[st[sn-1]] >= heights[i]) sn--;
    if (sn) left[i] = st[sn-1];
    st[sn++] = i;
  }
  sn = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (sn && heights[st[sn-1]] >= heights[i]) sn--;
    if (sn) right[i] = st[sn-1];
    st[sn++] = i;
  }
  int best = 0;
  for (int i = 0; i < n; i++) {
    int area = heights[i] * (right[i] - left[i] - 1);
    if (area > best) best = area;
  }
  free(left); free(right); free(st);
  return best;
}


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Append a 0 sentinel so every bar gets popped. One increasing stack of indices. When you pop height h at i, the width is i - newTop - 1. Same linear bound, one pass, less arrays.

#include <stdlib.h>
int largestRectangleArea(int* heights, int n) {
  int* h = (int*)malloc(sizeof(int) * (n + 1));
  for (int i = 0; i < n; i++) h[i] = heights[i];
  h[n] = 0;
  int* st = (int*)malloc(sizeof(int) * (n + 2));
  int sn = 0;
  st[sn++] = -1;
  int best = 0;
  for (int i = 0; i <= n; i++) {
    while (sn > 1 && h[st[sn-1]] > h[i]) {
      int height = h[st[--sn]];
      int width = i - st[sn-1] - 1;
      if (height * width > best) best = height * width;
    }
    st[sn++] = i;
  }
  free(h); free(st);
  return best;
}
