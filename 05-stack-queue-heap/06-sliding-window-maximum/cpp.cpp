// Method 1: Brute
// Time: O(n · k) | Space: O(1)
// For each window start, scan k items for the max. Simple and too slow when k is n/2.

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> out;
    int n = (int)nums.size();
    for (int i = 0; i + k - 1 < n; i++) {
      int m = nums[i];
      for (int j = i + 1; j < i + k; j++) if (nums[j] > m) m = nums[j];
      out.push_back(m);
    }
    return out;
  }
};


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Max-heap of [value, index] (store negated value in a min-heap). Pop the top while its index left the window. Lazy delete keeps the heap honest. Better than n*k, worse than a deque.

class Solution {
  struct MinHeap {
    vector<pair<int,int>> a;
    void push(pair<int,int> x) {
      a.push_back(x); int i = (int)a.size()-1;
      while (i > 0) { int p = (i-1)>>1; if (a[i].first >= a[p].first) break; swap(a[i], a[p]); i = p; }
    }
    pair<int,int> pop() {
      auto top = a[0]; auto last = a.back(); a.pop_back();
      if (!a.empty()) { a[0] = last; int i = 0;
        while (true) { int s = i, l = i*2+1, r = l+1, n = (int)a.size();
          if (l < n && a[l].first < a[s].first) s = l;
          if (r < n && a[r].first < a[s].first) s = r;
          if (s == i) break; swap(a[i], a[s]); i = s; } }
      return top;
    }
    pair<int,int> peek() { return a[0]; }
  };
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MinHeap heap; vector<int> out;
    for (int i = 0; i < (int)nums.size(); i++) {
      heap.push({-nums[i], i});
      if (i < k - 1) continue;
      while (heap.peek().second <= i - k) heap.pop();
      out.push_back(-heap.peek().first);
    }
    return out;
  }
};


// Method 3: More optimal
// Time: O(n) | Space: O(k)
// Decreasing deque of indices. Pop back while nums[i] is larger. Pop front if it left the window. Front is the max. Each index enters and leaves once.

class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> out;
    for (int i = 0; i < (int)nums.size(); i++) {
      while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
      dq.push_back(i);
      if (dq.front() <= i - k) dq.pop_front();
      if (i >= k - 1) out.push_back(nums[dq.front()]);
    }
    return out;
  }
};
