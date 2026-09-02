# Method 1: Brute
# Time: O(n * 2^{2n}) | Space: O(n * 2^{2n})
# Every bit mask is a string of ( and ). You copy the string, then scan it with a balance counter. Most strings fail. Extra copies of every mask.

def generateParenthesis(n):
  ans = []
  total = 1 << (2 * n)
  for mask in range(total):
    s = []
    for b in range(2 * n):
      s.append("(" if mask & (1 << b) else ")")
    s = "".join(s)
    bal, ok = 0, True
    for ch in s:
      bal += 1 if ch == "(" else -1
      if bal < 0:
        ok = False
        break
    if ok and bal == 0:
      ans.append(s)
  return ans


# Method 2: Optimal
# Time: O(4^n / sqrt(n)) | Space: O(n)
# Backtrack with a char buffer. Try '(' and ')' at every length. Still visits some invalid prefixes unless you add the count checks (see More optimal).

def generateParenthesis(n):
  ans = []
  def valid(s):
    bal = 0
    for ch in s:
      bal += 1 if ch == "(" else -1
      if bal < 0:
        return False
    return bal == 0
  def go(path):
    if len(path) == 2 * n:
      s = "".join(path)
      if valid(s):
        ans.append(s)
      return
    path.append("(")
    go(path)
    path.pop()
    path.append(")")
    go(path)
    path.pop()
  go([])
  return ans


# Method 3: More optimal
# Time: O(4^n / sqrt(n)) | Space: O(n)
# Prune: add '(' only while open < n. Add ')' only while close < open. Leaves are exactly the Catalan number C_n. No invalid prefix is ever built.

def generateParenthesis(n):
  ans = []
  def go(open_n, close, path):
    if len(path) == 2 * n:
      ans.append("".join(path))
      return
    if open_n < n:
      path.append("(")
      go(open_n + 1, close, path)
      path.pop()
    if close < open_n:
      path.append(")")
      go(open_n, close + 1, path)
      path.pop()
  go(0, 0, [])
  return ans
