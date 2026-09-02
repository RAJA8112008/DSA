# Method 1: Brute
# Time: O(n * n!) | Space: O(n)
# Generate every permutation with leftover copies. After a full perm, scan all n positions. n! full arrays, most fail only at the end.

def countArrangement(n):
  count = [0]
  def ok(perm):
    for i in range(1, n + 1):
      if perm[i - 1] % i != 0 and i % perm[i - 1] != 0:
        return False
    return True
  def go(left, perm):
    if not left:
      if ok(perm):
        count[0] += 1
      return
    for i in range(len(left)):
      go(left[:i] + left[i+1:], perm + [left[i]])
  go(list(range(1, n + 1)), [])
  return count[0]


# Method 2: Optimal
# Time: O(n!) | Space: O(n)
# At position pos (1-based), try unused numbers that already satisfy the divisibility rule. Fail early. used[] plus undo. Count leaves that fill n.

def countArrangement(n):
  count = [0]
  used = [False] * (n + 1)
  def go(pos):
    if pos > n:
      count[0] += 1
      return
    for num in range(1, n + 1):
      if used[num]:
        continue
      if num % pos != 0 and pos % num != 0:
        continue
      used[num] = True
      go(pos + 1)
      used[num] = False
  go(1)
  return count[0]


# Method 3: More optimal
# Time: O(n * 2^n) | Space: O(n * 2^n)
# n <= 15. mask bit (num-1) means num is used. pos = popcount(mask)+1. Memo[mask] caches how many ways finish from this used-set. Bitmask + prune + no leftover copies.

def countArrangement(n):
  memo = [-1] * (1 << n)
  def go(mask):
    pos = bin(mask).count("1") + 1
    if pos > n:
      return 1
    if memo[mask] != -1:
      return memo[mask]
    ways = 0
    for num in range(1, n + 1):
      if mask & (1 << (num - 1)):
        continue
      if num % pos != 0 and pos % num != 0:
        continue
      ways += go(mask | (1 << (num - 1)))
    memo[mask] = ways
    return ways
  return go(0)
