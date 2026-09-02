// Method 1: Brute
// Time: O(n) pop | Space: O(n)
// Two queues. pop moves all but the last item to the other queue, then swaps names. Push is O(1). Pop is O(n).

class MyStack {
  queue<int> q1, q2;
public:
  void push(int x) { q1.push(x); }
  int pop() {
    while (q1.size() > 1) { q2.push(q1.front()); q1.pop(); }
    int val = q1.front(); q1.pop();
    swap(q1, q2);
    return val;
  }
  int top() { int val = pop(); push(val); return val; }
  bool empty() { return q1.empty(); }
};


// Method 2: Optimal
// Time: O(n) push, O(1) pop | Space: O(n)
// One queue. After push, rotate length-1 items so the new item sits at the front. pop/top/empty are then O(1).

class MyStack {
  queue<int> q;
public:
  void push(int x) {
    q.push(x);
    for (int i = 0; i < (int)q.size() - 1; i++) { q.push(q.front()); q.pop(); }
  }
  int pop() { int x = q.front(); q.pop(); return x; }
  int top() { return q.front(); }
  bool empty() { return q.empty(); }
};


// Method 3: More optimal
// Time: O(1) push, O(n) pop | Space: O(n)
// One queue, no rotate on push. pop rotates n-1 items then shifts. Prefer this when pushes are common and pops are rare. Same extra space.

class MyStack {
  queue<int> q;
public:
  void push(int x) { q.push(x); }
  int pop() {
    for (int i = 0; i < (int)q.size() - 1; i++) { q.push(q.front()); q.pop(); }
    int x = q.front(); q.pop(); return x;
  }
  int top() { return q.back(); }
  bool empty() { return q.empty(); }
};
