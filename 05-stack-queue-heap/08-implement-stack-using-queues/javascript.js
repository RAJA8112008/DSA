// Method 1: Brute
// Time: O(n) pop | Space: O(n)
// Two queues. pop moves all but the last item to the other queue, then swaps names. Push is O(1). Pop is O(n).

function MyStack() {
  this.q1 = [];
  this.q2 = [];
}
MyStack.prototype.push = function (x) { this.q1.push(x); };
MyStack.prototype.pop = function () {
  while (this.q1.length > 1) this.q2.push(this.q1.shift());
  const val = this.q1.shift();
  const tmp = this.q1; this.q1 = this.q2; this.q2 = tmp;
  return val;
};
MyStack.prototype.top = function () {
  const val = this.pop();
  this.push(val);
  return val;
};
MyStack.prototype.empty = function () { return this.q1.length === 0; };


// Method 2: Optimal
// Time: O(n) push, O(1) pop | Space: O(n)
// One queue. After push, rotate length-1 items so the new item sits at the front. pop/top/empty are then O(1).

function MyStack() {
  this.q = [];
}
MyStack.prototype.push = function (x) {
  this.q.push(x);
  for (let i = 0; i < this.q.length - 1; i++) this.q.push(this.q.shift());
};
MyStack.prototype.pop = function () { return this.q.shift(); };
MyStack.prototype.top = function () { return this.q[0]; };
MyStack.prototype.empty = function () { return this.q.length === 0; };


// Method 3: More optimal
// Time: O(1) push, O(n) pop | Space: O(n)
// One queue, no rotate on push. pop rotates n-1 items then shifts. Prefer this when pushes are common and pops are rare. Same extra space.

function MyStack() {
  this.q = [];
}
MyStack.prototype.push = function (x) { this.q.push(x); };
MyStack.prototype.pop = function () {
  for (let i = 0; i < this.q.length - 1; i++) this.q.push(this.q.shift());
  return this.q.shift();
};
MyStack.prototype.top = function () { return this.q[this.q.length - 1]; };
MyStack.prototype.empty = function () { return this.q.length === 0; };
