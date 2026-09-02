# Method 1: Brute
# Time: O(sqrt(x)) | Space: O(1)
# Increase r while (r+1)*(r+1) still fits in x. Use 64-bit (or a division check) so r*r does not overflow 32-bit int.

def mySqrt(x):
  r = 0
  while (r + 1) * (r + 1) <= x:
    r += 1
  return r


# Method 2: Optimal
# Time: O(log x) | Space: O(1)
# Last-true search: mid is good when mid <= x / mid (avoids mid*mid overflow). If good, try a larger r. If not, shrink high. x in {0,1} returns x.

def mySqrt(x):
  if x < 2:
    return x
  lo, hi, ans = 1, x, 1
  while lo <= hi:
    mid = (lo + hi) >> 1
    if mid <= x // mid:
      ans = mid
      lo = mid + 1
    else:
      hi = mid - 1
  return ans


# Method 3: More optimal
# Time: O(log x) | Space: O(1)
# Integer Newton: r = (r + x/r) / 2 until r <= x/r. Overflow-safe. Usually fewer loops than binary search. Still exact for the floor sqrt.

def mySqrt(x):
  if x < 2:
    return x
  r = x
  while r > x // r:
    r = (r + x // r) // 2
  return r
