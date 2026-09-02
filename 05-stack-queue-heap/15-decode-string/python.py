# Method 1: Brute
# Time: O(n · out) | Space: O(n · out)
# Recursion: parse a chunk, and when you see k[...], slice the inner substring, decode it, repeat. Extra string copies of the remaining suffix. Correct, messy bounds.

def decodeString(s):
  def parse(i):
    out = ""
    while i < len(s) and s[i] != "]":
      if s[i] < "0" or s[i] > "9":
        out += s[i]
        i += 1
        continue
      k = 0
      while s[i] >= "0" and s[i] <= "9":
        k = k * 10 + int(s[i])
        i += 1
      i += 1  # skip '['
      inner = parse(i)
      out += inner["text"] * k
      i = inner["i"] + 1  # skip ']'
    return {"text": out, "i": i}
  return parse(0)["text"]


# Method 2: Optimal
# Time: O(n + out) | Space: O(n + out)
# One stack. Digits build k. '[' pushes the current string and k, then resets. Letters append. ']' pops and repeats. Linear in input plus output size.

def decodeString(s):
  st = []
  cur = ""
  k = 0
  for ch in s:
    if "0" <= ch <= "9":
      k = k * 10 + ord(ch) - 48
    elif ch == "[":
      st.append((cur, k))
      cur = ""
      k = 0
    elif ch == "]":
      prev, ck = st.pop()
      cur = prev + cur * ck
    else:
      cur += ch
  return cur


# Method 3: More optimal
# Time: O(n + out) | Space: O(n + out)
# Two stacks: counts and strings. Same linear bound. Some interviewers prefer two named stacks over pairs. Repeat still dominates the output cost.

def decodeString(s):
  counts = []
  strs = []
  cur = ""
  k = 0
  for ch in s:
    if "0" <= ch <= "9":
      k = k * 10 + ord(ch) - 48
    elif ch == "[":
      counts.append(k)
      strs.append(cur)
      cur = ""
      k = 0
    elif ch == "]":
      cur = strs.pop() + cur * counts.pop()
    else:
      cur += ch
  return cur
