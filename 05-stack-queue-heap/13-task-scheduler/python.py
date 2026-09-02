# Method 1: Brute
# Time: O(k^t) | Space: O(k)
# At each time slot, try every task type that still has remaining count and is off cooldown. Exponential in the number of tasks. Only for teaching.

def leastInterval(tasks, n):
  count = {}
  for t in tasks:
    count[t] = count.get(t, 0) + 1
  types = list(count.keys())
  best = float("inf")
  def left():
    return sum(count[t] for t in types)
  def dfs(time, cool):
    nonlocal best
    if time >= best: return
    if not left():
      best = time
      return
    placed = False
    for t in types:
      if count[t] == 0: continue
      if cool.get(t, 0) > time: continue
      placed = True
      count[t] -= 1
      old = cool.get(t, 0)
      cool[t] = time + n + 1
      dfs(time + 1, cool)
      cool[t] = old
      count[t] += 1
    if not placed:
      dfs(time + 1, cool)
  dfs(0, {})
  return best


# Method 2: Optimal
# Time: O(t log k) | Space: O(k)
# Max-heap of remaining counts (26 letters). Each round pop one, then park it in a cooldown queue for n+1 time. Idle when the heap is empty but cooldown is not. k is at most 26.

def leastInterval(tasks, n):
  freq = [0] * 26
  for t in tasks:
    freq[ord(t) - 65] += 1
  h = []
  def up(i):
    while i > 0:
      p = (i - 1) >> 1
      if h[i] <= h[p]: break
      h[i], h[p] = h[p], h[i]
      i = p
  def down(i):
    while True:
      s = i
      l, r = i * 2 + 1, i * 2 + 2
      if l < len(h) and h[l] > h[s]: s = l
      if r < len(h) and h[r] > h[s]: s = r
      if s == i: break
      h[i], h[s] = h[s], h[i]
      i = s
  def push(x):
    h.append(x); up(len(h) - 1)
  def pop():
    top = h[0]
    last = h.pop()
    if h:
      h[0] = last; down(0)
    return top
  for i in range(26):
    if freq[i]: push(freq[i])
  cool = []
  time = 0
  while h or cool:
    time += 1
    if h:
      left = pop() - 1
      if left: cool.append([left, time + n])
    if cool and cool[0][1] == time:
      push(cool.pop(0)[0])
  return time


# Method 3: More optimal
# Time: O(t) | Space: O(1)
# The busy skeleton is (maxFreq-1) groups of (n+1) slots, plus the tasks that share maxFreq. If that is shorter than tasks.length, there is no idle and the answer is tasks.length. O(t) count, O(1) extra.

def leastInterval(tasks, n):
  freq = [0] * 26
  for t in tasks:
    freq[ord(t) - 65] += 1
  maxF = maxCount = 0
  for f in freq:
    if f > maxF:
      maxF = f; maxCount = 1
    elif f == maxF:
      maxCount += 1
  frame = (maxF - 1) * (n + 1) + maxCount
  return max(frame, len(tasks))
