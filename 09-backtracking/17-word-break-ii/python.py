# Method 1: Brute
# Time: O(2^n * n) | Space: O(2^n * n)
# At each index, cut or grow the last token, copying the token list. After the string ends, every token must sit in the dict. Catastrophic on repeated letters.

def wordBreak(s, wordDict):
  d = set(wordDict)
  ans = []
  def go(i, parts, cur):
    if i == len(s):
      allp = parts + [cur] if cur else parts[:]
      if all(w in d for w in allp):
        ans.append(" ".join(allp))
      return
    go(i + 1, parts[:], cur + s[i])
    if cur:
      go(i, parts + [cur], "")
  go(0, [], "")
  return ans


# Method 2: Optimal
# Time: O(2^n * n) | Space: O(2^n * n)
# From i, try every dictionary word as a prefix of s[i..]. Push, recurse i+len, pop. Only legal words ever sit on the path. Still exponential in the number of sentences.

def wordBreak(s, wordDict):
  ans = []
  def go(i, path):
    if i == len(s):
      ans.append(" ".join(path))
      return
    for word in wordDict:
      if s[i:i + len(word)] != word:
        continue
      path.append(word)
      go(i + len(word), path)
      path.pop()
  go(0, [])
  return ans


# Method 3: More optimal
# Time: O(2^n * n) | Space: O(2^n * n)
# can[i] is true if s[i..] can be broken at all. If !can[i], skip that index (prune). Memo[i] stores the list of sentences from i so overlapping tails are not rebuilt.

def wordBreak(s, wordDict):
  n = len(s)
  d = set(wordDict)
  can = [False] * (n + 1)
  can[n] = True
  for i in range(n - 1, -1, -1):
    for word in wordDict:
      if s[i:i + len(word)] == word and can[i + len(word)]:
        can[i] = True
        break
  memo = [None] * (n + 1)
  def go(i):
    if memo[i] is not None:
      return memo[i]
    if i == n:
      return [""]
    if not can[i]:
      memo[i] = []
      return []
    res = []
    for word in wordDict:
      if s[i:i + len(word)] != word:
        continue
      for tail in go(i + len(word)):
        res.append(word + (" " + tail if tail else ""))
    memo[i] = res
    return res
  return go(0) if can[0] else []
