// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate v in 1..n, scan the array. If it never appears, it is missing.

int findDisappearedNumbers(int* nums, int n, int* out) {
  int v, i, on = 0;
  for (v = 1; v <= n; v++) {
    int found = 0;
    for (i = 0; i < n; i++) if (nums[i] == v) { found = 1; break; }
    if (!found) out[on++] = v;
  }
  return on;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A boolean array (or a set) of seen values. Then walk 1..n and collect the false slots.

int findDisappearedNumbers(int* nums, int n, int* out) {
  int seen[10001] = {0};
  int i, v, on = 0;
  for (i = 0; i < n; i++) seen[nums[i]] = 1;
  for (v = 1; v <= n; v++) if (!seen[v]) out[on++] = v;
  return on;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// For each value x, negate nums[abs(x)-1]. Values whose slots stay positive never appeared. Same marking trick as Find All Duplicates.

int findDisappearedMark(int* nums, int n, int* out) {
  int i, on = 0;
  for (i = 0; i < n; i++) {
    int x = nums[i] < 0 ? -nums[i] : nums[i];
    int slot = x - 1;
    if (nums[slot] > 0) nums[slot] = -nums[slot];
  }
  for (i = 0; i < n; i++) if (nums[i] > 0) out[on++] = i + 1;
  return on;
}
