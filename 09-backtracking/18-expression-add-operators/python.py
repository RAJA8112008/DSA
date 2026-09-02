# Method 1: Brute
# Time: O(4^n * n) | Space: O(n)
# Between digits you copy four choices: nothing (concat), +, -, *. At the end you parse and evaluate, respecting * first. Extra strings everywhere. Leading-zero expressions are built then thrown away.

def addOperators(num, target):
  ans = []
  ops = ["", "+", "-", "*"]
  def ok(expr):
    i = 0
    n = len(expr)
    while i < n:
      if expr[i] in "+-*":
        i += 1
        continue
      j = i
      while j < n and expr[j].isdigit():
        j += 1
      part = expr[i:j]
      if len(part) > 1 and part[0] == "0":
        return False
      i = j
    return True
  def eval_expr(expr):
    tokens = []
    i = 0
    n = len(expr)
    while i < n:
      if expr[i] in "+-":
        tokens.append(expr[i])
        i += 1
        continue
      if expr[i] == "*":
        i += 1
        continue
      j = i
      v = 0
      while j < n and expr[j].isdigit():
        v = v * 10 + ord(expr[j]) - 48
        j += 1
      if i > 0 and expr[i - 1] == "*":
        tokens[-1] *= v
      else:
        tokens.append(v)
      i = j
    sm, sign = 0, 1
    for t in tokens:
      if t == "+":
        sign = 1
      elif t == "-":
        sign = -1
      else:
        sm += sign * t
        sign = 1
    return sm
  def go(i, expr):
    if i == len(num):
      if ok(expr) and eval_expr(expr) == target:
        ans.append(expr)
      return
    if i == 0:
      go(1, num[0])
      return
    for op in ops:
      go(i + 1, expr + op + num[i])
  if num:
    go(0, "")
  return ans


# Method 2: Optimal
# Time: O(4^n) | Space: O(n)
# From index i, take the next operand as a long (concat digits). For the first number, just place it. Later, branch +, -, * onto one path buffer and undo. A running cur and last let you accept a leaf without a separate eval. Leading zeros are skipped.

def addOperators(num, target):
  ans = []
  def go(i, expr, cur, last):
    if i == len(num):
      if cur == target:
        ans.append(expr)
      return
    val = 0
    for j in range(i, len(num)):
      if j > i and num[i] == "0":
        break
      val = val * 10 + (ord(num[j]) - 48)
      piece = num[i:j + 1]
      if i == 0:
        go(j + 1, piece, val, val)
      else:
        go(j + 1, expr + "+" + piece, cur + val, val)
        go(j + 1, expr + "-" + piece, cur - val, -val)
        go(j + 1, expr + "*" + piece, cur - last + last * val, last * val)
  go(0, "", 0, 0)
  return ans


# Method 3: More optimal
# Time: O(4^n) | Space: O(n)
# Track cur (value of the expression so far) and last (the last operand, signed). Concat: last = last*10+d, cur = cur - oldLast + last. Plus: cur+val, last=val. Minus: cur-val, last=-val. Times: cur-last+last*val, last=last*val. No eval. Leading zeros break. Use 64-bit to avoid overflow.

def addOperators(num, target):
  ans = []
  def go(i, expr, cur, last):
    if i == len(num):
      if cur == target:
        ans.append(expr)
      return
    val = 0
    for j in range(i, len(num)):
      if j > i and num[i] == "0":
        break
      val = val * 10 + (ord(num[j]) - 48)
      piece = num[i:j + 1]
      if i == 0:
        go(j + 1, piece, val, val)
      else:
        go(j + 1, expr + "+" + piece, cur + val, val)
        go(j + 1, expr + "-" + piece, cur - val, -val)
        go(j + 1, expr + "*" + piece, cur - last + last * val, last * val)
  go(0, "", 0, 0)
  return ans
