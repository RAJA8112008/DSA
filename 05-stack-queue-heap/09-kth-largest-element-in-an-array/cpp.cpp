// Method 1: Brute
// Time: O(n · k) | Space: O(n)
// Copy the array. k times, find and remove the current max. Fine for tiny k, slow for k near n.

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> a = nums;
    int ans = 0;
    for (int t = 0; t < k; t++) {
      int best = 0;
      for (int i = 1; i < (int)a.size(); i++) if (a[i] > a[best]) best = i;
      ans = a[best];
      a.erase(a.begin() + best);
    }
    return ans;
  }
};


// Method 2: Optimal
// Time: O(n log n) | Space: O(n)
// Sort descending (or ascending and index). Honest and short. Use this first in an interview, then offer a heap.

class Solution {
public:
  int findKthLargest(vector<int> nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
  }
};


// Method 3: More optimal
// Time: O(n log k) | Space: O(k)
// Min-heap of size k. If the heap is full and x is bigger than the peek, replace the peek. The peek is the k-th largest. Tiny binary heap inlined. Quickselect is expected O(n) if they want that next.

class Solution {
  void up(vector<int>& h, int i) {
    while (i > 0) { int p=(i-1)>>1; if (h[i]>=h[p]) break; swap(h[i], h[p]); i=p; }
  }
  void down(vector<int>& h, int i) {
    int n=(int)h.size();
    while (true) { int s=i, l=i*2+1, r=l+1;
      if (l<n && h[l]<h[s]) s=l; if (r<n && h[r]<h[s]) s=r;
      if (s==i) break; swap(h[i], h[s]); i=s; }
  }
public:
  int findKthLargest(vector<int>& nums, int k) {
    vector<int> h;
    for (int x : nums) {
      if ((int)h.size() < k) { h.push_back(x); up(h, (int)h.size()-1); }
      else if (x > h[0]) {
        h[0] = h.back(); h.pop_back(); if (!h.empty()) down(h, 0);
        h.push_back(x); up(h, (int)h.size()-1);
      }
    }
    return h[0];
  }
};
