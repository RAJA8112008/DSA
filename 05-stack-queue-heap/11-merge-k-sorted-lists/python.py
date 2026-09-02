# Method 1: Brute
# Time: O(n log n) | Space: O(n)
# Walk every node into an array, sort, then wire a new list. Ignores that each list is already sorted. Easy to code under pressure.

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
def mergeKLists(lists):
  vals = []
  for p in lists:
    while p:
      vals.append(p.val)
      p = p.next
  vals.sort()
  dummy = ListNode(0)
  cur = dummy
  for v in vals:
    cur.next = ListNode(v)
    cur = cur.next
  return dummy.next


# Method 2: Optimal
# Time: O(n log k) | Space: O(k)
# Min-heap of list heads keyed by val. Pop the smallest, push its next. n pops, heap size k. Uses the sorted property.

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
def mergeKLists(lists):
  h = []
  def key(x): return x.val
  def up(i):
    while i > 0:
      p = (i - 1) >> 1
      if key(h[i]) >= key(h[p]): break
      h[i], h[p] = h[p], h[i]
      i = p
  def down(i):
    while True:
      s = i
      l, r = i * 2 + 1, i * 2 + 2
      if l < len(h) and key(h[l]) < key(h[s]): s = l
      if r < len(h) and key(h[r]) < key(h[s]): s = r
      if s == i: break
      h[i], h[s] = h[s], h[i]
      i = s
  def push(node):
    h.append(node); up(len(h) - 1)
  def pop():
    top = h[0]
    last = h.pop()
    if h:
      h[0] = last; down(0)
    return top
  for node in lists:
    if node: push(node)
  dummy = ListNode(0)
  cur = dummy
  while h:
    node = pop()
    cur.next = node
    cur = node
    if node.next: push(node.next)
  return dummy.next


# Method 3: More optimal
# Time: O(n log k) | Space: O(log k)
# Pairwise merge like merge sort. Recursion depth log k. No heap to implement. Same n log k, often faster constants in JS, and O(1) extra besides the call stack.

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
def mergeKLists(lists):
  if not lists: return None
  def mergeTwo(a, b):
    dummy = ListNode(0)
    cur = dummy
    while a and b:
      if a.val <= b.val:
        cur.next = a; a = a.next
      else:
        cur.next = b; b = b.next
      cur = cur.next
    cur.next = a or b
    return dummy.next
  def split(lo, hi):
    if lo == hi: return lists[lo]
    mid = (lo + hi) >> 1
    return mergeTwo(split(lo, mid), split(mid + 1, hi))
  return split(0, len(lists) - 1)
