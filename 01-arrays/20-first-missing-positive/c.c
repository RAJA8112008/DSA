// Method 1: Brute
// Time: O(n log n) | Space: O(n)
// Copy, sort, then walk looking for the next needed positive. Sorting dominates.
// How it works: ignore non-positives and duplicates. need starts at 1. When you see need, bump it. At the end, need is missing.

/* pass n for array length; simple loops */
int firstMissingPositive(int* nums, int n) {
  int list = /* sorted copy */;
  int need = 1;
  for (int i = 0; i < n; i++) {
    if (list[i] <= 0) continue;
    if (list[i] == need) need++;
    else if (list[i] > need) return need;
  }
  return need;
}


// Method 2: Optimal
// Time: O(n) | Space: O(n)
// One Set of the input, then at most n+1 membership tests.
// How it works: the answer is in 1..n+1. Probe 1, 2, 3, … until a value is not in the set.

/* pass n for array length; simple loops */
/* linear scan stands in for a hash map */
int map_find(int* keys, int used, int key) {
  int i;
  for (i = 0; i < used; i++) if (keys[i] == key) return i;
  return -1;
}
int firstMissingPositive(int* nums, int n) {
  int set_keys[1024]; int set_n = 0;
  int need = 1;
  while (map_find(set_keys, set_n, need) >= 0) need++;
  return need;
}


// Method 3: More optimal
// Time: O(n) | Space: O(1)
// Index-as-hash / cyclic placement. Extra memory is a few integers. The input is overwritten.
// How it works: swap nums[i] to index nums[i]-1 while that value is in 1..n and not already home. Then the first i with nums[i] !== i+1 is the missing number; else n+1.

/* pass n for array length; simple loops */
int firstMissingPositive(int* nums, int n) {
  /* n is the given length */
  for (int i = 0; i < n; i++) {
    while (
      nums[i] >= 1 &&
      nums[i] <= n &&
      nums[nums[i] - 1] != nums[i]
    ) {
      int dest = nums[i] - 1;
      int t = nums[i];
      nums[i] = nums[dest];
      nums[dest] = t;
    }
  }
  for (int i = 0; i < n; i++) {
    if (nums[i] != i + 1) return i + 1;
  }
  return n + 1;
}
