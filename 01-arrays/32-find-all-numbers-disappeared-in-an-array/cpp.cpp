// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate v in 1..n, scan the array. If it never appears, it is missing.

vector<int> findDisappearedNumbers(vector<int>& nums) {
  vector<int> out;
  int n = (int)nums.size();
  for (int v = 1; v <= n; v++) {
    bool found = false;
    for (int x : nums) if (x == v) { found = true; break; }
    if (!found) out.push_back(v);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A boolean array (or a set) of seen values. Then walk 1..n and collect the false slots.

vector<int> findDisappearedNumbers(vector<int>& nums) {
  int n = (int)nums.size();
  vector<int> seen(n + 1), out;
  for (int x : nums) seen[x] = 1;
  for (int v = 1; v <= n; v++) if (!seen[v]) out.push_back(v);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// For each value x, negate nums[abs(x)-1]. Values whose slots stay positive never appeared. Same marking trick as Find All Duplicates.

vector<int> findDisappearedNumbers(vector<int>& nums) {
  for (int x : nums) {
    int slot = abs(x) - 1;
    if (nums[slot] > 0) nums[slot] = -nums[slot];
  }
  vector<int> out;
  for (int i = 0; i < (int)nums.size(); i++) if (nums[i] > 0) out.push_back(i + 1);
  return out;
}
