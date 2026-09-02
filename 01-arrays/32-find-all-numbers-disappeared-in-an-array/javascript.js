// Method 1: Brute
// Time: O(n²) | Space: O(1)
// For each candidate v in 1..n, scan the array. If it never appears, it is missing.

function findDisappearedNumbers(nums) {
  const n = nums.length;
  const out = [];
  for (let v = 1; v <= n; v++) {
    let found = false;
    for (let i = 0; i < n; i++) if (nums[i] === v) { found = true; break; }
    if (!found) out.push(v);
  }
  return out;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// A boolean array (or a set) of seen values. Then walk 1..n and collect the false slots.

function findDisappearedNumbers(nums) {
  const n = nums.length;
  const seen = Array(n + 1).fill(false);
  for (let i = 0; i < n; i++) seen[nums[i]] = true;
  const out = [];
  for (let v = 1; v <= n; v++) if (!seen[v]) out.push(v);
  return out;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1) extra
// For each value x, negate nums[abs(x)-1]. Values whose slots stay positive never appeared. Same marking trick as Find All Duplicates.

function findDisappearedNumbers(nums) {
  for (let i = 0; i < nums.length; i++) {
    const x = nums[i] < 0 ? -nums[i] : nums[i];
    const slot = x - 1;
    if (nums[slot] > 0) nums[slot] = -nums[slot];
  }
  const out = [];
  for (let i = 0; i < nums.length; i++) if (nums[i] > 0) out.push(i + 1);
  return out;
}
