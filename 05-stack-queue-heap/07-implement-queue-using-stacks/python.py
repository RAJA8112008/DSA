# Method 1: Brute
# Time: O(n) pop/peek | Space: O(n)
# On pop, pour all into temp (that reverses), pop, pour back. Every call is O(n). Easy to see FIFO, slow.

class MyQueue:
  def __init__(self):
    self.st = []
  def push(self, x):
    self.st.append(x)
  def pop(self):
    tmp = []
    while self.st:
      tmp.append(self.st.pop())
    val = tmp.pop()
    while tmp:
      self.st.append(tmp.pop())
    return val
  def peek(self):
    tmp = []
    while self.st:
      tmp.append(self.st.pop())
    val = tmp[-1]
    while tmp:
      self.st.append(tmp.pop())
    return val
  def empty(self):
    return not self.st


# Method 2: Optimal
# Time: O(1) amortized | Space: O(n)
# push always goes to inSt. pop/peek pour inSt into outSt only when outSt is empty. Each item moves at most twice.

class MyQueue:
  def __init__(self):
    self.inSt = []
    self.outSt = []
  def pour(self):
    if self.outSt: return
    while self.inSt:
      self.outSt.append(self.inSt.pop())
  def push(self, x):
    self.inSt.append(x)
  def pop(self):
    self.pour(); return self.outSt.pop()
  def peek(self):
    self.pour(); return self.outSt[-1]
  def empty(self):
    return not self.inSt and not self.outSt


# Method 3: More optimal
# Time: O(1) amortized | Space: O(n)
# Same two stacks. pop is written as peek plus a pop so pour lives in one place. Interviewers like this factoring; complexity matches Optimal.

class MyQueue:
  def __init__(self):
    self.inSt = []
    self.outSt = []
  def push(self, x):
    self.inSt.append(x)
  def peek(self):
    if not self.outSt:
      while self.inSt:
        self.outSt.append(self.inSt.pop())
    return self.outSt[-1]
  def pop(self):
    self.peek()
    return self.outSt.pop()
  def empty(self):
    return not self.inSt and not self.outSt
