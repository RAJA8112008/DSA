# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each bar, walk left and right while bars are at least this tall. Width times height. n starts, each can walk n.

def largestRectangleArea(heights):
  best = 0
  n = len(heights)
  for i in range(n):
    left = right = i
    while left > 0 and heights[left - 1] >= heights[i]:
      left -= 1
    while right + 1 < n and heights[right + 1] >= heights[i]:
      right += 1
    best = max(best, heights[i] * (right - left + 1))
  return best


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Two monotonic stacks: nearest smaller to the left, nearest smaller to the right. Then one pass of height * (right - left - 1). Each index processed a constant number of times.

def largestRectangleArea(heights):
  n = len(heights)
  left = [-1] * n
  right = [n] * n
  st = []
  for i in range(n):
    while st and heights[st[-1]] >= heights[i]:
      st.pop()
    if st: left[i] = st[-1]
    st.append(i)
  st = []
  for i in range(n - 1, -1, -1):
    while st and heights[st[-1]] >= heights[i]:
      st.pop()
    if st: right[i] = st[-1]
    st.append(i)
  best = 0
  for i in range(n):
    best = max(best, heights[i] * (right[i] - left[i] - 1))
  return best


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Append a 0 sentinel so every bar gets popped. One increasing stack of indices. When you pop height h at i, the width is i - newTop - 1. Same linear bound, one pass, less arrays.

def largestRectangleArea(heights):
  h = heights + [0]
  st = [-1]
  best = 0
  for i in range(len(h)):
    while len(st) > 1 and h[st[-1]] > h[i]:
      height = h[st.pop()]
      width = i - st[-1] - 1
      best = max(best, height * width)
    st.append(i)
  return best
