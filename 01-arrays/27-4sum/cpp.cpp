// Method 1: Brute
// Time: O(n^4) | Space: O(1) extra
// Four nested indexes. Sort each hit so a set of strings can drop duplicates. Correct and too slow.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  int n = (int)nums.size();
  set<vector<int>> seen;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        for (int p = k + 1; p < n; p++) {
          if ((long long)nums[i] + nums[j] + nums[k] + nums[p] != target) continue;
          vector<int> q = { nums[i], nums[j], nums[k], nums[p] };
          sort(q.begin(), q.end());
          seen.insert(q);
        }
  return vector<vector<int>>(seen.begin(), seen.end());
}


// Method 2: Optimal
// Time: O(n^3) | Space: O(n)
// Fix i, j, k. Look up target - (a+b+c) in a set of values after k. Still cubic, extra set, duplicates need care. A stepping stone to two pointers.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  int n = (int)nums.size();
  set<vector<int>> seenQ;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      unordered_set<long long> seen;
      for (int k = j + 1; k < n; k++) {
        long long need = (long long)target - nums[i] - nums[j] - nums[k];
        if (seen.count(need)) {
          vector<int> q = { nums[i], nums[j], nums[k], (int)need };
          sort(q.begin(), q.end());
          seenQ.insert(q);
        }
        seen.insert(nums[k]);
      }
    }
  }
  return vector<vector<int>>(seenQ.begin(), seenQ.end());
}


// Method 3: More optimal
// Time: O(n^3) | Space: O(1) extra
// Sort. Fix i and j. Two pointers on the rest. Skip duplicate i, j, left, and right. Use 64-bit sums if the language overflows. This is the expected answer.

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  auto a = nums;
  sort(a.begin(), a.end());
  int n = (int)a.size();
  vector<vector<int>> out;
  for (int i = 0; i < n; i++) {
    if (i && a[i] == a[i - 1]) continue;
    for (int j = i + 1; j < n; j++) {
      if (j > i + 1 && a[j] == a[j - 1]) continue;
      int L = j + 1, R = n - 1;
      while (L < R) {
        long long sum = (long long)a[i] + a[j] + a[L] + a[R];
        if (sum == target) {
          out.push_back({ a[i], a[j], a[L], a[R] });
          L++; R--;
          while (L < R && a[L] == a[L - 1]) L++;
          while (L < R && a[R] == a[R + 1]) R--;
        } else if (sum < target) L++;
        else R--;
      }
    }
  }
  return out;
}
