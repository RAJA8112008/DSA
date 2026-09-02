// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each bar, walk left and right while bars are at least this tall. Width times height. n starts, each can walk n.

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int best = 0, n = (int)heights.size();
    for (int i = 0; i < n; i++) {
      int left = i, right = i;
      while (left > 0 && heights[left - 1] >= heights[i]) left--;
      while (right + 1 < n && heights[right + 1] >= heights[i]) right++;
      best = max(best, heights[i] * (right - left + 1));
    }
    return best;
  }
};


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Two monotonic stacks: nearest smaller to the left, nearest smaller to the right. Then one pass of height * (right - left - 1). Each index processed a constant number of times.

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    int n = (int)heights.size();
    vector<int> left(n, -1), right(n, n), st;
    for (int i = 0; i < n; i++) {
      while (!st.empty() && heights[st.back()] >= heights[i]) st.pop_back();
      if (!st.empty()) left[i] = st.back();
      st.push_back(i);
    }
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
      while (!st.empty() && heights[st.back()] >= heights[i]) st.pop_back();
      if (!st.empty()) right[i] = st.back();
      st.push_back(i);
    }
    int best = 0;
    for (int i = 0; i < n; i++) best = max(best, heights[i] * (right[i] - left[i] - 1));
    return best;
  }
};


// Method 3: More optimal
// Time: O(n) | Space: O(n)
// Append a 0 sentinel so every bar gets popped. One increasing stack of indices. When you pop height h at i, the width is i - newTop - 1. Same linear bound, one pass, less arrays.

class Solution {
public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> h = heights;
    h.push_back(0);
    vector<int> st;
    st.push_back(-1);
    int best = 0;
    for (int i = 0; i < (int)h.size(); i++) {
      while (st.size() > 1 && h[st.back()] > h[i]) {
        int height = h[st.back()]; st.pop_back();
        int width = i - st.back() - 1;
        best = max(best, height * width);
      }
      st.push_back(i);
    }
    return best;
  }
};
