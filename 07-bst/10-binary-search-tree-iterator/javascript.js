// Method 1: Brute
// Time: O(n) init, O(1) next | Space: O(n)
// Flatten inorder into an array at construction. next/hasNext are index moves. Simple, but you pay linear memory before the first call.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function BSTIterator(root) {
  this.vals = [];
  this.i = 0;
  const self = this;
  function go(node) {
    if (!node) return;
    go(node.left);
    self.vals.push(node.val);
    go(node.right);
  }
  go(root);
}
BSTIterator.prototype.next = function () {
  return this.vals[this.i++];
};
BSTIterator.prototype.hasNext = function () {
  return this.i < this.vals.length;
};


// Method 2: Optimal
// Time: O(h) init, amortized O(1) next | Space: O(h)
// Stack holds the path to the next node. Construction pushes the left spine. next() pops, then pushes the left spine of the right child.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function BSTIterator(root) {
  this.stack = [];
  this.pushLeft = function (node) {
    while (node) {
      this.stack.push(node);
      node = node.left;
    }
  };
  this.pushLeft(root);
}
BSTIterator.prototype.next = function () {
  const node = this.stack.pop();
  this.pushLeft(node.right);
  return node.val;
};
BSTIterator.prototype.hasNext = function () {
  return this.stack.length > 0;
};


// Method 3: More optimal
// Time: amortized O(1) next | Space: O(1)
// Morris: thread predecessor.right to the current node, walk without a stack. Unthread before yielding so the tree is restored. Extra memory is a handful of pointers.

function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

function BSTIterator(root) {
  this.cur = root;
}
BSTIterator.prototype.next = function () {
  while (this.cur) {
    if (!this.cur.left) {
      const val = this.cur.val;
      this.cur = this.cur.right;
      return val;
    }
    let pred = this.cur.left;
    while (pred.right && pred.right !== this.cur) pred = pred.right;
    if (!pred.right) {
      pred.right = this.cur;
      this.cur = this.cur.left;
    } else {
      pred.right = null;
      const val = this.cur.val;
      this.cur = this.cur.right;
      return val;
    }
  }
  return 0;
};
BSTIterator.prototype.hasNext = function () {
  return this.cur !== null;
};
