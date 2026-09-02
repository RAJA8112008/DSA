// Method 1: Brute
// Time: O(n) | Space: O(n)
// Recursive inorder: walk left, push this value, walk right. Matches the definition. Extra memory is the output array plus O(h) call stack.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function inorderTraversal(root) {
  const out = [];
  function go(node) {
    if (!node) return;
    go(node.left);
    out.push(node.val);
    go(node.right);
  }
  go(root);
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(h)
// Iterative stack: go left until null, pop, record val, go right. Same visit order as recursion without depending on engine stack limits as much; still O(h) extra.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function inorderTraversal(root) {
  const out = [];
  const stack = [];
  let cur = root;
  while (cur || stack.length) {
    while (cur) {
      stack.push(cur);
      cur = cur.left;
    }
    cur = stack.pop();
    out.push(cur.val);
    cur = cur.right;
  }
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Morris: if there is no left, visit and go right. Else find the predecessor (rightmost in left). If pred.right is null, thread it to cur and go left. If it already points at cur, unthread, visit, go right. Auxiliary space O(1) besides the output list.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function inorderTraversal(root) {
  const out = [];
  let cur = root;
  while (cur) {
    if (!cur.left) {
      out.push(cur.val);
      cur = cur.right;
    } else {
      let pred = cur.left;
      while (pred.right && pred.right !== cur) pred = pred.right;
      if (!pred.right) {
        pred.right = cur;
        cur = cur.left;
      } else {
        pred.right = null;
        out.push(cur.val);
        cur = cur.right;
      }
    }
  }
  return out;
}
