// Method 1: Brute
// Time: O(n) | Space: O(n)
// DFS preorder into an array (node, child, next). Then walk the array and set next/prev, clear child. Extra array of every node.

function Node(val, prev, next, child) {
  this.val = val;
  this.prev = prev;
  this.next = next;
  this.child = child;
}

function flatten(head) {
  const nodes = [];
  function dfs(node) {
    while (node) {
      nodes.push(node);
      if (node.child) dfs(node.child);
      node = node.next;
    }
  }
  dfs(head);
  for (let i = 0; i < nodes.length; i++) {
    nodes[i].prev = i === 0 ? null : nodes[i - 1];
    nodes[i].next = i === nodes.length - 1 ? null : nodes[i + 1];
    nodes[i].child = null;
  }
  return nodes[0] || null;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Recurse: if a node has a child, flatten the child, hang it after the node, find the child's tail, attach the old next. Stack depth follows nesting.

function Node(val, prev, next, child) {
  this.val = val;
  this.prev = prev;
  this.next = next;
  this.child = child;
}

function flatten(head) {
  function go(node) {
    let cur = node;
    let last = node;
    while (cur) {
      const next = cur.next;
      if (cur.child) {
        const childLast = go(cur.child);
        cur.next = cur.child;
        cur.child.prev = cur;
        cur.child = null;
        if (childLast) {
          childLast.next = next;
          if (next) next.prev = childLast;
          last = childLast;
        }
      } else {
        last = cur;
      }
      cur = next;
    }
    return last;
  }
  go(head);
  return head;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Walk with one pointer. On a child, find that child's current tail (no recurse), splice the whole child between cur and cur.next, clear child. Then continue. Auxiliary space O(1).

function Node(val, prev, next, child) {
  this.val = val;
  this.prev = prev;
  this.next = next;
  this.child = child;
}

function flatten(head) {
  let cur = head;
  while (cur) {
    if (cur.child) {
      let tail = cur.child;
      while (tail.next) tail = tail.next;
      tail.next = cur.next;
      if (cur.next) cur.next.prev = tail;
      cur.next = cur.child;
      cur.child.prev = cur;
      cur.child = null;
    }
    cur = cur.next;
  }
  return head;
}
