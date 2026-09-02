// Method 1: Brute
// Time: O(n) getMin | Space: O(n)
// A plain array. getMin walks every item. Correct, but the interview asks for O(1) getMin.

function MinStack() {
  this.a = [];
}
MinStack.prototype.push = function (val) { this.a.push(val); };
MinStack.prototype.pop = function () { this.a.pop(); };
MinStack.prototype.top = function () { return this.a[this.a.length - 1]; };
MinStack.prototype.getMin = function () {
  let m = this.a[0];
  for (let i = 1; i < this.a.length; i++) if (this.a[i] < m) m = this.a[i];
  return m;
};


// Method 2: Optimal
// Time: O(1) | Space: O(n)
// mins tracks the current minimum. Push val onto mins if it is <= current min. Pop mins when the popped value equals mins top. Duplicate mins matter: use <= so two equal mins both sit on mins.

function MinStack() {
  this.st = [];
  this.mins = [];
}
MinStack.prototype.push = function (val) {
  this.st.push(val);
  if (!this.mins.length || val <= this.mins[this.mins.length - 1]) this.mins.push(val);
};
MinStack.prototype.pop = function () {
  const val = this.st.pop();
  if (val === this.mins[this.mins.length - 1]) this.mins.pop();
};
MinStack.prototype.top = function () { return this.st[this.st.length - 1]; };
MinStack.prototype.getMin = function () { return this.mins[this.mins.length - 1]; };


// Method 3: More optimal
// Time: O(1) | Space: O(n)
// One stack of pairs [val, minSoFar]. Each node already knows the min of the prefix. Slightly more memory per item, one structure to talk through. Still O(1) everything.

function MinStack() {
  this.st = [];
}
MinStack.prototype.push = function (val) {
  const m = this.st.length ? Math.min(this.st[this.st.length - 1][1], val) : val;
  this.st.push([val, m]);
};
MinStack.prototype.pop = function () { this.st.pop(); };
MinStack.prototype.top = function () { return this.st[this.st.length - 1][0]; };
MinStack.prototype.getMin = function () { return this.st[this.st.length - 1][1]; };
