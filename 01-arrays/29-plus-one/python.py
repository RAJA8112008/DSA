# Method 1: Brute
# Time: O(n) | Space: O(n)
# Build a string / BigInt, add one, split back to digits. Fine in JS/Python, illegal in Java int, and not the interview idea.

def plusOne(digits):
  n = 0
  for d in digits:
    n = n * 10 + d
  n += 1
  return [int(ch) for ch in str(n)]


# Method 2: Optimal
# Time: O(n) | Space: O(n)
# Copy into a new array. From the last index, add 1 and propagate carry. If carry remains, allocate one extra leading 1.

def plusOne(digits):
  out = digits[:]
  carry = 1
  i = len(out) - 1
  while i >= 0 and carry:
    s = out[i] + carry
    out[i] = s % 10
    carry = s // 10
    i -= 1
  if carry:
    out = [1] + out
  return out


# Method 3: More optimal
# Time: O(n) | Space: O(1) extra if no new digit
# Walk from the right on the input. A digit < 9 becomes digit+1 and you return immediately. All nines become a new array [1, 0, 0, ...].

def plusOne(digits):
  for i in range(len(digits) - 1, -1, -1):
    if digits[i] < 9:
      digits[i] += 1
      return digits
    digits[i] = 0
  return [1] + digits
