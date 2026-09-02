# Method 1: Brute
# Time: O(n²) | Space: O(1)
# Outer index i, inner j > i. First pair that sums to target is the answer. Works, ignores the sorted hint.

def twoSum(numbers, target):
  n = len(numbers)
  for i in range(n):
    for j in range(i + 1, n):
      if numbers[i] + numbers[j] == target:
        return [i + 1, j + 1]
  return []


# Method 2: Optimal
# Time: O(n log n) | Space: O(1)
# For each left value, binary search target - numbers[i] on the right side. Sorted order makes the search legal. Extra log n versus two pointers.

def twoSum(numbers, target):
  n = len(numbers)
  for i in range(n):
    need = target - numbers[i]
    lo, hi = i + 1, n - 1
    while lo <= hi:
      mid = (lo + hi) // 2
      if numbers[mid] == need:
        return [i + 1, mid + 1]
      if numbers[mid] < need:
        lo = mid + 1
      else:
        hi = mid - 1
  return []


# Method 3: More optimal
# Time: O(n) | Space: O(1)
# Left at start, right at end. Sum too small: left++. Sum too big: right--. Sorted order guarantees you never miss the pair. Interview finish line.

def twoSum(numbers, target):
  left, right = 0, len(numbers) - 1
  while left < right:
    s = numbers[left] + numbers[right]
    if s == target:
      return [left + 1, right + 1]
    if s < target:
      left += 1
    else:
      right -= 1
  return []
