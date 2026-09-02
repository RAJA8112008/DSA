# Method 1: Brute
# Time: O(n * 2^n) | Space: O(n * 2^n)
# Each call does path.concat so every node of the tree allocates a new array. Correct, but you pay extra copies on internal nodes, not only at leaves. Time is still exponential because there are 2^n subsets.

def subsets(nums):
  ans = []
  def go(i, path):
    if i == len(nums):
      ans.append(path)
      return
    go(i + 1, path[:])
    take = path[:]
    take.append(nums[i])
    go(i + 1, take)
  go(0, [])
  return ans


# Method 2: Optimal
# Time: O(n * 2^n) | Space: O(n)
# One path array is shared. Push, recurse, pop. You copy only at a leaf. Extra memory besides the output is the path plus O(n) stack.

def subsets(nums):
  ans = []
  def go(i, path):
    if i == len(nums):
      ans.append(path[:])
      return
    go(i + 1, path)
    path.append(nums[i])
    go(i + 1, path)
    path.pop()
  go(0, [])
  return ans


# Method 3: More optimal
# Time: O(n * 2^n) | Space: O(n)
# No recursion. Each mask from 0 to 2^n-1 is one subset. Bit i on means nums[i] is in. Same output size, no call stack, tight inner loop.

def subsets(nums):
  n = len(nums)
  ans = []
  for mask in range(1 << n):
    cur = []
    for i in range(n):
      if mask & (1 << i):
        cur.append(nums[i])
    ans.append(cur)
  return ans
