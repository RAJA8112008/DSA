# Method 1: Brute
# Time: O(n * 2^n) | Space: O(n * 2^n)
# At each index you either cut or keep growing the last piece, copying the piece list every time. After a full partition you test every piece. Many illegal cuttings are built first and thrown away.

def partition(s):
  ans = []
  def is_pal(parts):
    for w in parts:
      if w != w[::-1]:
        return False
    return True
  def go(i, parts, cur):
    if i == len(s):
      allp = parts + [cur] if cur else parts[:]
      if is_pal(allp):
        ans.append(allp)
      return
    go(i + 1, parts[:], cur + s[i])
    if cur:
      go(i, parts + [cur], "")
  go(0, [], "")
  return ans


# Method 2: Optimal
# Time: O(n * 2^n) | Space: O(n)
# From start, try every end. If s[start..end] is a palindrome, push it, recurse end+1, pop. Illegal prefixes never grow. Copy only at the end of s.

def partition(s):
  ans = []
  def is_pal(l, r):
    while l < r:
      if s[l] != s[r]:
        return False
      l += 1
      r -= 1
    return True
  def go(start, path):
    if start == len(s):
      ans.append(path[:])
      return
    for end in range(start, len(s)):
      if not is_pal(start, end):
        continue
      path.append(s[start:end + 1])
      go(end + 1, path)
      path.pop()
  go(0, [])
  return ans


# Method 3: More optimal
# Time: O(n * 2^n) | Space: O(n^2)
# pal[l][r] is true if s[l..r] is a palindrome. Fill in O(n^2). Each cut check is then O(1). Same 2^n cuttings, cheaper work per node.

def partition(s):
  n = len(s)
  pal = [[False] * n for _ in range(n)]
  for i in range(n):
    pal[i][i] = True
  for i in range(n - 1):
    pal[i][i + 1] = s[i] == s[i + 1]
  for length in range(3, n + 1):
    for l in range(n - length + 1):
      r = l + length - 1
      pal[l][r] = s[l] == s[r] and pal[l + 1][r - 1]
  ans = []
  def go(start, path):
    if start == n:
      ans.append(path[:])
      return
    for end in range(start, n):
      if not pal[start][end]:
        continue
      path.append(s[start:end + 1])
      go(end + 1, path)
      path.pop()
  go(0, [])
  return ans
