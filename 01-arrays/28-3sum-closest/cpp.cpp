// Method 1: Brute
// Time: O(n³) | Space: O(1)
// Every triple, track the sum whose absolute gap to target is smallest.

int threeSumClosest(vector<int>& nums, int target) {
  int n = (int)nums.size(), best = nums[0] + nums[1] + nums[2];
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++) {
        int s = nums[i] + nums[j] + nums[k];
        if (abs(s - target) < abs(best - target)) best = s;
      }
  return best;
}


// Method 2: Optimal
// Time: O(n² log n) | Space: O(n)
// Sort. Fix two indexes, binary search the value closest to the leftover. Extra log n on each pair.

int threeSumClosest(vector<int>& nums, int target) {
  auto a = nums;
  sort(a.begin(), a.end());
  int n = (int)a.size(), best = a[0] + a[1] + a[2];
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int need = target - a[i] - a[j];
      int lo = j + 1, hi = n - 1, pick = j + 1;
      if (lo > hi) continue;
      while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] == need) return target;
        pick = mid;
        if (a[mid] < need) lo = mid + 1;
        else hi = mid - 1;
      }
      int cand[3] = { pick, pick - 1, pick + 1 };
      for (int t = 0; t < 3; t++) {
        int k = cand[t];
        if (k <= j || k >= n) continue;
        int s = a[i] + a[j] + a[k];
        if (abs(s - target) < abs(best - target)) best = s;
      }
    }
  }
  return best;
}


// Method 3: More optimal
// Time: O(n²) | Space: O(1) extra
// Sort. Fix i. Two pointers on the rest. Move the side that improves the sum. Track the closest. Stop early on an exact hit.

int threeSumClosest(vector<int>& nums, int target) {
  auto a = nums;
  sort(a.begin(), a.end());
  int n = (int)a.size(), best = a[0] + a[1] + a[2];
  for (int i = 0; i < n; i++) {
    int L = i + 1, R = n - 1;
    while (L < R) {
      int s = a[i] + a[L] + a[R];
      if (abs(s - target) < abs(best - target)) best = s;
      if (s == target) return s;
      if (s < target) L++;
      else R--;
    }
  }
  return best;
}
