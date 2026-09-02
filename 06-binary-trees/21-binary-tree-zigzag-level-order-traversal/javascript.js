// Method 1: Brute
// Time: O(n) | Space: O(n)
// Level-order into lists. Reverse rows whose index is odd. Extra reverse pass per odd level.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function zigzagLevelOrder(root) {
  if (!root) return [];
  const out = [];
  const q = [root];
  while (q.length) {
    const n = q.length;
    const row = [];
    for (let i = 0; i < n; i++) {
      const node = q.shift();
      row.push(node.val);
      if (node.left) q.push(node.left);
      if (node.right) q.push(node.right);
    }
    if (out.length % 2 === 1) row.reverse();
    out.push(row);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// Deque of nodes. Even levels poll from the front and offer children left-then-right at the back. Odd levels poll from the back and offer children right-then-left at the front.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function zigzagLevelOrder(root) {
  if (!root) return [];
  const out = [];
  const dq = [root];
  let leftToRight = true;
  while (dq.length) {
    const n = dq.length;
    const row = [];
    for (let i = 0; i < n; i++) {
      if (leftToRight) {
        const node = dq.shift();
        row.push(node.val);
        if (node.left) dq.push(node.left);
        if (node.right) dq.push(node.right);
      } else {
        const node = dq.pop();
        row.push(node.val);
        if (node.right) dq.unshift(node.right);
        if (node.left) dq.unshift(node.left);
      }
    }
    out.push(row);
    leftToRight = !leftToRight;
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(h)
// DFS with depth. Append a new list when you first reach a depth. Push on even depths, unshift on odd depths. Recursion stack only.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function zigzagLevelOrder(root) {
  const out = [];
  function go(node, d) {
    if (!node) return;
    if (d === out.length) out.push([]);
    if (d % 2 === 0) out[d].push(node.val);
    else out[d].unshift(node.val);
    go(node.left, d + 1);
    go(node.right, d + 1);
  }
  go(root, 0);
  return out;
}
