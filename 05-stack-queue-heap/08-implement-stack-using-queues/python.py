# Method 1: Brute
# Time: O(n) pop | Space: O(n)
# Two queues. pop moves all but the last item to the other queue, then swaps names. Push is O(1). Pop is O(n).

from collections import deque
class MyStack:
  def __init__(self):
    self.q1 = deque()
    self.q2 = deque()
  def push(self, x):
    self.q1.append(x)
  def pop(self):
    while len(self.q1) > 1:
      self.q2.append(self.q1.popleft())
    val = self.q1.popleft()
    self.q1, self.q2 = self.q2, self.q1
    return val
  def top(self):
    val = self.pop()
    self.push(val)
    return val
  def empty(self):
    return not self.q1


# Method 2: Optimal
# Time: O(n) push, O(1) pop | Space: O(n)
# One queue. After push, rotate length-1 items so the new item sits at the front. pop/top/empty are then O(1).

from collections import deque
class MyStack:
  def __init__(self):
    self.q = deque()
  def push(self, x):
    self.q.append(x)
    for _ in range(len(self.q) - 1):
      self.q.append(self.q.popleft())
  def pop(self):
    return self.q.popleft()
  def top(self):
    return self.q[0]
  def empty(self):
    return not self.q


# Method 3: More optimal
# Time: O(1) push, O(n) pop | Space: O(n)
# One queue, no rotate on push. pop rotates n-1 items then shifts. Prefer this when pushes are common and pops are rare. Same extra space.

from collections import deque
class MyStack:
  def __init__(self):
    self.q = deque()
  def push(self, x):
    self.q.append(x)
  def pop(self):
    for _ in range(len(self.q) - 1):
      self.q.append(self.q.popleft())
    return self.q.popleft()
  def top(self):
    return self.q[-1]
  def empty(self):
    return not self.q
