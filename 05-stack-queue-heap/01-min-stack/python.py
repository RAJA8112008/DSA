# Method 1: Brute
# Time: O(n) getMin | Space: O(n)
# A plain array. getMin walks every item. Correct, but the interview asks for O(1) getMin.

class MinStack:
  def __init__(self):
    self.a = []
  def push(self, val):
    self.a.append(val)
  def pop(self):
    self.a.pop()
  def top(self):
    return self.a[-1]
  def getMin(self):
    m = self.a[0]
    for x in self.a[1:]:
      if x < m: m = x
    return m


# Method 2: Optimal
# Time: O(1) | Space: O(n)
# mins tracks the current minimum. Push val onto mins if it is <= current min. Pop mins when the popped value equals mins top. Duplicate mins matter: use <= so two equal mins both sit on mins.

class MinStack:
  def __init__(self):
    self.st = []
    self.mins = []
  def push(self, val):
    self.st.append(val)
    if not self.mins or val <= self.mins[-1]:
      self.mins.append(val)
  def pop(self):
    val = self.st.pop()
    if val == self.mins[-1]:
      self.mins.pop()
  def top(self):
    return self.st[-1]
  def getMin(self):
    return self.mins[-1]


# Method 3: More optimal
# Time: O(1) | Space: O(n)
# One stack of pairs [val, minSoFar]. Each node already knows the min of the prefix. Slightly more memory per item, one structure to talk through. Still O(1) everything.

class MinStack:
  def __init__(self):
    self.st = []
  def push(self, val):
    m = min(self.st[-1][1], val) if self.st else val
    self.st.append((val, m))
  def pop(self):
    self.st.pop()
  def top(self):
    return self.st[-1][0]
  def getMin(self):
    return self.st[-1][1]
