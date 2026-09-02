// Method 1: Brute
// Time: O((max-min) * n) | Space: O(1)
// Sort, then try every distance from (max-min) down to 1. First distance that can place m balls is the answer. Distance range can be 10^9, so this times out.

class Solution {
  bool can(vector<int>& position, int m, int dist) {
    int count = 1, last = position[0];
    for (int i = 1; i < (int)position.size(); i++) {
      if (position[i] - last >= dist) { count++; last = position[i]; }
    }
    return count >= m;
  }
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int span = position.back() - position[0];
    for (int d = span; d >= 1; d--) if (can(position, m, d)) return d;
    return 0;
  }
};


// Method 2: Optimal
// Time: O(n log(max-min)) | Space: O(1)
// Sort once. Binary search the gap. Greedy: place the next ball at the first basket that is at least mid away from the last placed ball. If you place m, try a larger gap (lo = mid + 1).

class Solution {
  bool can(vector<int>& position, int m, int dist) {
    int count = 1, last = position[0];
    for (int i = 1; i < (int)position.size(); i++) {
      if (position[i] - last >= dist) {
        count++; last = position[i];
        if (count >= m) return true;
      }
    }
    return false;
  }
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int lo = 1, hi = position.back() - position[0], ans = 0;
    while (lo <= hi) {
      int mid = (lo + hi) >> 1;
      if (can(position, m, mid)) { ans = mid; lo = mid + 1; }
      else hi = mid - 1;
    }
    return ans;
  }
};


// Method 3: More optimal
// Time: O(n log(max-min)) | Space: O(1)
// Overflow-safe mid. Half-open last-true: if mid works, lo = mid + 1, else hi = mid, then return lo - 1. No separate ans. Early stop once m balls are placed.

class Solution {
  bool can(vector<int>& position, int m, int dist) {
    int count = 1, last = position[0];
    for (int i = 1; i < (int)position.size(); i++) {
      if (position[i] - last >= dist) {
        count++; last = position[i];
        if (count >= m) return true;
      }
    }
    return false;
  }
public:
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    int lo = 1, hi = position.back() - position[0] + 1;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (can(position, m, mid)) lo = mid + 1;
      else hi = mid;
    }
    return lo - 1;
  }
};
