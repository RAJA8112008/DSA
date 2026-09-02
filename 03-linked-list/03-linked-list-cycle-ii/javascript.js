// Method 1: Brute
// Time: O(n) | Space: O(n)
// Walk from head. The first node already in the Set is the start of the cycle. If you reach null, there is no cycle.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function detectCycle(head) {
  const seen = new Set();
  let cur = head;
  while (cur) {
    if (seen.has(cur)) return cur;
    seen.add(cur);
    cur = cur.next;
  }
  return null;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Floyd finds a node inside the cycle. Walk that loop once into a Set. Then walk from head until you hit a node in the set. Extra memory is the cycle length.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function detectCycle(head) {
  let slow = head;
  let fast = head;
  let meet = null;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) {
      meet = slow;
      break;
    }
  }
  if (!meet) return null;
  const inCycle = new Set();
  let p = meet;
  do {
    inCycle.add(p);
    p = p.next;
  } while (p !== meet);
  let q = head;
  while (!inCycle.has(q)) q = q.next;
  return q;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// After slow and fast meet, put one pointer at head. Walk both one step at a time. They meet at the cycle start. Proof: distance from head to start equals distance from meet to start around the loop. No extra set.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function detectCycle(head) {
  let slow = head;
  let fast = head;
  while (fast && fast.next) {
    slow = slow.next;
    fast = fast.next.next;
    if (slow === fast) {
      let p = head;
      while (p !== slow) {
        p = p.next;
        slow = slow.next;
      }
      return p;
    }
  }
  return null;
}
