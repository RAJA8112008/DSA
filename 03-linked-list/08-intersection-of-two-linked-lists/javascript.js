// Method 1: Brute
// Time: O(n·m) | Space: O(1)
// For each node in A, walk all of B looking for the same object. No extra set. Quadratic time.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function getIntersectionNode(headA, headB) {
  let a = headA;
  while (a) {
    let b = headB;
    while (b) {
      if (a === b) return a;
      b = b.next;
    }
    a = a.next;
  }
  return null;
}


// Method 2: Optimal
// Time: O(n+m) | Space: O(n)
// Put every node of A in a Set. Walk B; the first node in the set is the intersection. Linear time, extra memory for A.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function getIntersectionNode(headA, headB) {
  const seen = new Set();
  let a = headA;
  while (a) {
    seen.add(a);
    a = a.next;
  }
  let b = headB;
  while (b) {
    if (seen.has(b)) return b;
    b = b.next;
  }
  return null;
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Pointer a walks A then B. Pointer b walks B then A. They travel the same total length and meet at the first shared node, or both hit null. No set.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function getIntersectionNode(headA, headB) {
  let a = headA;
  let b = headB;
  while (a !== b) {
    a = a ? a.next : headB;
    b = b ? b.next : headA;
  }
  return a;
}
