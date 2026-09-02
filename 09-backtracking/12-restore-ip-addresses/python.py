# Method 1: Brute
# Time: O(n^4) | Space: O(n)
# Three nested cuts copy substring pieces, then a validator checks leading zeros and 0..255. n is at most 12, so this still finishes, but you build illegal IPs first.

def restoreIpAddresses(s):
  ans = []
  def ok(part):
    if not part or len(part) > 3:
      return False
    if len(part) > 1 and part[0] == "0":
      return False
    v = int(part)
    return 0 <= v <= 255
  n = len(s)
  for i in range(1, n):
    for j in range(i + 1, n):
      for k in range(j + 1, n):
        a, b, c, d = s[:i], s[i:j], s[j:k], s[k:]
        if ok(a) and ok(b) and ok(c) and ok(d):
          ans.append(".".join([a, b, c, d]))
  return ans


# Method 2: Optimal
# Time: O(1) | Space: O(1)
# s length is at most 12, so the search is constant. Backtrack parts 0..3. From i, try length 1, 2, 3. Push the piece, recurse, pop. Copy the joined string at 4 parts.

def restoreIpAddresses(s):
  ans = []
  def ok(part):
    if not part or len(part) > 3:
      return False
    if len(part) > 1 and part[0] == "0":
      return False
    return int(part) <= 255
  def go(i, parts):
    if len(parts) == 4:
      if i == len(s):
        ans.append(".".join(parts))
      return
    for length in range(1, 4):
      if i + length > len(s):
        break
      piece = s[i:i + length]
      if not ok(piece):
        continue
      parts.append(piece)
      go(i + length, parts)
      parts.pop()
  go(0, [])
  return ans


# Method 3: More optimal
# Time: O(1) | Space: O(1)
# Before trying a length, prune: leftover chars must sit in [4-parts, 3*(4-parts)]. Drop leading-zero parts immediately. Cuts the tiny tree even further.

def restoreIpAddresses(s):
  ans = []
  def go(i, parts):
    left_parts = 4 - len(parts)
    left_chars = len(s) - i
    if left_chars < left_parts or left_chars > 3 * left_parts:
      return
    if len(parts) == 4:
      ans.append(".".join(parts))
      return
    for length in range(1, 4):
      if i + length > len(s):
        break
      if length > 1 and s[i] == "0":
        break
      piece = s[i:i + length]
      if int(piece) > 255:
        continue
      parts.append(piece)
      go(i + length, parts)
      parts.pop()
  go(0, [])
  return ans
