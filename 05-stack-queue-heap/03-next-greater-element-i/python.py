# Method 1: Brute
# Time: O(n · m) | Space: O(1)
# For each nums1 value, scan nums2 to find it, then scan the suffix for a greater number. Fine when both arrays are tiny.

def nextGreaterElement(nums1, nums2):
  ans = []
  for x in nums1:
    found = False
    nxt = -1
    for y in nums2:
      if not found:
        if y == x: found = True
        continue
      if y > x:
        nxt = y
        break
    ans.append(nxt)
  return ans


# Method 2: Optimal
# Time: O(n · m) | Space: O(m)
# Hash each nums2 value to its index so the find step is O(1). The right scan is still O(m) per query. Clearer, same worst case.

def nextGreaterElement(nums1, nums2):
  idx = {}
  for i, x in enumerate(nums2):
    idx[x] = i
  ans = []
  for x in nums1:
    nxt = -1
    for j in range(idx[x] + 1, len(nums2)):
      if nums2[j] > x:
        nxt = nums2[j]
        break
    ans.append(nxt)
  return ans


# Method 3: More optimal
# Time: O(n + m) | Space: O(m)
# Monotonic stack on nums2 builds next[value] = first greater to the right. Then each nums1 lookup is O(1). Linear in the two array lengths.

def nextGreaterElement(nums1, nums2):
  nxt = {}
  st = []
  for x in nums2:
    while st and st[-1] < x:
      nxt[st.pop()] = x
    st.append(x)
  return [nxt.get(x, -1) for x in nums1]
