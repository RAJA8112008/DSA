// Method 1: Brute
// Time: O(n+m) | Space: O(n+m)
// Turn each list into a BigInt (least-significant digit first), add, then emit digits into a new list. Easy in JavaScript, hides the carry logic interviewers want.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function addTwoNumbers(l1, l2) {
  function toBig(node) {
    let n = 0n;
    let place = 1n;
    while (node) {
      n += BigInt(node.val) * place;
      place *= 10n;
      node = node.next;
    }
    return n;
  }
  let sum = toBig(l1) + toBig(l2);
  const dummy = new ListNode(0);
  let tail = dummy;
  if (sum === 0n) return dummy;
  while (sum > 0n) {
    tail.next = new ListNode(Number(sum % 10n));
    tail = tail.next;
    sum /= 10n;
  }
  return dummy.next;
}


// Method 2: Optimal
// Time: O(max(n,m)) | Space: O(max(n,m))
// Recursive add of two nodes plus carry. Next call gets the rest of both lists. Stack depth follows the longer number.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function addTwoNumbers(l1, l2) {
  function add(a, b, carry) {
    if (!a && !b && carry === 0) return null;
    const sum = (a ? a.val : 0) + (b ? b.val : 0) + carry;
    const node = new ListNode(sum % 10);
    node.next = add(a ? a.next : null, b ? b.next : null, Math.floor(sum / 10));
    return node;
  }
  return add(l1, l2, 0);
}


// Method 3: More optimal
// Time: O(max(n,m)) | Space: O(1)
// Iterative dummy. Each step sums two digits and carry, writes sum % 10, carry becomes floor(sum/10). Extra node if carry remains. Output list is required; extra pointers are constant.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function addTwoNumbers(l1, l2) {
  const dummy = new ListNode(0);
  let tail = dummy;
  let carry = 0;
  while (l1 || l2 || carry) {
    const sum = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
    tail.next = new ListNode(sum % 10);
    tail = tail.next;
    carry = Math.floor(sum / 10);
    if (l1) l1 = l1.next;
    if (l2) l2 = l2.next;
  }
  return dummy.next;
}
