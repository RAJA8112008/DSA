# Method 1: Brute
# Time: O(n²) | Space: O(n)
# Copy the list. Each round find the first operator, replace the triple with one number. Splice is O(n), and you do it O(n) times.

def evalRPN(tokens):
  a = list(tokens)
  ops = {"+", "-", "*", "/"}
  def calc(a, b, op):
    if op == "+": return a + b
    if op == "-": return a - b
    if op == "*": return a * b
    return int(a / b)  # trunc toward 0
  while len(a) > 1:
    i = 0
    while a[i] not in ops:
      i += 1
    val = calc(int(a[i - 2]), int(a[i - 1]), a[i])
    a = a[:i - 2] + [str(val)] + a[i + 1:]
  return int(a[0])


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# One stack. Numbers go on. An operator pops b then a (order matters for - and /), pushes the result. One pass.

def evalRPN(tokens):
  st = []
  for t in tokens:
    if t not in "+-*/":
      st.append(int(t))
      continue
    b = st.pop()
    a = st.pop()
    if t == "+": st.append(a + b)
    elif t == "-": st.append(a - b)
    elif t == "*": st.append(a * b)
    else: st.append(int(a / b))
  return st[0]


# Method 3: More optimal
# Time: O(n) | Space: O(n)
# Same stack, but a small apply helper and bitwise trunc for JS integers (or Math.trunc). Cleaner talk track. Complexity unchanged.

def evalRPN(tokens):
  st = []
  def apply(op, a, b):
    if op == "+": return a + b
    if op == "-": return a - b
    if op == "*": return a * b
    return int(a / b)
  for t in tokens:
    if t in "+-*/":
      b = st.pop()
      a = st.pop()
      st.append(apply(t, a, b))
    else:
      st.append(int(t))
  return st[0]
