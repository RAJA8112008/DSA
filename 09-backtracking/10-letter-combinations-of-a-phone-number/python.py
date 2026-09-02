# Method 1: Brute
# Time: O(4^n * n) | Space: O(4^n * n)
# Each digit branches up to 4 ways. path + letter allocates a new string every time. n is the number of digits. Fine for n <= 4, wasteful copies.

def letterCombinations(digits):
  if not digits:
    return []
  mp = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
  ans = []
  def go(i, path):
    if i == len(digits):
      ans.append(path)
      return
    for ch in mp[ord(digits[i]) - 48]:
      go(i + 1, path + ch)
  go(0, "")
  return ans


# Method 2: Optimal
# Time: O(4^n * n) | Space: O(n)
# One char buffer. Push a letter, recurse, pop. Copy to the answer only at the last digit. Extra space is O(n) besides the output.

def letterCombinations(digits):
  if not digits:
    return []
  mp = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
  ans = []
  path = []
  def go(i):
    if i == len(digits):
      ans.append("".join(path))
      return
    for ch in mp[ord(digits[i]) - 48]:
      path.append(ch)
      go(i + 1)
      path.pop()
  go(0)
  return ans


# Method 3: More optimal
# Time: O(4^n * n) | Space: O(4^n * n)
# Iterative: start with [""]. For each digit, replace every prefix with prefix+letter. No recursion. Empty digits return [] immediately (early stop).

def letterCombinations(digits):
  if not digits:
    return []
  mp = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
  cur = [""]
  for d in digits:
    letters = mp[ord(d) - 48]
    nxt = []
    for prefix in cur:
      for ch in letters:
        nxt.append(prefix + ch)
    cur = nxt
  return cur
