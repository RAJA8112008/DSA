// Method 1: Brute
// Time: O((n+m) log(n+m)) | Space: O(n+m)
// Collect every value, sort the array, rebuild. Simple, but sort is extra work and you throw away the original nodes.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function mergeTwoLists(list1, list2) {
  const vals = [];
  for (let p = list1; p; p = p.next) vals.push(p.val);
  for (let p = list2; p; p = p.next) vals.push(p.val);
  vals.sort((a, b) => a - b);
  const dummy = new ListNode(0);
  let tail = dummy;
  for (const v of vals) {
    tail.next = new ListNode(v);
    tail = tail.next;
  }
  return dummy.next;
}


// Method 2: Optimal
// Time: O(n+m) | Space: O(n+m)
// Recurse: the smaller head is the next output node, then merge the rest. Linear comparisons. Stack depth is O(n+m).

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function mergeTwoLists(list1, list2) {
  if (!list1) return list2;
  if (!list2) return list1;
  if (list1.val < list2.val) {
    list1.next = mergeTwoLists(list1.next, list2);
    return list1;
  }
  list2.next = mergeTwoLists(list1, list2.next);
  return list2;
}


// Method 3: More optimal
// Time: O(n+m) | Space: O(1)
// Dummy plus a tail pointer. Each step hangs the smaller remaining node. Leftover chain attaches at the end. Constant extra space besides the output, which reuses input nodes.

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

function mergeTwoLists(list1, list2) {
  const dummy = new ListNode(0);
  let tail = dummy;
  while (list1 && list2) {
    if (list1.val < list2.val) {
      tail.next = list1;
      list1 = list1.next;
    } else {
      tail.next = list2;
      list2 = list2.next;
    }
    tail = tail.next;
  }
  tail.next = list1 || list2;
  return dummy.next;
}
