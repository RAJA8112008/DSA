# Method 1: Brute
# Time: O(n²) | Space: O(1)
# For each day i, scan j > i until temperatures[j] > temperatures[i]. Worst case a falling array, so n² compares.

def dailyTemperatures(temperatures):
  n = len(temperatures)
  ans = [0] * n
  for i in range(n):
    for j in range(i + 1, n):
      if temperatures[j] > temperatures[i]:
        ans[i] = j - i
        break
  return ans


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Stack of indices with decreasing temps. When a warmer day arrives, pop until the stack is cooler again. Each index is pushed and popped at most once.

def dailyTemperatures(temperatures):
  n = len(temperatures)
  ans = [0] * n
  st = []
  for i in range(n):
    while st and temperatures[st[-1]] < temperatures[i]:
      j = st.pop()
      ans[j] = i - j
    st.append(i)
  return ans


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Right-to-left jump: if day j is not warmer, skip ahead by ans[j] days (those days are also not warmer than j, hence not warmer than i if temps[j] <= temps[i]). Extra space is only the output. Still linear.

def dailyTemperatures(temperatures):
  n = len(temperatures)
  ans = [0] * n
  for i in range(n - 2, -1, -1):
    j = i + 1
    while j < n and temperatures[j] <= temperatures[i]:
      if ans[j] == 0:
        j = n
        break
      j += ans[j]
    if j < n:
      ans[i] = j - i
  return ans
