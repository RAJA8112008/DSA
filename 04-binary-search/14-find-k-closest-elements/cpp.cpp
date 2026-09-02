// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Pair each value with its distance, sort by distance then by value, take k items, sort those k again so the answer is ascending. Heavy, but matches the tie rule clearly.

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    vector<int> idx(arr.size());
    for (int i = 0; i < (int)arr.size(); i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](int i, int j) {
      int di = abs(arr[i] - x), dj = abs(arr[j] - x);
      if (di != dj) return di < dj;
      return arr[i] < arr[j];
    });
    vector<int> pick;
    for (int t = 0; t < k; t++) pick.push_back(arr[idx[t]]);
    sort(pick.begin(), pick.end());
    return pick;
  }
};


// Method 2: Optimal
// Time: O(n - k) | Space: O(k)
// The answer is a contiguous window of length k (the array is sorted). Shrink from both ends until the window is size k. Drop the farther end; on a tie drop the right (larger) value.

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int lo = 0, hi = (int)arr.size() - 1;
    while (hi - lo + 1 > k) {
      if (abs(arr[lo] - x) > abs(arr[hi] - x)) lo++;
      else hi--;
    }
    return vector<int>(arr.begin() + lo, arr.begin() + hi + 1);
  }
};


// Method 3: More optimal
// Time: O(log(n - k) + k) | Space: O(k)
// Binary search the left index of the k-window in [0, n-k]. If x is closer to arr[mid+k] than to arr[mid], the window should start further right. Overflow-safe mid. Copy k values at the end.

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int lo = 0, hi = (int)arr.size() - k;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (x - arr[mid] > arr[mid + k] - x) lo = mid + 1;
      else hi = mid;
    }
    return vector<int>(arr.begin() + lo, arr.begin() + lo + k);
  }
};
