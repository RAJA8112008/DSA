// Method 1: Brute
// Time: O(n) pop/peek | Space: O(n)
// On pop, pour all into temp (that reverses), pop, pour back. Every call is O(n). Easy to see FIFO, slow.

function MyQueue() {
  this.st = [];
}
MyQueue.prototype.push = function (x) { this.st.push(x); };
MyQueue.prototype.pop = function () {
  const tmp = [];
  while (this.st.length) tmp.push(this.st.pop());
  const val = tmp.pop();
  while (tmp.length) this.st.push(tmp.pop());
  return val;
};
MyQueue.prototype.peek = function () {
  const tmp = [];
  while (this.st.length) tmp.push(this.st.pop());
  const val = tmp[tmp.length - 1];
  while (tmp.length) this.st.push(tmp.pop());
  return val;
};
MyQueue.prototype.empty = function () { return this.st.length === 0; };


// Method 2: Optimal
// Time: O(1) amortized | Space: O(n)
// push always goes to inSt. pop/peek pour inSt into outSt only when outSt is empty. Each item moves at most twice.

function MyQueue() {
  this.inSt = [];
  this.outSt = [];
}
MyQueue.prototype.pour = function () {
  if (this.outSt.length) return;
  while (this.inSt.length) this.outSt.push(this.inSt.pop());
};
MyQueue.prototype.push = function (x) { this.inSt.push(x); };
MyQueue.prototype.pop = function () { this.pour(); return this.outSt.pop(); };
MyQueue.prototype.peek = function () { this.pour(); return this.outSt[this.outSt.length - 1]; };
MyQueue.prototype.empty = function () { return !this.inSt.length && !this.outSt.length; };


// Method 3: More optimal
// Time: O(1) amortized | Space: O(n)
// Same two stacks. pop is written as peek plus a pop so pour lives in one place. Interviewers like this factoring; complexity matches Optimal.

function MyQueue() {
  this.inSt = [];
  this.outSt = [];
}
MyQueue.prototype.push = function (x) { this.inSt.push(x); };
MyQueue.prototype.peek = function () {
  if (!this.outSt.length) {
    while (this.inSt.length) this.outSt.push(this.inSt.pop());
  }
  return this.outSt[this.outSt.length - 1];
};
MyQueue.prototype.pop = function () {
  this.peek();
  return this.outSt.pop();
};
MyQueue.prototype.empty = function () { return !this.inSt.length && !this.outSt.length; };
