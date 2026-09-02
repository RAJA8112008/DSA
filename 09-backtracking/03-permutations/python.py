# Method 1: Brute
# Time: O(n * n!) | Space: O(n * n!)
# At each step you copy the leftover numbers into a new array and copy the path. Extra copies on every internal node. n! leaves, each of length n.

def permute(nums):
  ans = []
  def go(left, path):
    if not left:
      ans.append(path)
      return
    for i in range(len(left)):
      go(left[:i] + left[i+1:], path + [left[i]])
  go(list(nums), [])
  return ans


# Method 2: Optimal
# Time: O(n * n!) | Space: O(n)
# used[j] marks nums[j] as taken. One path, mark/unmark. Extra space is O(n) besides the n! output lists.

def permute(nums):
  ans = []
  used = [False] * len(nums)
  def go(path):
    if len(path) == len(nums):
      ans.append(path[:])
      return
    for j in range(len(nums)):
      if used[j]:
        continue
      used[j] = True
      path.append(nums[j])
      go(path)
      path.pop()
      used[j] = False
  go([])
  return ans


# Method 3: More optimal
# Time: O(n * n!) | Space: O(n)
# Swap nums[start] with each later index, recurse start+1, swap back. The prefix is the path. No used[] and no leftover copies. Still n! output.

def permute(nums):
  ans = []
  def go(start):
    if start == len(nums):
      ans.append(nums[:])
      return
    for i in range(start, len(nums)):
      nums[start], nums[i] = nums[i], nums[start]
      go(start + 1)
      nums[start], nums[i] = nums[i], nums[start]
  go(0)
  return ans
